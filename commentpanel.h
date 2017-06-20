#ifndef COMMENTPANEL_H
#define COMMENTPANEL_H

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
#include <QTextEdit>
#include "mysql.h"
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class commentpanel;
}

class commentpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit commentpanel(QWidget *parent = 0);
    ~commentpanel();
    void ShowImage(void){
        QNetworkRequest req;
        QNetworkAccessManager mynet;
        QEventLoop loop;
        QUrl url("http://img1.doubanio.com/view/movie_poster_cover/mpst/public/p2163632289.jpg");
        QNetworkReply *reply = mynet.get(QNetworkRequest(url));
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        QByteArray jpegData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        LbPic->setPixmap(pixmap);
//        FuncGetMovieInfo();
//        FuncGetMovieComments();
    }

    void FuncGetMovieInfo(QString Params)
    {/*
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
        LbScore->setText("TEST");*/
        QString movie_id = Params;
        QSqlQuery query;
        query = db.FuncReturnMovieByID(movie_id);
        qDebug()<<query.value(0).toString()<<query.value(1).toString()<<query.value(2).toString();
        LbTitle->clear();
        LbTitle->setText(query.value("movie_title").toString());
        LbDate->clear();
        LbDate->setText(query.value("movie_release").toString());
        LbActor->clear();
        LbActor->setText(query.value("movie_actor").toString());
        LbType->clear();
        LbType->setText(query.value("movie_type").toString());
        LbScore->clear();
        LbScore->setText(query.value("movie_grade").toString());
//        Viewed->clear();
//        Viewed->setText(query.value("movie_viewed").toString());
        QNetworkRequest req;
        QNetworkAccessManager mynet;
        QEventLoop loop;
        QUrl url(query.value("movie_posterlink").toString().replace("https","http"));
        qDebug()<<query.value("movie_posterlink").toString().replace("https","http");
        QNetworkReply *reply = mynet.get(QNetworkRequest(url));
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();
        QByteArray jpegData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        LbPic->setPixmap(pixmap);
    }


    void FuncGetMovieComments(QString Params)
    {
        QString SqlCom = "select * from comments where movie_id=\'"+Params+"\'";
        QSqlQuery query = db.FuncReturnComments(SqlCom);
//        query.next();
//        TeComments->append("ZXXXXXXXXXXXX");
//        query.next();
//        TeComments->append("AAAAAAAAAAAAAAAAAAA");
//        query.next();
//        TeComments->append("ASDASDASDASD");
        while(query.next())
        {
            TeComments->append(query.value(2).toString()+query.value(3).toString());
        }
    }

private:
    Ui::commentpanel *ui;
    QLabel *LbPic;
    QLabel *LbTitle;
    QLabel *LbDate;
    QLabel *LbActor;
    QLabel *LbType;
    QLabel *LbScore;
    QLabel *Viewed;
    QPushButton *BtNextPage;
    QPushButton *BtEdit;
    QTextEdit *TeComments;
    DB db;
};

#endif // COMMENTPANEL_H
