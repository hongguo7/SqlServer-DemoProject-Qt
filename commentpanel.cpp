#include "commentpanel.h"
#include "ui_commentpanel.h"



commentpanel::commentpanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::commentpanel)
{
    ui->setupUi(this);
    this->setFixedSize(700,700);
    BtNextPage = new QPushButton(this);
    BtNextPage->setGeometry(320,670,50,25);
    BtNextPage->setText("Next");
    LbPic = new QLabel(this);
    LbPic->setGeometry(QRect(100,50,200,200));
    LbTitle = new QLabel(this);
    LbTitle->setGeometry(QRect(350,50,100,25));
    LbTitle->setText("TEST");
    LbDate = new QLabel(this);
    LbDate->setGeometry(QRect(350,80,100,25));
    LbDate->setText("TEST");
    LbType = new QLabel(this);
    LbType->setGeometry(QRect(350,110,100,25));
    LbType->setText("Test");
    LbActor = new QLabel(this);
    LbActor->setGeometry(QRect(350,140,100,25));
    LbActor->setText("TEST");
    LbScore = new QLabel(this);
    LbScore->setGeometry(QRect(350,170,100,25));
    LbScore->setText("TEST");
    TeComments = new QTextEdit(this);
    TeComments->setGeometry(50,270,600,400);
}

commentpanel::~commentpanel()
{
    delete ui;
}
