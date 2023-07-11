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

std::shared_ptr<SCORE> model::GetPlayerScore()
{
     return this->score;
}

std::shared_ptr<POSES> model::GetBulletsPosX()
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

std::shared_ptr<POSES> model::GetBulletsPosY()
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

std::shared_ptr<BULLETTYPES> model::GetBulletsType()
{
    std::shared_ptr<BULLETTYPES> BulletType = std::make_shared<BULLETTYPES>();
    for(int i=1;i<=(*mybullets).size();++i)
    {
        int p=0;
        BulletType->push_back(&p);
    }
    for(auto it:*enemyplanes)
     {
        int p;
        if(it->type == ORD) p = 1;
         else p = 2;
        BulletType->push_back(&p);
     }
     return BulletType;
}

std::shared_ptr<POSES> model::GetEnemiesPosX()
{
    std::shared_ptr<POSES> enemiePosX = std::make_shared<POSES>();
    for(auto it:*enemyplanes)
    {
        double x2 = it->getx();
        enemiePosX->push_back(&x2);
    }
    return enemiePosX;
}

std::shared_ptr<POSES> model::GetEnemiesPosY()
{
    std::shared_ptr<POSES> enemiePosY = std::make_shared<POSES>();
    for(auto it:*enemyplanes)
    {
        double y2 = it->getx();
        enemiePosY->push_back(&y2);
    }
    return enemiePosY;
}
std::shared_ptr<ENEMYTYPES> model::GetEnemiesType()
{
    std::shared_ptr<ENEMYTYPES> enemieType1 = std::make_shared<ENEMYTYPES>();
    for(auto it:*enemyplanes)
    {
        int t2 = it->gett();
        enemieType1->push_back(&t2);
    }
    return enemieType1;
}
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

bool model::playergenerate()
{
     myplane = new MyPlane(width1/2, height1/2, 50, 5);
     return true;
}

inline bool collidesWithItem(double x0,double y0,double len0,double h0,double x2,double y2,double len2,double h2)
{
    double top0 = y0+h0/2, bot0 = y0-h0/2, left0 = x0-len0/2, right0 = x0+len0/2;
    double top2 = y2+h2/2, bot2 = y2-h2/2, left2 = x2-len2/2, right2 = x2+len2/2;
    if(left0 > right2 || left2 > right0 || bot0 > top2 || bot2 < top0)
       return 0;
    else return 1;
}

bool model::changeBulletPosition(Bullet * bullet, int newX, int newY)
{
    /* 检查位置是否有变化，无变化则返回true */
    if (bullet->x == newX && bullet->y == newY)
        return true;

    /* 检查子弹是否击中某一飞机 */
    /* 首先检查玩家飞机 */
    WarPart part1 = bullet->getp();
    if (part1==ENEMY && collidesWithItem(myplane->x,myplane->y, myplanewidth,myplaneheight,newX,newY,enemybulletwidth, enemybulletheight))
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
            if(collidesWithItem((*it)->x, (*it)->y, enemyplanewidth, enemyplaneheight, newX, newY, mybulletwidth, mybulletheight))
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
                double x = (*it)->x;
                double y = (*it)->y;
                delete *it;
                it = enemyplanes->erase(it);
                /* 25%的概率掉落生命补给 */
                srand(time(NULL));
                if(rand()%4==0)
                {
                    Object *lifeSupply = new Object(x, y, LIFESUPPLY);
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
        bullet->setx(newX);bullet->sety(newY);
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
    return true;
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
                //bullet1->setRotation(45);
                enemybullets->push_back(bullet1);

                Bullet *bullet2 = new Bullet(ENEMY, (*iter)->getx()+bosswidth/2, (*iter)->gety()+bossheight-15,
                                        QPointF(1,1), bossBulletPower);
                //bullet2->setRotation(-45);
                enemybullets->push_back(bullet2);
               // addItem(bullet2);
            }
        }
    return true;
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
    if (plane->x == newX && plane->y == newY)
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
            if(collidesWithItem(newX , newY, myplanewidth, myplaneheight, (*it)->x, (*it)->y, lifesupplywidth, lifesupplyheight))
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
            /* 若为玩家飞机，两架飞机均crash，生命值都减1 */
        if (plane->part == ME && collidesWithItem(newX , newY, myplanewidth, myplaneheight, (*it)->x, (*it)->y, enemyplanewidth, enemyplaneheight) )
        {
                plane->crash();
                alive = (*it)->crash1();
               // updateBar(lifeBar, lifeFrameBar, LifeBarPos, -2, QBrush(Qt::green));
        }
        if (plane->part == ENEMY && collidesWithItem(newX , newY, enemyplanewidth, enemyplaneheight, (*it)->x, (*it)->y, enemyplanewidth, enemyplaneheight)) //若同为敌机，则不允许改变位置，NOCHANGE
                return true;

        if (alive)
            it++;
        else //若飞机坠毁，则将此飞机去掉
        {
            delete *it;
            it = enemyplanes->erase(it);
        }
    }

    /* 若此飞机为敌机，且与玩家飞机发生了碰撞 */
    if (plane->part == ENEMY && collidesWithItem(newX , newY, enemyplanewidth, enemyplaneheight, myplane->x, myplane->y, myplanewidth, myplaneheight))
    {
        myplane->crash();
        plane->crash();
    }

    /* 若plane存活，则更改坐标并同步屏幕 */
    if (plane->life > 0)
    {
        plane->setx(newX);plane->sety(newY);
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
    myplane = new MyPlane(width1 / 2, height1 / 2,  myLife, mySkill);
    /* 添加敌机 */
 /*
    for (int i = 0; i < 3; i++)
        enemygenerate();*/
    return true;
}

bool model::playerbulletshoot()
{
    if((*myBulletType)==0)
    {
        Bullet *bullet = new Bullet(ME, myplane->x+40, myplane->y-38,
                                    QPointF(0,-3), myBulletPower);
        mybullets->push_back(bullet);
       // addItem(bullet);
    }
    else if((*myBulletType)==1)
    {
        Bullet *bullet1 = new Bullet(ME, myplane->x+40, myplane->y-38,
                                    QPointF(-3,-3), myBulletPower);
        mybullets->push_back(bullet1);
        //bullet1->setRotation(-45);
        //addItem(bullet1);

        Bullet *bullet2 = new Bullet(ME, myplane->x+40, myplane->y-38,
                                    QPointF(0,-3), myBulletPower);
        mybullets->push_back(bullet2);
        //addItem(bullet2);

        Bullet *bullet3 = new Bullet(ME, myplane->x+40, myplane->y-38,
                                    QPointF(3,-3), myBulletPower);
        mybullets->push_back(bullet3);
        //bullet3->setRotation(45);
        //addItem(bullet3);
    }
    return true;
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
    changePlanePosition(myplane, myplane->x+myPlaneMove.x(), myplane->y+myPlaneMove.y());
    return true;
}

std::shared_ptr<POSES>  model::GetLifeSuppliesPosX()
{
    std::shared_ptr<POSES>  SuppliesPosX =std::make_shared<POSES>();
    for(auto it:*lifesupplys)
    {
        double x2= it->x;
        SuppliesPosX->push_back(&x2);
    }
    return SuppliesPosX;
}

std::shared_ptr<POSES> model::GetLifeSuppliesPosY()
{
    std::shared_ptr<POSES>  SuppliesPosY =std::make_shared<POSES>();
    for(auto it:*lifesupplys)
    {
        double y2= it->y;
        SuppliesPosY->push_back(&y2);
    }
    return SuppliesPosY;
}

std::shared_ptr<POS> model::GetPlayerPosX()
{
    return std::make_shared<POS>(myplane->x);
}

std::shared_ptr<POS> model::GetPlayerPosY()
{
    return std::make_shared<POS>(myplane->y);
}
