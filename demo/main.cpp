#include "quicreator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 9));
    a.setWindowIcon(QIcon(":/main.ico"));

    QUICreator w;
    w.setWindowTitle("Cmini");
    w.show();

    return a.exec();
}
