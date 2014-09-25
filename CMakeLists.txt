cmake_minimum_required (VERSION 2.6)
project (X509box)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(X509box main.cpp x509.cpp oid.cpp maindialog.cpp csrtab.cpp datatab.cpp keytab.cpp pkcs12.cpp p12tab.cpp abouttab.cpp)

find_package (GnuTLS REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets} ${GNUTLS_INCLUDE_DIR})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
target_link_libraries(X509box ${Qt5Widgets_LIBRARIES} ${GNUTLS_LIBRARIES})

