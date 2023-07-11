#ifndef VIEW_H
#define VIEW_H
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
#include "../common/precomp.h"

#define myBulletImageFile  ":/images/mybullet.png"

#define enemyPlaneImageFile  ":/images/enemyplane.png"

#define myPlaneImageFile  ":/images/myplane.png"

#define bossImageFile  ":/images/boss2.gif"
//boss图片

#define enemyBulletImageFile  ":/images/76446d7d2b8c45cb8ed30baf1f75397e.png"
//敌机子弹图片


#define bossBulletImageFile  ":/images/76446d7d2b8c45cb8ed30baf1f75397e.png"
//boss子弹图片

#define lifeSupplyImageFile  ":/images/lifesupply.png"
//补给图片

#include "./sinks/viewpropertysink.h"

using namespace std;
class View : public QGraphicsScene
{
protected:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public:
    View();
    std::shared_ptr<IPropertyNotification> GetPropertySink();

    void SetMyPlane(std::shared_ptr<MyPlane>);

    void SetEnemiesPlane( std::shared_ptr<vector<EnemyPlane *>>);

    void SetBullets(std::shared_ptr<vector<Bullet *>>);

    void SetLifeSupplies(std::shared_ptr<vector<Object *>> );

    void SetPlayerLife(shared_ptr<BAR>);

    void SetPlayerSkill(shared_ptr<BAR>);

    void SetPlayerScore(std::shared_ptr<int>);

    void SetAllBulletMoveCommand(shared_ptr<ICommandBase> a);

    void SetBossGenerateCommand(shared_ptr<ICommandBase>a);

    void SetEnemyBulletShootCommand(shared_ptr<ICommandBase> a);

    void SetEnemyGenerateCommand(shared_ptr<ICommandBase> a);

    void SetEnemyMoveCommand(shared_ptr<ICommandBase> a);

    void SetGamePauseCommand(shared_ptr<ICommandBase> a);

    void SetGameResetCommand(shared_ptr<ICommandBase> a);

    void SetPlayerBulletShootCommand(shared_ptr<ICommandBase> a);

    void SetPlayerMoveCommand(shared_ptr<ICommandBase> a);

    void SetSkillUseCommand(shared_ptr<ICommandBase> a);

    void SetPlayerPosX(shared_ptr<POS>);

    void SetPlayerPosY(shared_ptr<POS>);

    void SetBulletsPosX(shared_ptr<POSES>);

    void SetBulletsPosY(shared_ptr<POSES>  );

    void SetBulletsType(shared_ptr<BULLETTYPES> );

    void SetEnemiesPosX(shared_ptr<POSES> );

    void SetEnemiesPosY(shared_ptr<POSES>);

    void SetEnemiesType(shared_ptr<ENEMYTYPES>);

    void PlayerGenerateCommand(shared_ptr<ICommandBase>);

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
       shared_ptr <ICommandBase> m_cmdgeneratemyplane;
       shared_ptr<ViewPropertySink> m_propertysink;
       shared_ptr<POS>  play_posX;

       shared_ptr<POS>  play_posY;

       shared_ptr<POSES>  bullet_posX;

       shared_ptr<POSES>  bullet_posY;

       shared_ptr<BULLETTYPES>  bullet_type;

       shared_ptr<POSES>  enemy_posX;

       shared_ptr<POSES>  enemy_posY;

       shared_ptr<ENEMYTYPES>  enemy_type;

       std::shared_ptr<vector<EnemyPlane *>> EnemiesPlane;

       std::shared_ptr<vector<Bullet *>> Bullets;

       std::shared_ptr<MyPlane>  myplane;

       std::shared_ptr<vector<Object *>> LifeSupplies;

       std::shared_ptr<int> PlayerScore;

       shared_ptr<BAR>  player_life;

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

       void changescene();

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

#endif // VIEW_H
