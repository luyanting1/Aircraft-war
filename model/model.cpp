#include "model.h"
/*
const int myBulletShootTimerItv = 300;
const int enemyBulletShootTimerItv = 1000;
const int allBulletMoveTimerItv = 10;

const int myPlaneMoveTimerItv = 30;
const int enemyPlaneMoveTimerItv = 50;
const int enemyPlaneGenerateTimerItv = 3000;
const int bossGenerateTimeItv = 5000;*/

model::model() {
    score = std::make_shared<int>(0); //得分
    myBulletType = std::make_shared<int>(0);
    enemyplanes = std::make_shared<vector<EnemyPlane *>>();
    enemybullets = std::make_shared<vector<Bullet*>>();
    myplane = new MyPlane();
    myplane->setlife(50);
    myplane->setskill(5);
    this->myBulletPower = 1;
    this->enemyLife = 1;
    this->enemyBulletPower = 1;
    this->bossLife = 10;
    this->bossBulletPower = 2;
    this->myLife = 50;
    this->mySkill = 5;
    mybullets = std::make_shared<vector<Bullet*>>();
    lifesupplys = std::make_shared<vector<Object*>>();
}

std::shared_ptr<MyPlane> model::GetMyPlane()
{
    return std::make_shared<MyPlane>(myplane);
}

std::shared_ptr<vector<Bullet *>> model::GetBullets()
{
    return std::make_shared<vector<Bullet *>>(mybullets);
}

std::shared_ptr<vector<EnemyPlane *>> model::GetEnemiesPlane()
{
    return std::make_shared<vector<EnemyPlane *>>(enemyplanes);
}

std::shared_ptr<SCORE> model::GetPlayerScore()
{
     return std::make_shared<SCORE>(this->score);
}
/*
std::shared_ptr<POSES> model::GetBulletPosX()
{
     std::shared_ptr<POSES> BulletPosX = std::make_shared<POSES>();
     for(auto it:*mybullets)
     {
         double x2 = it->getx();
         BulletPosX->push_back(&x2);
     }
     for(auto it:*enemybullets)
     {
         double x2 = it->getx();
         BulletPosX->push_back(&x2);
     }
     return BulletPosX;
}

std::shared_ptr<POSES> model::GetBulletPosY()
{
    std::shared_ptr<POSES> BulletPosY = std::make_shared<POSES>();
    for(auto it:*mybullets)
    {
        double y2 = it->gety();
        BulletPosY->push_back(&y2);
    }
    for(auto it:*enemybullets)
    {
        double y2 = it->gety();
        BulletPosY->push_back(&y2);
    }
    return BulletPosY;
}

std::shared_ptr<BULLETTYPES> model::GetBulletType()
{
    std::shared_ptr<BULLETTYPES> BulletType = std::make_shared<BULLETTYPES>();
    for(auto it:*mybullets)
    {
        pair<WarPart, int>p;
        p.first = ME;
        p.second = *myBulletType;
        BulletType->push_back(&p);
    }
    for(auto it:*enemyplanes)
     {
        pair<WarPart, int>p;
        p.first = ENEMY;
        p.second = it->gett();
        BulletType->push_back(&p);
     }
     return BulletType;
}

std::shared_ptr<POSES> model::GetEmemiePosX()
{
    std::shared_ptr<POSES> EmemiePosX = std::make_shared<POSES>();
    for(auto it:*enemyplanes)
    {
        double x2 = it->getx();
        EmemiePosX->push_back(&x2);
    }
    return EmemiePosX;
}

std::shared_ptr<POSES> model::GetEmemiePosY()
{
    std::shared_ptr<POSES> EmemiePosY = std::make_shared<POSES>();
    for(auto it:*enemyplanes)
    {
        double y2 = it->getx();
        EmemiePosY->push_back(&y2);
    }
    return EmemiePosY;
}
std::shared_ptr<ENEMYTYPES> model::GetEmemieType()
{
    std::shared_ptr<ENEMYTYPES> EmemieType1 = std::make_shared<ENEMYTYPES>();
    for(auto it:*enemyplanes)
    {
        int t2 = it->gett();
        EmemieType1->push_back(&t2);
    }
    return EmemieType1;
}*/
std::shared_ptr<int> model::GetPlayerLife()
{
    return std::make_shared<int>(myplane->getlife());
}

std::shared_ptr<int> model::GetPlayerSkill()
{
    return std::make_shared<int>(myplane->getskill());
}

bool model::skilluse(int sk_index)
{
    int _skill = myplane->getskill();
    if(sk_index>_skill)
         return 0;
    myplane ->setskill(_skill-sk_index);
    switch(sk_index)
    {
       case 3:
         *myBulletType = 1;
       break;
       case 5:
         for(auto iter: *enemyplanes)
         {
            (*score)++;
             delete iter;
         }
         enemyplanes->clear();
       break;
       case 7:
         for(auto iter: *enemybullets)
            delete iter;
         enemybullets->clear();
       break;
       default: return 0;
    }
    return 1;
}

bool model::changeBulletPosition(Bullet * bullet, int newX, int newY)
{
    /* 检查位置是否有变化，无变化则返回true */
    if (bullet->x() == newX && bullet->y() == newY)
        return true;

    /* 检查子弹是否击中某一飞机 */
    /* 首先检查玩家飞机 */
    WarPart part1 = bullet->getp();
    if (part1==ENEMY && bullet->collidesWithItem(myplane))
    {
        /*bullet->hit(this);
        myplane->crash(this);
        updateBar(lifeBar, lifeFrameBar, LifeBarPos, -2, QBrush(Qt::green));*/
        int life1 = myplane->getlife();
        --life1;
        myplane->setlife(life1);
    }
    else if(part1==ME)
    {
        //vector<EnemyPlane *> *enemyplanes1 = enemyplanes.get();
        //MyPlane *enplane;
        /* 然后检查敌机：若敌机已经没有生命值，就从enemyplanes中删去 */
        for (vector<EnemyPlane*>::iterator it = enemyplanes->begin(); it != enemyplanes->end();)
        {
            bool alive = true;
            if(bullet->collidesWithItem((const QGraphicsItem *)(*it)))
            {
                //alive = (*it)->crash(this);
                myplane->setskill(myplane->getskill()+1);
               // updateBar(skillBar, skillFrameBar, SkillBarPos, +2, QBrush(Qt::blue));
                (*score)++;
              //  scoreText->setHtml(tr("<font color=white>SCORE: %1</font>").arg(score));
            }

            if(alive)
                it++;
            else
            {
                delete *it;
                it = enemyplanes->erase(it);
                /* 25%的概率掉落生命补给 */
                srand(time(NULL));
                if(rand()%4==0)
                {
                    Object *lifeSupply = new Object(LIFESUPPLY);
                    lifeSupply->setPos(bullet->pos());
                    lifesupplys->push_back(lifeSupply);
                }
            }
        }
    }

    /* 若子弹还具有杀伤力则更新位置并同步屏幕 */
    if (bullet->getpower() > 0)
    {
        /* 若此时子弹试图打出边界，则销毁子弹 */
        if (newX <= 0 || newX >= width1 || newY <= 0 || newY >= height1)
            return false;
       // bullet->synScreen(this);
        bullet->moveBy(newX-bullet->x(), newY-bullet->y());
        bullet->update();
    }

    return bullet->getpower()>0;
}


bool model::allbulletmove()
{
    for(vector<Bullet*>::iterator it = (*enemybullets).begin(); it!=(*enemybullets).end(); )
    {
        pair<int ,int> loc = (*it)->updatePosition();
        if(changeBulletPosition(*it, loc.first, loc.second))
            it++;
        else
        {
            delete *it;
            it = enemybullets->erase(it);
        }
    }
    for(vector<Bullet*>::iterator it = enemybullets->begin(); it!=enemybullets->end(); )
    {
        pair<int ,int> loc = (*it)->updatePosition();
        if(changeBulletPosition(*it, loc.first, loc.second))
            it++;
        else
        {
            delete *it;
            it = enemybullets->erase(it);
        }
    }
}

bool model::bossgenerate()
{
    /* 随机在第一行生成敌机 */
    srand(time(NULL));//初始化时间种子
    int cnt = 0;
    int x = rand() % width1; //敌机最左端位置
    for(cnt=0;cnt<100;cnt++)
    {
        bool flag = true; //此位置是否合法
        for(auto iter:*enemyplanes)
        {
            QGraphicsItem *iter1 =(QGraphicsItem *)(iter);
            if(iter1->sceneBoundingRect().intersects(QRectF(x, 0, bosswidth, bossheight)))
            {
                flag = false;
                break;
            }
        }

        if(flag)
            break;
        else
            x = rand() % width1;
    }

    /* 若生成100次随机都未能找到合适的位置则退出 */
    if(cnt>=100)
        return false;

    /* 新增敌机 */
    EnemyPlane *enemy = new EnemyPlane(x, 0, BOSS, 10);
    enemyplanes->push_back(enemy);
    return true;
}

bool model::enemybulletshoot()
{
    for (vector<EnemyPlane*>::iterator iter = enemyplanes->begin(); iter != enemyplanes->end(); iter++)
        if ((*iter)->getl() > 0)
        {
            if((*iter)->type==ORD)
            {
                Bullet *bullet = new Bullet(ENEMY, (*iter)->getx()+enemyplanewidth/2, (*iter)->gety()+enemyplaneheight-15,
                                         QPointF(0,1), enemyBulletPower);
                enemybullets->push_back(bullet);
              //  addItem(bullet);
            }
            else if((*iter)->type==BOSS)
            {
                Bullet *bullet0 = new Bullet(ENEMY, (*iter)->getx()+bosswidth/2, (*iter)->gety()+bossheight-15,
                                         QPointF(0,1), bossBulletPower);
                enemybullets->push_back(bullet0);

                Bullet *bullet1 = new Bullet(ENEMY, (*iter)->getx()+bosswidth/2, (*iter)->gety()+bossheight-15,
                                         QPointF(-1,1), bossBulletPower);
                bullet1->setRotation(45);
                enemybullets->push_back(bullet1);

                Bullet *bullet2 = new Bullet(ENEMY, (*iter)->getx()+bosswidth/2, (*iter)->gety()+bossheight-15,
                                        QPointF(1,1), bossBulletPower);
                bullet2->setRotation(-45);
                enemybullets->push_back(bullet2);
               // addItem(bullet2);
            }
        }
}

bool model::enemygenerate()
{
    srand(time(NULL));//初始化时间种子
    //QPixmap pixmap(QPixmap(QString::fromStdString(enemyPlaneImageFile)));
    int cnt = 0;
    int x = rand() % (int)width1; //敌机最左端位置
    for(cnt=0;cnt<100;cnt++)
    {
        bool flag = true; //此位置是否合法
        for(auto iter:*enemyplanes)
        {
            QGraphicsItem *iter1 =(QGraphicsItem *)(iter);
            if(iter1->sceneBoundingRect().intersects(QRectF(x, 0, enemyplanewidth, enemyplaneheight)))
            {
                flag = false;
                break;
            }
        }

        if(flag)
            break;
        else
            x = rand() % width1;
    }

    /* 若生成100次随机都未能找到合适的位置则退出 */
    if(cnt>=100)
        return false;

    /* 新增敌机 */
    EnemyPlane *enemy = new EnemyPlane(x, 0, ORD, enemyLife);
    enemyplanes->push_back(enemy);
    return true;
}


bool model::changePlanePosition(Plane *plane, int newX, int newY)
{
    /* 检查位置是否有变化，无变化则直接返回 */
    if (plane->x() == newX && plane->y() == newY)
        return true;

    /* 检查新位置是否合法，不合法则直接返回 */
    if (newX<0 || newX>width1 || newY<0 || newY>height1)
    {
        if (plane->part == ME) //玩家飞机不允许出界
            return true;
        else if (plane->part == ENEMY) //敌机不允许出上界、左界、右界，但出下界之后将被删除
        {
            if (newY>height1)
                return false;
            else
                return true;
        }
    }

    /* 若为玩家飞机，则首先检查是否与补给碰撞，遇到生命补给则+5 */
    if(plane->part==ME)
        for(vector<Object*>::iterator it=lifesupplys->begin();it!=lifesupplys->end(); )
        {
            if(plane->collidesWithItem(*it))
            {
                plane->life = min(plane->life+10, myLife);
                delete *it;
                it = lifesupplys->erase(it);
            }
            else
                it++;
        }

    /* 检查新位置是否与某一飞机位置冲突 */
    /* 首先检查是否与敌机碰撞 */
    for (vector<EnemyPlane*>::iterator it = enemyplanes->begin(); it != enemyplanes->end(); ) //遍历敌机
    {
        if (plane == (Plane *)(*it)) //跳过自己
        {
            it++;
            continue;
        }

        bool alive = true; //it所指向的飞机是否还有生命值
        if (plane->collidesWithItem((QGraphicsItem *)(*it)))
        {
            /* 若为玩家飞机，两架飞机均crash，生命值都减1 */
            if (plane->part == ME)
            {
                plane->crash();
                alive = (*it)->crash1();
               // updateBar(lifeBar, lifeFrameBar, LifeBarPos, -2, QBrush(Qt::green));
            }
            if (plane->part == ENEMY) //若同为敌机，则不允许改变位置，NOCHANGE
                return true;
        }

        if (alive)
            it++;
        else //若飞机坠毁，则将此飞机去掉
        {
            delete *it;
            it = enemyplanes->erase(it);
        }
    }

    /* 若此飞机为敌机，且与玩家飞机发生了碰撞 */
    if (plane->part == ENEMY && plane->collidesWithItem(myplane))
    {
        myplane->crash();
        plane->crash();
    }

    /* 若plane存活，则更改坐标并同步屏幕 */
    if (plane->life > 0)
    {
        plane->moveBy(newX-plane->x(), newY-plane->y());
        plane->update();
    }

    return plane->life > 0;
}

bool model::enemymove()
{
    if ((*enemyplanes).size() < 1)
    {
        int genNum = rand() % 3;
        for (int i = 0; i < genNum; i++)
            enemygenerate();
    }

    /* 所有敌机移动位置 */
    for (vector<EnemyPlane*>::iterator it = enemyplanes->begin(); it != enemyplanes->end(); )
    {
        //qDebug() << it-enemyplanes.begin() << "  (" << (*it)->x() << "," << (*it)->y() << ")";
        pair<int, int> loc = (*it)->updatePosition();
        if (changePlanePosition((Plane *)(*it), loc.first, loc.second))
            it++;
        else
            it = enemyplanes->erase(it);
    }

    return myplane->life > 0;
}

bool model::gamereset()
{
    score = std::make_shared<int>(0); //得分
    myBulletType = std::make_shared<int>(0);
    enemyplanes = std::make_shared<vector<EnemyPlane *>>();
    enemybullets = std::make_shared<vector<Bullet*>>();
    myplane = new MyPlane();
    myplane->setlife(50);
    myplane->setskill(5);
    this->myBulletPower = 1;
    this->enemyLife = 1;
    this->enemyBulletPower = 1;
    this->bossLife = 10;
    this->bossBulletPower = 2;
    this->myLife = 50;
    this->mySkill = 5;
    mybullets = std::make_shared<vector<Bullet*>>();
    lifesupplys = std::make_shared<vector<Object*>>();
    myplane = new MyPlane(width1 / 2, height1 / 2, myLife, mySkill);
    /* 添加敌机 */
    for (int i = 0; i < 3; i++)
        enemygenerate();
}

bool model::playerbulletshoot()
{
    if((*myBulletType)==0)
    {
        Bullet *bullet = new Bullet(ME, myplane->x()+40, myplane->y()-38,
                                    QPointF(0,-3), myBulletPower);
        mybullets->push_back(bullet);
       // addItem(bullet);
    }
    else if((*myBulletType)==1)
    {
        Bullet *bullet1 = new Bullet(ME, myplane->x()+40, myplane->y()-38,
                                    QPointF(-3,-3), myBulletPower);
        mybullets->push_back(bullet1);
        bullet1->setRotation(-45);
        //addItem(bullet1);

        Bullet *bullet2 = new Bullet(ME, myplane->x()+40, myplane->y()-38,
                                    QPointF(0,-3), myBulletPower);
        mybullets->push_back(bullet2);
        //addItem(bullet2);

        Bullet *bullet3 = new Bullet(ME, myplane->x()+40, myplane->y()-38,
                                    QPointF(3,-3), myBulletPower);
        mybullets->push_back(bullet3);
        bullet3->setRotation(45);
        //addItem(bullet3);
    }
}

bool model::playermove(char dir)
{
    switch(dir)
    {
     case 'W': myPlaneMove = QPointF(0, -10); break;
     case 'S': myPlaneMove = QPointF(0, 10); break;
     case 'A': myPlaneMove = QPointF(-10, 0); break;
     case 'D': myPlaneMove = QPointF(10, 0); break;
     default: myPlaneMove = QPointF(0, 0); break;
    }
    changePlanePosition(myplane, myplane->x()+myPlaneMove.x(), myplane->y()+myPlaneMove.y());
}


