#ifndef EDITMOVIES_H
#define EDITMOVIES_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <mysql.h>

namespace Ui {
class editmovies;
}

class editmovies : public QMainWindow
{
    Q_OBJECT

public:
    explicit editmovies(QWidget *parent = 0);
    ~editmovies();
    void FuncEditInit()
    {

        QString SqlCom = "101";
        QSqlQuery query = db.FuncReturnMovieByID(SqlCom);
        TeTitle->setText(query.value(1).toString());
        TeDate->setText(query.value(8).toString());
        TeID->setText(query.value(0).toString());
        TeActor->setText(query.value(3).toString());
        TeType->setText(query.value(7).toString());
        TeScore->setText(query.value(2).toString());
        TeViewed->setText(query.value(6).toString());
        TeMoiveLink->setText(query.value(5).toString());
    }

    void FuncEditCommit()
    {
        QString StrArray[8];
        StrArray[0] = TeTitle->toPlainText();
        StrArray[1] = TeDate->toPlainText();
        StrArray[2] = TeID->toPlainText();
        StrArray[3] = TeActor->toPlainText();
        StrArray[4] = TeType->toPlainText();
        StrArray[5] = TeScore->toPlainText();
        StrArray[6] = TeViewed->toPlainText();
        StrArray[7] = TeMoiveLink->toPlainText();
        qDebug()<<StrArray[0]<<StrArray[2]<<StrArray[4];
        db.FuncUpdateMovieInfo(StrArray);

    }

    QPushButton *BtCommit;

private:
    Ui::editmovies *ui;
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


    DB db;
};

#endif // EDITMOVIES_H
