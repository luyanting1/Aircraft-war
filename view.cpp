#include "view.h"
const QPointF scoreTextPos = QPointF(650, 520);
const QPointF LifeBarPos = QPointF(650,550);
const QPointF SkillBarPos = QPointF(650, 570);
View::View()
{
    setSceneRect(0,0,800,600);//设置整个界面的大小
    this->myPlaneImageFile = ":/images/myplane.png";//飞机图片
    this->myLife = 50;
    this->mySkill = 5;

    this->myBulletImageFile = ":/images/mybullet.png";//子弹图片
    this->myBulletPower = 1;

    this->enemyPlaneImageFile = ":/images/enemyplane.png";//敌机图片
    this->enemyLife = 1;

    this->enemyBulletImageFile = ":/images/enemybullet.png";//敌机子弹图片
    this->enemyBulletPower = 1;

    this->bossImageFile = ":/images/boss.png";//boss图片
    this->bossLife = 10;

    this->bossBulletImageFile = ":/images/bossbullet.png";//boss子弹图片
    this->bossBulletPower = 2;

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
       //connect(startGameBtn,SIGNAL(clicked()),this,SLOT(startGame()));
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
    /*
    score = 0;
    scoreText->setHtml(tr("<font color=white>SCORE: %1</font>").arg(score));

    hasStarted = true;
    titleText->hide();
    startGameButton->hide();
    helpGameButton->hide();
    quitGameButton->hide();
    authorText->hide();
    maskWidget->hide();

    scoreText->show();
    lifeFrameBar->show();
    lifeBar->setRect(LifeBarPos.x(), LifeBarPos.y(), myLife*2, lifeBar->rect().height());
    lifeBar->setBrush(Qt::green);
    lifeBar->update();
    lifeBar->show();

    skillFrameBar->show();
    skillBar->setRect(SkillBarPos.x(), SkillBarPos.y(), mySkill*2, skillBar->rect().height());
    skillBar->setBrush(Qt::blue);
    skillBar->update();
    skillBar->show();

    /* 设置各动作更新时钟 */
    /*
    myPlaneMove = QPointF(0, 0);
    myBulletShootTimerId = startTimer(myBulletShootTimerItv);
    enemyBulletShootTimerId = startTimer(enemyBulletShootTimerItv);
    allBulletMoveTimerId = startTimer(allBulletMoveTimerItv);
    enemyPlaneMoveTimerId = startTimer(enemyPlaneMoveTimerItv);
    enemyPlaneGenerateTimerId = startTimer(enemyPlaneGenerateTimerItv);
    bossGenerateTimeId = startTimer(bossGenerateTimeItv);

    /* 添加玩家飞机 */
    /*
    myplane = new MyPlane(width() / 2, height() / 2, myPlaneImageFile, this, myLife, mySkill);
    myplane->synScreen(this);

    /* 添加敌机 */
    /*
    for (int i = 0; i < 3; i++)
        generateEnemyPlane();
        */
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
