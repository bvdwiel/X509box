#include "abouttab.hpp"
#include "maindialog.hpp"

aboutTab::aboutTab(mainDialog* parent) {
    aboutText = new QLabel(tr("X509box is a free tool for sysadmins to generate SSL/TLS certificate requests. Find the project on GitHub: https://github.com/bvdwiel/X509box"));
    aboutText->setWordWrap(true);
    QVBoxLayout* aboutLayout = new QVBoxLayout;

    aboutLayout->addWidget(aboutText);
    setLayout(aboutLayout);
}
