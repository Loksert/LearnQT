#include <QtWidgets>


int main (int argc, char** argv)
{
    QApplication app(argc, argv);


    const int n = 3;
    QTabWidget tab;
    QTreeWidget twg;
    QStringList llst;
    QStringList lst;
    QTableWidget tbl(n,n);

    lst<<"First"<<"Second"<<"Third";
    tbl.setHorizontalHeaderLabels(lst);
    tbl.setVerticalHeaderLabels(lst);
    tab.addTab(&tbl,"Table");

    QSplitter spl(Qt::Horizontal);
    QFileSystemModel model;

    model.setRootPath(QDir::rootPath());
    QTreeView* pTreeView = new QTreeView;
    pTreeView->setModel(&model);
    QTableView* pTableView = new QTableView;
    pTableView->setModel(&model);

    QObject::connect(pTreeView,SIGNAL(clicked(const QModelIndex&)),pTableView,SLOT(setRootIndex(const QModelIndex&)));
    QObject::connect(pTableView,SIGNAL(activated(const QModelIndex&)),pTreeView,SLOT(setCurrentIndex(const QModelIndex&)));
    QObject::connect(pTableView,SIGNAL(activated(const QModelIndex&)),pTreeView,SLOT(setRootIndex(const QModelIndex&)));
    spl.addWidget(pTreeView);
    spl.addWidget(pTableView);

    tab.addTab(&spl,"Folders");

    tab.show();
    return app.exec();
}
