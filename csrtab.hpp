#ifndef CSRTAB_H
#define CSRTAB_H

#include <QtWidgets>
#include <QFileDialog>

class csrTab : public QWidget {
	Q_OBJECT
public:
	csrTab(QWidget* parent);
private slots:
    void saveFile();
private:
	QLabel* csrLabel;
	QTextEdit* csrField;
	QPushButton* generateCsrButton;
	QPushButton* saveCsrButton;
};

#endif /*CSRTAB*/
