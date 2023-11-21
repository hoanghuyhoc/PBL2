#include "Menu.h"
#include "Character.h"
void clear_cin()
{
    using namespace std;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void Menu::StartMenu(int &Start_Menu_Option)
{
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
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |                            PRESS ANY KEY TO START                             |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |      ___________________________________________________________________      |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |                                           Made by ...                         |\n";
        std::cout<<"           |                                                                               |\n";
        std::cout<<"           |_______________________________________________________________________________|\n";

        std::cin>>Start_Menu_Option;
        if ((Start_Menu_Option!=1)&&(Start_Menu_Option!=2))
        {
            system("cls");
            std::cout<<"Please enter a valid number!!";
            Sleep(1500);
        }
    }
    while((Start_Menu_Option!=1) && (Start_Menu_Option!=2));
    // Sau thay bằng hàm void pressAnyKey(); để tự động clear màn hình khi bấm phím bất kỳ

}
void Menu::StartGame(std::string &Player_name, int &class_choice)
{
    // Sau thêm vào hàm chạy story mở đầu game
    system("cls");
    std::cout<<"    Type your name:";
    std::string Player_name;
    std::cin>>Player_name;
    clear_cin();
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
    std::cout<<"           |_______________________________________________________________________________|\n";
    std::cout<<"            Select [1,2,3]: ";
    int class_choice;
    std::cin>>class_choice;
    switch(class_choice){
        case 1:
        {
            std::cout << "You've chosen Warrior! Good luck!";
            // setMaxHP(100);
            // setHP(100);
            // setATK(20);
            // setDEF(5);
        }
        case 2:
        {
            std::cout << "You've chosen Tank! Good luck!";
            // setMaxHP(150);
            // setHP(150);
            // setATK(10);
            // setDEF(10);
        }
        case 3:
        {
            std::cout << "You've chosen Assassin! Good luck!";
            // setMaxHP(80);
            // setHP(80);
            // setATK(30);
            // setDEF(2);
        }
    }
}