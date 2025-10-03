// Routine of all section
#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (true)
    {
        string day, section;
        cout << "Enter your section name in Capital Letter : "<<endl;
        cout << "1. For A section type A: " << endl
             << "2. For B section type B: " << endl
             << "3. For C section type C: "<<endl
             << "4. For Exit type cc : ";
        cin >> section;
        if (section == "A")
        {
            cout << "Enter the day of first three letter like sun for Sunday : ";
            cin >> day;
            transform(day.begin(), day.end(), day.begin(), :: tolower);
            if (day == "sun")
            {
                cout << "Time : 11: 00 am - 1: 30 pm  Class : PHY-134 Sessional (A-1)" << endl;
                cout << "Time : 2 : 30 pm - 3: 20 pm  Class : Math-133" << endl;
                cout << "Time : 3 : 20 pm - 4: 10 pm  Class : EE-131" << endl;
                cout << "Time : 4 : 10 pm - 5: 00 pm  Class : ME-181" << endl;
            }
            else if (day == "mon")
            {
                cout << "Time : 11: 00 am - 1: 30 pm  Class : PHY-134 Sessional (A-2)" << endl;
                cout << "Time : 2 : 30 pm - 3: 20 pm  Class : PHY-133" << endl;
                cout << "Time : 3 : 20 pm - 4: 10 pm  Class : ME-181" << endl;
                cout << "Time : 4 : 10 pm - 5: 00 pm  Class : CHEM-133" << endl;
            }
            else if (day == "tue")
            {
                cout << "Time : 11: 00 am - 1: 30 pm  Class : EE-132 Sessional (A-1/A-2)" << endl;
                cout << "Time : 2 : 30 pm - 3: 20 pm  Class : CHEM-133" << endl;
                cout << "Time : 3 : 20 pm - 4: 10 pm  Class : EE-132" << endl;
                cout << "Time : 4 : 10 pm - 5: 00 pm  Class : MATH-133" << endl;
            }
            else if (day == "wed")
            {
                cout << "Time : 9 : 50 am - 12: 20 pm  Class : ME-182 Sessional (A)" << endl;
                cout << "Time : 12: 40 pm -  1: 30 pm  Class : EE-131" << endl;
                cout << "Time : 2 : 30 pm - 3: 20 pm  Class : ME-181" << endl;
                cout << "Time : 3 : 20 pm - 4: 10 pm  Class : PHY-133" << endl;
                cout << "Time : 4 : 10 pm - 5: 00 pm  Class : CHEM-133" << endl;
            }
            else if(day=="thu")
            {
                cout << "Time : 11: 00 am - 1: 30 pm  Class : ME-154 Sessional (A-1/A-2)" << endl;
                cout << "Time : 2 : 30 pm - 3: 20 pm  Class : PHY-133" << endl;
                cout << "Time : 3 : 20 pm - 4: 10 pm  Class : EE-132" << endl;
                cout << "Time : 4 : 10 pm - 5: 00 pm  Class : MATH-133" << endl;

            }
        }
        else if (section == "B")
        {
            cout << "Enter the day of first three letter like sun for Sunday : ";
            cin >> day;
            if (day == "sun")
            {
                cout << "Time : 11: 00 am - 1: 30 pm  Class : EE-132 Sessional (B-1/B-2)" << endl;
                cout << "Time : 2 : 30 pm - 3: 20 pm  Class : ME-181" << endl;
                cout << "Time : 3 : 20 pm - 4: 10 pm  Class : MATH-133" << endl;
                cout << "Time : 4 : 10 pm - 5: 00 pm  Class : EE-131" << endl;
            }
        }
        else if (section == "C")
        {
            cout << "Enter the day of first three letter like sun for Sunday : ";
            cin >> day;

            cout << "Time : 8 : 10 am - 9 : 45 am Class : EE-132 Sessional (C-1)";
            cout << "Time : 9 : 45 am - 11 : 00 am Class : EE-132 Sessional (C-1)";
            cout << "Time : 11: 00 am - 1: 30 pm  Class : ME-154 Sessional (C-1/C-2)" << endl;
            cout << "Time : 2 : 30 pm - 3: 20 pm  Class : EE-131" << endl;
            cout << "Time : 3 : 20 pm - 4: 10 pm  Class : ME-181" << endl;
            cout << "Time : 4 : 10 pm - 5: 00 pm  Class : MATH-133" << endl;
        }
        else if (section == "cc")
            break;
        else
            cout << "Your input is wrong , please try again.";
    }

    return 0;
}