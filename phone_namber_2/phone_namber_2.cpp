#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Phone.h"
#include <cstring>
using namespace std;

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    setlocale(0, "");
    const int max_user = 100;
    int ID = 0;
    Phone user[max_user];
    char input_menu;
    int menu = 0;
    const int size = 4;
    string main_menu[size] = { "Добавить абонента", "Удалить абонента", "Искать абонента", "Показать всех абоненотов" };

    while (true)
    {
        do {
            system("cls");
            for (int i = 0; i < size; i++)
            {
                if (menu == i)
                {
                    setColor(10);
                }
                else
                {
                    setColor(7);
                }
                cout << main_menu[i] << endl;
            }
            input_menu = _getch();
            if (input_menu == 'w' || input_menu == 'W' || input_menu == 'ц' || input_menu == 'Ц')
            {
                menu--;
                if (menu < 0) { menu = size - 1; }
            }
            else if (input_menu == 's' || input_menu == 'S' || input_menu == 'ы' || input_menu == 'Ы')
            {
                menu++;
                if (menu >= 4) { menu = 0; }
            }
            if (input_menu == 'e' || input_menu == 'E') { break; }
        } while (true);

        system("cls");
        switch (menu)
        {
        case 0:
            while (true)
            {
                cout << "Добавление абонента" << endl;
                char choice_add;

                user[ID].setID(ID);
                user[ID].addUser();
                user[ID].Print();

                ID++;
                cout << "Добавить еще:(Y/N) ";
                cin >> choice_add;
                if (choice_add == 'n' || choice_add == 'N') { break; }
            }
            break;
        case 1:
            char choice_remove;
            int id_remove;

            cout << "УДАЛЕНИЕ АБОНЕНТА" << endl;
            cout << "Удаление по (ID): ";

            cin >> id_remove;
            if(choice_remove == 'r'|| choice_remove == 'R'){ break; }
            user[id_remove].Print();
            cout << "Удалить этого абонента(Y/N): ";
            cin >> choice_remove;
            if (choice_remove == 'Y' || choice_remove == 'y') { user[id_remove].removeUser(); }
            break;
        case 2:
            char choice_find;
            int id_find;
            char gag_f;

            cout << "Поиск абонента" << endl;
            cout << "Введите ID: ";

            cin >> id_find;
            if (choice_find == 'r' || choice_find == 'R') { break; }
            user[id_find].Print();
            gag_f = _getch();
            break;
        case 3:
            char gag_a;

            cout << "Вывод всех абонентов" << endl;
            for(int i = 0; i < ID; i++)
            {
                user[i].Print();
            }
            gag_a = _getch();
            break;
        }
    }
}
