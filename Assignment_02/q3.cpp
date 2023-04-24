#include <iostream>
#include <cmath>
using namespace std;

class pointType
{
private:
    double x_Coordinate;
    double y_Coordinate;

public:
    // Default constructor
    pointType()
    {
        x_Coordinate = 0.0;
        y_Coordinate = 0.0;
    }
    // Constructor
    pointType(double x = 0.0, double y = 0.0) : x_Coordinate(x), y_Coordinate(y) {}

    // parameter constructor
    /*pointType(double x, double y)
    {
        x_Coordinate = x;
        y_Coordinate = y; //Extra one not being used in program
    }*/

    // Set X
    void set_X(double x)
    {
        x_Coordinate = x;
    }
    // Set Y
    void set_Y(double y)
    {
        y_Coordinate = y;
    }
    // Setter
    void set_Coordinates(double x, double y)
    {
        x_Coordinate = x;
        y_Coordinate = y;
    }

    // Get X
    double get_X() const
    {
        return x_Coordinate;
    }
    // Get Y
    double get_Y() const
    {
        return y_Coordinate;
    }

    // Print coordinates
    void print_Coordinates() const
    {
        cout << "(" << x_Coordinate << ", " << y_Coordinate << ")" << endl;
    }

    // Calculate distance
    static void calc_Distance(const pointType &p1, const pointType &p2)
    {
        double distance = sqrt(pow(p1.get_X() - p2.get_X(), 2) + pow(p1.get_Y() - p2.get_Y(), 2));
        cout << "Distance between points: " << distance << endl;
    }
    // destructor
    ~pointType()
    {
        cout << endl
             << endl;
    }
};

int main()
{
    pointType p1(3, 4); // constructor used to initialize coordinates
    pointType p2(6, 8);

    cout << "Object p1 created: ";
    p1.print_Coordinates();
    cout << endl;
    cout << "Object p2 created: "; // Print function used to print coordinates
    p2.print_Coordinates();
    cout << endl
         << endl;

    cout << "Printing Coordinates of p1 using getters!" << endl;
    cout << "X-coordinate of p1: " << p1.get_X() << endl;
    cout << "Y-coordinate of p1: " << p1.get_Y() << endl
         << endl;

    cout << "Printing Coordinates of p2 using getters!" << endl;
    cout << "X-coordinate of p2: " << p2.get_X() << endl;
    cout << "Y-coordinate of p2: " << p2.get_Y() << endl
         << endl;

    cout << "Now, using setters to set value of p1!" << endl;
    cout << "Enter x-coordinate of p1: ";
    double x;
    cin >> x;
    p1.set_X(x);
    cout << "Enter y-coordinate of p1: ";
    double y;
    cin >> y;
    p1.set_Y(y);
    cout << endl
         << endl;
    cout << "Now, using setters to set value of p2!" << endl;
    cout << "Enter x-coordinate of p2: ";
    cin >> x;
    cout << "Enter y-coordinate of p2: ";
    cin >> y;
    p2.set_Coordinates(x, y);

    cout << endl
         << endl
         << endl;

    cout << "New coordinates of p1: ";
    p1.print_Coordinates();
    cout << endl;
    cout << "New coordinates of p2: ";
    p2.print_Coordinates();
    cout << endl
         << endl;

    cout << "Calculating distance between p1 and p2! using [sqrt(p1_x - p2_x)^2 + (p1_y - p2_y)^2]: " << endl;
    pointType::calc_Distance(p1, p2);
    cout << endl
         << endl;

    system("pause");
    return 0;
}