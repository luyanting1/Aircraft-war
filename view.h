#ifndef VIEW_H
#define VIEW_H

#endif // VIEW_H
#include <ctime>
#include <vector>
#include <cassert>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <QGraphicsScene>
#include <QUrl>
#include <QPointF>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsView>
#include <QPushButton>
using namespace std;
class View : public QGraphicsScene
{
public:
    View();
private:
       string myPlaneImageFile;
       int myLife;
       int mySkill;

       string myBulletImageFile;
       int myBulletPower;

       string enemyPlaneImageFile;
       int enemyLife;

       string enemyBulletImageFile;
       int enemyBulletPower;

       string bossImageFile;
       int bossLife;

       string bossBulletImageFile;
       int bossBulletPower;

       int myBulletShootTimerId;
       int enemyBulletShootTimerId;
       int allBulletMoveTimerId;

       QPointF myPlaneMove;
       int myPlaneMoveTimerId;
       int enemyPlaneMoveTimerId;
       int enemyPlaneGenerateTimerId;
       int bossGenerateTimeId;

       string lifeSupplyImageFile;

       QGraphicsRectItem *lifeFrameBar;
       QGraphicsRectItem *lifeBar;
       QGraphicsRectItem *skillFrameBar;
       QGraphicsRectItem *skillBar;

       QGraphicsTextItem *titleText; //游戏标题
       QGraphicsTextItem *authorText; //作者信息
       QGraphicsTextItem *scoreText; //显示当前打掉的飞机数
       QGraphicsTextItem *gameLostText; //玩家死亡显示文本
       QGraphicsTextItem *gameHelpText; //游戏初始帮助
       void start(); //初始界面
       bool hasStarted; //是否已经开始游戏
       int score;//游戏得分
       QGraphicsWidget *maskWidget; //遮罩面板
       QGraphicsWidget *startGameButton;
       QGraphicsWidget *helpGameButton;
       QGraphicsWidget *continueGameButton;
       QGraphicsWidget *retryGameButton;
       QGraphicsWidget *quitGameButton;
protected slots:
    void startGame(); //开始游戏
    void showHelpMessage(); //显示帮助信息
    void pauseGame(); //暂停游戏
    void loseGame(); //玩家生命值用尽
    void retryGame();  //重新开始
    void quitGame(); //结束游戏
};
