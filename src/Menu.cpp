#include "Menu.h"
#define MISS 31
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
int Menu::ShowBattleStats(Player* &player, Enemy monster, std::string AreaName, int AreaLevel)
{
    using namespace std;
    string SkillPoint="";
    for (int i=1; i<=player->getSP();i++) SkillPoint+="O ";
    cout<<"AREA: "<<AreaName<<"        AREA LEVEL: "<<AreaLevel<<"\n\n";
    ostringstream screen[5];
    screen[0]<<"    "<<player->getName()<<"        "<<monster.getName()<<endl;
    int max=screen[0].str().length();
    if (max<34) max=34;
    screen[0].str(""); screen[0].clear();
    screen[0]<<"    "<<player->getName()<<setw(max-11-4-player->getName().length())<<""
    <<monster.getName()<<endl;
    screen[1]<<"    "<<setw(4)<<right<<"HP:"<<setw(7)<<player->getHP()<<setw(max-26)<<""
    <<setw(4)<<right<<"HP:"<<setw(7)<<monster.getHP()<<endl;
    screen[2]<<"    "<<setw(4)<<right<<"ATK:"<<setw(7)<<player->getATK()<<setw(max-26)<<""
    <<setw(4)<<right<<"ATK:"<<setw(7)<<monster.getATK()<<endl;
    screen[3]<<"    "<<setw(4)<<right<<"DEF:"<<setw(7)<<player->getDEF()<<setw(max-26)<<""
    <<setw(4)<<right<<"DEF:"<<setw(7)<<monster.getDEF()<<endl;
    screen[4]<<endl<<"Skill Points: "<<SkillPoint<<endl;

    for (int i=0; i<5;i++)    
        std::cout<<screen[i].str();
    std::cout<<endl<<string(max,'-')<<endl;
    return max;
}
void Menu::BattleScreen(Player* &player, Enemy monster, std::string AreaName, int AreaLevel)
{
    system("cls");
    int turn=0;

    //chuan bi status cua player
    player->setSP(3);
    int save_atk=player->getATK(), save_def=player->getDEF();

    do
    {
        system("cls");
        int Battle_Option;
        do
        {
            int max=Menu::ShowBattleStats(player, monster, AreaName, AreaLevel);
            {
                using namespace std;
                std::cout<<"1. [Attack]   | Use your Normal attack. [Gain 1 Skill Point if hit]"<<endl;
                std::cout<<"2. [Skill]    | Power based on your weapon. [Consumes 1 Skill Point]"<<endl;
                std::cout<<"3. [Ultimate] | Use your Ultimate attack. [Consumes 5 Skill Points]"<<endl;
                std::cout<<"4. [Use Item] | Use your Item."<<endl;
                std::cout<<std::endl<<std::string(max,'-')<<std::endl;
            }
            std::cout<<"Choose your action: ";
            //clear_cin();
            std::cin>>Battle_Option;
            std::cout<<std::endl<<std::string(max,'-')<<std::endl;
            if (!(Battle_Option==1||Battle_Option==2||Battle_Option==3||Battle_Option==4)) 
            {
                system("cls");
                Menu::ShowBattleStats(player, monster, AreaName, AreaLevel);
                std::cout<<"There's no such option! Please choose again!";
                Sleep(1500);
                system("cls");
            }
        } while(!(Battle_Option==1||Battle_Option==2||Battle_Option==3||Battle_Option==4));
        system("cls");
        Menu::ShowBattleStats(player, monster, AreaName, AreaLevel);
        try
        {
            int currentSP=player->getSP();
            switch (Battle_Option)
                {
                    case 1:
                    {
                        if (RandomInt(0,127)!=MISS)
                        {
                            player->Attack(monster);
                            if(currentSP<5)
                            player->setSP(currentSP+1);
                        }
                        else std::cout<<"Your attack missed the opponent!\n";
                        break;
                    }
                    case 2:
                    {
                        if (RandomInt(0,127)!=MISS)
                        {
                            if (player->getSP()==0)
                                throw 2;
                            if (player->getWeapon()==nullptr)
                                throw 3;

                            player->Skill(monster);
                            player->setSP(currentSP-1);
                        }
                        else throw 1;
                        break;
                    }
                    case 3:
                    {
                        if (currentSP<5) throw 2;
                        player->Ultimate(monster);
                        player->setSP(currentSP-5);
                        break;
                    }
                    case 4:
                    {
                        if (player->useItem()==0)
                            throw 4;
                        break;
                    }
                }
        }
        catch (int err)
        {
            switch (err)
            {
                case 2:
                    std::cout<<"You do not have enough Skill Points!\n";
                    break;
                case 3:
                    std::cout<<"You do not have any weapon!\n";
                    break;
                case 4:
                    std::cout<<"You do not have any item!\n";
                    break;
            }                
            Sleep(1500);
            continue;
        }
        if (monster.getHP()>0)
            {
                if (RandomInt(0,127)!=MISS)
                    monster.Attack(*player);
                else std::cout<<"The opponent's attack missed!\n";
            }
        turn++;
        system("cls");
    } while(player->getHP()>0 && monster.getHP()>0);
    if (player->getHP()>0) 
    {
        std::cout<<"[COMBAT] CONGRATULATIONS! You have defeated an enemy!";
        Sleep(3000);

        //quay lai chi so cu, neu nhu co tang chi so bang item
        player->setATK(save_atk);
        player->setDEF(save_def);
        player->setSP(3);

        player->gainXP( monster.Give_XP() );
    }
    else
    {
        std::cout<<"\n\n[COMBAT] You have been defeated...\nThis was as far as you can go...\n\nGoing back to main menu...";
        Sleep(3000);
        throw 2;
    }
}