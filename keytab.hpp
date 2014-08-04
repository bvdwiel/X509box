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
};

#endif /*KEYTAB_H*/
