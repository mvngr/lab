#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QPair>
#include <QVariant>
#include <QInputDialog>
#include <QString>


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
    db_.setHostName("127.0.0.1");
    db_.setDatabaseName("postgres");
    db_.setPassword("postgres");
    db_.setUserName("postgres");
    if(!db_.open())
    {
        qDebug() << db_.lastError().text();
    }
    else
    {
        updComboBox();
    }
}

void MainWindow::actionGroupChanged(QAction *action)
{
    scene_->setMode(static_cast<MyScene::SceneMode>(action->data().toInt()));
}

void MainWindow::saveData()
{
    QString name = QInputDialog::getText(this, tr("Сохранение"), tr("Введите название сохранения"));
    auto items = scene_->items();
    QSqlQuery q(db_);
    q.prepare("insert into draws(name, points) values (:name, :points)");
    q.bindValue(":name", name);

    QString serialized;
    for(const auto &item : qAsConst(items))
    {
        auto lineF = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        if(lineF)
        {
            auto line = lineF->line().toLine();
            serialized.push_back(QString::number(line.x1()) + "," + QString::number(line.y1()) + "," + QString::number(line.x2())  + "," + QString::number(line.y2()) + ";");
        }
    }
    q.bindValue(":points", serialized);
    q.exec();
    updComboBox();
}

void MainWindow::updComboBox()
{
    ui->comboBox->clear();
    QSqlQuery q(db_);
    q.prepare("select * from draws;");
    q.exec();


    while(q.next())
    {
        ui->comboBox->addItem(q.value("name").toString(), QVariant::fromValue(QPair<int, QString>(q.value("id").toInt(), q.value("points").toString())));
    }

    ui->comboBox->setCurrentIndex( -1);
    scene_->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    scene_->clear();
    QVariant data = ui->comboBox->itemData(index);
    QPair<int, QString> info = data.value<QPair<int, QString>>();

    QStringList lines = info.second.split(';');
    for(auto &line : lines)
    {
        if(!line.isEmpty())
        {
            auto points = line.split(',');
            scene_->addLine(points.at(0).toInt(), points.at(1).toInt(), points.at(2).toInt(), points.at(3).toInt());

        }
    }
}

