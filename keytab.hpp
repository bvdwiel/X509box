#ifndef KEYTAB_H
#define KEYTAB_H

#include <exception>
#include <QtWidgets>
#include "x509.hpp"

class mainDialog;

class keyTab : public QWidget {
	Q_OBJECT

public:
	keyTab(mainDialog* parent);
private slots:
    void generateKey();
    void saveFile();
private:
    QLabel* keyLabel;
    QTextEdit* keyField;
    QPushButton* generateKeyButton;
    QPushButton* saveKeyButton;
    X509* myCrypto;
};

#endif /*KEYTAB_H*/
