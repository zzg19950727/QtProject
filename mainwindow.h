#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QIcon>
#include <QPoint>
#include <QColor>
#include <QMenu>
#include <QKeyEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QtWinExtras>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void contextMenuEvent(QContextMenuEvent* event);
    void init_ui();
    void Print();
    void clear();
    void read_history();
    void save_game();


private slots:
    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void save();

    void high();

    void change();

    void again();

private:
    Ui::MainWindow *ui;
    QPoint dragPosition;
    QIcon icon[12];
    bool over;
};

#endif // MAINWINDOW_H
