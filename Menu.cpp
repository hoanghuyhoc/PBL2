#include "Menu.h"
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
        std::cout<<"1. Start game\n2. Quit game\nEnter your option number:";
        std::cin>>Start_Menu_Option;
        if ((Start_Menu_Option!=1)&&(Start_Menu_Option!=2))
        {
            system("cls");
            std::cout<<"Please enter a valid number!!";
            Sleep(1500);
        }
    }
    while((Start_Menu_Option!=1) && (Start_Menu_Option!=2));
}
void Menu::StartGame(std::string &Player_name, int &class_choice)
{
    system("cls");
    std::cout<<"Choose a name for your character:";
    std::string Player_name;
    std::cin>>Player_name;
    clear_cin();
    std::cout<<"Choose your class:\n1. Warrior\n2. Assassin\n3. Tanker";
    std::cout<<"\nYour choice is:";
    int class_choice;
    std::cin>>class_choice;
}