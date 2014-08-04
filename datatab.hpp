#ifndef DATATAB_H
#define DATATAB_H

#include <QtWidgets>

class QComboBox;
class QLabel;
class QLineEdit;
class QTabWidget;
class QTextEdit;
class QPushButton;

class dataTab : public QWidget {
	Q_OBJECT

public:
	dataTab(QWidget* parent);
private:
	QLabel* countryLabel;
	QLineEdit* countryField;
	QLabel* stateLabel;
	QLineEdit* stateField;
	QLabel* localityLabel;
	QLineEdit* localityField;
	QLabel* organizationLabel;
	QLineEdit* organizationField;
	QLabel* organizationalUnitLabel;
	QLineEdit* organizationalUnitField;
	QLabel* commonNameLabel;
	QLineEdit* commonNameField;
	QLabel* keySizeLabel;
	QComboBox* keySizeSelector;
};

#endif /*DATATAB_H*/

