#ifndef KEYTAB_H
#define KEYTAB_H

#include <exception>
#include <QtWidgets>
#include "oid.hpp"
#include "x509.hpp"

class mainDialog;

class keyTab : public QWidget {
	Q_OBJECT

public:
	keyTab(mainDialog* parent);
	~keyTab();
private slots:
	int getKeyWidgetWidth(QTextEdit* widget);
	void generateKey();
	void loadFile();
	void saveFile();
private:
	QLabel* keyLabel;
	QTextEdit* keyField;
	QLabel* passPhraseLabel;
	QTextEdit* passPhraseField;
	QPushButton* generateKeyButton;
	QPushButton* loadKeyButton;
	QPushButton* saveKeyButton;
	QString loadedKey;
	OID* myOid;
	X509* myCrypto;
};

#endif /*KEYTAB_H*/
