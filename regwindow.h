#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "mysql.h"

namespace Ui {
class regWindow;
}

class regWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void SigRegSuccess(QString *retMsg);

public:
    explicit regWindow(QWidget *parent = 0);
    ~regWindow();
    void FuncRegisterClicked()
    {
        QString Name = LeName->text();
        QString Pswd1 = LePswd->text();
        QString Pswd2 = LePswd2->text();
        qDebug()<<Name<<Pswd1<<Pswd2;
        QString Array[2];
        Array[0].append(Name);
        Array[1].append(Pswd1);
        if(Pswd1==Pswd2)
        {

//            qDebug()<<"Reg Success";
            db.FuncInsertUserInfo(Array);
            QString retParams[2];
            retParams[0]=Name;
            retParams[1]=Pswd1;
            SigRegSuccess(retParams);
            this->hide();
        }else{
//            qDebug()<<"Err Reg";
            LbErr->setText("密码前后输入不一致，请重新输入。");

        }
    }

    DB db;
    QPushButton *BtReg;
    QLabel *LbName;
    QLabel *LbPswd;
    QLabel *LbErr;
    QLabel *LbPswd2;
    QLineEdit *LeName;
    QLineEdit *LePswd;
    QLineEdit *LePswd2;
//    QLabel *LbErr;
private:
    Ui::regWindow *ui;
};

#endif // REGWINDOW_H
