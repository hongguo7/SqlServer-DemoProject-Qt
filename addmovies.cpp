#include "addmovies.h"
#include "ui_addmovies.h"

addmovies::addmovies(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addmovies)
{
    ui->setupUi(this);
    this->setWindowTitle("AddMovies");
    LbTitle = new QLabel(this);
    LbTitle->setText("Title");
    LbTitle->setGeometry(QRect(50,50,50,25));
    TeTitle = new QTextEdit(this);
    TeTitle->setGeometry(QRect(200,50,200,25));

    LbDate = new QLabel(this);
    LbDate->setText("Date");
    LbDate->setGeometry(QRect(50,100,50,25));
    TeDate = new QTextEdit(this);
    TeDate->setGeometry(QRect(200,100,200,25));

    LbID = new QLabel(this);
    LbID->setText("ID");
    LbID->setGeometry(QRect(50,150,50,25));
    TeID = new QTextEdit(this);
    TeID->setGeometry(QRect(200,150,200,25));

    LbActor = new QLabel(this);
    LbActor->setText("Actor");
    LbActor->setGeometry(QRect(50,200,50,25));
    TeActor = new QTextEdit(this);
    TeActor->setGeometry(QRect(200,200,200,25));

    LbType = new QLabel(this);
    LbType->setText("Type");
    LbType->setGeometry(QRect(50,250,50,25));
    TeType = new QTextEdit(this);
    TeType->setGeometry(QRect(200,250,200,25));

    LbScore = new QLabel(this);
    LbScore->setText("Score");
    LbScore->setGeometry(QRect(50,300,50,25));
    TeScore = new QTextEdit(this);
    TeScore->setGeometry(QRect(200,300,200,25));

    LbViewed = new QLabel(this);
    LbViewed->setText("Viewed");
    LbViewed->setGeometry(QRect(50,350,50,25));
    TeViewed = new QTextEdit(this);
    TeViewed->setGeometry(QRect(200,350,200,25));

    LbMovieLink = new QLabel(this);
    LbMovieLink->setText("Link");
    LbMovieLink->setGeometry(QRect(50,400,50,25));
    TeMoiveLink = new QTextEdit(this);
    TeMoiveLink->setGeometry(QRect(200,400,200,25));

    BtCommit = new QPushButton(this);
    BtCommit->setText("Commit");
    BtCommit->setGeometry(200,450,70,25);
}

addmovies::~addmovies()
{
    delete ui;
}
