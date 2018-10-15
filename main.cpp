#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
#include "matrixcontroller.h"
#include "matrix.h"
#include<vector>
using std::vector;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog* p = new Dialog(7,7,7,7);

    matrixController t(p);

    return a.exec();

}
