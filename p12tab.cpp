#include "p12tab.hpp"

p12Tab::p12Tab(QWidget* parent) {
    QVBoxLayout* windowLayout;			// Layout for the whole tab
    QGroupBox* intermediateGroup;
    QVBoxLayout* intermediateStack;		// Controls for adding intermediate CA's
    QHBoxLayout* intermediateControlsLayout;	// Add/remove controls for intermediate CA's
    QPushButton* addIntermediateButton;
    QPushButton* removeIntermediateButton;
    QVBoxLayout* ownCertStack;
    QHBoxLayout* ownCertFileLayout;
    QHBoxLayout* ownKeyFileLayout;
    QLabel* ownCertLabel;
    QLineEdit* ownCertFileName;
    QPushButton* ownCertFileBrowseButton;
    QLabel* ownKeyLabel;
    QLineEdit* ownKeyFileName;
    QPushButton* ownKeyBrowseButton;
    QGroupBox* ownCertGroup;

    intermediateStack = new QVBoxLayout;
    windowLayout = new QVBoxLayout;
    intermediateControlsLayout = new QHBoxLayout;
    intermediateGroup = new QGroupBox(tr("Intermediate CA certificates"));
    addIntermediateButton = new QPushButton(tr("+"));
    removeIntermediateButton = new QPushButton(tr("-"));

    // Preload tab with room for 4 intermediate CA's, should be enough for most cases.
    for ( unsigned int i=0; i < 4; i++ ) {
	intermediateStack->insertLayout(i, addCertificate());
    }

    // Buttons to allow user to add/remove intermediate CA's
    intermediateControlsLayout->addWidget(addIntermediateButton);
    intermediateControlsLayout->addWidget(removeIntermediateButton);
    intermediateControlsLayout->addStretch();

    intermediateGroup->setLayout(intermediateStack);

    // Put together the grouping for the user's own certificate
    ownCertLabel = new QLabel(tr("Your certificate:"));
    ownCertFileName = new QLineEdit;
    ownCertFileBrowseButton = new QPushButton(tr("Browse..."));
    ownKeyFileLayout = new QHBoxLayout;
    ownCertFileLayout = new QHBoxLayout;
    ownKeyLabel = new QLabel(tr("Your private key:"));
    ownKeyFileName = new QLineEdit;
    ownKeyBrowseButton = new QPushButton(tr("Browse..."));
    ownCertStack = new QVBoxLayout;
    ownCertGroup = new QGroupBox(tr("Your own X509 certificate."));
    ownCertFileLayout->addWidget(ownCertLabel);
    ownCertFileLayout->addWidget(ownCertFileName);
    ownCertFileLayout->addWidget(ownCertFileBrowseButton);
    ownKeyFileLayout->addWidget(ownKeyLabel);
    ownKeyFileLayout->addWidget(ownKeyFileName);
    ownKeyFileLayout->addWidget(ownKeyBrowseButton);
    ownCertStack->addLayout(ownCertFileLayout);
    ownCertStack->addLayout(ownKeyFileLayout);
    ownCertGroup->setLayout(ownCertStack);

    // Compose the actual tab contents into a QVBoxLayout
    windowLayout->addWidget(intermediateGroup);
    windowLayout->addLayout(intermediateControlsLayout);
    windowLayout->addWidget(ownCertGroup);
    windowLayout->addStretch();

    setLayout(windowLayout);
}

QHBoxLayout* p12Tab::addCertificate() {
    QLabel* certFileLabel;
    QLineEdit* certFileName;
    QPushButton* certFileBrowseButton;
    QHBoxLayout* certFileLayout;

    certFileLabel = new QLabel(tr("Intermediate CA:"));
    certFileName = new QLineEdit;
    certFileBrowseButton = new QPushButton(tr("Browse..."));
    certFileLayout = new QHBoxLayout;

    certFileLayout->addWidget(certFileLabel);
    certFileLayout->addWidget(certFileName);
    certFileLayout->addWidget(certFileBrowseButton);
    return(certFileLayout);
}
