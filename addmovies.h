#ifndef ADDMOVIES_H
#define ADDMOVIES_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QSqlQuery>
#include "mysql.h"

namespace Ui {
class addmovies;
}

class addmovies : public QMainWindow
{
    Q_OBJECT

public:
    explicit addmovies(QWidget *parent = 0);
    ~addmovies();

    void FuncCommitMovie(void)
    {
        QString Title = TeTitle->toPlainText();
        QString Date = TeDate->toPlainText();
        QString ID = TeID->toPlainText();
        QString Actor = TeActor->toPlainText();
        QString Type = TeType->toPlainText();
        QString Score = TeScore->toPlainText();
        QString Viewed = TeViewed->toPlainText();
        QString Link = TeMoiveLink->toPlainText();

        qDebug()<<Title<<Date<<ID<<Actor<<Type<<Score<<Viewed<<Link;
        QString SqlCom = "insert into movie (movie_title,movie_release,movie_id,movie_actor,movie_type,movie_grade,movie_viewed,movie_posterlink) values ";
        QString Temp = "(\'"+Title+"\',\'"+Date+"\',\'"+ID+"\',\'"+Actor+"\',\'"+Type+"\',"+Score+","+Viewed+",\'"+Link+"\')";
        db.FuncInsertMovieInfo(SqlCom+Temp);
    }

    QTextEdit *TeTitle;
    QTextEdit *TeDate;
    QTextEdit *TeID;
    QTextEdit *TeActor;
    QTextEdit *TeType;
    QTextEdit *TeScore;
    QTextEdit *TeViewed;
    QTextEdit *TeMoiveLink;

    QLabel *LbTitle;
    QLabel *LbDate;
    QLabel *LbID;
    QLabel *LbActor;
    QLabel *LbType;
    QLabel *LbScore;
    QLabel *LbViewed;
    QLabel *LbMovieLink;

    QPushButton *BtCommit;

private:
    Ui::addmovies *ui;
    DB db;
};

#endif // ADDMOVIES_H
