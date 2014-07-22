#include "oid.hpp"

OID::OID() {
	/* Some stupid defaults for development purposes */
	this->setCountryName("ARDA");
	this->setStateOrProvinceName("Middle-Earth");
	this->setLocalityName("The Shire");
	this->setOrganizationName("Bilbo's place");
	this->setOrganizationalUnitName("Catering");
	this->setCommonName("eleventyone.party.com");
}

void OID::debug() {
	std::cerr << "CountryName: " << this->getCountryName() << std::endl;
	std::cerr << "StateOrProvinceName: " << this->getStateOrProvinceName() << std::endl;
	std::cerr << "LocalityName: " << this->getLocalityName() << std::endl;
	std::cerr << "OrganizationName: " << this->getOrganizationName() << std::endl;
	std::cerr << "OrganizationalUnitName: " << this->getOrganizationalUnitName() << std::endl;
	std::cerr << "CommonName: " << this->getCommonName() << std::endl;
}

/* Getters */
std::string OID::getCountryName() {
	return ( this->countryName );
}

std::string OID::getStateOrProvinceName() {
	return ( this->stateOrProvinceName );
}

std::string OID::getLocalityName() {
	return ( this->localityName );
}

std::string OID::getOrganizationName() {
	return ( this->organizationName );
}

std::string OID::getOrganizationalUnitName() {
	return ( this->organizationalUnitName );
}

std::string OID::getCommonName() {
	return ( this->commonName );
}

/* Setters */
void OID::setCountryName(std::string countryName) {
	/* No validation for now */
	this->countryName = countryName;
}

void OID::setStateOrProvinceName(std::string stateOrProvinceName) {
	this->stateOrProvinceName = stateOrProvinceName;
}

void OID::setLocalityName(std::string localityName) {
	this->localityName = localityName;
}

void OID::setOrganizationName(std::string organizationName) {
	this->organizationName = organizationName;
}

void OID::setOrganizationalUnitName(std::string organizationalUnitName) {
	this->organizationalUnitName = organizationalUnitName;
}

void OID::setCommonName(std::string commonName) {
	this->commonName = commonName;
}
