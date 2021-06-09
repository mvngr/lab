#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene_ = new MyScene(this);
    ui->graphicsView->setScene(scene_);
    //убираем прокрутку при рисовании
    ui->graphicsView->setFocusPolicy( Qt::NoFocus );
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_->setSceneRect(ui->graphicsView->sceneRect());

    //делаем только одну кнопку выделяемой
    QActionGroup *actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(true);

    //задаем нужные параметры и добавляем в ui
    for(const auto &action : actions_)
    {
        action.second->setCheckable(true);
        action.second->setData(action.first);
        actionGroup->addAction(action.second);
        ui->toolBar->addAction(action.second);
    }
    QAction *saveAction = new QAction(tr("Сохранить"), this);
    ui->toolBar->addAction(saveAction);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveData);

    //если в контейнере есть элементы делаем первый выделенным
    if(actions_.begin() != actions_.end())
        (*actions_.begin()).second->setChecked(true);

    //коннектим изменение экшна на нужный
    connect(actionGroup, &QActionGroup::triggered, this, &MainWindow::actionGroupChanged);

    db_ = QSqlDatabase::addDatabase("QPSQL");
    db_.setHostName("localhost");
    db_.setDatabaseName("conf");
    db_.setPassword("cdt321");
    db_.setUserName("postgres");
    if(db_.open())
    {
        qDebug() <<"opened" ;
        db_.close();

    }
    else
    {
        qDebug() << db_.lastError().text();
    }

}

void MainWindow::actionGroupChanged(QAction *action)
{
    scene_->setMode(static_cast<MyScene::SceneMode>(action->data().toInt()));
}

void MainWindow::saveData()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

