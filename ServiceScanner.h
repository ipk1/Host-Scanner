#pragma once
#include "Stdafx.h"
#include "Service.h"

/*!
 * Represents a port scanner.
 */
class ServiceScanner
{
public:

	/*!
	 * Scans a service to determine aliveness.
	 * 
	 * \param service Service.
	 */
	virtual void Scan(Service* service) = 0;

	/*!
	 * Scans a list of services to determine aliveness.
	 * 
	 * \param services List of services.
	 */
	virtual void Scan(Services* services) = 0;

	/*!
	 * Dumps the scan results into the standard output.
	 *
	 * \param services List of services.
	 */
	static void DumpResults(Services* services);

	/*!
	 * Frees up the resources allocated during the lifetime of this instance.
	 */
	virtual ~ServiceScanner();
	
};