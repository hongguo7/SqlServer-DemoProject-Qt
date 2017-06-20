#ifndef MOVIEPANEL_H
#define MOVIEPANEL_H

#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork>
#include <QPushButton>
#include <QPixmap>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>
#include <QComboBox>
#include "mysql.h"
#include <QTime>
#include "commentpanel.h"

namespace Ui {
class moviepanel;
}

class moviepanel : public QMainWindow
{
    Q_OBJECT
public:
    explicit moviepanel(QWidget *parent = 0);
    ~moviepanel();
    void FuncTest()
    {
        qDebug()<<"Test";
    }

    void ShowImage(void){
        QNetworkRequest req;
        QNetworkAccessManager mynet;
        QEventLoop loop;
        QUrl urlArray[6];
        FuncGetSomeMovie();
        for(int i=0;i<6;i++)
        {
            urlArray[i]=LinkArray[i].replace("https","http");
        }
        //QUrl url("http://img1.doubanio.com/view/movie_poster_cover/mpst/public/p2163632289.jpg");
        for(int i=0;i<6;i++)
        {
            QNetworkReply *reply = mynet.get(QNetworkRequest(urlArray[i]));
            QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
            loop.exec();
            QByteArray jpegData = reply->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(jpegData);
            LbArray[i]->setPixmap(pixmap);
        }
    }



    void FuncGetSomeMovie()
    {
        QSqlQuery query;
        query = db.FuncReturnSomeMovie();
        QTime Time;
        Time = QTime::currentTime();
        qsrand(Time.msec()+Time.second()*1000);
        QString SqlCom = "select movie_title,movie_id,movie_posterlink from movie";
        query.exec(SqlCom);
        int BaseNum = qrand()%100;
        int Count = 0;
        int I_I = 0;
        while (query.next()) {
            int RandNum = qrand()%5;
            if((Count%5)==RandNum)
            {
               TitleArray[I_I]=query.value(0).toString();
               IDArray[I_I]=query.value(1).toString();
               LinkArray[I_I]=query.value(2).toString();
               I_I++;
               if(I_I==6)
               {
                  break;
               }
            }
            Count++;
        }
        for(int i=0;i<6;i++)
        {
            qDebug()<<TitleArray[i];
        }
    }

    void FuncClicked0()
    {
        SigBtClicked(IDArray[0]);
        qDebug()<<"ZZZ"<<IDArray[0];
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDArray[0]);
        comm->FuncGetMovieInfo(IDArray[0]);
    }

    void FuncClicked1()
    {
        SigBtClicked(IDArray[1]);
        qDebug()<<"ZZZ"<<IDArray[1];
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDArray[1]);
        comm->FuncGetMovieInfo(IDArray[1]);
    }

    void FuncClicked2()
    {
        SigBtClicked(IDArray[2]);
        qDebug()<<"ZZZ"<<IDArray[2];
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDArray[2]);
        comm->FuncGetMovieInfo(IDArray[2]);
    }

    void FuncClicked3()
    {
        SigBtClicked(IDArray[3]);
        qDebug()<<"ZZZ"<<IDArray[3];
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDArray[3]);
        comm->FuncGetMovieInfo(IDArray[3]);
    }

    void FuncClicked4()
    {
        SigBtClicked(IDArray[4]);
        qDebug()<<"ZZZ"<<IDArray[4];
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDArray[4]);
        comm->FuncGetMovieInfo(IDArray[4]);
    }

    void FuncClicked5()
    {
        SigBtClicked(IDArray[5]);
        qDebug()<<"ZZZ"<<IDArray[5];
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDArray[5]);
        comm->FuncGetMovieInfo(IDArray[5]);
    }

//    QString movie_title = LeSearch->text();
//    QString SqlCom = "select * from movie where movie_title=\'"+movie_title+"\'";
//    qDebug()<<"SqlCom"<<SqlCom;
//    QSqlQuery query;
//    query = db.FuncBaseFullCom(SqlCom);
//    query.next();
//    qDebug()<<query.value(0).toString();
    void FuncSearchMovie()
    {
        QString movie_title = LeSearch->text();
        QString SqlCom = "select * from movie where movie_title=\'"+movie_title+"\'";
        qDebug()<<"SqlCom"<<SqlCom;/*
        query =
        query.next();
        IDID = query.value("movie_id").toString();*/
//        SigBtSearch();
//        IDID="10757577";
        IDID = db.FuncBaseFullCom(SqlCom);
        SigBtSearch();
    }

    void FuncNONONO()
    {
        comm = new commentpanel(this);
        comm->show();
        comm->FuncGetMovieComments(IDID);
        comm->FuncGetMovieInfo(IDID);
    }

    QLabel *LbArray[6];
    QPushButton *BtArray[6];
    QLineEdit *LeSearch;
    QPushButton *BtSearch;
    QListView *LvTypeSearch;
    QStandardItemModel *Model;
    QComboBox *CbTypeSearch;
    QPushButton *BtChange;
    DB db;
    QString LinkArray[6];
    QString TitleArray[6];
    QString IDArray[6];

signals:
    void SigSendText(const QString &RetMsg);
    void SigBtClicked(QString retMsg);
    void SigBtSearch(void);

private:
    Ui::moviepanel *ui;
    commentpanel *comm;
    QString IDID;
};

#endif // MOVIEPANEL_H
