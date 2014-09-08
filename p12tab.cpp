#include "p12tab.hpp"

p12Tab::p12Tab(QWidget* parent) {
    rootFileLabel = new QLabel(tr("Root CA certificate:"));
    rootFileName = new QLineEdit;
    rootFileBrowseButton = new QPushButton(tr("Browse..."));
    rootFileLayout = new QHBoxLayout;

    rootFileLayout->addWidget(rootFileLabel);
    rootFileLayout->addWidget(rootFileName);
    rootFileLayout->addWidget(rootFileBrowseButton);
    setLayout(rootFileLayout);
}
