#include "x509.hpp"

std::string X509::generatePrivateKey() {
	/* Generate a sane default of 2048 bits if you don't care */
	return(this->generatePrivateKey(2048));
}

std::string X509::generatePrivateKey(unsigned int numBits) {
	gnutls_x509_privkey_t myPrivateKey;
	//std::string pemBuffer;
	unsigned char buffer[10 * 1024];
	size_t buffer_size = sizeof(buffer);

	if (numBits < 1024) {
		std::cerr << "WARNING: Using insecure key length." << std::endl;
	}

	gnutls_global_init();
	gnutls_x509_privkey_init(&myPrivateKey);
	gnutls_x509_privkey_generate(myPrivateKey, GNUTLS_PK_RSA, numBits, 0);
	gnutls_x509_privkey_export(myPrivateKey, GNUTLS_X509_FMT_PEM, buffer, &buffer_size);
	std::string pemBuffer((const char*) buffer);
	gnutls_x509_privkey_deinit(myPrivateKey);
	this->privateKey = pemBuffer;
	return pemBuffer;
}
