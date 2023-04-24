#include <iostream>
#include <string>
using namespace std;

class Appointment
{
public:
    Appointment(const string &description, int year, int month, int day)
    {
        this->description = description;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    virtual bool occursOn(int year, int month, int day) const = 0;
    void print() const
    {
        cout << description << endl;
    }

protected:
    string description;
    int year, month, day;
};

class Onetime : public Appointment
{
public:
    Onetime(const string &description, int year, int month, int day)
        : Appointment(description, year, month, day) {}
    bool occursOn(int year, int month, int day) const override
    {
        return this->year == year && this->month == month && this->day == day;
    }
};

class Daily : public Appointment
{
public:
    Daily(const string &description, int year, int month, int day)
        : Appointment(description, year, month, day) {}
    bool occursOn(int year, int month, int day) const override
    {
        return true;
    }
};

class Monthly : public Appointment
{
public:
    Monthly(const string &description, int year, int month, int day)
        : Appointment(description, year, month, day) {}
    bool occursOn(int year, int month, int day) const override
    {
        return ((year > this->year) || (year == this->year && month >= this->month)) && this->day == day;
    }
};

int main()
{
    Appointment *appointments[100];
    int appointment_count = 0;
    int choice, year, month, day;
    string description;

    while (true)
    {
        cout << "1. Add Onetime appointment" << endl;
        cout << "2. Add Daily appointment" << endl;
        cout << "3. Add Monthly appointment" << endl;
        cout << "4. Check appointments" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5)
        {
            break;
        }

        if (choice >= 1 && choice <= 3)
        {
            cout << "Enter appointment description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter appointment date (yyyy mm dd): ";
            cin >> year >> month >> day;
        }

        if (choice == 1)
        {
            appointments[appointment_count++] = new Onetime(description, year, month, day);
            cout << "Onetime appointment added." << endl;
        }
        else if (choice == 2)
        {
            appointments[appointment_count++] = new Daily(description, year, month, day);
            cout << "Daily appointment added." << endl;
        }
        else if (choice == 3)
        {
            appointments[appointment_count++] = new Monthly(description, year, month, day);
            cout << "Monthly appointment added." << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter a date to check (yyyy mm dd): ";
            cin >> year >> month >> day;

            cout << "Appointments on " << year << "-" << month << "-" << day << ":" << endl;
            for (int i = 0; i < appointment_count; i++)
            {
                if (appointments[i]->occursOn(year, month, day))
                {
                    appointments[i]->print();
                }
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        cout << endl
             << endl
             << endl;
    }

    for (int i = 0; i < appointment_count; i++)
    {
        delete appointments[i];
    }

    cout << endl
         << endl
         << endl;

    std::system("pause");
    return 0;
}