#include "datatab.hpp"

dataTab::dataTab(QWidget* parent) {
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
}
