#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("AtMoive");
    this->setFixedSize(this->width(),this->height());
    BtLogin = new QPushButton(this);
    BtLogin->setText("登陆");
    LbName = new QLabel(this);
    LbName->setText("账号：");
    LbPswd = new QLabel(this);
    LbPswd->setText("密码：");
    LeName = new QLineEdit(this);
    LePswd = new QLineEdit(this);
    LePswd->setEchoMode(QLineEdit::Password);
    BtRegister = new QPushButton(this);
    BtRegister->setText("注册");
    LbErr = new QLabel(this);

    int LeftPos = 120;
    int Space = 30;
    int Widght = 140;
    int Hight = 25;

    LbName->setGeometry(QRect(LeftPos,100,50,Hight));
    LbPswd->setGeometry(QRect(LeftPos,100+Space,50,Hight));
    LeName->setGeometry(QRect(LeftPos+10+Space,100,Widght,Hight));
    LePswd->setGeometry(QRect(LeftPos+10+Space,100+Space,Widght,Hight));
    BtLogin->setGeometry(QRect(LeftPos,170+Space,80,Hight));
    BtRegister->setGeometry(QRect(LeftPos+105,170+Space,80,Hight));
    LbErr->setGeometry(QRect(LeftPos,200+Space,300,Hight));
}

login::~login()
{
    delete ui;
}
