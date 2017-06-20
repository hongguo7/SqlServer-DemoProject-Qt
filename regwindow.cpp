#include "regwindow.h"
#include "ui_regwindow.h"

regWindow::regWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::regWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("AtMoive");
    this->setFixedSize(404,336);
    BtReg = new QPushButton(this);
    BtReg->setText("注册");
    LbName = new QLabel(this);
    LbName->setText("账号：");
    LbPswd = new QLabel(this);
    LbPswd->setText("密码：");
    LbPswd2 = new QLabel(this);
    LbPswd2->setText("密码：");
    LeName = new QLineEdit(this);
    LePswd = new QLineEdit(this);
    LePswd->setEchoMode(QLineEdit::Password);
    LePswd2 = new QLineEdit(this);
    LePswd2->setEchoMode(QLineEdit::Password);
    LbErr = new QLabel(this);

    int LeftPos = 120;
    int Space = 30;
    int Widght = 140;
    int Hight = 25;

    LbName->setGeometry(QRect(LeftPos,          100,50,Hight));
    LbPswd->setGeometry(QRect(LeftPos,          100+Space,50,Hight));
    LeName->setGeometry(QRect(LeftPos+10+Space, 100,Widght,Hight));
    LePswd->setGeometry(QRect(LeftPos+10+Space, 100+Space,Widght,Hight));
    LbPswd2->setGeometry(QRect(LeftPos,100+2*Space,Widght,Hight));
    LePswd2->setGeometry(QRect(LeftPos+10+Space,100+2*Space,Widght,Hight));
    BtReg->setGeometry(QRect(LeftPos+20+Space,170+2*Space,80,Hight));
    LbErr->setGeometry(QRect(LeftPos,200+2*Space,300,Hight));
}

regWindow::~regWindow()
{
    delete ui;
}
