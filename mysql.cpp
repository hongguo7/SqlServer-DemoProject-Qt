#include "mysql.h"
#include <QTime>

DB::DB(){
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString(
              "DRIVER={SQL SERVER};"
              "SERVER=%1;"
              "DATABASE=%2;"
              "UID=%3;"
              "PWD=%4").arg("DESKTOP-36K0A1S")
                       .arg("douban")
                       .arg("sa")
                       .arg("yp19951209"));
        db.open();
        qDebug()<<"Database init success";
}

void DB::SearchTest(){
    QSqlQuery query(db);
    query.exec("select * from type");
    while (query.next()) {
        qDebug()<<query.value(0).toString()<<" "<<query.value(1).toString();
    }
}

QSqlQuery DB::FuncSearchByOneID(QString Item,QString TableName)
{
    QSqlQuery query(db);
    QString SqlCom;
    SqlCom = "select * from "+TableName+" where user_id="+Item;
    qDebug()<<SqlCom;
    query.exec(SqlCom);
    query.next();
    qDebug()<<query.value(0).toString();
    return query;
}


int DB::FuncInsertUserInfo(QString *Item)
{
    QSqlQuery query(db);
    QString SqlCom;
    QString Temp;
    Temp = "\'"+Item[0]+"\',\'"+Item[1]+"\')";
    SqlCom = "insert into user_info (user_id,user_password) values ("+Temp;
    query.exec(SqlCom);
    db.commit();
    return 1;
}

QSqlQuery DB::FuncReturnSomeMovie()
{
    QSqlQuery query(db);
    QString SqlCom = "select movie_id,movie_posterlink from movie";
    query.exec(SqlCom);
//    QTime Time;
//    Time = QTime::currentTime();
//    qsrand(Time.msec()+Time.second()*1000);
//    QString StrArray[6];
//    QString SqlCom = "select movie_id,movie_posterlink from movie";
//    query.exec(SqlCom);
//    int Count = 0;
//    int I_I = 0;
//    while (query.next()) {
//        int RandNum = qrand()%5;
//        if((Count%5)==RandNum)
//        {
//            StrArray[I_I]=query.value(0).toString();
//            I_I++;
//            if(I_I==6)
//            {
//                break;
//            }
//        }
//        Count++;
//    }
    return query;
}

void DB::FuncInsertMovieInfo(QString SqlCom)
{
    qDebug()<<SqlCom;
    QSqlQuery query(db);
    query.exec(SqlCom);
    db.commit();
}


QSqlQuery DB::FuncReturnMovieByID(QString Params)
{
    QString SqlCom = "select * from movie where movie_id="+Params;
    QSqlQuery query(db);
    query.exec(SqlCom);
    query.next();
    return query;
}


void DB::FuncUpdateMovieInfo(QString StrArray[])
{/*
    StrArray[0] = TeTitle->toPlainText();
    StrArray[1] = TeDate->toPlainText();
    StrArray[2] = TeID->toPlainText();
    StrArray[3] = TeActor->toPlainText();
    StrArray[4] = TeType->toPlainText();
    StrArray[5] = TeScore->toPlainText();
    StrArray[6] = TeViewed->toPlainText();
    StrArray[7] = TeMoiveLink->toPlainText();*/
    QSqlQuery query(db);
    QString SqlCom;
    SqlCom = "delete from movie where movie_id=\'"+StrArray[2]+"\'";
    query.exec(SqlCom);
    db.commit();
    SqlCom = "";
    SqlCom = "insert into movie (movie_title,movie_release,movie_id,movie_actor,movie_type,movie_grade,movie_viewed,movie_posterlink) values (\'";
    SqlCom = SqlCom+StrArray[0]+"\',\'";
    SqlCom = SqlCom+StrArray[1]+"\',\'";
    SqlCom = SqlCom+StrArray[2]+"\',\'";
    SqlCom = SqlCom+StrArray[3]+"\',\'";
    SqlCom = SqlCom+StrArray[4]+"\',\'";
    SqlCom = SqlCom+StrArray[5]+"\',\'";
    SqlCom = SqlCom+StrArray[6]+"\',\'";
    SqlCom = SqlCom+StrArray[7]+"\')";
    query.exec(SqlCom);
    db.commit();

    qDebug()<<SqlCom;
}
