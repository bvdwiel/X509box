#include "p12tab.hpp"

p12Tab::p12Tab(QWidget* parent) {
    QVBoxLayout* windowLayout;
    QVBoxLayout* intermediateStack;
    intermediateStack = new QVBoxLayout;
    windowLayout = new QVBoxLayout;
    intermediateGroup = new QGroupBox(tr("Intermediate CA's"));

    for ( unsigned int i=0; i < 4; i++ ) {
	intermediateStack->insertLayout(i, addCertificate());
    }

    QHBoxLayout* intermediateControlsLayout;
    QPushButton* addIntermediateButton;
    QPushButton* removeIntermediateButton;

    intermediateControlsLayout = new QHBoxLayout;
    addIntermediateButton = new QPushButton(tr("+"));
    removeIntermediateButton = new QPushButton(tr("-"));
    intermediateControlsLayout->addWidget(addIntermediateButton);
    intermediateControlsLayout->addWidget(removeIntermediateButton);
    intermediateControlsLayout->addStretch();

    intermediateGroup->setLayout(intermediateStack);

    windowLayout->addWidget(intermediateGroup);
    windowLayout->addLayout(intermediateControlsLayout);
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
