#include <iostream>

using namespace std;

int maxHoursRank[20] = {5, 10, 20, 40, 50, 50, 50, 100, 100, 100, 200, 200, 200, 400, 400, 400, 400, 400, 500, 500};

struct NameBonus
{
    string name;
    int bonus;
};

NameBonus names[2] =
{
    {"robin", 5688},
    {"biginteger", 3673}
};

void getLevelProgress(string name, int days, int hours, int userbonus)
{
    int bonus = userbonus;
    if (name.compare("0") == 1)
    {
        for (int i = 0; i < sizeof(names) / 8; i++)
        {
            if (names[i].name.compare(name) == 0)
            {
                bonus += names[i].bonus;
                break;
            }
        }
    }
    int total = (24 * days) + hours + bonus;
    int current = 0;
    int rank = 0;
    float percentage;

    while (current < total)
    {
        if (rank <= 20) current += maxHoursRank[rank];
        else current += 1000;
        rank++;
    }
    if (rank > 20) percentage = (1000 - ((float)current - (float)total)) / 10;
    else percentage = (((float)maxHoursRank[rank - 1] - ((float)current - (float)total)) / ((float)maxHoursRank[rank - 1])) * 100;

    cout << "Level: " << rank << ", Percentage: " << percentage << "\n\n";
}

int main()
{
    while (1 != 2)
    {
        string name;
        int days;
        int hours;
        int bonus;
        cout << "Name: ";
        cin >> name;
        cout << "Days: ";
        cin >> days;
        cout << "Hours: ";
        cin >> hours;
        cout << "Bonus: ";
        cin >> bonus;
        getLevelProgress(name, days, hours, bonus);
    }
    return 0;
}
