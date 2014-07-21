cmake_minimum_required (VERSION 2.6)
project (X509box)

add_executable(X509box main.cpp x509.cpp oid.cpp)

find_package (GnuTLS)
include_directories(${GNUTLS_INCLUDE_DIR})
target_link_libraries(X509box ${GNUTLS_LIBRARIES})

