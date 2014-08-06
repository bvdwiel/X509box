#ifndef DATATAB_H
#define DATATAB_H

#include <exception>
#include <string>
#include <QtWidgets>
#include "x509.hpp"
#include "oid.hpp"

class QComboBox;
class QLabel;
class QLineEdit;
class QTabWidget;
class QTextEdit;
class QPushButton;

class mainDialog;

class dataTab : public QWidget {
	Q_OBJECT

public:
	dataTab(mainDialog* parent);
private slots:
	void setCountry();
	void setState();
	void setLocality();
	void setOrganization();
	void setOrganizationalUnit();
	void setCommonName();
private:
	QLabel* countryLabel;
	QLineEdit* countryField;
	QLabel* stateLabel;
	QLineEdit* stateField;
	QLabel* localityLabel;
	QLineEdit* localityField;
	QLabel* organizationLabel;
	QLineEdit* organizationField;
	QLabel* organizationalUnitLabel;
	QLineEdit* organizationalUnitField;
	QLabel* commonNameLabel;
	QLineEdit* commonNameField;
	QLabel* keySizeLabel;
	QComboBox* keySizeSelector;
	X509* myCrypto;
	OID* myOid;
};

#endif /*DATATAB_H*/

