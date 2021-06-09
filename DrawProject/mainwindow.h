#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <map>
#include <QAction>
#include <QSqlDatabase>

#include "myscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void actionGroupChanged(QAction *action);

    void saveData();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    void updComboBox();


    Ui::MainWindow *ui;
    MyScene *scene_ = nullptr;

    std::map<MyScene::SceneMode, QAction *> actions_ {
        { MyScene::Cursour, new QAction("Arrow", this) },
        { MyScene::Line, new QAction("Line", this) }
    };

    QSqlDatabase db_;
};
#endif // MAINWINDOW_H
