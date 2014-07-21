/**
 * X509box class for X.500 object identifier
 **/

#ifndef OID_H
#define OID_H

#include <iostream>
#include <string>

class OID {
public:
	OID();
	std::string getCountryName();
	std::string getStateOrProvinceName();
	std::string getLocalityName();
	std::string getStreetAddress();
	std::string getOrganizationName();
	std::string getOrganizationalUnitName();
	std::string getCommonName();
	void setCountryName(std::string countryName);
	void setStateOrProvinceName(std::string stateOrProvinceName);
	void setLocalityName(std::string localityName);
	void setStreetAddress(std::string streetAddress);
	void setOrganizationName(std::string organizationName);
	void setOrganizationalUnitName(std::string organizationalUnitName);
	void setCommonName(std::string commonName);
	void debug();
protected:
	std::string countryName;
	std::string stateOrProvinceName;
	std::string localityName;
	std::string streetAddress;
	std::string organizationName;
	std::string organizationalUnitName;
	std::string commonName;
};

#endif /*OID_H*/
