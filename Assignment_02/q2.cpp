#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
    int id;
    string title;

public:
    Course(int id, string title)
    {
        this->id = id;
        this->title = title;
    }

    void display()
    {
        cout << "Course ID: " << id << ", Title: " << title << endl;
    }

    int getId()
    {
        return id;
    }
};

class Teacher
{
private:
    int id;
    string name;
    Course **courses;
    int courseCount;
    int courseCapacity;

public:
    Teacher(int id, string name)
    {
        this->id = id;
        this->name = name;
        this->courseCapacity = 10;
        this->courses = new Course *[courseCapacity];
        this->courseCount = 0;
    }

    void addCourse(Course *course)
    {
        if (courseCount >= courseCapacity)
        {
            courseCapacity *= 2;
            Course **newCourses = new Course *[courseCapacity];
            for (int i = 0; i < courseCount; i++)
            {
                newCourses[i] = courses[i];
            }
            delete[] courses;
            courses = newCourses;
        }
        courses[courseCount] = course;
        courseCount++;
    }

    void displayCourses()
    {
        cout << endl
             << endl;
        cout << "Courses taught by " << name << ":" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            courses[i]->display();
        }
    }

    int getId()
    {
        return id;
    }

    ~Teacher()
    {
        // free memory
        for (int i = 0; i < courseCount; i++)
        {
            delete courses[i];
        }
        // free memory
        delete[] courses;
    }
};

void displayMenu()
{
    cout << "\nMenu:" << endl;
    cout << "1. Create a teacher" << endl;
    cout << "2. Create a course" << endl;
    cout << "3. Add a course to a teacher" << endl;
    cout << "4. Display all courses of a teacher" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    Teacher *teachers[10];
    int teacherCount = 0;
    Course *courses[10];
    int courseCount = 0;
    int choice;

    int check = true;

    while (check == true)
    {
        displayMenu();
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            cout << "Enter teacher ID: ";
            cin >> id;
            cout << "Enter teacher name: ";
            cin >> name;
            teachers[teacherCount] = new Teacher(id, name);
            teacherCount++;
        }
        else if (choice == 2)
        {
            int id;
            string title;
            cout << "Enter course ID: ";
            cin >> id;
            cout << "Enter course title: ";
            cin >> title;
            courses[courseCount] = new Course(id, title);
            courseCount++;
        }
        else if (choice == 3)
        {
            int teacherId, courseId;
            cout << "Enter the teacher ID: ";
            cin >> teacherId;
            cout << "Enter the course ID: ";
            cin >> courseId;

            Teacher *teacher = nullptr;
            Course *course = nullptr;

            for (int i = 0; i < teacherCount; i++)
            {
                if (teachers[i]->getId() == teacherId)
                {
                    teacher = teachers[i];
                    break;
                }
            }

            for (int i = 0; i < courseCount; i++)
            {
                if (courses[i]->getId() == courseId)
                {
                    course = courses[i];
                    break;
                }
            }

            if (teacher != nullptr && course != nullptr)
            {
                teacher->addCourse(course);
            }
            else
            {
                cout << "Invalid teacher or course ID" << endl;
            }
        }
        else if (choice == 4)
        {
            int teacherId;
            cout << "Enter the teacher ID: ";
            cin >> teacherId;

            Teacher *teacher = nullptr;

            for (int i = 0; i < teacherCount; i++)
            {
                if (teachers[i]->getId() == teacherId)
                {
                    teacher = teachers[i];
                    break;
                }
            }

            if (teacher != nullptr)
            {
                teacher->displayCourses();
            }
            else
            {
                cout << "Invalid teacher ID" << endl;
            }
        }
        else if (choice == 5)
        {
            check = false;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        cout << endl
             << endl;
    }

    // Free memory
    for (int i = 0; i < teacherCount; i++)
    {
        delete teachers[i];
    }
    // Free memory
    for (int i = 0; i < courseCount; i++)
    {
        delete courses[i];
    }

    cout << endl
         << endl;

    std::system("pause");
    return 0;
}