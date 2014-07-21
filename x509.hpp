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

class X509 {
public:
	std::string generateCSR();
	std::string generatePrivateKey();
	std::string generatePrivateKey(unsigned int numBits);
protected:
	std::string pemCSR;
	std::string privateKey;
};

#endif /*CSR_H*/
