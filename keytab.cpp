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
	saveKeyButton->setEnabled(false);

    /* Arrange widgets into layouts */
    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(generateKeyButton);
    buttonsLayout->addWidget(saveKeyButton);

    QVBoxLayout* keyLayout = new QVBoxLayout;
	keyLayout->addWidget(keyLabel);
	keyLayout->addWidget(keyField);
    keyLayout->addLayout(buttonsLayout);
    setLayout(keyLayout);

    /* Signal/slot collections */
    connect(saveKeyButton, SIGNAL(clicked()), this, SLOT(saveFile()));
}

void keyTab::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
         tr("RSA private key"), "",
         tr("RSA private key (*.txt);;All files (*)"));
}
