#include "x509.hpp"
#include <exception>
#include <QApplication>
#include "keydialog.hpp"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	keyDialog* dialog = new keyDialog;
	dialog->show();
	return app.exec();
}
