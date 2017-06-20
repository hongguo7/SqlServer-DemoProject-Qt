#include "login.h"
#include "mysql.h"
#include "regwindow.h"
#include "moviepanel.h"
#include <QApplication>
#include "commentpanel.h"
#include "editmovies.h"
#include "addmovies.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    regWindow regw;
    moviepanel movie;
    commentpanel comments;
    editmovies edit;
    addmovies add;
    DB mydb;
    mydb.FuncReturnSomeMovie();
    QObject::connect(w.BtRegister,&QPushButton::clicked,&regw,&regWindow::show);
    QObject::connect(w.BtRegister,&QPushButton::clicked,&w,&login::FuncCloseWindow);
    QObject::connect(w.BtLogin,&QPushButton::clicked,&w,&login::FuncLoginClicked);
    QObject::connect(&w,&login::SigLoginSuccess,&movie,&moviepanel::show);

    QObject::connect(&regw,&regWindow::SigRegSuccess,&w,&login::FuncOpenWindow);
    QObject::connect(regw.BtReg,&QPushButton::clicked,&regw,&regWindow::FuncRegisterClicked);

    //
    QObject::connect(movie.BtArray[0],&QPushButton::clicked,&movie,&moviepanel::FuncClicked0);
    QObject::connect(movie.BtArray[1],&QPushButton::clicked,&movie,&moviepanel::FuncClicked1);
    QObject::connect(movie.BtArray[2],&QPushButton::clicked,&movie,&moviepanel::FuncClicked2);
    QObject::connect(movie.BtArray[3],&QPushButton::clicked,&movie,&moviepanel::FuncClicked3);
    QObject::connect(movie.BtArray[4],&QPushButton::clicked,&movie,&moviepanel::FuncClicked4);
    QObject::connect(movie.BtArray[5],&QPushButton::clicked,&movie,&moviepanel::FuncClicked5);
    QObject::connect(movie.BtSearch,&QPushButton::clicked,&movie,&moviepanel::FuncSearchMovie);
    QObject::connect(&movie,&moviepanel::SigBtSearch,&movie,&moviepanel::FuncNONONO);
    //

    QObject::connect(movie.BtChange,&QPushButton::clicked,&movie,&moviepanel::ShowImage);
    QObject::connect(add.BtCommit,&QPushButton::clicked,&add,&addmovies::FuncCommitMovie);
    QObject::connect(edit.BtCommit,&QPushButton::clicked,&edit,&editmovies::FuncEditCommit);


    //insert into movie (movie_title,movie_release,movie_id,movie_actor,movie_type,movie_grade,movie_viewed,movie_posterlink) values ('啊啊','2016','101','阿斯达','阿斯顿',2.5,2000,'asdasd')
//    DB mydb;
    w.show();
//    edit.show();
//    comments.show();
//    add.show();
//    movie.show();
    return a.exec();
}
