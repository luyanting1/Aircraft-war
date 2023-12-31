﻿#include "view.h"
const QPointF scoreTextPos = QPointF(650, 520);
const QPointF LifeBarPos = QPointF(650,550);
const QPointF SkillBarPos = QPointF(650, 570);
const int myBulletShootTimerItv = 900;
const int enemyBulletShootTimerItv = 3000;
const int allBulletMoveTimerItv = 10;

const int myPlaneMoveTimerItv = 30;
const int enemyPlaneMoveTimerItv = 100;
const int enemyPlaneGenerateTimerItv = 8000;
const int bossGenerateTimeItv = 16000;

const int debugTimerItv = 10;
int debugTimer;
View::View()
{
    m_propertysink = std::make_shared<ViewPropertySink>(this);
    setSceneRect(0,0,800,600);//设置整个界面的大小

    myLife=50;
    //(*player_life) = 50;
    mySkill=5;
    //(*player_skill) = 5;


       /* 游戏标题 */
       titleText = new QGraphicsTextItem;
       addItem(titleText);
       titleText->setHtml(tr("<font color=white>Thunder Plane</font>"));
       titleText->setFont(QFont("Algerian", 30));
       titleText->setPos(200,100);
       titleText->setZValue(2);
       titleText->hide();
       /* 作者信息 */
       authorText = new QGraphicsTextItem;
       addItem(authorText);
       authorText->setHtml(tr("<font color=white>Copyright © 2023,c++."));
       authorText->setFont(QFont("Courier"));
       authorText->setPos(100, 500);
       authorText->setZValue(2);
       authorText->hide();
        /* 遮罩面板 */
        QWidget *mask = new QWidget;
        mask->setAutoFillBackground(true);
        mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
        mask->resize(width(),height());
        maskWidget = addWidget(mask);
        maskWidget->setPos(0,0);
        maskWidget->setZValue(1); //设置处在z值为0的图形项上方
        maskWidget->hide();

       /*游戏开始按钮 */
       QPushButton *startGameBtn = new QPushButton("Start Game");
       startGameBtn->setFont(QFont("Algerian",18));
       startGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                   "QPushButton:hover{color:red;}");
       connect(startGameBtn,&QAbstractButton::clicked,this,&View::startGame);
       startGameButton = addWidget(startGameBtn);
       startGameButton->setPos(300,250);
       startGameButton->setZValue(2);
       startGameButton->hide();

       /* 游戏帮助 */
       QPushButton *helpGameBtn = new QPushButton(tr("Help"));
       helpGameBtn->setFont(QFont("Algerian",18));
       helpGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                      "QPushButton:hover{color:red;}");
       connect(helpGameBtn,&QAbstractButton::clicked,this,&View::showHelpMessage);
       helpGameButton = addWidget(helpGameBtn);
       helpGameButton->setPos(350,300);
       helpGameButton->setZValue(2);
       helpGameButton->hide();

       /* 退出游戏 */
       QPushButton *quitGameBtn = new QPushButton(tr("Quit Game"));
       quitGameBtn->setFont(QFont("Algerian",18));
       quitGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                  "QPushButton:hover{color:red;}");
       connect(quitGameBtn,&QAbstractButton::clicked,this,&View::quitGame);
       quitGameButton = addWidget(quitGameBtn);
       quitGameButton->setPos(310, 350);
       quitGameButton->setZValue(2);
       quitGameButton->hide();


       /* 游戏暂停提示 */
       isPause = false;
       QPushButton *continueGameBtn = new QPushButton(tr("Resume"));
       continueGameBtn->setFont(QFont("Algerian",18));
       continueGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                          "QPushButton:hover{color:red;}");
       connect(continueGameBtn,&QAbstractButton::clicked,this,&View::pauseGame);
       continueGameButton = addWidget(continueGameBtn);
       continueGameButton->setPos(330,250);
       continueGameButton->setZValue(2);
       continueGameButton->hide();

       /* 游戏终止提示 */
       gameLostText = new QGraphicsTextItem;
       addItem(gameLostText);
       gameLostText->setHtml(tr("<font color=white>Game Over</font>"));
       gameLostText->setFont(QFont("Algerian", 22));
       gameLostText->setPos(150, 150);
       gameLostText->setZValue(2);
       gameLostText->hide();

       /* 重试 */
       /*
       QPushButton *retryGameBtn = new QPushButton(tr("Retry"));
       retryGameBtn->setFont(QFont("Algerian",18));
       retryGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                      "QPushButton:hover{color:red;}");
       connect(retryGameBtn,&QAbstractButton::clicked,this,&View::retryGame);
       retryGameButton = addWidget(retryGameBtn);
       retryGameButton->setPos(345,250);
       retryGameButton->setZValue(2);
       retryGameButton->hide();
       */
       /* 生命值 */
       lifeFrameBar = new QGraphicsRectItem(LifeBarPos.x(), LifeBarPos.y(), myLife*2,5);//设置血条方框，以血量作为长度
       lifeFrameBar->setPen(QPen(Qt::white));//设置一个边框颜色，区分
       addItem(lifeFrameBar);
       lifeFrameBar->hide();
       lifeBar = new QGraphicsRectItem(LifeBarPos.x(), LifeBarPos.y(), myLife*2, 5);
       lifeBar->setBrush(QBrush(Qt::green));//填充血条颜色
       addItem(lifeBar);
       lifeBar->hide();

       /* 技能值 */
       skillFrameBar = new QGraphicsRectItem(SkillBarPos.x(),SkillBarPos.y(),  mySkill*2,5);
       skillFrameBar->setPen(QPen(Qt::white));
       addItem(skillFrameBar);
       skillFrameBar->hide();
       skillBar = new QGraphicsRectItem(SkillBarPos.x(), SkillBarPos.y(), mySkill*2, 5);
       skillBar->setBrush(QBrush(Qt::blue));
       addItem(skillBar);
       skillBar->hide();
       start();
}
void View::start()
{
        hasStarted = false;
        maskWidget->show();
        titleText->show();
        startGameButton->show();
        helpGameButton->show();
        quitGameButton->show();
        authorText->show();
}
void View::quitGame()
{
    exit(0);
}

void View::startGame()
{
    //debugTimer = startTimer(debugTimerItv);
    /* 设置各动作更新时钟 */

    myPlaneMove = QPointF(0, 0);

    myBulletShootTimerId = startTimer(myBulletShootTimerItv);
    enemyBulletShootTimerId = startTimer(enemyBulletShootTimerItv);
    allBulletMoveTimerId = startTimer(allBulletMoveTimerItv);
    enemyPlaneMoveTimerId = startTimer(enemyPlaneMoveTimerItv);
    enemyPlaneGenerateTimerId = startTimer(enemyPlaneGenerateTimerItv);
    bossGenerateTimeId = startTimer(bossGenerateTimeItv);

}

void View::showHelpMessage()
{
    QString helpText;
    helpText += tr("欢迎来到飞机大战\n");
    helpText += tr("\n当你击落敌机时，你的得分和技能值都会相应地增加\n");
    helpText += tr("若你被敌机击中或撞到，你的生命值会相应减少\n");
    helpText += tr("当你的技能值达到一定量的时候，便可释放技能\n");
    helpText += tr("\n进度条：\n");
    helpText += tr("绿色进度条：你的生命值\n");
    helpText += tr("蓝色进度条：你的技能值\n");
    helpText += tr("\n操作：\n");
    helpText += tr("W：上； S：下； A：左； D：右\n");
    helpText += tr("J：超级子弹技能，一次发射三个方向的子弹，消耗5点技能\n");
    helpText += tr("K：轰炸技能，一次性炸掉所有敌机，消耗3点技能\n");
    helpText += tr("L：子弹拦截技能，一次性拦截掉所有子弹，消耗7点技能\n");
    helpText += tr("空格键：暂停游戏\n");
    helpText += tr("\n补给：\n");
    helpText += tr("被击毁的敌机随机生成补给，即绿色的加号，每次可补充10点生命值");
    QMessageBox Box;
    Box.setText("游戏帮助");
    Box.setInformativeText(helpText);
    Box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    Box.setDefaultButton(QMessageBox::Ok);
    int ret = Box.exec();
    //QMessageBox::information(NULL,tr("游戏帮助"),helpText);
}
void View::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction='W';
    }
    else if(event->key()==Qt::Key_S && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction='S';
    }
    else if(event->key()==Qt::Key_A && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction='A';
    }
    else if(event->key()==Qt::Key_D && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction='D';
    }
    else if(event->key()==Qt::Key_J && *(player_skill)>=5)
    {
        //按Q的技能可以一次发射3个子弹，但是会消耗5点技能
        skill_use(5);
        skillQTimerId = startTimer(5000); //5秒使用时间
    }
    else if(event->key()==Qt::Key_K && *(player_skill)>=3)
    {
        skill_use(3);
    }
    else if(event->key()==Qt::Key_L && *(player_skill)>=7)
    {
        skill_use(7);
    }
    else if(event->key()==Qt::Key_Space)
        pauseGame();
}
void View::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == debugTimer){
        enemyplane_generate();
        enemybullet_shoot();
        for(int i = 1; i < 20; i++){
            bullet_move();
        }
        killTimer(debugTimer);
        debugTimer = -1;
    }
    if(event->timerId()==myPlaneMoveTimerId)
    {
        myplane_move(direction);
        if(*(player_life)<=0)
        {
            hasLoseGmae=1;
            //loseGame();
        }
        //changescene();
      }
    if(event->timerId()==enemyBulletShootTimerId)
    {
        enemybullet_shoot();
        //changescene();

    }
    else if(event->timerId()==myBulletShootTimerId)
       {
        mybullet_shoot();
        //changescene();
    }

    else if(event->timerId()==allBulletMoveTimerId)
    {
        bullet_move();
        if(*(player_life)<=0)
        {
            hasLoseGmae=1;
            //loseGame();
        }
        //changescene();
    }
    else if(event->timerId()==enemyPlaneMoveTimerId)
    {
        enemyplane_move();
        //changescene();
    }
    else if(event->timerId()==enemyPlaneGenerateTimerId)
    {
        enemyplane_generate();
        //changescene();
    }
    else if(event->timerId()==bossGenerateTimeId)
    {
        boss_generate();
        //changescene();
    }
    else if(event->timerId()==skillQTimerId)
        myBulletType = 0;
}
void View::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_W || event->key()==Qt::Key_S || event->key()==Qt::Key_A || event->key()==Qt::Key_D)
            && !event->isAutoRepeat())
    {
        direction='N';//不移动的时候
        if (myPlaneMoveTimerId > 0) {
            killTimer(myPlaneMoveTimerId);//当飞机不动以后将他的时钟释放掉
            myPlaneMoveTimerId = -1;
        }
    }
}

void View::myplane_move(char direction)
{
    m_cmdplanemove->SetParameter(direction);
    m_cmdplanemove->Exec();
}

void View::skill_use(int skillselect)
{
    m_cmdskilluse->SetParameter(skillselect);
    m_cmdskilluse->Exec();
}

void View::pauseGame()
{
    if(!isPause)
       {
           isPause = true;
           if (myBulletShootTimerId > 0) {
               killTimer(myBulletShootTimerId);
               myBulletShootTimerId = -1;
           }
           if (enemyBulletShootTimerId > 0) {
               killTimer(enemyBulletShootTimerId);
               enemyBulletShootTimerId = -1;
           }
           if (allBulletMoveTimerId > 0) {
               killTimer(allBulletMoveTimerId);
               allBulletMoveTimerId = -1;
           }
           if (enemyPlaneMoveTimerId > 0) {
               killTimer(enemyPlaneMoveTimerId);
               enemyPlaneMoveTimerId = -1;
           }
           if (enemyPlaneGenerateTimerId > 0) {
               killTimer(enemyPlaneGenerateTimerId);
               enemyPlaneGenerateTimerId = -1;
           }
           if (bossGenerateTimeId > 0) {
               killTimer(bossGenerateTimeId);
               bossGenerateTimeId = -1;
           }

           maskWidget->show();
           continueGameButton->show();
           helpGameButton->show();
           quitGameButton->show();
       }
       else
       {
           isPause = false;
           myBulletShootTimerId = startTimer(myBulletShootTimerItv);
           enemyBulletShootTimerId = startTimer(enemyBulletShootTimerItv);
           allBulletMoveTimerId = startTimer(allBulletMoveTimerItv);
           enemyPlaneMoveTimerId = startTimer(enemyPlaneMoveTimerItv);
           enemyPlaneGenerateTimerId = startTimer(enemyPlaneGenerateTimerItv);
           bossGenerateTimeId = startTimer(bossGenerateTimeItv);
           maskWidget->hide();
           continueGameButton->hide();
           helpGameButton->hide();
           quitGameButton->hide();
       }
}

void View::reset_game()
{
    m_cmdgamereset->Exec();
}

void View::boss_generate()
{
    m_cmdgenerateboss->Exec();
}

void View::enemyplane_generate()
{
    m_cmdgenerateenemyplane->Exec();
}
void View::myplane_generate()
{
    m_cmdgeneratemyplane->Exec();
}
void View::enemyplane_move()
{
    m_cmdmoveenemyplane->Exec();
}

void View::bullet_move()
{
    m_cmdmovebullet->Exec();
}

void View::enemybullet_shoot()
{
    m_cmdshootenemybullet->Exec();
}

void View::mybullet_shoot()
{
    m_cmdshootmybullet->Exec();
}
void View::loseGame()
{
    if (myBulletShootTimerId > 0) {
        killTimer(myBulletShootTimerId);
        myBulletShootTimerId = -1;
    }
    if (enemyBulletShootTimerId > 0) {
        killTimer(enemyBulletShootTimerId);
        enemyBulletShootTimerId = -1;
    }
    if (allBulletMoveTimerId > 0) {
        killTimer(allBulletMoveTimerId);
        allBulletMoveTimerId = -1;
    }
    if (enemyPlaneMoveTimerId > 0) {
        killTimer(enemyPlaneMoveTimerId);
        enemyPlaneMoveTimerId = -1;
    }
    if (enemyPlaneGenerateTimerId > 0) {
        killTimer(enemyPlaneGenerateTimerId);
        enemyPlaneGenerateTimerId = -1;
    }
    if (bossGenerateTimeId > 0) {
        killTimer(bossGenerateTimeId);
        bossGenerateTimeId = -1;
    }

    maskWidget->show();
    gameLostText->setHtml(tr("<font color=white>Game Over, Your Score: %1</font>").arg(score));
    gameLostText->show();
    //retryGameButton->show();
    helpGameButton->show();
    quitGameButton->show();
}
void View::changescene()
{
    QList<QGraphicsItem *> itemslist = items();
    for (auto item : itemslist) {
        removeItem(item);
        delete item;
    }
    /* 游戏标题 */
    titleText = new QGraphicsTextItem;
    addItem(titleText);
    titleText->setHtml(tr("<font color=white>Thunder Plane</font>"));
    titleText->setFont(QFont("Algerian", 30));
    titleText->setPos(200,100);
    titleText->setZValue(2);
    titleText->hide();
    /* 作者信息 */
    authorText = new QGraphicsTextItem;
    addItem(authorText);
    authorText->setHtml(tr("<font color=white>Copyright © 2023,c++."));
    authorText->setFont(QFont("Courier"));
    authorText->setPos(100, 500);
    authorText->setZValue(2);
    authorText->hide();
     /* 遮罩面板 */
     QWidget *mask = new QWidget;
     mask->setAutoFillBackground(true);
     mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
     mask->resize(width(),height());
     maskWidget = addWidget(mask);
     maskWidget->setPos(0,0);
     maskWidget->setZValue(1); //设置处在z值为0的图形项上方
     maskWidget->hide();

    /*游戏开始按钮 */
    QPushButton *startGameBtn = new QPushButton("Start Game");
    startGameBtn->setFont(QFont("Algerian",18));
    startGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(startGameBtn,&QAbstractButton::clicked,this,&View::startGame);
    startGameButton = addWidget(startGameBtn);
    startGameButton->setPos(300,250);
    startGameButton->setZValue(2);
    startGameButton->hide();

    /* 游戏帮助 */
    QPushButton *helpGameBtn = new QPushButton(tr("Help"));
    helpGameBtn->setFont(QFont("Algerian",18));
    helpGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                   "QPushButton:hover{color:red;}");
    connect(helpGameBtn,&QAbstractButton::clicked,this,&View::showHelpMessage);
    helpGameButton = addWidget(helpGameBtn);
    helpGameButton->setPos(350,300);
    helpGameButton->setZValue(2);
    helpGameButton->hide();

    /* 退出游戏 */
    QPushButton *quitGameBtn = new QPushButton(tr("Quit Game"));
    quitGameBtn->setFont(QFont("Algerian",18));
    quitGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                               "QPushButton:hover{color:red;}");
    connect(quitGameBtn,&QAbstractButton::clicked,this,&View::quitGame);
    quitGameButton = addWidget(quitGameBtn);
    quitGameButton->setPos(310, 350);
    quitGameButton->setZValue(2);
    quitGameButton->hide();


    /* 游戏暂停提示 */
    isPause = false;
    QPushButton *continueGameBtn = new QPushButton(tr("Resume"));
    continueGameBtn->setFont(QFont("Algerian",18));
    continueGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                       "QPushButton:hover{color:red;}");
    connect(continueGameBtn,&QAbstractButton::clicked,this,&View::pauseGame);
    continueGameButton = addWidget(continueGameBtn);
    continueGameButton->setPos(330,250);
    continueGameButton->setZValue(2);
    continueGameButton->hide();

    /* 游戏终止提示 */
    gameLostText = new QGraphicsTextItem;
    addItem(gameLostText);
    gameLostText->setHtml(tr("<font color=white>Game Over</font>"));
    gameLostText->setFont(QFont("Algerian", 22));
    gameLostText->setPos(150, 150);
    gameLostText->setZValue(2);
    gameLostText->hide();

    /* 重试 */
    /*
    QPushButton *retryGameBtn = new QPushButton(tr("Retry"));
    retryGameBtn->setFont(QFont("Algerian",18));
    retryGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                   "QPushButton:hover{color:red;}");
    connect(retryGameBtn,&QAbstractButton::clicked,this,&View::retryGame);
    retryGameButton = addWidget(retryGameBtn);
    retryGameButton->setPos(345,250);
    retryGameButton->setZValue(2);
    retryGameButton->hide();
    */
    /* 生命值 */
    lifeFrameBar = new QGraphicsRectItem(LifeBarPos.x(), LifeBarPos.y(), myLife*2,5);//设置血条方框，以血量作为长度
    lifeFrameBar->setPen(QPen(Qt::white));//设置一个边框颜色，区分
    addItem(lifeFrameBar);
    lifeFrameBar->hide();
    lifeBar = new QGraphicsRectItem(LifeBarPos.x(), LifeBarPos.y(), *(player_life)*2, 5);
    lifeBar->setBrush(QBrush(Qt::green));//填充血条颜色
    addItem(lifeBar);
    lifeBar->hide();

    /* 技能值 */
    skillFrameBar = new QGraphicsRectItem(SkillBarPos.x(),SkillBarPos.y(), mySkill*2,5);
    skillFrameBar->setPen(QPen(Qt::white));
    addItem(skillFrameBar);
    skillFrameBar->hide();
    skillBar = new QGraphicsRectItem(SkillBarPos.x(), SkillBarPos.y(), *(player_skill)*2, 5);
    skillBar->setBrush(QBrush(Qt::blue));
    addItem(skillBar);
    skillBar->hide();

    //得分显示
    scoreText = new QGraphicsTextItem;
    scoreText->setPos(scoreTextPos);
    scoreText->setHtml(tr("<font color=white>SCORE: %1</font>").arg(*(PlayerScore)));
    scoreText->setFont(QFont("Courier"));
    addItem(scoreText);
    scoreText->hide();

    scoreText->show();


    lifeFrameBar->show();
    lifeBar->setRect(LifeBarPos.x(), LifeBarPos.y(), *(player_life)*2, lifeBar->rect().height());
    lifeBar->setBrush(Qt::green);
    lifeBar->update();//血量值会更新
    lifeBar->show();

    skillFrameBar->show();
    skillBar->setRect(SkillBarPos.x(), SkillBarPos.y(), *(player_skill)*2, skillBar->rect().height());
    skillBar->setBrush(Qt::blue);
    skillBar->update();
    skillBar->show();

    for(int i=0;i<(*Bullets_view).size();i++)
    {
        if((*Bullets_view)[i]->gett()==0)
        {
           QPixmap pixmap(myBulletImageFile); // 加载图像
           QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
           pixmapItem->setPos((*Bullets_view)[i]->getx()-15/2, (*Bullets_view)[i]->gety()-38/2);
           this->addItem(pixmapItem);
        }else if((*Bullets_view)[i]->gett()==1)
        {
            QPixmap pixmap(enemyBulletImageFile);
            QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
            pixmapItem->setPos((*Bullets_view)[i]->getx()-15/2, (*Bullets_view)[i]->gety()-15/2);
            this->addItem(pixmapItem);
        }
        else if((*Bullets_view)[i]->gett()==2)
        {
            QPixmap pixmap(enemyBulletImageFile);
            QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
            pixmapItem->setPos((*Bullets_view)[i]->getx()-10/2,(*Bullets_view)[i]->gety()-23/2);
            this->addItem(pixmapItem);
        }
    }
    for (int i=0;i<(*EnemiesPlane_view).size();i++)
    {
        if((*EnemiesPlane_view)[i]->gett()==0)
        {
           QPixmap pixmap(enemyPlaneImageFile); // 加载图像
           QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
           pixmapItem->setPos((*EnemiesPlane_view)[i]->getx()-90/2, (*EnemiesPlane_view)[i]->gety()-69/2);
           this->addItem(pixmapItem);
        }else if((*EnemiesPlane_view)[i]->gett()==1)
        {
            QPixmap pixmap(bossImageFile);
            QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
            pixmapItem->setPos((*EnemiesPlane_view)[i]->getx()-140/2,(*EnemiesPlane_view)[i]->gety()-140/2);
            this->addItem(pixmapItem);
        }
    }
    for(int i=0;i<(*LifeSupplies_view).size();i++)
    {
        QPixmap pixmap(lifeSupplyImageFile);
        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
        pixmapItem->setPos((*LifeSupplies_view)[i]->getx()-26/2, (*LifeSupplies_view)[i]->gety()-24/2);
        this->addItem(pixmapItem);
    }
    QPixmap pixmap(myPlaneImageFile);
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap); // 创建QGraphicsPixmapItem对象
    pixmapItem->setPos(MyPlane_view->getx()-120/2, MyPlane_view->gety()-79/2);
    this->addItem(pixmapItem);
    if(hasLoseGmae==1)
    {
        if (myBulletShootTimerId > 0) {
            killTimer(myBulletShootTimerId);
            myBulletShootTimerId = -1;
        }
        if (enemyBulletShootTimerId > 0) {
            killTimer(enemyBulletShootTimerId);
            enemyBulletShootTimerId = -1;
        }
        if (allBulletMoveTimerId > 0) {
            killTimer(allBulletMoveTimerId);
            allBulletMoveTimerId = -1;
        }
        if (enemyPlaneMoveTimerId > 0) {
            killTimer(enemyPlaneMoveTimerId);
            enemyPlaneMoveTimerId = -1;
        }
        if (enemyPlaneGenerateTimerId > 0) {
            killTimer(enemyPlaneGenerateTimerId);
            enemyPlaneGenerateTimerId = -1;
        }
        if (bossGenerateTimeId > 0) {
            killTimer(bossGenerateTimeId);
            bossGenerateTimeId = -1;
        }

        maskWidget->show();
        gameLostText->setHtml(tr("<font color=white>Game Over,Your Score: %1</font>").arg(*(PlayerScore)));
        gameLostText->setPos(200, 200);
        QFont font("Arial", 16);
        gameLostText->setFont(font);
        gameLostText->show();
        //retryGameButton->show();
        helpGameButton->show();
        quitGameButton->show();
    }
}

void View::SetPlayerScore(std::shared_ptr<int> a)
{
     PlayerScore=a;
}
void View::SetAllBulletMoveCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdmovebullet=a;
}
void View::SetBossGenerateCommand(std::shared_ptr<ICommandBase>a)
{
    m_cmdgenerateboss=a;
}
void View::SetPlayerGenerateCommand(std::shared_ptr<ICommandBase>a)
{
    m_cmdgeneratemyplane=a;
}
void View::SetEnemyBulletShootCommand(std::shared_ptr<ICommandBase> a)
{
   m_cmdshootenemybullet=a;
}
void View::SetEnemyGenerateCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdgenerateenemyplane=a;
}
void View::SetEnemyMoveCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdmoveenemyplane=a;
}
void View::SetGamePauseCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdgamepause=a;
}
void View::SetGameResetCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdgamereset=a;
}
void View::SetPlayerBulletShootCommand(std::shared_ptr<ICommandBase> a)
{
     m_cmdshootmybullet=a;
}
void View::SetPlayerMoveCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdplanemove=a;
}
void View::SetSkillUseCommand(std::shared_ptr<ICommandBase> a)
{
    m_cmdskilluse=a;
}

void View::SetPlayerLife(std::shared_ptr<BAR> a)
{
    player_life=a;
}

void View::SetPlayerSkill(std::shared_ptr<BAR> a)
{
    player_skill=a;
}
std::shared_ptr<IPropertyNotification> View::GetPropertySink()
{
    return std::static_pointer_cast<IPropertyNotification>(m_propertysink);
}
void View::SetBullets(std::shared_ptr<OBJECTS> a){
    Bullets_view=a;
}

void View::SetLifeSupplies(std::shared_ptr<OBJECTS> a){
    LifeSupplies_view=a;
}
void View::SetMyPlane(std::shared_ptr<Object> a){
    MyPlane_view=a;
}

void View::SetEnemiesPlane(std::shared_ptr<OBJECTS> a){
    EnemiesPlane_view=a;
}
