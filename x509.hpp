/**
 * Certificate signing request
 **/

#ifndef X509_H
#define X509_H

#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#include <gnutls/abstract.h>
#include <iostream>
#include <string>
#include "oid.hpp"

class X509 {
public:
	X509();
	~X509();
	std::string generateCSR();
	std::string generateCSR(OID* oid);
	std::string generatePrivateKey();
	std::string generatePrivateKey(unsigned int numBits);
protected:
	std::string pemCSR;
	std::string privateKey;
	OID* objectID;
};

#endif /*CSR_H*/
