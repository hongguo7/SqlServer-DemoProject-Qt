#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QTextCodec>
#include <QSqlQuery>
#include <QDebug>

class DB : public QObject
{
private:

public:
    QSqlDatabase db;
    DB();
    void SearchTest();
    QSqlQuery FuncSearchByOneID(QString,QString);
    int FuncInsertUserInfo(QString *);
    QSqlQuery FuncReturnSomeMovie(void);
    void FuncInsertMovieInfo(QString);
    QSqlQuery FuncReturnMovieByID(QString);
    void FuncUpdateMovieInfo(QString *);
    QSqlQuery FuncReturnComments(QString SqlCom)
    {
        QSqlQuery query(db);
        query.exec(SqlCom);
        return query;
    }
    QString FuncBaseFullCom(QString SqlCom)
    {
        QSqlQuery query(db);
        query.exec(SqlCom);
        query.next();
        return query.value("movie_id").toString();
    }
};


#endif // MYSQL_H
