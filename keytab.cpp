#include "keytab.hpp"

keyTab::keyTab(QWidget* parent) {
    keyField = new QTextEdit();
    keyLabel = new QLabel(tr("Your private key:"));
    generateKeyButton = new QPushButton(tr("Generate key"));
    saveKeyButton = new QPushButton(tr("Save key"));

    /* Configure controls */
	keyField->setFontFamily("Courier");
	keyField->setMinimumWidth(500);
	keyField->setMinimumHeight(450);
	keyField->setReadOnly(true);

    /* Arrange widgets into layouts */
    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(generateKeyButton);
    buttonsLayout->addWidget(saveKeyButton);

    QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(keyLabel);
	keyLayout->addWidget(keyField);
    keyLayout->addLayout(buttonsLayout);
    setLayout(keyLayout);
}
