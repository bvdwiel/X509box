#include "datatab.hpp"
#include "maindialog.hpp"

dataTab::dataTab(mainDialog* parent) {
	countryLabel = new QLabel(tr("Country:"));
	stateLabel = new QLabel(tr("State or province:"));
	localityLabel = new QLabel(tr("City or locality:"));
	organizationLabel = new QLabel(tr("Organization:"));
	organizationalUnitLabel = new QLabel(tr("Organizational unit:"));
	commonNameLabel = new QLabel(tr("Hostname or common name:"));
	keySizeLabel = new QLabel(tr("Key size in bits:"));
	countryField = new QLineEdit;
	stateField = new QLineEdit;
	localityField = new QLineEdit;
	organizationField = new QLineEdit;
	organizationalUnitField = new QLineEdit;
	commonNameField = new QLineEdit;
	keySizeSelector = new QComboBox;

	/* Configure controls */
	keySizeSelector->addItem("2048");
	keySizeSelector->addItem("3072");
	keySizeSelector->addItem("4096");
	keySizeSelector->addItem("8192");
	countryLabel->setBuddy(countryField);
	stateLabel->setBuddy(stateField);
	localityLabel->setBuddy(localityField);
	organizationLabel->setBuddy(organizationField);
	commonNameLabel->setBuddy(commonNameField);
	keySizeLabel->setBuddy(keySizeSelector);

	/* Group controls and labels into layouts */
	QHBoxLayout* countryLayout = new QHBoxLayout;
	countryLayout->addWidget(countryLabel);
	countryLayout->addWidget(countryField);

	QHBoxLayout* stateLayout = new QHBoxLayout;
	stateLayout->addWidget(stateLabel);
	stateLayout->addWidget(stateField);

	QHBoxLayout* localityLayout = new QHBoxLayout;
	localityLayout->addWidget(localityLabel);
	localityLayout->addWidget(localityField);

	QHBoxLayout* organizationLayout = new QHBoxLayout;
	organizationLayout->addWidget(organizationLabel);
	organizationLayout->addWidget(organizationField);

	QHBoxLayout* organizationalUnitLayout = new QHBoxLayout;
	organizationalUnitLayout->addWidget(organizationalUnitLabel);
	organizationalUnitLayout->addWidget(organizationalUnitField);

	QHBoxLayout* commonNameLayout = new QHBoxLayout;
	commonNameLayout->addWidget(commonNameLabel);
	commonNameLayout->addWidget(commonNameField);

	QHBoxLayout* keySizeLayout = new QHBoxLayout;
	keySizeLayout->addWidget(keySizeLabel);
	keySizeLayout->addWidget(keySizeSelector);

	QVBoxLayout* metaFieldsLayout = new QVBoxLayout;
	metaFieldsLayout->addLayout(countryLayout);
	metaFieldsLayout->addLayout(stateLayout);
	metaFieldsLayout->addLayout(localityLayout);
	metaFieldsLayout->addLayout(organizationLayout);
	metaFieldsLayout->addLayout(organizationalUnitLayout);
	metaFieldsLayout->addLayout(commonNameLayout);
	metaFieldsLayout->addLayout(keySizeLayout);
	metaFieldsLayout->addStretch();
	setLayout(metaFieldsLayout);

	/* Variables */
	myCrypto = parent->crypto;
	myOid = parent->oid;

	/* Signal/slot-connections */
	connect(countryField, SIGNAL(editingFinished()), this, SLOT(setCountry()));
	connect(stateField, SIGNAL(editingFinished()), this, SLOT(setState()));
	connect(localityField, SIGNAL(editingFinished()), this, SLOT(setLocality()));
	connect(organizationField, SIGNAL(editingFinished()), this, SLOT(setOrganization()));
	connect(organizationalUnitField, SIGNAL(editingFinished()), this, SLOT(setOrganizationalUnit()));
	connect(commonNameField, SIGNAL(editingFinished()), this, SLOT(setCommonName()));
}

void dataTab::setCountry() {
	std::string countryName;
	countryName = countryField->text().toStdString();
	myOid->setCountryName(countryName);
}

void dataTab::setState() {
	std::string stateName;
	stateName = stateField->text().toStdString();
	myOid->setStateOrProvinceName(stateName);
}

void dataTab::setLocality() {
	std::string localityString;
	localityString = localityField->text().toStdString();
	myOid->setLocalityName(localityString);
}

void dataTab::setOrganization() {
	std::string organizationName;
	organizationName = organizationField->text().toStdString();
	myOid->setOrganizationName(organizationName);
}

void dataTab::setOrganizationalUnit() {
	std::string organizationalUnitName;
	organizationalUnitName = organizationalUnitField->text().toStdString();
	myOid->setOrganizationalUnitName(organizationalUnitName);
}

void dataTab::setCommonName() {
	std::string commonName;
	commonName = commonNameField->text().toStdString();
	myOid->setCommonName(commonName);
}

