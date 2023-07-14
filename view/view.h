#ifndef VIEW_H
#define VIEW_H
#include <string>
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
#include "../base/Bullet.h"
#include "../base/EnemyPlane.h"
#include "../base/MyPlane.h"
#include "../base/Object.h"
#include "../base/Plane.h"
#include "../common/etlbase.h"
#include "../common/common.h"

#define myBulletImageFile  ":/images/mybullet_new.png"

#define enemyPlaneImageFile  ":/images/enemyplane.png"

#define myPlaneImageFile  ":/images/myplane.png"

#define bossImageFile  ":/images/boss.png"
//boss图片

#define enemyBulletImageFile  ":/images/enemybullet_new.png"
//敌机子弹图片


#define bossBulletImageFile  ":/images/bossbullet_new.pngd"
//boss子弹图片

#define lifeSupplyImageFile  ":/images/lifesupply.png"
//补给图片

#include "./sink/viewpropertysink.h"

class View : public QGraphicsScene
{
protected:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public:
    View();
    void changescene();
    std::shared_ptr<IPropertyNotification> GetPropertySink();
/*
    void SetMyPlane(std::shared_ptr<MyPlane>);

    void SetEnemiesPlane( std::shared_ptr<vector<EnemyPlane *>>);

    void SetBullets(std::shared_ptr<vector<Bullet *>>);

    void SetLifeSupplies(std::shared_ptr<vector<Object *>> );
*/
    void SetPlayerLife(std::shared_ptr<BAR>);

    void SetPlayerSkill(std::shared_ptr<BAR>);

    void SetPlayerScore(std::shared_ptr<int>);

    void SetAllBulletMoveCommand(std::shared_ptr<ICommandBase> a);

    void SetBossGenerateCommand(std::shared_ptr<ICommandBase>a);

    void SetEnemyBulletShootCommand(std::shared_ptr<ICommandBase> a);

    void SetEnemyGenerateCommand(std::shared_ptr<ICommandBase> a);

    void SetEnemyMoveCommand(std::shared_ptr<ICommandBase> a);

    void SetGamePauseCommand(std::shared_ptr<ICommandBase> a);

    void SetGameResetCommand(std::shared_ptr<ICommandBase> a);

    void SetPlayerBulletShootCommand(std::shared_ptr<ICommandBase> a);

    void SetPlayerMoveCommand(std::shared_ptr<ICommandBase> a);

    void SetSkillUseCommand(std::shared_ptr<ICommandBase> a);
/*
    void SetPlayerPosX(POS* );

    void SetPlayerPosY(POS* );

    void SetBulletsPosX(shared_ptr<POSES>);

    void SetBulletsPosY(shared_ptr<POSES>  );

    void SetBulletsType(shared_ptr<BULLETTYPES> );

    void SetEnemiesPosX(shared_ptr<POSES> );

    void SetEnemiesPosY(shared_ptr<POSES>);

    void SetEnemiesType(shared_ptr<ENEMYTYPES>);

    void SetLifeSuppliesPosX(shared_ptr<POSES>);

    void SetLifeSuppliesPosY(shared_ptr<POSES>);
*/
    void SetPlayerGenerateCommand(std::shared_ptr<ICommandBase>);
    void SetBullets(std::shared_ptr<OBJECTS> a);

    void SetLifeSupplies(std::shared_ptr<OBJECTS> a);
    void SetMyPlane(std::shared_ptr<Object> a);

    void SetEnemiesPlane(std::shared_ptr<OBJECTS> a);

private:
       //各种模型的属性
       int myLife;
       int mySkill;

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

       std::shared_ptr<ICommandBase> m_cmdgenerateboss;
       std::shared_ptr<ICommandBase> m_cmdgamereset;
       std::shared_ptr<ICommandBase> m_cmdgamepause;
       std::shared_ptr<ICommandBase> m_cmdskilluse;
       std::shared_ptr<ICommandBase> m_cmdplanemove;
       std::shared_ptr<ICommandBase> m_cmdgenerateenemyplane;
       std::shared_ptr<ICommandBase> m_cmdmovebullet;
       std::shared_ptr<ICommandBase> m_cmdshootenemybullet;
       std::shared_ptr<ICommandBase> m_cmdshootmybullet;
       std::shared_ptr<ICommandBase> m_cmdmoveenemyplane;
       std::shared_ptr <ICommandBase> m_cmdgeneratemyplane;
       std::shared_ptr<ViewPropertySink> m_propertysink;
       /*
       POS*  play_posX;

       POS*  play_posY;

*/
       std::shared_ptr<OBJECTS>  Bullets_view;

       std::shared_ptr<OBJECTS>  LifeSupplies_view;

       std::shared_ptr<Object>   MyPlane_view;

       std::shared_ptr<OBJECTS>    EnemiesPlane_view;
/*
       std::shared_ptr<POSES>  bullet_posX;

       std::shared_ptr<POSES>  bullet_posY;

       std::shared_ptr<POSES>  lifesupply_posX;

       std::shared_ptr<POSES>  lifesupply_posY;

       std::shared_ptr<BULLETTYPES>  bullet_type;

       std::shared_ptr<POSES>  enemy_posX;

       std::shared_ptr<POSES>  enemy_posY;

       std::shared_ptr<ENEMYTYPES>  enemy_type;
*/
       std::shared_ptr<std::vector<EnemyPlane *>> EnemiesPlane;

       std::shared_ptr<std::vector<Bullet *>> Bullets;

       std::shared_ptr<MyPlane>  myplane;

       std::shared_ptr<std::vector<Object *>> LifeSupplies;

       std::shared_ptr<int> PlayerScore;

       std::shared_ptr<BAR>  player_life;

       std::shared_ptr<BAR>  player_skill;

       void enemyplane_move();

       void boss_generate();

       void enemyplane_generate();

       void myplane_generate();

       void bullet_move();

       void enemybullet_shoot();

       void mybullet_shoot();

       void myplane_move(char direction);

       void skill_use(int skillselect);

       void pause_game();

       void reset_game();

       int   hasLoseGmae=0;
       char  direction;
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

#endif // VIEW_H
