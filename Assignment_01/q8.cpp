#include <iostream>
using namespace std;

class ComboLock
{
private:
	int secret1, secret2, secret3;
	int dial;
	bool first, second, third;
public:
	ComboLock(int secret1, int secret2, int secret3)
	{
		this->secret1 = secret1;
		this->secret2 = secret2;
		this->secret3 = secret3;
		dial = 0;
		first = false;
		second = false;
		third = false;
	}
	void reset()
	{
		dial = 0;
		first = false;
		second = false;
		third = false;
	}
	void turnLeft(int ticks)
	{
		dial = (dial - ticks) % 40;
		if (dial < 0)
			dial += 40;
		if (dial == secret2)
			second = true;
	}
	void turnRight(int ticks)
	{
		dial = (dial + ticks) % 40;
		if (dial == secret1)
			first = true;
		if (dial == secret3)
			third = true;
	}
	bool open()
	{
		return first && second && third;
	}
};

class Menu
{
private:
	string *options;
	int size;
public:
	Menu(string *options, int size)
	{
		this->options = options;
		this->size = size;
	}
	void display()
	{
		for (int i = 0; i < size; i++)
			cout << i + 1 << ". " << options[i] << endl;
	}
	int getChoice()
	{
		int choice;
		do
		{
			cout << "Enter your choice: ";
			cin >> choice;
		} while (choice < 1 || choice > size);
		return choice;
	}
};

int main()
{
	cout << "Enter 3 numbers between 0 and 39: ";
	int secret1, secret2, secret3;
	cin >> secret1 >> secret2 >> secret3;
	int ticks = 0;
	ComboLock lock(secret1, secret2, secret3);
	int choice;
	do
	{
		cout << "1. Reset" << endl;
		cout << "2. Turn left" << endl;
		cout << "3. Turn right" << endl;
		cout << "4. Open" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			lock.reset();
			cout << "Lock reset" << endl;
		}
		if (choice == 2)
		{
			cout << "Enter number of ticks: ";
			cin >> ticks;
			while (ticks < 0 || ticks > 39)
			{
				cout << "Enter number of ticks: ";
				cin >> ticks;
			}
			lock.turnLeft(ticks);
		}
		if (choice == 3)
		{
			cout << "Enter number of ticks: ";
			cin >> ticks;
			while (ticks < 0 || ticks > 39)
			{
				cout << "Enter number of ticks: ";
				cin >> ticks;
			}
			lock.turnRight(ticks);
		}
		if (choice == 4)
		{
			if (lock.open())
				cout << "Lock opened" << endl;
			else
				cout << "Lock not opened" << endl;
			break;
		}
	} while (choice != 5);
	return 0;

}
