#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


struct Date
{
    unsigned short Day; // день
    unsigned short Month; // месяц
    unsigned short Year; // год
};

struct Inicialy
{
    string Name; // имя
    string SurName; // фамилия
    string Otche; // отчество
    Date MyDate = { 0, 0, 0 };
};

struct GP
{
    unsigned short GPyear; // год поступления в вуз
};

struct Kaf
{
    string Kafedra; // название кафедры
};

struct Groups
{
    string NumGroup; // номер группы
};

struct NumZatchet
{
    string Zachet; // номер зачётной книжки
};

struct Gender
{
    string Pol; // пол студента
};

struct Session
{
    string subjectNames[10] = { }; // названия предметов 
    int grades[10] = { }; // оценки по каждому предмету в каждой сессии 
};

struct User
{
    Inicialy Inicy;
    GP Group = { 0 };
    Kaf Kafedrs;
    Groups Gru;
    NumZatchet Zach;
    Gender SO;
    Session sessions[9] = { }; // максимально 9 сессий
};

int age(int day, int month, int year, int Group)
{
    int current_day = 20; // дата начала приёма документов в вуз
    int current_month = 6;
    int current_year = Group;
    int ages = current_year - year;
    if (month > current_month || (month == current_month && day > current_day))
    {
        ages--;
    }
    return ages;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    User* users = nullptr;
    int numUsers = 0; // счётчик количества студентов
    int capacity = 0; // вместимость студентов

    int choice;
    do
    {
        cout
            << "--------------------------------------------------\n"
            << "Программа по заполнению данных о студентах РТУ МИРЭА.\n"
            << "Выберите действие:\n"
            << "1. Ввод пользователей\n"
            << "2. Вывод всех пользователей\n"
            << "3. Редактировать данные пользователей\n"
            << "4. Удалить пользователя\n"
            << "0. Выход\n--------------------------------------------------\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Введите данные о студенте: ";
            /*while (true)
            {*/
            User user;
            cout << "\nИмя: ";
            cin >> user.Inicy.Name;
            cin.clear();
            /*if (user.Inicy.Name == "0")
            {
                break;
            }*/
            int ch = 0;
            while ((ch = cin.get() != '\n' && ch != EOF));
            cout << "Фамилия: ";
            cin >> user.Inicy.SurName;
            cin.clear();
            while ((ch = cin.get() != '\n' && ch != EOF));
            cout << "Отчество: ";
            cin >> user.Inicy.Otche;
            cin.clear();
            while ((ch = cin.get() != '\n' && ch != EOF));
            int ages = 100;
            do {
                if (ages < 16)
                {
                    cout << "Ошибка! Введите корректную дату";
                }
                cout << "День рождения: ";
                cin >> user.Inicy.MyDate.Day;
                cin.clear();
                while ((ch = cin.get() != '\n' && ch != EOF));
                cout << "Месяц рождения: ";
                cin >> user.Inicy.MyDate.Month;
                cin.clear();
                while ((ch = cin.get() != '\n' && ch != EOF));
                cout << "Год рождения: ";
                cin >> user.Inicy.MyDate.Year;
                cin.clear();
                while ((ch = cin.get() != '\n' && ch != EOF));
                cout << "Введите год поступления: ";
                cin >> user.Group.GPyear;
                cin.clear();
                while ((ch = cin.get() != '\n' && ch != EOF));
                ages = age(user.Inicy.MyDate.Day, user.Inicy.MyDate.Month, user.Inicy.MyDate.Year, user.Group.GPyear);
            } while (ages < 16);





            if (numUsers >= capacity)
            {
                // увеличиваем ёмкость массива в два раза
                capacity = (capacity == 0 ? 1 : capacity * 2);
                User* newUsers = new User[capacity];
                for (int i = 0; i < numUsers; i++)
                {
                    newUsers[i] = users[i];
                }
                delete[] users;
                users = newUsers;
            }

            users[numUsers] = user;
            numUsers++;
            //}

            break;
        }
        case 2:
        {
            if (numUsers == 0)
            {
                cout << "Список студентов пуст.\n";
            }
            else
            {
                cout << "Список всех студентов:\n";
                for (int i = 0; i < numUsers; i++)
                {
                    cout << i + 1 << ". Имя: " << users[i].Inicy.Name << "\n   Фамилия: " << users[i].Inicy.SurName
                        << "\n   Отчество: " << users[i].Inicy.Otche << "\n   День рождения: " << users[i].Inicy.MyDate.Day
                        << "\n   Месяц рождения: " << users[i].Inicy.MyDate.Month << "\n   Год рождения: " << users[i].Inicy.MyDate.Year
                        << "\n   Год поступления: " << users[i].Group.GPyear << endl;
                }

            }

            break;
        }
        case 3:
        {
            if (numUsers == 0)
            {
                cout << "Список пользователей пуст.\n";
            }
            else
            {
                cout << "Введите индекс пользователя (от 1 до " << numUsers << "): ";
                int index;
                cin >> index;

                if (index - 1 >= 0 && index - 1 < numUsers)
                {
                    cout << "Введите новые данные пользователя\n";
                    cout << "Введите новое имя: ";
                    cin >> users[index - 1].Inicy.Name;
                    cout << "Введите новую фамилию: ";
                    cin >> users[index - 1].Inicy.SurName;
                    cout << "Введите новое отчество: ";
                    cin >> users[index - 1].Inicy.Otche;
                    cout << "Введите новую дату рождения: ";
                    cin >> users[index - 1].Inicy.MyDate.Day;
                    cout << "Введите новый месяц рождения: ";
                    cin >> users[index - 1].Inicy.MyDate.Month;
                    cout << "Введите новый год рождения: ";
                    cin >> users[index - 1].Inicy.MyDate.Year;
                    cout << "Введите новый год поступления: ";
                    cin >> users[index - 1].Group.GPyear;
                }
                else
                {
                    cout << "Некорректный индекс.\n";
                }
            }

            break;
        }
        case 4:
        {
            if (numUsers == 0)
            {
                cout << "Список пользователей пуст.\n";
            }
            else
            {
                cout << "Введите индекс пользователя (от 1 до " << numUsers << "): ";
                int index;
                cin >> index;
                index--;
                if (index >= 0 && index < numUsers)
                {
                    for (int i = index; i < numUsers - 1; i++)
                    {
                        users[i] = users[i + 1];
                    }
                    numUsers--;
                }
                else
                {
                    cout << "Некорректный индекс.\n";
                    break;
                }
            }
        }
        case 0:
        {
            cout << "До свидания!\n";
            break;
        }
        default:
        {
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
            break;
        }
        }
    } while (choice != 0);

    delete[] users;

    return 0;
}