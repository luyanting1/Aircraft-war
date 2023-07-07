#include "model.h"

model::model() {
    score = std::make_shared<int>(0); //得分
    myBulletType = std::make_shared<int>(0);
    enemyplanes = std::make_shared<vector<EnemyPlane *>>();
    enemybullets = std::make_shared<vector<Bullet*>>();
    myplane = new MyPlane();
    mybullets = std::make_shared<vector<Bullet*>>();
    lifesupplys = std::make_shared<vector<Object*>>();
}

std::shared_ptr<POS> model::GetPlayerPosx()
{
     return std::make_shared<POS>(myplane->getx());
}

std::shared_ptr<POS> model::GetPlayerPosy()
{
     return std::make_shared<POS>(myplane->gety());
}

std::shared_ptr<SCORE> model::GetPlayerScore()
{
     return std::make_shared<SCORE>(this->score);
}

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
    for(auto it:*enemybullets)
     {
        pair<WarPart, int>p;
        p.first = ENEMY;
       // p.second = it->gett();
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
}
std::shared_ptr<int> model::GetPlayerLife()
{
    return std::make_shared<int>(myplane->getlife());
}

std::shared_ptr<int> model::GetPlayerSkill()
{
    return std::make_shared<int>(myplane->getskill());
}

bool model::

bool model::framerun()
{

}
