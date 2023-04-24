#include <iostream>
using namespace std;

class ChocolateShop
{
private:
    int *stack;
    int top;
    int chocolatesSold;
    int capacity;
    int minute;

public:
    // constructor
    ChocolateShop(int capacity)
    {
        this->capacity = capacity;
        this->stack = new int[capacity];
        this->top = -1;
        this->chocolatesSold = 0;
        this->minute = 0;
    }
    // destructor
    ~ChocolateShop()
    {
        delete[] stack;
    }
    // sellBox() to sell a box of chocolates
    void sellBox()
    {
        if (top >= 0)
        {
            chocolatesSold += stack[top];
            top--;
        }
        cout << "At minute " << minute << ", a box of chocolates is sold." << endl
             << endl;
        minute++;
    }
    // receiveBox() to receive a box of chocolates
    void receiveBox(int chocolates)
    {
        if (top + 1 < capacity)
        {
            top++;
            stack[top] = chocolates;
        }
        cout << "At minute " << minute << ", a box of chocolates is received." << endl
             << endl;
        minute++;
    }
    // getChocolatesSold() to return the number of chocolates sold
    int getChocolatesSold()
    {
        return chocolatesSold;
    }
    // inputStack() to input values into the stack from user
    void inputStack()
    {
        cout << "Enter the number of chocolates in each stack!\n"
             << endl;
        for (int i = 0; i < capacity; i++)
        {
            int chocolates;
            cout << "Value " << i + 1 << ": ";
            cin >> chocolates;
            // check if it is less then 0
            while (chocolates < 0)
            {
                cout << "Invalid input. Enter a number greater than -1: ";
                cin >> chocolates;
            }
            // sell or recieve
            if (chocolates == 0)
            {
                sellBox();
            }
            else
            {
                receiveBox(chocolates);
            }
        }
    }
    // displayStack() to display the current state of the stack
    void displayStack()
    {
        cout << "\nStack: ";
        for (int j = top; j >= 0; j--)
        {
            cout << stack[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "It must be confirmed that he gets a buyer only when he has a non-empty stack!" << endl;
    cout << "Otherwise, this program will not work!" << endl
         << endl;
    int N;
    // input the total number of stacks
    cout << "Enter the total number of stacks: ";
    cin >> N;
    cout << endl;
    // Display Error message if N is less than 2
    while (N < 2)
    {
        cout << "Invalid input. Enter a number greater than 1: ";
        cin >> N;
    }

    // object of class ChocolateShop
    ChocolateShop shop(N);

    // input values
    shop.inputStack();

    // display stack and events
    shop.displayStack();
    cout << endl
         << endl;
    // display total chocolates sold
    cout << "Total chocolates sold: " << shop.getChocolatesSold() << endl;
    cout << endl
         << endl
         << endl;
    system("pause");
    return 0;
}