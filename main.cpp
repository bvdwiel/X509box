#include "x509.hpp"
#include <exception>
#include <QApplication>
#include "maindialog.hpp"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	mainDialog* dialog = new mainDialog;
	dialog->show();
	return app.exec();
}
