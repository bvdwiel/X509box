#include "privkey.hpp"

privkey::privkey() {
  this->generate(2048);
}

privkey::privkey(int keySize) {
  this->generate(keySize);
}

void privkey::generate(int keySize) {
  if ( keySize < 1024 ) {
    throw("FATAL ERROR: Using insecure keylength smaller than 1024 bits.");
  }
  if ( gnutls_x509_privkey_init(&this->keyData) != 0 ) {
    throw("FATAL ERROR: Failed to initialize the private key object.");
  }
  if ( gnutls_x509_privkey_generate(this->keyData, GNUTLS_PK_RSA, keySize, 0) != 0 ) {
    throw("FATAL ERROR: Failed to generate the private key.");
  }
  this->pemKey.clear();
}

std::string privkey::getPem() {
  // Handle case where passphrase is empty
  if ( this->passPhrase.empty()) {
    unsigned char buffer[10 * 1024];
    size_t buffer_size = sizeof(buffer);
    if ( gnutls_x509_privkey_export(this->keyData, GNUTLS_X509_FMT_PEM, buffer, &buffer_size) != 0 ) {
      throw ( "FATAL ERROR: Failed to export the private key to PEM format." );
    }
    std::string pemTemp(reinterpret_cast<char*>(buffer));
    this->pemKey = pemTemp;
    pemTemp.clear();
    return ( this->pemKey );
  } else

  // Handle case where passphrase is set
  {
    gnutls_datum_t pem;
    if ( gnutls_x509_privkey_export2_pkcs8(this->keyData, GNUTLS_X509_FMT_PEM, this->passPhrase.c_str(), GNUTLS_PKCS_PBES2_AES_128,&pem) != 0) {
      throw ( "FATAL ERROR: Failed to export the protected private key to PEM format." );
    }
    std::string pemTemp(reinterpret_cast<char*>(pem.data));
    this->pemKey = pemTemp;
    pemTemp.clear();
  }
}
