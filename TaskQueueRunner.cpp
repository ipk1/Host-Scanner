#include "TaskQueueRunner.h"

using namespace boost;

TaskQueueRunner::TaskQueueRunner(int capacity, int batch)
	: batch(batch), running(batch), pending(capacity)
{
}

void TaskQueueRunner::Enqueue(void* task)
{
	pending.push(task);
}

void TaskQueueRunner::Run()
{
	for (auto i = 0; i < batch; i++)
	{
		void* task;

		if (pending.pop(task))
		{
			running.push(task);
		}
		else
		{
			break;
		}
	}

	while (!pending.empty() || !running.empty())
	{
		void* task;

		if (!running.pop(task))
		{
			break;
		}

		auto result = reinterpret_cast<void*(*)(void)>(task)();

		if (result == nullptr)
		{
			void* next;

			if (pending.pop(next))
			{
				running.push(next);
			}
		}
		else
		{
			running.push(result);
		}
	}
}

TaskQueueRunner::~TaskQueueRunner()
{
}