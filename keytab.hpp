#ifndef KEYTAB_H
#define KEYTAB_H

#include <QtWidgets>

class keyTab : public QWidget {
	Q_OBJECT

public:
	keyTab(QWidget* parent);
private:
    QLabel* keyLabel;
    QTextEdit* keyField;
    QPushButton* generateKeyButton;
    QPushButton* saveKeyButton;
};

#endif /*KEYTAB_H*/
