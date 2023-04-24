#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Customer
{
private:
    int id;
    string name;
    int discount;

public:
    // constructor
    Customer(int id, string name, int discount)
    {
        this->id = id;
        this->name = name;
        this->discount = discount;
    }

    // getter
    int getID() const
    {
        return id;
    }

    // getter
    string getName() const
    {
        return name;
    }

    // getter
    int getDiscount() const
    {
        return discount;
    }

    // setter
    void setDiscount(int discount)
    {
        this->discount = discount;
    }

    string toString() const
    {
        return name + "(" + to_string(id) + ")(" + to_string(discount) + "%)";
    }
};

class Invoice
{
private:
    int id;
    Customer *customer; // Use pointer for aggregation
    double amount;

public:
    Invoice(int id, Customer *customer, double amount)
    {
        this->id = id;
        this->customer = customer;
        this->amount = amount;
    }

    int getID() const
    {
        return id;
    }

    Customer *getCustomer() const
    {
        return customer;
    }

    void setCustomer(Customer *customer)
    {
        this->customer = customer;
    }

    double getAmount() const
    {
        return amount;
    }

    void setAmount(double amount)
    {
        this->amount = amount;
    }

    int getCustomerID() const
    {
        return customer->getID();
    }

    string getCustomerName() const
    {
        return customer->getName();
    }

    int getCustomerDiscount() const
    {
        return customer->getDiscount();
    }

    double getAmountAfterDiscount() const
    {
        return amount * (1.0 - static_cast<double>(customer->getDiscount()) / 100);
    }

    string toString() const
    {
        return "Invoice[ id=" + to_string(id) + ", customer=" + customer->toString() + ", amount=" + to_string(amount) + " ]";
    }
};

void saveToFile(Customer **customers, int numberOfCustomers, Invoice **invoices, int numberOfInvoices)
{
    ofstream customersFile("customers.txt");
    ofstream invoicesFile("invoices.txt");

    for (int i = 0; i < numberOfCustomers; i++)
    {
        customersFile << customers[i]->getID() << endl
                      << customers[i]->getName() << endl
                      << customers[i]->getDiscount() << endl;
    }

    for (int i = 0; i < numberOfInvoices; i++)
    {
        invoicesFile << invoices[i]->getID() << endl
                     << invoices[i]->getCustomerID() << endl
                     << invoices[i]->getAmount() << endl;
    }

    customersFile.close();
    invoicesFile.close();
}

void loadFromFile(Customer **&customers, int &numberOfCustomers, Invoice **&invoices, int &numberOfInvoices)
{
    ifstream customersFile("customers.txt");
    ifstream invoicesFile("invoices.txt");

    int id;
    string name;
    int discount;

    while (customersFile >> id)
    {
        customersFile.ignore();
        getline(customersFile, name);
        customersFile >> discount;

        customers[numberOfCustomers++] = new Customer(id, name, discount);
    }

    int invoiceID;
    int customerID;
    double amount;

    while (invoicesFile >> invoiceID)
    {
        invoicesFile >> customerID >> amount;

        Customer *customer = nullptr;
        for (int i = 0; i < numberOfCustomers; i++)
        {
            if (customers[i]->getID() == customerID)
            {
                customer = customers[i];
                break;
            }
        }

        if (customer != nullptr)
        {
            invoices[numberOfInvoices++] = new Invoice(invoiceID, customer, amount);
        }
    }

    customersFile.close();
    invoicesFile.close();
}

int main()
{
    int choice;
    int customerID;
    string customerName;
    int customerDiscount;
    int invoiceID;
    double invoiceAmount;
    int numberOfCustomers = 0;
    int numberOfInvoices = 0;
    int maxCustomers = 10;
    int maxInvoices = 10;
    Customer **customers = new Customer *[maxCustomers];
    Invoice **invoices = new Invoice *[maxInvoices];

    loadFromFile(customers, numberOfCustomers, invoices, numberOfInvoices);

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Create customer" << endl;
        cout << "2. Create invoice" << endl;
        cout << "3. Update customer discount" << endl;
        cout << "4. Update invoice amount" << endl;
        cout << "5. Show customer details" << endl;
        cout << "6. Show invoice details" << endl;
        cout << "7. Show amount after discount" << endl;
        cout << "8. Save data to file" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (numberOfCustomers >= maxCustomers)
            {
                cout << "Maximum number of customers reached!" << endl;
                continue;
            }

            cout << "Enter customer ID: ";
            cin >> customerID;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, customerName);
            cout << "Enter customer discount: ";
            cin >> customerDiscount;

            customers[numberOfCustomers++] = new Customer(customerID, customerName, customerDiscount);
            cout << "Customer created successfully!" << endl;
        }
        else if (choice == 2)
        {
            if (numberOfInvoices >= maxInvoices)
            {
                cout << "Maximum number of invoices reached!" << endl;
                continue;
            }

            cout << "Enter invoice ID: ";
            cin >> invoiceID;
            cout << "Enter customer ID: ";
            cin >> customerID;

            Customer *customer = nullptr;
            for (int i = 0; i < numberOfCustomers; i++)
            {
                if (customers[i]->getID() == customerID)
                {
                    customer = customers[i];
                    break;
                }
            }

            if (customer == nullptr)
            {
                cout << "Customer not found!" << endl;
                continue;
            }

            cout << "Enter invoice amount: ";
            cin >> invoiceAmount;

            invoices[numberOfInvoices++] = new Invoice(invoiceID, customer, invoiceAmount);
            cout << "Invoice created successfully!" << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter customer ID: ";
            cin >> customerID;

            Customer *customer = nullptr;
            for (int i = 0; i < numberOfCustomers; i++)
            {
                if (customers[i]->getID() == customerID)
                {
                    customer = customers[i];
                    break;
                }
            }

            if (customer == nullptr)
            {
                cout << "Customer not found!" << endl;
                continue;
            }

            cout << "Enter new customer discount: ";
            cin >> customerDiscount;

            customer->setDiscount(customerDiscount);
            cout << "Customer discount updated successfully!" << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter invoice ID: ";
            cin >> invoiceID;

            Invoice *invoice = nullptr;
            for (int i = 0; i < numberOfInvoices; i++)
            {
                if (invoices[i]->getID() == invoiceID)
                {
                    invoice = invoices[i];
                    break;
                }
            }

            if (invoice == nullptr)
            {
                cout << "Invoice not found!" << endl;
                continue;
            }

            cout << "Enter new invoice amount: ";
            cin >> invoiceAmount;

            invoice->setAmount(invoiceAmount);
            cout << "Invoice amount updated successfully!" << endl;
        }
        else if (choice == 5)
        {
            cout << "Enter customer ID: ";
            cin >> customerID;

            Customer *customer = nullptr;
            for (int i = 0; i < numberOfCustomers; i++)
            {
                if (customers[i]->getID() == customerID)
                {
                    customer = customers[i];
                    break;
                }
            }

            if (customer == nullptr)
            {
                cout << "Customer not found!" << endl;
                continue;
            }

            cout << "Customer details: " << customer->toString() << endl;
        }
        else if (choice == 6)
        {
            cout << "Enter invoice ID: ";
            cin >> invoiceID;

            Invoice *invoice = nullptr;
            for (int i = 0; i < numberOfInvoices; i++)
            {
                if (invoices[i]->getID() == invoiceID)
                {
                    invoice = invoices[i];
                    break;
                }
            }

            if (invoice == nullptr)
            {
                cout << "Invoice not found!" << endl;
                continue;
            }

            cout << "Invoice details: " << invoice->toString() << endl;
        }
        else if (choice == 7)
        {
            cout << "Enter invoice ID: ";
            cin >> invoiceID;

            Invoice *invoice = nullptr;
            for (int i = 0; i < numberOfInvoices; i++)
            {
                if (invoices[i]->getID() == invoiceID)
                {
                    invoice = invoices[i];
                    break;
                }
            }

            if (invoice == nullptr)
            {
                cout << "Invoice not found!" << endl;
                continue;
            }

            cout << "Amount after discount: " << invoice->getAmountAfterDiscount() << endl;
        }
        else if (choice == 8)
        {
            saveToFile(customers, numberOfCustomers, invoices, numberOfInvoices);
            cout << "Data saved successfully!" << endl;
        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl
             << endl
             << endl;
    }

    for (int i = 0; i < numberOfCustomers; i++)
    {
        delete customers[i];
    }
    delete[] customers;

    for (int i = 0; i < numberOfInvoices; i++)
    {
        delete invoices[i];
    }
    delete[] invoices;

    cout << endl
         << endl
         << endl;

    std::system("pause");
    return 0;
}