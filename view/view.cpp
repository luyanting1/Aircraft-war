#include "view.h"
const QPointF scoreTextPos = QPointF(650, 520);
const QPointF LifeBarPos = QPointF(650,550);
const QPointF SkillBarPos = QPointF(650, 570);
const int myBulletShootTimerItv = 300;
const int enemyBulletShootTimerItv = 1000;
const int allBulletMoveTimerItv = 10;

const int myPlaneMoveTimerItv = 30;
const int enemyPlaneMoveTimerItv = 50;
const int enemyPlaneGenerateTimerItv = 3000;
const int bossGenerateTimeItv = 5000;

View::View()
{
    setSceneRect(0,0,800,600);//设置整个界面的大小

    myLife=50;
    //(*player_life) = 50;
    mySkill=5;
    //(*player_skill) = 5;

    this->myBulletImageFile = ":/images/mybullet.png";
    this->enemyPlaneImageFile = ":/images/enemyplane.png";
    this->myPlaneImageFile = ":/images/myplane.png";
    this->bossImageFile = ":/images/boss2.gif";//boss图片



    this->enemyBulletImageFile = ":/images/76446d7d2b8c45cb8ed30baf1f75397e.png";//敌机子弹图片


    this->bossBulletImageFile = ":/images/76446d7d2b8c45cb8ed30baf1f75397e.png";//boss子弹图片

    this->lifeSupplyImageFile = ":/images/lifesupply.png";//补给图片

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
    *PlayerScore = 0;

    //得分显示
    scoreText = new QGraphicsTextItem;
    scoreText->setPos(scoreTextPos);
    scoreText->setHtml(tr("<font color=white>SCORE: %1</font>").arg(*(PlayerScore)));
    scoreText->setFont(QFont("Courier"));
    addItem(scoreText);
    scoreText->hide();


    hasStarted = true;
    titleText->hide();
    startGameButton->hide();
    helpGameButton->hide();
    quitGameButton->hide();
    authorText->hide();
    maskWidget->hide();


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

    /* 设置各动作更新时钟 */
    myPlaneMove = QPointF(0, 0);
    myBulletShootTimerId = startTimer(myBulletShootTimerItv);
    enemyBulletShootTimerId = startTimer(enemyBulletShootTimerItv);
    allBulletMoveTimerId = startTimer(allBulletMoveTimerItv);
    enemyPlaneMoveTimerId = startTimer(enemyPlaneMoveTimerItv);
    enemyPlaneGenerateTimerId = startTimer(enemyPlaneGenerateTimerItv);
    bossGenerateTimeId = startTimer(bossGenerateTimeItv);

    /* 添加玩家飞机 */
    myplane = make_shared<MyPlane>(width() / 2, height() / 2, *player_life, *player_skill);
    this->addItem(((std::shared_ptr<QGraphicsItem>)(myplane)).get());
    /* 添加敌机 */
    for (int i = 0; i < 3; i++)
    {
        enemyplane_generate();
    }
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
        direction="W";
    }
    else if(event->key()==Qt::Key_S && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction="S";
    }
    else if(event->key()==Qt::Key_A && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction="A";
    }
    else if(event->key()==Qt::Key_D && !event->isAutoRepeat())
    {
        if(myPlaneMove==QPointF(0,0))
            myPlaneMoveTimerId = startTimer(myPlaneMoveTimerItv);
        direction="D";
    }
    else if(event->key()==Qt::Key_J && myplane->getskill()>=5)
    {
        //按Q的技能可以一次发射3个子弹，但是会消耗5点技能
        /*
        myBulletType = 1;
        myplane->skill -= 5;
        updateBar(skillBar, skillFrameBar, SkillBarPos, -10, QBrush(Qt::blue));
        */
        skill_use(5);
        skillQTimerId = startTimer(5000); //5秒使用时间
    }
    else if(event->key()==Qt::Key_K && myplane->getskill()>=3)
    {
        //按E的技能可以打掉所有飞机，消耗3点技能值

        /*
        for(vector<EnemyPlane*>::iterator iter=enemyplanes.begin(); iter!=enemyplanes.end(); iter++)
        {
            score++;
            scoreText->setHtml(tr("<font color=white>SCORE: %1</font>").arg(score));
            removeItem(*iter);
            delete *iter;
        }
        enemyplanes.clear();

        myplane->skill -= 3;
        updateBar(skillBar, skillFrameBar, SkillBarPos, -6, QBrush(Qt::blue));
        */
        skill_use(3);
    }
    else if(event->key()==Qt::Key_L && myplane->getskill()>=7)
    {
        //按R可以消掉所有敌机子弹，消耗7点技能值
        /*
        for(vector<Bullet*>::iterator it = enemybullets.begin(); it!= enemybullets.end(); it++)
        {
            removeItem(*it);
            delete *it;
        }
        enemybullets.clear();

        myplane->skill -= 7;

        */
        skill_use(7);
    }
    else if(event->key()==Qt::Key_Space)
        pauseGame();
}
void View::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==myPlaneMoveTimerId)
    {
        myplane_move(direction);
        changescene();
      }  //changePlanePosition(myplane, myplane->x()+myPlaneMove.x(), myplane->y()+myPlaneMove.y());
    if(event->timerId()==enemyBulletShootTimerId)
    {
        enemybullet_shoot();
        changescene();

    }
    else if(event->timerId()==myBulletShootTimerId)
       {
        mybullet_shoot();
        changescene();
    }

    else if(event->timerId()==allBulletMoveTimerId)
    {
        bullet_move();
        changescene();
    }
    else if(event->timerId()==enemyPlaneMoveTimerId)
    {
        enemyplane_move();
        changescene();
    }
    else if(event->timerId()==enemyPlaneGenerateTimerId)
    {
        for(int i=0;i<2;i++)
            enemyplane_generate();
        changescene();
    }
    else if(event->timerId()==bossGenerateTimeId)
    {
        boss_generate();
        changescene();
    }
    else if(event->timerId()==skillQTimerId)
        myBulletType = 0;
}
void View::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_W || event->key()==Qt::Key_S || event->key()==Qt::Key_A || event->key()==Qt::Key_D)
            && !event->isAutoRepeat())
    {
        direction="N";//不移动的时候
        killTimer(myPlaneMoveTimerId);//当飞机不动以后将他的时钟释放掉
    }
}

void View::myplane_move(string direction)
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
           killTimer(myBulletShootTimerId);
           killTimer(enemyBulletShootTimerId);
           killTimer(allBulletMoveTimerId);
           killTimer(enemyPlaneMoveTimerId);
           killTimer(enemyPlaneGenerateTimerId);
           killTimer(bossGenerateTimeId);
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

void View::changescene()
{
    QList<QGraphicsItem *> itemslist = items();
    for (auto item : itemslist) {
        removeItem(item);
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


    for(Bullet* bullet: *Bullets)
    {
       this->addItem(bullet);
    }
    for (EnemyPlane* enemyPlane : *EnemiesPlane)
    {
        this->addItem(enemyPlane);
    }
    for(Object* lifesupply:*LifeSupplies)
    {
        this->addItem(lifesupply);

    }
    this->addItem(((std::shared_ptr<QGraphicsItem>)(myplane)).get());
}
 void View::SetMyPlane(std::shared_ptr<MyPlane> a)
{
      myplane = a;
}
void View::SetEnemiesPlane(std::shared_ptr<vector<EnemyPlane *>>a)
{
     EnemiesPlane=a;
}
void  View::SetBullets(std::shared_ptr<vector<Bullet *>>a)
{
     Bullets=a;
}
void  View::SetLifeSupplies(std::shared_ptr<vector<Object *>>a )
{
     LifeSupplies=a;
}
void View::SetPlayerScore(std::shared_ptr<int> a)
{
     PlayerScore=a;
}

void View::SetAllBulletMoveCommand(shared_ptr<ICommandBase> a)
{
    m_cmdmovebullet=a;
}
void View::SetBossGenerateCommand(shared_ptr<ICommandBase>a)
{
    m_cmdgenerateboss=a;
}
void View::SetEnemyBulletShootCommand(shared_ptr<ICommandBase> a)
{
   m_cmdshootenemybullet=a;
}
void View::SetEnemyGenerateCommand(shared_ptr<ICommandBase> a)
{
    m_cmdgenerateenemyplane=a;
}
void View::SetEnemyMoveCommand(shared_ptr<ICommandBase> a)
{
    m_cmdmoveenemyplane=a;
}
void View::SetGamePauseCommand(shared_ptr<ICommandBase> a)
{
    m_cmdgamepause=a;
}
void View::SetGameResetCommand(shared_ptr<ICommandBase> a)
{
    m_cmdgamereset=a;
}
void View::SetPlayerBulletShootCommand(shared_ptr<ICommandBase> a)
{
     m_cmdshootmybullet=a;
}
void View::SetPlayerMoveCommand(shared_ptr<ICommandBase> a)
{
    m_cmdplanemove=a;
}
void View::SetSkillUseCommand(shared_ptr<ICommandBase> a)
{
    m_cmdskilluse=a;
}
std::shared_ptr<IPropertyNotification> View::get_updateSink(){
    return std::static_pointer_cast<IPropertyNotification>(m_updateSink);
}

void View::SetPlayerLife(shared_ptr<BAR> a)
{
    player_life=a;
}

void View::SetPlayerSkill(shared_ptr<BAR> a)
{
    player_skill=a;
}

