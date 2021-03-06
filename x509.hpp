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
	//std::string generatePrivateKey();
	std::string generatePrivateKey(unsigned int numBits, std::string passPhrase);
	void setPrivateKey(std::string rsaKey);
	bool validateRsaKey(std::string rsaKey);
	void debug();
protected:
	std::string pemCSR;
	std::string privateKey;
	bool privateKeyEncrypted;
	OID* objectID;
private:
	std::string passPhrase;
};

#endif /*CSR_H*/
