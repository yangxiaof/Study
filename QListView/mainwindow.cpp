#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QStandardItemModel>
#include <QListView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList strList;

    for(int i = 0; i < 5; i++)
    {
        strList.append(QStringLiteral("项目_")  + QString::number(i));
    }
    QStringListModel *strListModel = new QStringListModel(this);
    strListModel->setStringList(strList);
    qDebug() << "strlist " << strList;


    QListView* list = new QListView(this);
    list->setModel(strListModel);
    list->setFixedSize(200,200);
    list->setEnabled(false);
    list->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

