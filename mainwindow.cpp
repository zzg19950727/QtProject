#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "head.h"
#define LEN 60

extern int game[4][4];
extern int xy[6];
extern int score,q, p;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_ui();
    difficult_game();
    read_history();
    Print();
    this->setFocus();
    over = false;
}

MainWindow::~MainWindow()
{
    //save_game();
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QPoint pos = event->globalPos() - dragPosition;
        if(frameGeometry().topLeft().y()+pos.y() < 0)
            pos.setY(0);
        move(pos);
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
    if (event->button() == Qt::LeftButton)
    {
         dragPosition = event->globalPos() - frameGeometry().topLeft();
         event->accept();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    srand( time(NULL) );
    q=0;
    int f, h, b, c, m, n, g=4;
    if( event->key() == Qt::Key_Left )
    {
        f=LEFT(game);
    }
    else if( event->key() == Qt::Key_Right )
    {
        f=RIGHT(game);
    }
    else if( event->key() == Qt::Key_Up )
    {
        f=UP(game);
    }
    else if( event->key() == Qt::Key_Down )
    {
        f=DOWN(game);
    }

    if(f==0&&q==0)
    {
        QMessageBox::warning(this, "", "Game Over");
        over = true;
        goto end;
    }

    score=0;h=0;
    for(n=0;n<4;n++)//判断游戏是否结束
    {
       for(m=0;m<4;m++)
       {
            if(game[n][m]==0)
          {
               h++;
          }
           score+=game[n][m];
       }
    }

    if(!(q&&!f))
    {
        if(h)
        {
        c=rand()%4;
        b=rand()%4;

        while(game[c][b]!=0)
        {
            c=rand()%4;
            b=rand()%4;
        }
        game[c][b]=2*p;
        p=bili(g,xy,game);
        Print();
        }
    }
    end:
    event->accept();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QAction *save = new QAction("保存", this);
    QAction *high = new QAction("最高分", this);
    QAction *change = new QAction("换背景", this);
    QAction *again = new QAction("重来", this);

    QMenu *menu = new QMenu(this);
    menu->addAction( save );
    connect(save, SIGNAL(triggered(bool)), this, SLOT(save()) );

    menu->addAction( high );
    connect(high, SIGNAL(triggered(bool)), this, SLOT(high()) );

    menu->addAction( change );
    connect(change, SIGNAL(triggered(bool)), this, SLOT(change()) );

    menu->addAction( again );
    connect(again, SIGNAL(triggered(bool)), this, SLOT(again()) );

    menu->move( this->cursor().pos() );

    QMenu *level = new QMenu("难度", this);
    menu->addMenu( level );
    level->addAction(new QAction("容易", this));
    level->addAction(new QAction("一般", this));
    level->addAction(new QAction("困难", this));
    menu->show();
}

void MainWindow::init_ui()
{
    ui->pushButton->setMinimumSize(LEN, LEN);
    ui->pushButton_2->setMinimumSize(LEN, LEN);
    ui->pushButton_3->setMinimumSize(LEN, LEN);
    ui->pushButton_4->setMinimumSize(LEN, LEN);
    ui->pushButton_5->setMinimumSize(LEN, LEN);
    ui->pushButton_6->setMinimumSize(LEN, LEN);
    ui->pushButton_7->setMinimumSize(LEN, LEN);
    ui->pushButton_8->setMinimumSize(LEN, LEN);
    ui->pushButton_9->setMinimumSize(LEN, LEN);
    ui->pushButton_10->setMinimumSize(LEN, LEN);
    ui->pushButton_11->setMinimumSize(LEN, LEN);
    ui->pushButton_12->setMinimumSize(LEN, LEN);
    ui->pushButton_13->setMinimumSize(LEN, LEN);
    ui->pushButton_14->setMinimumSize(LEN, LEN);
    ui->pushButton_15->setMinimumSize(LEN, LEN);
    ui->pushButton_16->setMinimumSize(LEN, LEN);

    ui->pushButton->setMaximumSize(LEN, LEN);
    ui->pushButton_2->setMaximumSize(LEN, LEN);
    ui->pushButton_3->setMaximumSize(LEN, LEN);
    ui->pushButton_4->setMaximumSize(LEN, LEN);
    ui->pushButton_5->setMaximumSize(LEN, LEN);
    ui->pushButton_6->setMaximumSize(LEN, LEN);
    ui->pushButton_7->setMaximumSize(LEN, LEN);
    ui->pushButton_8->setMaximumSize(LEN, LEN);
    ui->pushButton_9->setMaximumSize(LEN, LEN);
    ui->pushButton_10->setMaximumSize(LEN, LEN);
    ui->pushButton_11->setMaximumSize(LEN, LEN);
    ui->pushButton_12->setMaximumSize(LEN, LEN);
    ui->pushButton_13->setMaximumSize(LEN, LEN);
    ui->pushButton_14->setMaximumSize(LEN, LEN);
    ui->pushButton_15->setMaximumSize(LEN, LEN);
    ui->pushButton_16->setMaximumSize(LEN, LEN);

    ui->pushButton->setFlat(true);
    ui->pushButton_2->setFlat(true);
    ui->pushButton_3->setFlat(true);
    ui->pushButton_4->setFlat(true);
    ui->pushButton_5->setFlat(true);
    ui->pushButton_6->setFlat(true);
    ui->pushButton_7->setFlat(true);
    ui->pushButton_8->setFlat(true);
    ui->pushButton_9->setFlat(true);
    ui->pushButton_10->setFlat(true);
    ui->pushButton_11->setFlat(true);
    ui->pushButton_12->setFlat(true);
    ui->pushButton_13->setFlat(true);
    ui->pushButton_14->setFlat(true);
    ui->pushButton_15->setFlat(true);
    ui->pushButton_16->setFlat(true);

    clear();

    this->setMaximumSize(5*LEN, 5*LEN+10);
    this->setMinimumSize(5*LEN, 5*LEN+10);

    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":images/background.png")));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    QtWin::extendFrameIntoClientArea(this, -1, -1, -1, -1);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_NoSystemBackground, false);

    //ui->pushButton_20->setIcon(QIcon(":images\\refresh.ico"));
    ui->pushButton_20->setFlat(true);
    ui->pushButton_20->setIconSize(QSize(20, 20));
    ui->pushButton_20->setEnabled(false);

    ui->pushButton_19->setIcon(QIcon(":images\\my2048.png"));
    ui->pushButton_19->setFlat(true);
    ui->pushButton_19->setIconSize(QSize(30, 30));
    //ui->pushButton_19->setEnabled(false);

    ui->pushButton_18->setIcon(QIcon(":images\\line.ico"));
    ui->pushButton_18->setFlat(true);
    ui->pushButton_18->setIconSize(QSize(20, 20));

    ui->pushButton_17->setIcon(QIcon(":images\\Cancel.ico"));
    ui->pushButton_17->setFlat(true);
    ui->pushButton_17->setIconSize(QSize(20, 20));

    icon[0] = QIcon(":images\\0.png");
    icon[1] = QIcon(":images\\2.png");
    icon[2] = QIcon(":images\\4.png");
    icon[3] = QIcon(":images\\8.png");
    icon[4] = QIcon(":images\\16.png");
    icon[5] = QIcon(":images\\32.png");
    icon[6] = QIcon(":images\\64.png");
    icon[7] = QIcon(":images\\128.png");
    icon[8] = QIcon(":images\\256.png");
    icon[9] = QIcon(":images\\512.png");
    icon[10] = QIcon(":images\\1024.png");
    icon[11] = QIcon(":images\\2048.png");

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::black);
    ui->score->setPalette( pe );
    ui->label->setPalette( pe );

    /*addAction( new QAction("保存", this));
    addAction( new QAction("最高分", this));
    addAction( new QAction("换背景", this));
    addAction( new QAction("重来", this));
    setContextMenuPolicy(Qt::ActionsContextMenu);*/
}

void MainWindow::Print()
{
    ui->pushButton->setIcon(icon[num(game[0][0])]);
    ui->pushButton_2->setIcon(icon[num(game[0][1])]);
    ui->pushButton_3->setIcon(icon[num(game[0][2])]);
    ui->pushButton_4->setIcon(icon[num(game[0][3])]);
    ui->pushButton_5->setIcon(icon[num(game[1][0])]);
    ui->pushButton_6->setIcon(icon[num(game[1][1])]);
    ui->pushButton_7->setIcon(icon[num(game[1][2])]);
    ui->pushButton_8->setIcon(icon[num(game[1][3])]);
    ui->pushButton_9->setIcon(icon[num(game[2][0])]);
    ui->pushButton_10->setIcon(icon[num(game[2][1])]);
    ui->pushButton_11->setIcon(icon[num(game[2][2])]);
    ui->pushButton_12->setIcon(icon[num(game[2][3])]);
    ui->pushButton_13->setIcon(icon[num(game[3][0])]);
    ui->pushButton_14->setIcon(icon[num(game[3][1])]);
    ui->pushButton_15->setIcon(icon[num(game[3][2])]);
    ui->pushButton_16->setIcon(icon[num(game[3][3])]);

    QString text = QString::number(score);
    ui->score->setText( text );
    ui->label_3->setText( QString::number(p*2) );
}

void MainWindow::clear()
{
    QIcon icon1("");
    ui->pushButton->setIcon(icon1);
    ui->pushButton->setIconSize(QSize(LEN, LEN));

    ui->pushButton_2->setIcon(icon1);
    ui->pushButton_2->setIconSize(QSize(LEN, LEN));

    ui->pushButton_3->setIcon(icon1);
    ui->pushButton_3->setIconSize(QSize(LEN, LEN));

    ui->pushButton_4->setIcon(icon1);
    ui->pushButton_4->setIconSize(QSize(LEN, LEN));

    ui->pushButton_5->setIcon(icon1);
    ui->pushButton_5->setIconSize(QSize(LEN, LEN));

    ui->pushButton_6->setIcon(icon1);
    ui->pushButton_6->setIconSize(QSize(LEN, LEN));

    ui->pushButton_7->setIcon(icon1);
    ui->pushButton_7->setIconSize(QSize(LEN, LEN));

    ui->pushButton_8->setIcon(icon1);
    ui->pushButton_8->setIconSize(QSize(LEN, LEN));

    ui->pushButton_9->setIcon(icon1);
    ui->pushButton_9->setIconSize(QSize(LEN, LEN));

    ui->pushButton_10->setIcon(icon1);
    ui->pushButton_10->setIconSize(QSize(LEN, LEN));

    ui->pushButton_11->setIcon(icon1);
    ui->pushButton_11->setIconSize(QSize(LEN, LEN));

    ui->pushButton_12->setIcon(icon1);
    ui->pushButton_12->setIconSize(QSize(LEN, LEN));

    ui->pushButton_13->setIcon(icon1);
    ui->pushButton_13->setIconSize(QSize(LEN, LEN));

    ui->pushButton_14->setIcon(icon1);
    ui->pushButton_14->setIconSize(QSize(LEN, LEN));

    ui->pushButton_15->setIcon(icon1);
    ui->pushButton_15->setIconSize(QSize(LEN, LEN));

    ui->pushButton_16->setIcon(icon1);
    ui->pushButton_16->setIconSize(QSize(LEN, LEN));
}

void MainWindow::read_history()
{
    FILE*fp = fopen(":history.txt", "r");
    if( fp )
    {
        int state = 1;
        fscanf(fp, "%d", &state);
        if( !state )
        {
            fscanf(fp, "%d", &p);
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    fscanf(fp, "%d\n", &game[i][j]);
        }
    }
    fclose(fp);
}

void MainWindow::save_game()
{
    FILE* fp = fopen(":history.txt", "w");
    if( fp )
    {
        fprintf(fp, "%d\n", over);
        fprintf(fp, "%d\n", p);
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                fprintf(fp, "%d\n", game[i][j]);
    }
    fclose(fp);
}

void MainWindow::on_pushButton_18_clicked()
{
    this->showMinimized();
}

void MainWindow::on_pushButton_17_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_20_clicked()
{
    difficult_game();
    Print();
    this->setFocus();
    over = false;
}

void MainWindow::save()
{
    save_game();
}

void MainWindow::high()
{

}

void MainWindow::change()
{

}

void MainWindow::again()
{
    difficult_game();
    Print();
    this->setFocus();
    over = false;
}
