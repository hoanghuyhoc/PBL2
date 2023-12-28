#include "Menu.h"
void clear_cin()
{
    using namespace std;
    std::cin.clear();
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int Menu::StartMenu()
{
    int Start_Menu_Option;
    do
    {
        system("cls");
        std::cout<<"            _______________________________________________________________________________\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |                                 TEXT DUNGEONS                                 |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |      ___________________________________________________________________      |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |                           [1] Enter the Dungeons                              |\n";
        std::cout<<"           |                           [2] Exit game                                       |\n";
        std::cout<<"           |      ___________________________________________________________________      |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |                                           Made by Hoang Huy Hoc               |\n";
        std::cout<<"           |                                                   Le Quang Hung               |\n";
        std::cout<<"           |_______________________________________________________________________________|\n";
        std::cout<<                 "Enter your option: ";
        std::cin>>Start_Menu_Option;
        if ((Start_Menu_Option!=1)&&(Start_Menu_Option!=2))
        {
            system("cls");
            std::cout<<"Please enter a valid number!!";
            Sleep(1500);
        }
        if (Start_Menu_Option==2) 
        {
            system("cls");
            std::cout<<"Exiting...\nThank you for playing!";
            Sleep(3000);
        }
        if (Start_Menu_Option==1)
        {
            system("cls");
            std::cout<<"Game starting...";
            Sleep(2000);
        }
    } while ((Start_Menu_Option!=1)&&(Start_Menu_Option!=2));
    return Start_Menu_Option;
}
void Menu::StartGame(Player *&player)
{
    system("cls");
    std::cout<<"Tell us your name: ";
    std::string Player_name;
    clear_cin();
    std::getline(std::cin,Player_name,'\n');
    system("cls");
    std::cout<<"            _______________________________________________________________________________\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |                              CHOOSE YOUR CLASS                                |\n";
    std::cout<<"           |      ___________________________________________________________________      |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |        [1] Warrior                                                            |\n";
    std::cout<<"           |        Both proficient in offense and defense                                 |\n";
    std::cout<<"           |        ULTIMATE: Deals damage and increases ATK in the next 2 turns.          |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |        [2] Tank                                                               |\n";
    std::cout<<"           |        Extreme sturdiness along with self-recovery                            |\n";
    std::cout<<"           |        ULTIMATE: Heals for a proportion of max HP and increases DEF in        |\n";
    std::cout<<"           |        the next 2 turns.                                                      |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |        [3] Assassin                                                           |\n";
    std::cout<<"           |        Fragile but deadly.                                                    |\n";
    std::cout<<"           |        ULTIMATE: Deals a large amount of damage. If the ultimate defeats      |\n";
    std::cout<<"           |        an enemy, regains 1 Skill Point.                                       |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |      ___________________________________________________________________      |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |                                                                               |\n";
    std::cout<<"           |_______________________________________________________________________________|\n\n";
    std::cout<<"Select [1,2,3]: ";
    int class_choice;
    std::cin>>class_choice;
    std::cout<<"\n";
    switch(class_choice)
    {
        case 1:
        {
            std::cout << "You've chosen Warrior! Good luck!\n";
            Sleep(2000);
            player=dynamic_cast<Player*>(new Warrior(Player_name));
            break;
            // setMaxHP(100);
            // setHP(100);
            // setATK(20);
            // setDEF(5);
        }
        case 2:
        {
            std::cout << "You've chosen Tank! Good luck!";
            Sleep(2000);
            player=dynamic_cast<Player*>(new Tank(Player_name));
            break;
            // setMaxHP(150);
            // setHP(150);
            // setATK(10);
            // setDEF(10);
        }
        case 3:
        {
            std::cout << "You've chosen Assassin! Good luck!";
            Sleep(2000);
            player=dynamic_cast<Player*>(new Assassin(Player_name));
            break;
            // setMaxHP(80);
            // setHP(80);
            // setATK(30);
            // setDEF(2);
        }
    }
}
void Menu::BattleScreen(Player* &player, Enemy monster, std::string AreaName, int AreaLevel)
{
    system("cls");
    std::cout<<"[GAME] You have encounter an enemy!\n";
    Sleep(1500);
    int turn=0;
    do
    {
        system("cls");
        int Battle_Option;
        do
        {
            using namespace std;
            cout<<"Area: "<<AreaName<<"     Level: "<<AreaLevel<<endl;
            ostringstream screen[4];
            screen[0]<<"    "<<player->getName()<<"        "<<monster.getName()<<endl;
            int max=screen[0].str().length();
            if (max<34) max=34;
            screen[0].str(""); screen[0].clear();
            screen[0]<<"    "<<player->getName()<<setw(max-11-4-player->getName().length())<<""
            <<monster.getName()<<endl;
            screen[1]<<"    "<<setw(4)<<left<<"HP:"<<setw(7)<<player->getHP()<<setw(max-26)<<""
            <<setw(4)<<left<<"HP:"<<setw(7)<<monster.getHP()<<endl;
            screen[2]<<"    "<<setw(4)<<left<<"ATK:"<<setw(7)<<player->getATK()<<setw(max-26)<<""
            <<setw(4)<<left<<"ATK:"<<setw(7)<<monster.getATK()<<endl;
            screen[3]<<"    "<<setw(4)<<left<<"DEF:"<<setw(7)<<player->getDEF()<<setw(max-26)<<""
            <<setw(4)<<left<<"DEF:"<<setw(7)<<monster.getDEF()<<endl;
            for (int i=0; i<4;i++)    
                std::cout<<screen[i].str();
            std::cout<<string(max,'-')<<endl<<endl;
            std::cout<<"1. [Attack]    | Use your Normal attack"<<endl<<setw(4)<<""<<"Choose your action:";
            clear_cin();
            std::cin>>Battle_Option;
            std::cout<<std::endl<<string(max,'-')<<std::endl;
            if (Battle_Option!=1) 
            {
                std::cout<<"\nThere's no such option! Please choose again!\n";
                Sleep(1500);
                system("cls");
            }
        } while(Battle_Option!=1);
        if (Battle_Option==1) player->Attack(monster);
        if (monster.getHP()>0) monster.Attack(*player);
        turn++;
        system("cls");
    } while(player->getHP()>0 && monster.getHP()>0);
    if (player->getHP()>0) 
    {
        std::cout<<"[COMBAT] CONGRATULATIONS! You have defeated an enemy!";
        Sleep(3000);
        player->gainXP( monster.Give_XP() );
        player->setHP(player->getMaxHP());
    }
    if (player->getHP()<=0)
    {
        std::cout<<"\n\n[COMBAT] You have been defeated...";
        Sleep(3000);
        throw 2;
    }
}