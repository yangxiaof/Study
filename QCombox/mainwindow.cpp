#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QListView>
#include <QListWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QComboBox *combox = new QComboBox(this);
    combox->setGeometry(50,50,50,30);
    QListWidget *listView = new QListWidget(this);
    combox->setModel(listView->model());
    combox->setView(listView);

    QStringList items;
    items.append("1");
    items.append("2");
    items.append("2");
    items.append("3");

//    combox->addItems(items);
    combox->insertItems(0,items);

    connect(combox, SIGNAL(currentIndexChanged(int)), this, SLOT(m_slot_indexChange(int)));

}

void MainWindow::m_slot_indexChange(int index)
{
    qDebug() << "index " << index;
}
MainWindow::~MainWindow()
{
    delete ui;
}

