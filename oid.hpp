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
	std::string getOrganizationName();
	std::string getOrganizationalUnitName();
	std::string getCommonName();
	std::string getPassPhrase();
	unsigned int getKeySize();
	void setCountryName(std::string countryName);
	void setStateOrProvinceName(std::string stateOrProvinceName);
	void setLocalityName(std::string localityName);
	void setOrganizationName(std::string organizationName);
	void setOrganizationalUnitName(std::string organizationalUnitName);
	void setCommonName(std::string commonName);
	void setPassPhrase(std::string passPhrase);
	void setKeySize(unsigned int keySize);
	void debug();
protected:
	std::string countryName;
	std::string stateOrProvinceName;
	std::string localityName;
	std::string organizationName;
	std::string organizationalUnitName;
	std::string commonName;
	std::string passPhrase;
	unsigned int keySize; // Not technically an OID value, not worth a separate class though.
};

#endif /*OID_H*/
