#include <iostream>
#include <stack>
using namespace std;

class ChocolateShop
{
private:
    stack<int> chocolateStack;
    int chocolatesSold;
    int minute;

public:
    // constructor
    ChocolateShop()
    {
        this->chocolatesSold = 0;
        this->minute = 0;
    }
    // sellBox() to sell a box of chocolates
    void sellBox()
    {
        if (!chocolateStack.empty())
        {
            chocolatesSold += chocolateStack.top();
            chocolateStack.pop();
        }
        cout << "At minute " << minute << ", a box of chocolates is sold." << endl
             << endl;
        minute++;
    }
    // receiveBox() to receive a box of chocolates
    void receiveBox(int chocolates)
    {
        chocolateStack.push(chocolates);
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
    void inputStack(int capacity)
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
        stack<int> temp = chocolateStack;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    // destructor
    ~ChocolateShop()
    {
        // As it will execute at the end of program
        cout << "\nThe program is terminated!" << endl;
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
    ChocolateShop shop;

    // input values
    shop.inputStack(N);

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