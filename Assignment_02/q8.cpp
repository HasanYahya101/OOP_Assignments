#include <iostream>
#include <fstream>
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
        // cout << "Apointment parameterised constructor called" << endl;
    }
    virtual bool occursOn(int year, int month, int day) const = 0;
    void print() const
    {
        cout << description << endl;
    }

    virtual void save(ofstream &outFile) const
    {
        outFile << description << endl
                << year << " " << month << " " << day << endl;
    }

    string getDescription() const
    {
        return description;
    }
    ~Appointment()
    {
        cout << "Appointment destructor called" << endl;
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

    void save(ofstream &outFile) const override
    {
        outFile << "Onetime" << endl;
        Appointment::save(outFile);
    }
    ~Onetime()
    {
        cout << "Onetime destructor called" << endl;
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

    void save(ofstream &outFile) const override
    {
        outFile << "Daily" << endl;
        Appointment::save(outFile);
    }
    ~Daily()
    {
        cout << "Daily destructor called" << endl;
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

    void save(ofstream &outFile) const override
    {
        outFile << "Monthly" << endl;
        Appointment::save(outFile);
    }
    ~Monthly()
    {
        cout << "Monthly destructor called" << endl;
    }
};

void saveAppointments(Appointment *appointments[], int appointment_count)
{
    ofstream outFile("appointments.txt");

    outFile << appointment_count << endl;

    for (int i = 0; i < appointment_count; i++)
    {
        appointments[i]->save(outFile);
    }

    outFile.close();
}

int loadAppointments(Appointment *appointments[])
{
    ifstream inFile("appointments.txt");

    if (!inFile || inFile.peek() == ifstream::traits_type::eof()) // exception handling
    {
        return 0;
    }

    if (!inFile)
    {
        return 0;
    }

    int appointment_count;
    inFile >> appointment_count;
    inFile.ignore();

    string type, description;
    int year, month, day;

    for (int i = 0; i < appointment_count; i++)
    {
        getline(inFile, type);
        getline(inFile, description);
        inFile >> year >> month >> day;
        inFile.ignore();

        if (type == "Onetime")
        {
            appointments[i] = new Onetime(description, year, month, day);
        }
        else if (type == "Daily")
        {
            appointments[i] = new Daily(description, year, month, day);
        }
        else if (type == "Monthly")
        {
            appointments[i] = new Monthly(description, year, month, day);
        }
    }

    inFile.close();

    return appointment_count;
}

int main()
{
    Appointment *appointments[100];
    int appointment_count = loadAppointments(appointments);
    int choice, year, month, day;
    string description;

    while (true)
    {
        cout << "1. Add Onetime appointment" << endl;
        cout << "2. Add Daily appointment" << endl;
        cout << "3. Add Monthly appointment" << endl;
        cout << "4. Check appointments" << endl;
        cout << "5. Save and exit" << endl;
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

    saveAppointments(appointments, appointment_count);

    cout << endl
         << endl
         << endl;

    for (int i = 0; i < appointment_count; i++)
    {
        delete appointments[i];
    }

    std::system("pause");
    return 0;
}