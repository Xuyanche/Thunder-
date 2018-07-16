#pragma once
#include <vector>
#include <iostream>
#include "../include/flyingObject.h"
using namespace std;


enum BelongTo {
	Enemy, Nutural, Friend
};
enum BulletType {
	Ordinary_Friend, Ordinary_Enemy
};


class Bullet :public FlyingObject {
public:
	Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue);
	~Bullet();


	void hitCtrl();
	void advance();
	flyingObjectType getType();
	void destroy();

	//�̳���QgraphicsObject�Ĵ��麯��
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	qreal xspeed;
	qreal yspeed;
	int damage;
	BelongTo belong;

};



class BulletManager {
public:
	static Bullet* createBullet(BulletType typevalue, QGraphicsScene *scene, qreal anglevalue);


};




