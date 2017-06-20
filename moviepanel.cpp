#include "moviepanel.h"
#include "ui_moviepanel.h"

moviepanel::moviepanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::moviepanel)
{
    ui->setupUi(this);
    this->setFixedSize(800,800);
    LeSearch = new QLineEdit(this);
    LeSearch->setGeometry(QRect(100,50,390,25));
    BtSearch = new QPushButton(this);
    BtSearch->setGeometry(QRect(554,49,80,27));
    BtSearch->setText("搜索");
    Model = new QStandardItemModel(this);
    CbTypeSearch = new QComboBox(this);
    CbTypeSearch->setGeometry(QRect(492,50,60,25));
    BtChange = new QPushButton(this);
    BtChange->setGeometry(QRect(329,700,50,25));
    BtChange->setText("Kika");
    QStringList List;
    List.append("电影");
    List.append("演员");
    List.append("时间");
    for(int i=0;i<3;i++)
    {
        QString string = List.at(i);
        QStandardItem *item = new QStandardItem(string);
        Model->appendRow(item);
    }
    CbTypeSearch->setModel(Model);
    for(int i=0;i<6;i++)
    {
        LbArray[i]=new QLabel(this);
        BtArray[i] = new QPushButton(this);
    }
    int X = 50;
    int L = 200;
    for(int i=0;i<6;i++)
    {
        if(i<3){
            LbArray[i]->setGeometry(QRect(X*(1+i)+i*L,100+X,L,L));
            int X_X = (X*(1+i)+i*L)/2;
            BtArray[i]->setGeometry(QRect(X_X+i*180,300+X,50,25));
            BtArray[i]->setText("Click");
        }
        if(i>=3)
        {
            LbArray[i]->setGeometry(QRect(X*(i-2)+(i-3)*L,150+2*X+L,L,L));
            int X_X = (X*(i-2)+(i-3)*L)/2;
            BtArray[i]->setGeometry(QRect(X_X+(i-3)*180,350+2*X+L,50,25));
            BtArray[i]->setText("Click");
        }
        qDebug()<<i;
    }
    ShowImage();
}

moviepanel::~moviepanel()
{
    delete ui;
}
