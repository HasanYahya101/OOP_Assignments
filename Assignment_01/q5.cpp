#include <iostream>
#include <string.h>
using namespace std;

class Book
{
private:
	int publicationID;
	char bookTitle[100];
	char author[100];
	char patronSubscribers[100];
public:
	Book()
	{
		publicationID = 0;
		strcpy_s(bookTitle, "");
		strcpy_s(author, "");
		strcpy_s(patronSubscribers, "");
	}
	Book(int id, char title[], char auth[], char sub[])
	{
		publicationID = id;
		strcpy_s(bookTitle, title);
		strcpy_s(author, auth);
		strcpy_s(patronSubscribers, sub);
	}
	void display()
	{
		cout << "Publication ID: " << publicationID << endl;
		cout << "Book Title: " << bookTitle << endl;
		cout << "Author: " << author << endl;
		cout << "Patron Subscribers: " << patronSubscribers << endl;
	}
	int getID()
	{
		return publicationID;
	}
	void setID(int id)
	{
		publicationID = id;
	}
	char* getTitle()
	{
		return bookTitle;
	}
	void setTitle(char title[])
	{
		strcpy_s(bookTitle, title);
	}
	char* getAuthor()
	{
		return author;
	}
	void setAuthor(char auth[])
	{
		strcpy_s(author, auth);
	}
	char* getSubscribers()
	{
		return patronSubscribers;
	}
	void setSubscribers(char sub[])
	{
		strcpy_s(patronSubscribers, sub);
	}
};

int main()
{
	Book books[100];
	int choice, id, count = 0;
	char title[100], auth[100], sub[100];
	while (true)
	{
		system("cls");
		cout << "1. Add a new book" << endl;
		cout << "2. Edit details of an available book" << endl;
		cout << "3. Delete a book" << endl;
		cout << "4. Display all books in the library" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter the publication ID: ";
			cin >> id;
			cout << "Enter the book title: ";
			cin.ignore();
			cin.getline(title, 100);
			cout << "Enter the author: ";
			cin.getline(auth, 100);
			cout << "Enter the patron subscribers: ";
			cin.getline(sub, 100);
			books[count] = Book(id, title, auth, sub);
			count++;
		}
		if (choice == 2)
		{
			cout << "Enter the publication ID of the book you want to edit: ";
			cin >> id;
			for (int i = 0; i < count; i++)
			{
				if (books[i].getID() == id)
				{
					cout << "Enter the new book title: ";
					cin.ignore();
					cin.getline(title, 100);
					cout << "Enter the new author: ";
					cin.getline(auth, 100);
					cout << "Enter the new patron subscribers: ";
					cin.getline(sub, 100);
					books[i].setTitle(title);
					books[i].setAuthor(auth);
					books[i].setSubscribers(sub);
					break;
				}
			}
		}
		if (choice == 3)
		{
			cout << "Enter the publication ID of the book you want to delete: ";
			cin >> id;
			for (int i = 0; i < count; i++)
			{
				if (books[i].getID() == id)
				{
					for (int j = i; j < count - 1; j++)
					{
						books[j] = books[j + 1];
					}
					count--;
					break;
				}
			}
		}
		if (choice == 4)
		{
			for (int i = 0; i < count; i++)
			{
				books[i].display();
			}
		}
		if (choice == 5)
		{
			exit(0);
		}
	}
	return 0;
}