#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class keyDialog;

class mainWindow : public QMainWindow {
	Q_OBJECT

public:
	mainWindow();

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void generatePrivateKey();
};

#endif /*MAINWINDOW_H*/
