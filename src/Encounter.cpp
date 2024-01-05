#include "Encounter.h"
Encounter::Encounter(int location)
            :Nodes(2,location), EncounterType(RandomInt(1,6))
{}
void Encounter::GatheringStormclouds(Player * this_player)
{
    std::stringstream dialogue;
    dialogue<<"[ENCOUNTER] Gathering Stormclouds\n"
            <<"You've never seen such dense storm clouds before.\n"
            <<"Staring at the nature's onslaught, you asked yourself what to do.\n"
            <<"______________________________________________________________________\n\n"
            <<"	[1] Just pray		    | Heals you to full health\n"
            <<"	[2] Tries to get away   | Gains 30 XP and 5 coins\n"
            <<"______________________________________________________________________\n\n";
    int choice;
    do
    {
        system("cls");    
        std::cout<<dialogue.str()
        <<" Your choice is (choose a number) : ";
        std::cin>>choice;
        if (choice!=1 && choice!=2) 
        {
            system("cls");
            std::cout<<dialogue.str();
            std::cout<<" Option not available !!";
            Sleep(1500);
        }
    } while (choice!=1 && choice!=2);
    system("cls");
    std::cout<<dialogue.str();
    switch (choice)
    {
        case 1:
            if (this_player->getHP()==this_player->getMaxHP())
                std::cout<<" Your HP is already full.\n";
            else
            {
                int heal=this_player->getMaxHP()-this_player->getHP();
                this_player->setHP(this_player->getMaxHP());
                std::cout<<" You have restored "<<heal<<" HP.\n";
            }
            Sleep(1500);
            break;
        case 2:
            this_player->earnMoney(5);
            std::cout<<" You have earned 5 coins. You now have "<<this_player->getMoney()<<" coins.\n";
            Sleep(1500);
            this_player->gainXP(30);
            break;
    }
    system("cls");
}
void Encounter::MysteriousTrader(Player *player, Item *ItemList)
{
    std::stringstream dialogue;
    dialogue<<"[ENCOUNTER] Mysterious Trader\n"
            <<"You entered a small abandoned house and met a person in black cloak.\n"
            <<"That person seems to be a trader. He wants to trade your stuff for some goodies.\n"
            <<"______________________________________________________________________\n\n";
            //<<"[PLAYER] Wallet: "<<player->getMoney()<<" coin"
            //<<( (player->getMoney()>1)? "s" : "" )<<"\n\n";
    Item *itemchoice[3];
    int maxnamelength=0,maxcoinlength=1;
    for (int i=0;i<3;i++)
    {
        Item *ptr=ItemList,*templist=nullptr;
        int count=0;
        while (ptr!=nullptr)
        {
            if (ptr->getLevel()==(i+1))
            {
                count++;
                Item* temp=new Item(count, *ptr);
                temp->InsertIntoList(templist);
            }
            ptr=ptr->EnterNext();
        }
        int target=RandomInt(1,count);
        ptr=templist;
        count=1;
        while (ptr!=nullptr && count!=target)
        {
            ptr=ptr->EnterNext();
            count++;
        }
        itemchoice[i]=new Item(i+1,*ptr);
        Data::DeleteData(templist);

        int namelength=itemchoice[i]->getName().length();
        if (maxnamelength<namelength) maxnamelength=namelength;
        
        std::stringstream coinlength;
        coinlength<<itemchoice[i]->getPrice();
        if (int(coinlength.str().length())>maxcoinlength) maxcoinlength=coinlength.str().length();
    }
    if (maxnamelength<10) maxnamelength=10;
    maxnamelength+=2;
    for (int i=0;i<4;i++)
    {
        if (i<3)
            dialogue<<" ["<<i+1<<"] "<<std::left<<std::setw(maxnamelength)<<itemchoice[i]->getName()<<"| "
                    <<std::right<<std::setw(maxcoinlength)<<itemchoice[i]->getPrice()
                    <<" coin"<<( (itemchoice[i]->getPrice()>1)? "s" : "" )<<" | "
                    <<itemchoice[i]->getDescription()<<"\n";
        else 
            dialogue<<" ["<<i+1<<"] "<<std::left<<std::setw(maxnamelength)<<"No thanks."
                    <<"| Leaves the house.\n";
    }
    dialogue<<"______________________________________________________________________\n\n";
    int status;
    do
    {
        int choice;
        do
        {
            system("cls");
            std::cout<<dialogue.str()
            <<"[PLAYER] Wallet: "<<player->getMoney()<<" coin"
            <<( (player->getMoney()>1)? "s" : "" )<<"\n\n";
            std::cout<<" Your choice is: ";
            
            std::cin>>choice;
            if (choice!=1 && choice!=2 && choice!=3 && choice!=4) 
            {
                system("cls");
                std::cout<<dialogue.str();
                std::cout<<" Option not available !!";
                Sleep(1500);
            }
        } while (choice!=1 && choice!=2 && choice!=3 && choice!=4);
        system("cls");
        std::cout<<dialogue.str();
        switch (choice)
        {
            case 1:
            case 2:
            case 3:
                if (player->getMoney()>=itemchoice[choice-1]->getPrice())
                {
                    std::cout<<"You have received "<<itemchoice[choice-1]->getName()<<" !\n";
                    Sleep(2000);
                    player->equipItem(new Item(*itemchoice[choice-1]));
                    player->earnMoney(-itemchoice[choice-1]->getPrice());
                    status=1;
                }
                else 
                {
                    std::cout<<"You don't have enough money!\n";
                    Sleep(1500);
                    status=0;
                }
                break;
            case 4:
                std::cout<<"You are leaving...";
                Sleep(3000);
                status=1;
                break;
        }
    }while (!status);
    system("cls");
}
void Encounter::AnUnexpectedMeetup(Player *player, Enemy* EnemyList, std::string AreaName, int AreaLevel, Item* ItemList, Weapon* WeaponList)
{
    std::stringstream dialogue;
    dialogue<<"[ENCOUNTER] An Unexpected Meetup\n"
            <<"You were stopped by a strange creature.\n"
            <<"Suddenly, it started charging at you!!\n"
            <<"______________________________________________________________________\n\n"
            <<" [1] Fight it		    | Enters a battle.\n"
            <<" [2] Flee from it     	| Avoids unnecessary fight.\n"
            <<"______________________________________________________________________\n\n";

    int choice;
    do
    {
        system("cls");    
        std::cout<<dialogue.str()
        <<" Your choice is (choose a number) : ";
        std::cin>>choice;
        if (choice!=1 && choice!=2) 
        {
            system("cls");
            std::cout<<dialogue.str();
            std::cout<<" Option not available !!";
            Sleep(1500);
        }
    } while (choice!=1 && choice!=2);
    system("cls");
    std::cout<<dialogue.str();
    switch (choice)
    {
        case 1:
        {
            Combat choice1(this->getLocation(),0);
            choice1.Enter(player, EnemyList, AreaName, AreaLevel, ItemList, WeaponList);
            break;
        }
        case 2:
        {
            std::cout<<" You are leaving...";
            Sleep(2000);
            break;
        }
    }
    system("cls");
}
void Encounter::SlumberInTheCabin(Player *player)
{
    std::stringstream dialogue;
    dialogue<<"[ENCOUNTER] Slumber in the cabin\n"
            <<"You found a wooden cabin located not far from your sight.\n"
            <<"It seems to be in a deteriorating state, but still enough for protection\n"
            <<"from dangers lurking in the dark. You also seems to be really tired now.\n"
            <<"______________________________________________________________________\n\n"
            <<"	[1] Take a rest		    | Heals you to full health and gains 50XP\n"
            <<"	[2] Still not safe      | Gains 200XP\n"
            <<"______________________________________________________________________\n\n";
    int choice;
    do
    {
        system("cls");    
        std::cout<<dialogue.str()
        <<" Your choice is (choose a number) : ";
        std::cin>>choice;
        if (choice!=1 && choice!=2) 
        {
            system("cls");
            std::cout<<dialogue.str();
            std::cout<<" Option not available !!";
            Sleep(1500);
        }
    } while (choice!=1 && choice!=2);
    system("cls");
    std::cout<<dialogue.str();
    switch (choice)
    {
        case 1:
            if (player->getHP()==player->getMaxHP())
                std::cout<<" Your HP is already full.\n";
            else
            {
                int heal=player->getMaxHP()-player->getHP();
                player->setHP(player->getMaxHP());
                std::cout<<" You have restored "<<heal<<" HP.\n";
            }
            Sleep(1500);
            player->gainXP(50);
            break;
        case 2:
            player->gainXP(200);
            break;
    }
    system("cls");
}
void Encounter::Supplies(Player *player)
{
    std::stringstream dialogue;
    dialogue<<"[ENCOUNTER] Supplies\n"
            <<"There is an abandoned house with a lot of stuff left inside.\n"
            <<"You went in to scourge them all.\n"
            <<"______________________________________________________________________\n\n";

    system("cls");
    std::cout<<dialogue.str()
            <<"	You will gain 15 coins and 50XP.\n\n";
    system("pause");
    system("cls");
    std::cout<<dialogue.str();
    player->earnMoney(15);
    std::cout<<" You have earned 15 coins!\n";
    Sleep(1500);
    player->gainXP(50);
    system("cls");
}
void Encounter::Weaponsmith(Player *player, Weapon *WeaponList)
{
    std::stringstream dialogue;
    dialogue<<"[ENCOUNTER] Weaponsmith\n"
            <<"You entered a small garage and met a weapon-making expert.\n"
            <<"Time to get a decent weapon!\n"
            <<"______________________________________________________________________\n\n";
    Weapon *weaponchoice[3];
    int maxnamelength=0,maxcoinlength=1;

    //Random weapon id de tao dsach mua
    Weapon *ptr=WeaponList;
    int count=0;
    while (ptr!=nullptr)
    {
        count++;
        ptr=ptr->EnterNext();
    }
    int target[3];
    target[0]=RandomInt(1,count);
    while (int i=RandomInt(1,count))
    {
        if (i!=target[0]) 
        {
            target[1]=i;
            break;
        }
    }
    while (int i=RandomInt(1,count))
    {
        if (i!=target[0] && i!=target[1]) 
        {
            target[2]=i;
            break;
        }
    }

    //Tim weapon theo ID da random
    for (int i=0;i<3;i++)
    {
        Weapon *ptr=WeaponList;
        while (ptr!=nullptr && ptr->getID()!=target[i])
        {
            ptr=ptr->EnterNext();
        }
        weaponchoice[i]= new Weapon(i+1, *ptr);
        int namelength=weaponchoice[i]->getName().length();
        if (maxnamelength<namelength) maxnamelength=namelength;
        
        std::stringstream coinlength;
        coinlength<<weaponchoice[i]->getPrice();
        if (int(coinlength.str().length())>maxcoinlength) maxcoinlength=coinlength.str().length();
    }

    if (maxnamelength<10) maxnamelength=10;
    maxnamelength+=2;

    for (int i=0;i<4;i++)
    {
        if (i<3)
            dialogue<<" ["<<i+1<<"] "<<std::left<<std::setw(maxnamelength)<<weaponchoice[i]->getName()<<"| "
                    <<std::right<<std::setw(maxcoinlength)<<weaponchoice[i]->getPrice()
                    <<" coin"<<( (weaponchoice[i]->getPrice()>1)? "s" : "" )<<" | "
                    <<weaponchoice[i]->getDescription()<<"\n";
        else 
            dialogue<<" ["<<i+1<<"] "<<std::left<<std::setw(maxnamelength)<<"No thanks."
                    <<"| Leaves the place.\n";
    }
    dialogue<<"______________________________________________________________________\n\n";
    int status;
    do
    {
        int choice;
        do
        {
            system("cls");
            std::cout<<dialogue.str()
            <<"[PLAYER] Wallet: "<<player->getMoney()<<" coin"
            <<( (player->getMoney()>1)? "s" : "" )<<"\n\n";
            std::cout<<" Your choice is: ";
            std::cin>>choice;
            if (choice!=1 && choice!=2 && choice!=3 && choice!=4) 
            {
                system("cls");
                std::cout<<dialogue.str();
                std::cout<<" Option not available !!";
                Sleep(1500);
            }
        } while (choice!=1 && choice!=2 && choice!=3 && choice!=4);
        system("cls");
        std::cout<<dialogue.str();
        switch (choice)
        {
            case 1:
            case 2:
            case 3:
                if (player->getMoney()>=weaponchoice[choice-1]->getPrice())
                {
                    std::cout<<"You have received "<<weaponchoice[choice-1]->getName()<<" !\n";
                    Sleep(2000);
                    player->equipWeapon(new Weapon(*weaponchoice[choice-1]));
                    player->earnMoney(-weaponchoice[choice-1]->getPrice());
                    status=1;
                }
                else 
                {
                    std::cout<<"You don't have enough money!\n";
                    Sleep(1500);
                    status=0;
                }
                break;
            case 4:
                std::cout<<"You are leaving...";
                Sleep(3000);
                status=1;
                break;
        }
    }while (!status);
    system("cls");
}
void Encounter::Enter(Player *player, Enemy *EnemyList, std::string AreaName, int AreaLevel, Item *ItemList, Weapon *WeaponList)
{
    system("cls");
    std::cout<<"[GAME] You entered the ENCOUNTER node!\n";
    Sleep(2000);
    switch (this->EncounterType)
    {
    case 1:
        this->GatheringStormclouds(player);
        break;
    case 2:
        this->MysteriousTrader(player,ItemList);
        break;
    case 3:
        this->AnUnexpectedMeetup(player, EnemyList, AreaName, AreaLevel, ItemList, WeaponList);
        break;
    case 4:
        this->SlumberInTheCabin(player);
        break;
    case 5:
        this->Supplies(player);
        break;
    case 6:
        this->Weaponsmith(player, WeaponList);
        break;
    }
} 