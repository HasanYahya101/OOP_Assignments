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
    // Create appointments
    Appointment *onetime_appointment = new Onetime("See the dentist", 2023, 07, 26);
    Appointment *daily_appointment = new Daily("Go to consultation", 2020, 10, 27);
    Appointment *monthly_appointment = new Monthly("Go to meeting", 2023, 6, 7);

    cout << "Appointments:" << endl;
    cout << "1. See the dentist, Type: OneTime, set on date: 2022, 10, 31" << endl;
    cout << "2. Go to consultation, Type: Daily, set on date: 2022, 10, 1" << endl;
    cout << "3. Go to meeting, Type: Monthly, set on date: 2022, 1, 1" << endl
         << endl
         << endl;

    // Add appointments to the list
    Appointment *appointments[] = {onetime_appointment, daily_appointment, monthly_appointment};
    int appointment_count = 3;

    // Check appointments for a specific date
    int year = 2022, month = 10, day = 31;
    cout << "Appointments on " << year << "-" << month << "-" << day << ":" << endl;
    for (int i = 0; i < appointment_count; i++)
    {
        if (appointments[i]->occursOn(year, month, day))
        {
            appointments[i]->print();
        }
    }

    // Check appointments for another specific date
    year = 2023, month = 3, day = 1;
    cout << "Appointments on " << year << "-" << month << "-" << day << ":" << endl;
    for (int i = 0; i < appointment_count; i++)
    {
        if (appointments[i]->occursOn(year, month, day))
        {
            appointments[i]->print();
        }
    }

    cout << endl
         << endl;
    cout << "For search using user input:" << endl;
    cout << "Enter year: ";
    int year1;
    cin >> year1;
    cout << "Enter month: ";
    int month1;
    cin >> month1;
    cout << "Enter day: ";
    int day1;
    cin >> day1;
    cout << "Appointments on " << year1 << "-" << month1 << "-" << day1 << ":" << endl;
    for (int i = 0; i < appointment_count; i++)
    {
        if (appointments[i]->occursOn(year1, month1, day1))
        {
            appointments[i]->print();
        }
    }
    cout << endl;

    // Clean up memory
    for (int i = 0; i < appointment_count; i++)
    {
        delete appointments[i];
    }

    cout << endl
         << endl
         << endl;

    system("pause");

    return 0;
}