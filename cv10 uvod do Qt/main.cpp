#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	QLabel label("Hello Qt!");
	label.show();
	label.setWindowTitle("Hello Qt!");
	return a.exec();
}
