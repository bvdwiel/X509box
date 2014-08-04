#include "keytab.hpp"

keyTab::keyTab(QWidget* parent) {
    keyField = new QTextEdit();
    keyLabel = new QLabel(tr("Your private key:"));

    /* Configure controls */
	keyField->setFontFamily("Courier");
	keyField->setMinimumWidth(500);
	keyField->setMinimumHeight(450);
	keyField->setReadOnly(true);

    /* Arrange widgets into layouts */
    QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(keyLabel);
	keyLayout->addWidget(keyField);
    //keyLayout->addWidget(generateCsrButton);
    setLayout(keyLayout);
}
