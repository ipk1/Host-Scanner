#pragma once
#include "Stdafx.h"
#include "HostScanner.h"
#include <string>

/*!
 * Implements a passive scanner which returns Shodan data.
 */
class ShodanScanner : public HostScanner
{
public:

	/*!
	 * Initializes a new instance of this class.
	 */
	ShodanScanner() = default;

	/*!
	 * Initializes a new instance of this class.
	 *
	 * \param key API key to use for the requests.
	 */
	explicit ShodanScanner(const std::string& key);

	/*!
	 * Sets the specified API key.
	 *
	 * \param key API key to set.
	 */
	void SetKey(const std::string& key);

	/*!
	 * Value indicating whether an API key was specified.
	 *
	 * \return true if key is present, otherwise false.
	 */
	bool HasKey();

	/*!
	 * Sets the specified API endpoint location.
	 *
	 * \param uri API location to set.
	 */
	void SetEndpoint(const std::string& uri);

	/*!
	 * Value indicating whether this instance is a passive scanner.
	 * 
	 * A passive scanner does not actively send packets towards the
	 * scanned target, it instead uses miscellaneous data sources to
	 * gather information regarding the target.
	 * 
	 * \return true if passive, false if not.
	 */
	bool IsPassive() override;

	/*!
	 * Scans a host to determine service availability.
	 * 
	 * \param host Host.
	 */
	void Scan(Host* host) override;

	/*!
	 * Scans a list of hosts to determine service availability.
	 * 
	 * \param hosts List of hosts.
	 */
	void Scan(Hosts* hosts) override;

	/*!
	 * Frees up the resources allocated during the lifetime of this instance.
	 */
	~ShodanScanner() override;

private:
	
	/*!
	 * API key to use for the requests.
	 */
	std::string key;

	/*!
	 * API endpoint location.
	 */
	std::string endpoint = "https://api.shodan.io/shodan";

	/*!
	 * Gets the information available on the API for the specified host.
	 *
	 * \param host Host.
	 */
	void getHostInfo(Host* host);

};
