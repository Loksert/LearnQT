#include <QtWidgets>
#include "syntaxl.h"


int main (int argc, char** argv)
{
    QApplication app(argc, argv);


    const int n = 3;
    QTabWidget tab;
    QTreeWidget twg;
    QStringList llst;
    QStringList lst;
    QTableWidget tbl(n,n);
    QTableWidgetItem* ptwi = nullptr;

    lst<<"First"<<"Second"<<"Third";
    tbl.setHorizontalHeaderLabels(lst);
    tbl.setVerticalHeaderLabels(lst);

    tab.addTab(&tbl,"Table");
    tab.addTab(new QLabel("Linux",&tab),"Linux");

    tbl.resize(370,135);
    tab.resize(370,135);
    tab.show();



    return app.exec();
}
