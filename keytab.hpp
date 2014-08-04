#ifndef KEYTAB_H
#define KEYTAB_H

#include <QtWidgets>
#include "x509.hpp"

class keyTab : public QWidget {
	Q_OBJECT

public:
	keyTab(QWidget* parent);
private slots:
    void generateKey();
    void saveFile();
private:
    QLabel* keyLabel;
    QTextEdit* keyField;
    QPushButton* generateKeyButton;
    QPushButton* saveKeyButton;
};

#endif /*KEYTAB_H*/
