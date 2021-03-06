#include "game1.h"
#include"ui_game1.h"
#include"include/global.h"
#include <QTimer>
#include "qlabel.h"
#include <qgraphicsitem.h>

game1::game1(gamenumber game,QWidget *parent)
	: QMainWindow(parent)
{   
	this->game = game;
	ui = new Ui::game1();
	ui->setupUi(this);
	ui->backbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/back.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	ui->nextbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/next.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	ui->resumebutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/resume.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	ui->stopbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/stop.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	connect(ui->backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_game1()));
	connect(ui->nextbutton, SIGNAL(clicked(bool)), this, SLOT(on_nextbutton_clicked_game1()));
	connect(ui->resumebutton, SIGNAL(clicked(bool)), this, SLOT(on_resumebutton_clicked_game1()));
	connect(ui->stopbutton, SIGNAL(clicked(bool)), this, SLOT(on_stopbutton_clicked_game1()));
	ui->nextbutton->setEnabled(false);
	sence = new QGraphicsScene(10, 0, SCENEHEIGHT/2, SCENEWIDTH);
	ui->view->setScene(sence);
	ui->progressBar->setTextVisible(false);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	sound = new QSound(":/start/music/02.wav");
	isInit = false;
	islastgame = false;
}

game1::~game1()
{
	delete ui;
}

void game1::on_backbutton_clicked_game1()
{   
	this->hide();
	sound->stop();
	emit show_fromgame1();
}

void game1::on_nextbutton_clicked_game1()
{  
	this->hide();
	ui->nextbutton->setEnabled(false);
	sound->stop();
	emit show_next();
	
}
void game1::init()
{
	
	if (isInit) {
		return;
	}
    boss = createBoss(sence, game);
	fighter = createPlayerFighter(sence);
	QObject::connect(fighter, SIGNAL(sig_fall()), this, SLOT(slt_playerDead()));
	QObject::connect(boss, SIGNAL(sig_fall()), this, SLOT(slt_bossDead()));
	switch (game)
	{
	case gameone:
		fighter->setPos(100, 350);
		fighter->setFocus();
		boss->setPos(100, 50);
		lamp = startTimer(50);
		this->setStyleSheet("QMainWindow {border-image: url(:/start/image/gw1.png);}");
		ui->view->setStyleSheet( "border-image: url(:/start/image/bg1.jpg)");
		
		ui->progressBar->setRange(0, PLAYER_ORDINARY_MAXHEALTH);
		ui->progressBar->setValue(PLAYER_ORDINARY_MAXHEALTH);
		QObject::connect(fighter, SIGNAL(notify(int)), this, SLOT(OnNotify(int)));
		
		isInit = true;
		
		break;
	case gametwo:
		fighter->setPos(100, 350);
		fighter->setFocus();
		boss->setPos(100, 50);
		lamp = startTimer(25);
		this->setStyleSheet("QMainWindow {border-image: url(:/start/image/gw1.png);}");
		ui->view->setStyleSheet("border-image: url(:/start/image/bg2.jpg)");
		
		ui->progressBar->setRange(0, PLAYER_ORDINARY_MAXHEALTH);
		ui->progressBar->setValue(PLAYER_ORDINARY_MAXHEALTH);
		QObject::connect(fighter, SIGNAL(notify(int)), this, SLOT(OnNotify(int)));
		isInit = true;
		islastgame = true;
		break;
	case gamethree:
		break;
	default:
		break;
	}
	return;
}

void game1::receive_fromgame1()
{
	this->show();
	this->close();
	init();
	sound->play();
}

void game1::timerEvent(QTimerEvent* Event)
{
	if(Event->timerId()==lamp)
		sence->advance();
	    sence->update();
}

void game1::close()
{
	sence->clear();
	isInit = false;

}
void  game1::slt_playerDead()
{   
	sound->stop();
	this->hide();
	emit showgameover();
}
void game1::slt_bossDead()
{   
	
	if (islastgame)
	{  
		sound->stop();
		this->hide();
		emit show_congratulation();
		islastgame = false;
	}
	else
	{
		ui->nextbutton->setEnabled(true);
	}
	
	
}
void game1::OnNotify(int health)
{
	ui->progressBar->setValue(health);
}

void game1::on_resumebutton_clicked_game1()
{   
	sound->play();
	if (lamp == startTimer(50))
	{
		return;
	}
	switch (game)
	{
	case gameone:
		lamp = startTimer(50);
		break;
	case gametwo:
		lamp = startTimer(25);
		break;
	case gamethree:
		break;
	default:
		break;
	}
}

void game1::on_stopbutton_clicked_game1()
{   
	sound->stop();
	if (lamp == 0)
	{
		return;
	}
	lamp = 0;
}