#include "Combat.h"
Combat::Combat(int location, int combattype)
        :Nodes(1,location), CombatType(combattype)
{}

void Combat::Enter(Player* player, Enemy* EnemyList, std::string AreaName, int AreaLevel, Item *ItemList, Weapon *WeaponList)
{
    if (this->CombatType==0) //Danh thuong
    {
        Enemy* temp=EnemyList;
        int count=0;
        while (temp!=nullptr)
        {
            if (temp->IsBoss()==0) count++;
            temp=temp->EnterNext();
        }
        count=RandomInt(1,count);
        temp=EnemyList;
        int target=0;
        while (temp!=nullptr)
        {
            if (temp->IsBoss()==0) target++;
            if (target==count) break;
            else temp=temp->EnterNext();
        }
        Enemy *new_enemy= new Enemy(*temp, AreaLevel);
        system("cls");
        std::cout<<"[GAME] You entered the COMBAT node!\n"
                 <<"[COMBAT] You are facing "<<new_enemy->getName()<<" !\n"
                 <<" Description: "<<new_enemy->Show_Description()<<"\n\n";
        system("pause");
        std::cout<<"\nEntering battle...";
        Sleep(2000);
        Menu::BattleScreen(player,*new_enemy, AreaName, AreaLevel);
    }
    else //Danh boss
    {
        Enemy* temp=EnemyList;
        int count=0;
        while (temp!=nullptr)
        {
            if (temp->IsBoss()==1) count++;
            temp=temp->EnterNext();
        }
        count=RandomInt(1,count);
        temp=EnemyList;
        int target=0;
        while (temp!=nullptr)
        {
            if (temp->IsBoss()==1) target++;
            if (target==count) break;
            else temp=temp->EnterNext();
        }
        Enemy *new_enemy= new Enemy(*temp, AreaLevel);
        system("cls");
        std::cout<<"[GAME] You entered the final node! You are about to face the BOSS\n"
                 <<"[COMBAT] This area's BOSS is "<<new_enemy->getName()<<" !\n"
                 <<" Description: "<<new_enemy->Show_Description()<<"\n\n";
        system("pause");
        std::cout<<"\nGood luck!...";
        Sleep(2000);
        Menu::BattleScreen(player,*new_enemy, AreaName, AreaLevel);
    }
}