#ifndef LOGIN_H
#define LOGIN_H

#include "mysql.h"
#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
signals:
    void SigLoginSuccess();
public:
    explicit login(QWidget *parent = 0);
    ~login();

    void FuncLoginClicked()
    {
        QString Name;
        QString Pswd;
        Name = LeName->text();
        Name = "'"+Name+"'";
        Pswd = LePswd->text();
        QSqlQuery query;
        query = db.FuncSearchByOneID(Name,"user_info");
        if(query.value(3).toString()==Pswd)
        {
            qDebug()<<"Login Success";
            this->hide();
            SigLoginSuccess();
        }else
        {
//            qDebug()<<"Login Failed";
            LbErr->setText("用户名错误或者账号错误！请重新输入。");
        }
    }

    void FuncCloseWindow()
    {
        this->hide();
    }

    void FuncOpenWindow(QString *Params)
    {
        this->show();
        LeName->setText(Params[0]);
        LePswd->setText(Params[1]);
    }

    DB db;
    QPushButton *BtLogin;
    QLabel *LbName;
    QLabel *LbPswd;
    QLabel *LbErr;
    QLineEdit *LeName;
    QLineEdit *LePswd;
    QPushButton*BtRegister;
private:
    Ui::login *ui;
};

#endif // LOGIN_H
