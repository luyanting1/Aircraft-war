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
#include <QLabel>
#include <QString>
#include <QPainter>
#include <QObject>
#include "./base/Plane.h"
#include "./base/MyPlane.h"
#include "./base/EnemyPlane.h"
using namespace std;
class View : public QGraphicsScene
{
protected:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public:
    View();
private:
       //各种模型的属性
       string myPlaneImageFile;
       int myLife;
       int mySkill;

       string myBulletImageFile;

       string enemyPlaneImageFile;


       string enemyBulletImageFile;

       string bossImageFile;

       string bossBulletImageFile;

       string lifeSupplyImageFile;

       QPointF myPlaneMove;//飞机的位移

       //各种动作的时钟
       int myBulletShootTimerId;
       int enemyBulletShootTimerId;
       int allBulletMoveTimerId;
       int myPlaneMoveTimerId;
       int enemyPlaneMoveTimerId;
       int enemyPlaneGenerateTimerId;
       int bossGenerateTimeId;


       //血条和技能框
       QGraphicsRectItem *lifeFrameBar;
       QGraphicsRectItem *lifeBar;
       QGraphicsRectItem *skillFrameBar;
       QGraphicsRectItem *skillBar;

       QGraphicsTextItem *titleText; //游戏标题
       QGraphicsTextItem *authorText; //作者信息
       QGraphicsTextItem *scoreText; //显示当前打掉的飞机数
       QGraphicsTextItem *gameLostText; //玩家死亡显示文本
       QGraphicsTextItem *gameHelpText; //游戏初始帮助

       QGraphicsWidget *maskWidget; //遮罩面板
       QGraphicsWidget *startGameButton;
       QGraphicsWidget *helpGameButton;
       QGraphicsWidget *continueGameButton;
       QGraphicsWidget *retryGameButton;
       QGraphicsWidget *quitGameButton;

       shared_ptr<ICommandBase> m_cmdgenerateboss;
       shared_ptr<ICommandBase> m_cmdgamereset;
       shared_ptr<ICommandBase> m_cmdgamepause;
       shared_ptr<ICommandBase> m_cmdskilluse;
       shared_ptr<ICommandBase> m_cmdplanemove;
       shared_ptr<ICommandBase> m_cmdgenerateenemyplane;
       shared_ptr<ICommandBase> m_cmdmovebullet;
       shared_ptr<ICommandBase> m_cmdshootenemybullet;
       shared_ptr<ICommandBase> m_cmdshootmybullet;
       shared_ptr<ICommandBase> m_cmdmoveenemyplane;

       MyPlane *myplane;
       void SetPlayerPosX(shared_ptr<POS>);
       shared_ptr<POS>  play_posX;
       void SetPlayerPosY(shared_ptr<POS>);
       shared_ptr<POS>  play_posY;
       void SetPlayerScore(shared_ptr<SCORE>);
       shared_ptr<SCORE>  player_score;
       void SetBulletsPosX(shared_ptr<POSES>);
       shared_ptr<POSES>  bullet_posX;
       void SetBulletsPosY(shared_ptr<POSES>  );
       shared_ptr<POSES>  bullet_posY;
       void SetBulletsType(shared_ptr<BULLETTYPES> );
       shared_ptr<BULLETTYPES>  bullet_type;
       void SetEnemiesPosX(shared_ptr<POSES> );
       shared_ptr<POSES>  enemy_posX;
       void SetEnemiesPosY(shared_ptr<POSES>);
       shared_ptr<POSES>  enemy_posY;
       void SetEnemiesType(shared_ptr<ENEMYTYPES>);
       shared_ptr<ENEMYTYPES>  enemy_type;
       void SetPlayerLife(shared_ptr<BAR>);
       shared_ptr<BAR>  player_life;
       void SetPlayerSkill(shared_ptr<BAR>);
       shared_ptr<BAR>  player_skill;
       void enemyplane_move();

       void boss_generate();

       void enemyplane_generate();

       void bullet_move();

       void enemybullet_shoot();

       void mybullet_shoot();

       void myplane_move(string direction);

       void skill_use(int skillselect);

       void pause_game();

       void reset_game();
       string direction;
       bool  hasStarted; //是否已经开始游戏
       int   score;//游戏得分
       bool  isPause; //游戏是否暂停
       int   myBulletType; //是否使用技能
       int   skillQTimerId; //技能Q使用时间
       void  start(); //初始界面
protected slots:
    void startGame(); //开始游戏
    void showHelpMessage(); //显示帮助信息
    void pauseGame(); //暂停游戏
    void loseGame(); //玩家生命值用尽
    void retryGame();  //重新开始
    void quitGame(); //结束游戏
};
