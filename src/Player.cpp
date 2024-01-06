#include"Player.h"

Player::Player(std::string name, int maxhp, int atk, int def, std::string PClass)
        :Character(name, 1, maxhp, atk, def), XP(0.0), Money(0), SP(0),Player_Class(PClass)
{
    this->Player_Item=nullptr;
    this->Player_Weapon=nullptr;
}
Player::~Player()
{
    this->Player_Item=nullptr;
    this->Player_Weapon=nullptr;
}
void Player::Show_Status()
{
    using namespace std;
    ostringstream test_string[4];
    test_string[0]<<left<<setw(6)<<"\nLevel"<<": "<<left<<setw(12)<<this->getLevel()<<left<<setw(5)<<"XP"<<": "<<this->XP;
    test_string[1]<<left<<setw(6)<<"\nHP"<<": "<<left<<setw(12)<<this->getHP()<<left<<setw(5)<<"MaxHP"<<": "<<this->getMaxHP();
    test_string[2]<<left<<setw(6)<<"\nATK"<<": "<<left<<setw(12)<<this->getATK()<<left<<setw(5)<<"DEF"<<": "<<this->getDEF();
    test_string[3]<<left<<setw(6)<<"\nMoney"<<": "<<this->Money<<left<<setw(8)<<" coins"<<left<<setw(5)<<"XP"<<": "<<this->XP<<"/"<<this->getLevel()*100;
    int max=0;
    for (int i=max+1;i<4;i++)
    {
        if(test_string[max].str().length()<=test_string[i].str().length()) max=i;
    }
    int padding=test_string[max].str().length()-13;
    cout<<"\n"<<string(padding/2,'~')<<"PLAYER STATUS"<<string(padding-padding/2,'~');
    for (int i=0;i<4;i++)
    {
        cout<<test_string[i].str();
    }
    cout<<endl<<string(padding+13,'~')<<endl<<endl;
    system("pause");
    system("cls");
}   
int Player::Attack(Enemy &e, int ultiStatus)
{
    if (RandomInt(0,127)!=MISS)
    {
        if (this->Player_Class!="Warrior") ultiStatus=0;
        int atk=this->getATK()*(ultiStatus?1.5:1), def=e.getDEF();

        int damage;
        if(atk <= def) damage = 1;
            else damage=(atk-def)+RandomInt(0,3);

        e.setHP(e.getHP()-damage);
        std::cout<<"[COMBAT] You used Normal attack and dealt "<<damage<<" Damage to the Enemy!\n";
        Sleep(1500);
        return 1;
    }
    else 
    {
        std::cout<<"[COMBAT] Your attack missed the opponent!\n";
        Sleep(1500);
        return 0;
    }
}
int Player::Skill(Enemy &e, int ultiStatus)
{
    if (RandomInt(0,127)!=MISS)
    {
        if (this->Player_Class!="Warrior") ultiStatus=0;
        int atk=this->getATK()*(ultiStatus?1.5:1), def=e.getDEF();

        int damage;
        if(atk <= def) damage = 1;
        else damage=(atk-def)*(1+((this->Player_Weapon!=nullptr)?this->Player_Weapon->getBonusATK():0)/100.0);//*multiplier (dựa trên vũ khí, gây thêm số % damage so với bình thường)

        e.setHP(e.getHP()-damage);
        std::cout<<"[COMBAT] You used Skill and dealt "<<damage<<" Damage to the Enemy!\n";
        Sleep(1500);
        return 1;
    }
    else
    {
        std::cout<<"[COMBAT] Your Skill attack missed the opponent!\n";
        Sleep(1500);
        return 0;
    }
}

void Player::gainXP(int xp_gained)
{
    std::cout<<" You have gained "<<xp_gained<<" XP !\n";
    Sleep(1500);
    this->XP+=xp_gained;
    while(this->XP>=(this->getLevel()*100))
    {
        system("cls");
        this->XP-=(this->getLevel()*100);
        this->Level_Up();
    }
}
int Player::getXP()
{
    return this->XP;
}
void Player::useItem()
{
    this->Player_Item->useItem(*this);
    this->Player_Item=nullptr;
}
std::string Player::returnClass()
{
    return this->Player_Class;
}
int Player::getSP()
{
    return this->SP;
}
void Player::setSP(int sp)
{
    this->SP=sp;
}
void Player::equipWeapon(Weapon* w)
{
    this->Player_Weapon=w;
}
const Weapon *Player::getWeapon()
{
    return this->Player_Weapon;
}
void Player::equipItem(Item *w)
{
    this->Player_Item=w;
}
const Item *Player::getItem()
{
    return this->Player_Item;
}
int Player::getMoney()
{
    return this->Money;
}
void Player::earnMoney(int money)
{
    this->Money+=money;
    if (this->Money<0) this->Money=0;
}