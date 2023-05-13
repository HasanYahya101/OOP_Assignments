#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <csignal>
#include <memory>
using namespace std;


class AccountType
{
protected:
    double dailyWithdrawalLimit;

public:
    AccountType(double limit) : dailyWithdrawalLimit(limit) {}
    virtual ~AccountType() {}
    virtual double getDailyWithdrawalLimit() const = 0;
    virtual std::string getAccountTypeName() const = 0;
};

class Bronze : public AccountType
{
public:
    Bronze() : AccountType(100000) {}

    double getDailyWithdrawalLimit() const
    {
        return dailyWithdrawalLimit;
    }

    std::string getAccountTypeName() const
    {
        return "Bronze";
    }
};

class Gold : public AccountType
{
public:
    Gold() : AccountType(500000) {}

    double getDailyWithdrawalLimit() const
    {
        return dailyWithdrawalLimit;
    }

    std::string getAccountTypeName() const
    {
        return "Gold";
    }
};

class Business : public AccountType
{
public:
    Business() : AccountType(20000000) {}

    double getDailyWithdrawalLimit() const
    {
        return dailyWithdrawalLimit;
    }

    std::string getAccountTypeName() const
    {
        return "Business";
    }
};

class cardWarning
{
private:
    int ID;
    long long card_num;

public:
    cardWarning(int id, long long card_num) : ID(id), card_num(card_num) {}

    int getID() const
    {
        return ID;
    }

    long long getCardNum() const
    {
        return card_num;
    }
};

class Loan
{
protected:
    long long amount;
    int Comp_ID;
    long long card_num;

public:
    Loan(long long amt, int id, long long num) : amount(amt), Comp_ID(id), card_num(num) {}

    ~Loan() {}
    long long getAmount() const
    {
        return amount;
    }
    int getCompID() const
    {
        return Comp_ID;
    }
    void setAmount(long long amt)
    {
        amount = amt;
    }
    void setCompID(int id)
    {
        Comp_ID = id;
    }
    long long getCardNum() const
    {
        return card_num;
    }
    void setCardNum(long long num)
    {
        card_num = num;
    }
};

class Card
{
    long long cardNumber;
    string cardPin;
    double balance;

public:
    Card()
    {
        // Nothing to do here
    }
    Card(long long number, string pin)
    {
        cardNumber = number;
        cardPin = pin;
        balance = 0;
    }
    Card(long long number, string pin, double bal)
    {
        cardNumber = number;
        cardPin = pin;
        balance = bal;
    }
    long long getCardNumber() const
    {
        return cardNumber;
    }
    string getCardNumber_str() const
    {
        return to_string(cardNumber);
    }
    string getCardPin() const
    {
        return cardPin;
    }
    double getBalance() const
    {
        return balance;
    }
    void setCardNumber(int number)
    {
        cardNumber = number;
    }
    void setCardPin(int pin)
    {
        cardPin = pin;
    }
    void setBalance(double bal)
    {
        balance = bal;
    }
};

class Transaction
{
    string date;
    int userID;
    double amount;
    string type;
    int recieverID;

public:
    Transaction(const string &d, int id, double amt, const string &t)
        : date(d), userID(id), amount(amt), type(t) {}
    Transaction(const string &d, int id, double amt, const string &t, int recID)
        : date(d), userID(id), amount(amt), type(t), recieverID(recID) {}

    Transaction(int Id, double amount, string date, string type, string recieverid)
    {
        this->userID = Id;
        this->amount = amount;
        this->date = date;
        this->type = type;

        if (recieverid == "N/A")
        {
            this->recieverID = 0;
        }
        else
        {
            this->recieverID = stoi(recieverid);
        }
    }

    // getters
    string getDate() const { return date; }
    int getUserID() const { return userID; }
    double getAmount() const { return amount; }
    string getType() const { return type; }
    int getRecieverID() const { return recieverID; }

    string get_reciever_id() const
    {
        if (recieverID == 0)
        {
            return "N/A";
        }
        else
        {
            return to_string(this->recieverID);
        }
    }

    // setters
    void setDate(const string &d)
    {
        date = d;
    }
    void setUserID(int id)
    {
        userID = id;
    }
    void setAmount(double amt)
    {
        amount = amt;
    }
    void setType(const string &t)
    {
        type = t;
    }
    void setRecieverID(int recID)
    {
        recieverID = recID;
    }
};

class User
{
public:
    User()
    {
        // Nothing to do here
    }

    ~User()
    {
        // Nothing to do here
    }
};

class UserClient : public User
{
protected:
    int userID;
    string name;
    string address;
    string CNIC;
    string email;
    string password;
    double balance;
    int companyID;
    AccountType *accountType;
    vector<Transaction> transactions;
    vector<Card> cards;

public:
    UserClient(int id, string name, string add, string cnic, string email, string pass, double bal, long long estimate_limit) : User()
    {
        userID = id;
        this->name = name;
        address = add;
        CNIC = cnic;
        this->email = email;
        password = pass;
        balance = bal;

        companyID = 0;

        if (estimate_limit <= 100000 && estimate_limit > 0)
        {
            accountType = new Bronze;
        }
        else if (estimate_limit <= 500000 && estimate_limit > 100000)
        {
            accountType = new Gold;
        }
        else
        {
            cout << "Account type not allowed!" << endl;
        }
    }

    UserClient(int userID, string name, string address, string CNIC, string email, string password, double balance, int comp_ID, string accountName) : User()
    {
        this->userID = userID;
        this->name = name;
        this->address = address;
        this->CNIC = CNIC;
        this->email = email;
        this->password = password;
        this->balance = balance;
        companyID = comp_ID;

        if (accountName == "Bronze")
        {
            accountType = new Bronze;
        }
        else if (accountName == "Gold")
        {
            accountType = new Gold;
        }
        else if (accountName == "Business")
        {
            accountType = new Business;
        }
        else
        {
            cout << "Account type not allowed!" << endl;
        }
    }

    void save_cards(string filename)
    {
        ofstream fout(filename, ios::app);
        for (int i = 0; i < cards.size(); i++)
        {
            fout << userID << ", " << cards[i].getCardNumber() << ", " << cards[i].getCardPin() << ", " << cards[i].getBalance() << endl;
        }
        fout.close();
    }

    void save_transactions(string file)
    {
        ofstream fout(file, ios::app);
        for (int i = 0; i < transactions.size(); i++)
        {
            fout << transactions[i].getDate() << ", " << transactions[i].getUserID() << ", " << transactions[i].getAmount() << ", " << transactions[i].getType() << ", " << transactions[i].get_reciever_id() << endl;
        }
        fout.close();
    }

    void delete_user(int userID)
    {
        // check all transactions with user and recievr id equal to userID and delete them
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getUserID() == userID || transactions[i].getRecieverID() == userID)
            {
                transactions.erase(transactions.begin() + i);
            }
        }
    }

    void delete_comp(int CompID)
    {
        if (this->companyID == CompID)
        {
            this->companyID = 0;
        }
    }

    int get_Comp_ID()
    {
        return companyID;
    }

    void reset_Comp_ID(int id)
    {
        companyID = 0;
    }

    string getCardPin_per_index(int index)
    {
        return cards[index].getCardPin();
    }

    double total_transactions_amount_on_day(string day)
    {
        double total = 0;
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getDate() == day)
            {
                if (transactions[i].getType() == "Withdraw" || transactions[i].getType() == "Transfer")
                {
                    total += transactions[i].getAmount();
                }
            }
        }
        return total;
    }

    void setCompanyID(int id)
    {
        companyID = id;
    }

    double get_card_balance_by_index(int index)
    {
        return cards[index].getBalance();
    }

    void withdraw_card_by_index(int index, double amount)
    {
        double balance_new = cards[index].getBalance() - amount;
        cards[index].setBalance(balance_new);
        calculate_balance();
    }

    double getcardbalance_per_index(int index)
    {
        return cards[index].getBalance();
    }

    void deposit_card_by_index(int index, double amount)
    {
        cards[index].setBalance(cards[index].getBalance() + amount);
        calculate_balance();
    }

    void print_transactions()
    {
        cout << "Order is: Date, Amount, Type, User Id, Reciever ID" << endl
             << endl;
        for (int i = 0; i < transactions.size(); i++)
        {
            cout << i + 1 << ". " << transactions[i].getDate() << ", " << transactions[i].getAmount() << ", "
                 << transactions[i].getType() << ", " << transactions[i].getUserID() << ", "
                 << transactions[i].get_reciever_id() << endl;
        }
    }

    void calculate_balance()
    {
        // loop through all cards and get balances
        double bal = 0;
        for (int i = 0; i < cards.size(); i++)
        {
            bal += cards[i].getBalance();
        }
        this->balance = bal;
    }

    long long getCardNumber_per_index(int index)
    {
        return cards[index].getCardNumber();
    }

    int card_vector_size()
    {
        return cards.size();
    }

    int transaction_vector_size()
    {
        return transactions.size();
    }

    void add_transaction(const Transaction &transaction)
    {
        transactions.push_back(transaction);
    }

    void add_card(const Card &card)
    {
        cards.push_back(card);
    }

    void delete_card(int index)
    {
        cards.erase(cards.begin() + index);
    }

    // getters
    int getUserID() const
    {
        return userID;
    }
    string getName() const
    {
        return name;
    }
    string getAddress() const
    {
        return address;
    }
    string getCNIC() const
    {
        return CNIC;
    }
    string getEmail() const
    {
        return email;
    }
    string getPassword() const
    {
        return password;
    }
    double getBalance() const
    {
        return balance;
    }
    double getLimit() const
    {
        return accountType->getDailyWithdrawalLimit();
    }
    string getaccountname() const
    {
        return accountType->getAccountTypeName();
    }
    AccountType *getAccountType() const
    {
        return accountType;
    }
    vector<Transaction> getTransactions() const
    {
        return transactions;
    }
    vector<Card> getCards() const
    {
        return cards;
    }
    double get_withdraw_limit() const
    {
        return accountType->getDailyWithdrawalLimit();
    }

    // setters
    void setUserID(int id)
    {
        userID = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setAddress(string add)
    {
        address = add;
    }
    void setCNIC(string cnic)
    {
        CNIC = cnic;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setPassword(string pass)
    {
        password = pass;
    }
    void setBalance(double bal)
    {
        balance = bal;
    }
    void setAccountType(AccountType *accType)
    {
        accountType = accType;
    }

    ~UserClient()
    {
        delete accountType;
    }
};

class CompanyClient : public User
{
protected:
    int compID;
    string comp_name;
    string address;
    string tax_num;
    string email;
    string password;
    double balance;
    AccountType *accountType;
    vector<int> userids;
    vector<Transaction> transactions;
    vector<Card> cards;

public:
    CompanyClient(int id, string name, string add, string tax_num, string email, string pass, double bal, long long estimate_limit) : User()
    {
        compID = id;
        comp_name = name;
        address = add;
        this->tax_num = tax_num;
        this->email = email;
        password = pass;
        balance = bal;

        if (estimate_limit <= 100000 && estimate_limit > 0)
        {
            accountType = new Bronze;
        }
        else if (estimate_limit <= 500000 && estimate_limit > 100000)
        {
            accountType = new Gold;
        }
        else if (estimate_limit <= 20000000 && estimate_limit > 500000)
        {
            accountType = new Business;
        }
        else
        {
            cout << "Account type not allowed!" << endl;
        }
    }

    CompanyClient(int compID, string name, string address, string taxNum, string email, string password, double balance, string accountTypeName)
    {
        this->compID = compID;
        this->comp_name = name;
        this->address = address;
        this->tax_num = taxNum;
        this->email = email;
        this->password = password;
        this->balance = balance;

        if (accountTypeName == "Bronze")
        {
            accountType = new Bronze;
        }
        else if (accountTypeName == "Gold")
        {
            accountType = new Gold;
        }
        else if (accountTypeName == "Business")
        {
            accountType = new Business;
        }
        else
        {
            cout << "Account type not allowed!" << endl;
        }
    }

    void save_company_employees(string file)
    {
        ofstream fout(file, ios::app);
        for (int i = 0; i < userids.size(); i++)
        {
            fout << compID << ", " << userids[i] << endl;
        }
        fout.close();
    }

    void save_cards(string filename)
    {

        ofstream fout(filename, ios::app);
        for (int i = 0; i < cards.size(); i++)
        {
            fout << compID << ", " << cards[i].getCardNumber() << ", " << cards[i].getCardPin() << ", " << cards[i].getBalance() << endl;
        }
        fout.close();
    }

    void save_transactions(string file)
    {
        ofstream fout(file, ios::app);
        for (int i = 0; i < transactions.size(); i++)
        {
            fout << transactions[i].getDate() << ", " << transactions[i].getUserID() << ", " << transactions[i].getAmount() << ", " << transactions[i].getType() << ", " << transactions[i].get_reciever_id() << endl;
        }
        fout.close();
    }

    void delete_company_id(int compID_given)
    {
        // loop through transactions and delete transactions with user id = compID_given
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getUserID() == compID_given)
            {
                transactions.erase(transactions.begin() + i);
            }
        }
    }

    void delete_user_ids(int userID_given)
    {
        // check if reciever ids in transactions are equal to userID_given
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getRecieverID() == userID_given)
            {
                transactions.erase(transactions.begin() + i);
            }
        }
    }

    void setLoan(long long amt, long long crd)
    {
        for (int i = 0; i < cards.size(); i++)
        {
            if (cards[i].getCardNumber() == crd)
            {
                cards[i].setBalance(amt);
            }
        }
        calculate_balance();
    }

    void print_cards()
    {
        for (int i = 0; i < cards.size(); i++)
        {
            cout << i + 1 << ". " << cards[i].getCardNumber() << endl;
        }
        cout << endl;
    }

    bool id_exists_in_list(int id)
    {
        for (int i = 0; i < userids.size(); i++)
        {
            if (userids[i] == id)
            {
                return true;
            }
        }
        return false;
    }

    double total_transactions_amount_on_day(string day)
    {
        double total = 0;
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].getDate() == day)
            {
                if (transactions[i].getType() == "Withdraw" || transactions[i].getType() == "Transfer")
                {
                    total += transactions[i].getAmount();
                }
            }
        }
        return total;
    }

    int int_vector_size()
    {
        return userids.size();
    }

    bool UserID_exists(int userid)
    {
        for (int i = 0; i < userids.size(); i++)
        {
            if (userids[i] == userid)
            {
                return true;
            }
        }
        return false;
    }

    double getcardbalance_per_index(int index)
    {
        return cards[index].getBalance();
    }

    string getCardPin_per_index(int index)
    {
        return cards[index].getCardPin();
    }

    void print_transactions()
    {
        cout << "Order is: Date, Amount, Type, User Id, Reciever ID" << endl
             << endl;
        for (int i = 0; i < transactions.size(); i++)
        {
            cout << i + 1 << ". " << transactions[i].getDate() << ", " << transactions[i].getAmount() << ", "
                 << transactions[i].getType() << ", " << transactions[i].getUserID() << ", "
                 << transactions[i].get_reciever_id() << endl;
        }
    }

    double get_card_balance_by_index(int index)
    {
        return cards[index].getBalance();
    }

    void withdraw_card_by_index(int index, double amount)
    {
        cards[index].setBalance(cards[index].getBalance() - amount);
        calculate_balance();
    }

    void deposit_card_by_index(int index, double amount)
    {
        cards[index].setBalance(cards[index].getBalance() + amount);
        calculate_balance();
    }

    void delete_card(int index)
    {
        cards.erase(cards.begin() + index);
    }

    void calculate_balance()
    {
        // loop through all cards and get balances
        double bal = 0;
        for (int i = 0; i < cards.size(); i++)
        {
            bal += cards[i].getBalance();
        }
        this->balance = bal;
    }

    void add_user_id(int id)
    {
        userids.push_back(id);
    }

    long long getCardNumber_per_index(int index)
    {
        return cards[index].getCardNumber();
    }

    int card_vector_size()
    {
        return cards.size();
    }

    int transaction_vector_size()
    {
        return transactions.size();
    }

    void add_transaction(const Transaction &transaction)
    {
        transactions.push_back(transaction);
    }

    void add_card(const Card &card)
    {
        cards.push_back(card);
    }

    string get_pin_by_index(int index)
    {
        return cards[index].getCardPin();
    }

    // getters
    int getCompID() const
    {
        return compID;
    }
    string getName() const
    {
        return comp_name;
    }
    string getAddress() const
    {
        return address;
    }
    string getTaxNum() const
    {
        return tax_num;
    }
    string getEmail() const
    {
        return email;
    }
    string getPassword() const
    {
        return password;
    }
    double getBalance() const
    {
        return balance;
    }
    string getAccountTypeNamename() const
    {
        return accountType->getAccountTypeName();
    }
    AccountType *getAccountType() const
    {
        return accountType;
    }
    vector<Transaction> getTransactions() const
    {
        return transactions;
    }
    vector<Card> getCards() const
    {
        return cards;
    }
    double get_withdraw_limit() const
    {
        return accountType->getDailyWithdrawalLimit();
    }

    // setters
    void setCompID(int id)
    {
        compID = id;
    }
    void setName(string name)
    {
        comp_name = name;
    }
    void setAddress(string add)
    {
        address = add;
    }
    void setTaxNum(string tax_num)
    {
        this->tax_num = tax_num;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setPassword(string pass)
    {
        password = pass;
    }
    void setBalance(double bal)
    {
        balance = bal;
    }
    void setAccountType(AccountType *accType)
    {
        accountType = accType;
    }

    ~CompanyClient()
    {
        delete accountType;
    }
};

class BankEmployee : public User
{
protected:
    int employee_ID;
    string name;
    string username;
    string password;
    vector<UserClient *> userClients;
    vector<CompanyClient *> companyClients;

public:
    BankEmployee(string name, string username, string password, int ID) : User()
    {
        this->name = name;
        this->username = username;
        this->password = password;
        employee_ID = ID;
    }

    BankEmployee(int employee_ID, string name, string username, string password)
    {
        this->employee_ID = employee_ID;
        this->name = name;
        this->username = username;
        this->password = password;
    }

    void add_user_client(UserClient *userClient)
    {
        userClients.push_back(userClient);
    }

    void add_company_client(CompanyClient *companyClient)
    {
        companyClients.push_back(companyClient);
    }

    void delete_all_user_clients()
    {
        userClients.clear();
    }

    void delete_all_company_clients()
    {
        companyClients.clear();
    }

    // getters
    string getName() const
    {
        return name;
    }
    string getUsername() const
    {
        return username;
    }
    string getPassword() const
    {
        return password;
    }
    int getEmployeeID() const
    {
        return employee_ID;
    }
    vector<UserClient *> getUserClients() const
    {
        return userClients;
    }
    vector<CompanyClient *> getCompanyClients() const
    {
        return companyClients;
    }

    // setters
    void setName(string name)
    {
        this->name = name;
    }
    void setUsername(string username)
    {
        this->username = username;
    }
    void setPassword(string password)
    {
        this->password = password;
    }

    ~BankEmployee()
    {
        // Nothing to do here
    }
};

// global variables
vector<UserClient *> userClients;              // approved users
vector<UserClient *> userClients_temp;         // for approval from bank employee
vector<UserClient *> userClients_frozen;       // for frozen accounts
vector<CompanyClient *> companyClients;        // approved company clients
vector<CompanyClient *> companyClients_temp;   // for approval from bank employee
vector<CompanyClient *> companyClients_frozen; // for frozen accounts
vector<BankEmployee *> bankEmployees;
vector<cardWarning *> usercardWarnings;
vector<cardWarning *> companycardWarnings;
vector<Loan *> Loans_temp;
string currentUser;
string currentCompany;
string currentBankEmployee;
int currentUserID;
int currentCompanyID;
bool startCheck = true;

// function prototypes
void user_menu();
void user_menu_loggedin();
void check_files();
void company_menu_loggedin();
bool cnic_check(string cnic);
bool user_email_check(string email);
void user_check_info();
void bank_employee_menu();
void register_user_menu();
void login_user_menu();
void login_user();
bool existintemp(int compID);
void login_company();
void register_company();
void register_user();
void user_view_balance();
void user_withdraw();
void user_deposit();
void user_transfer();
void user_view_transactions();
void login_bank();
void register_bank();
void check_loan_requests();
void bank_employee_menu_loggedin();
void check_account_requests();
bool bank_user(string username);
void check_user_account_requests();
void check_company_account_requests();
void user_apply_card();
void user_delete_card();
bool request_acc(int id);
bool request_acc_comp(int id);
void view_all_accounts_list_menu();
void company_accounts_view_list();
void user_accounts_view_list();
void freeze_account_menu();
void freeze_user_account();
void freeze_company_account();
void unfreeze_company();
void unfreeze_user();
void unfreeze_account_menu();
void company_add_card();
void company_delete_card();
void close_user();
void close_company();
void close_account_menu();
void login_company_user_side();
void comp_or_user();
long long generate_card_number();
void check_company_cards();
bool check_card_pin(string pin);
void company_view_balance();
void company_withdraw();
void company_deposit();
void company_transfer();
void company_view_transactions();
void view_warning_list_menu();
void view_company_warnings_list();
void view_user_warnings_list();
void company_apply_loan();
void company_add_user();
void view_account_transactions_menu();
void view_user_account_transactions();
void view_company_account_transactions();
void view_transactions_user_side();
void transfer_money_user_side();
void withdraw_money_user_side();
void deposit_money_user_side();
void view_balance_user_side();
void company_menu_loggedin_user_side();
void save_all();
void save_user_clients();
void save_company_clients();
void save_bank_employee();
string get_current_date();
int main();

string get_current_date()
{
    // get curent date month and year in this format in string: yyyy-mm-dd
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string year = to_string(1900 + ltm->tm_year);
    string month = to_string(1 + ltm->tm_mon);
    string day = to_string(ltm->tm_mday);
    if (month.length() == 1)
    {
        month = "0" + month;
    }
    if (day.length() == 1)
    {
        day = "0" + day;
    }
    string date = year + "-" + month + "-" + day;
    return date;
}

bool user_email_check(string email)
{
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::userClients_temp.size(); i++)
    {
        if (::userClients_temp[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::companyClients_temp.size(); i++)
    {
        if (::companyClients_temp[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        if (::userClients_frozen[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        if (::companyClients_frozen[i]->getEmail() == email)
        {
            return false;
        }
    }

    return true;
}

bool cnic_check(string cnic)
{
    if (cnic.length() != 13)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < cnic.length(); i++)
        {
            if (cnic[i] < '0' || cnic[i] > '9')
            {
                return false;
            }
        }
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getCNIC() == cnic)
        {
            return false;
        }
    }

    return true;
}

void register_user()
{
    system("cls");
    int userID;
    string name;
    string address;
    string CNIC;
    string email;
    string password;
    double balance;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your CNIC: ";
    getline(cin, CNIC);

    while (!cnic_check(CNIC))
    {
        cout << endl;
        cout << "Invalid CNIC! Please enter again: ";
        getline(cin, CNIC);
    }

    cout << "Enter your email: ";
    getline(cin, email);

    while (!user_email_check(email))
    {
        cout << endl;
        cout << "Email already exists! Please enter again: ";
        getline(cin, email);
    }

    cout << "Enter your password: ";
    getline(cin, password);

    balance = 0.0; // default

    long long estimate_limit;
    cout << "Enter your estimated daily withdrawl limit (1-500000): ";
    cin >> estimate_limit;

    while (estimate_limit <= 0 || estimate_limit > 500000)
    {
        cout << endl;
        cout << "Invalid limit! Please enter again: ";
        cin >> estimate_limit;
    }

    int largest_user_id = 0;

    // check the largest user id that exists by checking each vector
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getUserID() > largest_user_id)
        {
            largest_user_id = userClients[i]->getUserID();
        }
    }

    for (int i = 0; i < ::userClients_temp.size(); i++)
    {
        if (::userClients_temp[i]->getUserID() > largest_user_id)
        {
            largest_user_id = userClients_temp[i]->getUserID();
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        if (::userClients_frozen[i]->getUserID() > largest_user_id)
        {
            largest_user_id = userClients_frozen[i]->getUserID();
        }
    }

    userID = largest_user_id + 1;

    UserClient *newuserClient = new UserClient(userID, name, address, CNIC, email, password, balance, estimate_limit);
    userClients_temp.push_back(newuserClient);

    cout << "Account request sent successfully!" << endl
         << endl;
    system("pause");
    main();
}

bool valid_tax_num(string tax_num)
{
    if (tax_num.length() != 13)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < tax_num.length(); i++)
        {
            if (tax_num[i] < '0' || tax_num[i] > '9')
            {
                return false;
            }
        }
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getTaxNum() == tax_num)
        {
            return false;
        }
    }

    return true;
}

bool check_email_comp(string email)
{
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::companyClients_temp.size(); i++)
    {
        if (::companyClients_temp[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::userClients_temp.size(); i++)
    {
        if (::userClients_temp[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        if (::companyClients_frozen[i]->getEmail() == email)
        {
            return false;
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        if (::userClients_frozen[i]->getEmail() == email)
        {
            return false;
        }
    }
    return true;
}

void register_company()
{
    int compID;
    string comp_name;
    string address;
    string tax_num;
    string email;
    string password;
    double balance;

    cout << "Enter your company name: ";
    cin.ignore();
    getline(cin, comp_name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your tax number: ";
    getline(cin, tax_num);

    while (!valid_tax_num(tax_num))
    {
        cout << endl;
        cout << "Invalid tax number! Please enter again: ";
        getline(cin, tax_num);
    }

    cout << "Enter your email: ";
    getline(cin, email);

    while (!check_email_comp(email))
    {
        cout << endl;
        cout << "Email already exists! Please enter again: ";
        getline(cin, email);
    }

    cout << "Enter your password: ";
    getline(cin, password);

    balance = 0.0; // default

    long long estimate_limit;
    cout << "Enter your estimated daily withdrawl limit (1-20000000): ";
    cin >> estimate_limit;
    while (estimate_limit <= 0 || estimate_limit > 20000000)
    {
        cout << endl;
        cout << "Invalid limit! Please enter again: ";
        cin >> estimate_limit;
    }

    int largest_comp_id = 0;

    // check the largest user id that exists by checking each vector
    for (int i = 0; i < ::companyClients_temp.size(); i++)
    {
        if (::companyClients_temp[i]->getCompID() > largest_comp_id)
        {
            largest_comp_id = companyClients_temp[i]->getCompID();
        }
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getCompID() > largest_comp_id)
        {
            largest_comp_id = companyClients[i]->getCompID();
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        if (::companyClients_frozen[i]->getCompID() > largest_comp_id)
        {
            largest_comp_id = companyClients_frozen[i]->getCompID();
        }
    }

    compID = largest_comp_id + 1;

    CompanyClient *newcompanyClient = new CompanyClient(compID, comp_name, address, tax_num, email, password, balance, estimate_limit);
    companyClients_temp.push_back(newcompanyClient);

    cout << "Account Request sent successfully!" << endl
         << endl;
    system("pause");
    main();
}

void register_user_menu()
{
    system("cls");
    cout << "1. Register as a user" << endl;
    cout << "2. Register as a company" << endl;
    cout << "3. Back to Main" << endl;
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        register_user();
    }
    else if (choice == 2)
    {
        register_company();
    }
    else if (choice == 3)
    {
        main();
    }
}

void login_user_menu()
{
    system("cls");

    cout << "1. Login as User" << endl;
    cout << "2. Login as Company" << endl;
    cout << "3. Back to Main" << endl;
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        // login_user();
        comp_or_user();
    }
    else if (choice == 2)
    {
        login_company();
    }
    else if (choice == 3)
    {
        main();
    }
}

void login_user()
{
    cout << "Enter Email: ";
    string email;
    cin.ignore();
    getline(cin, email);
    cout << "Enter Password: ";
    string password;
    getline(cin, password);

    bool found = false;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getEmail() == email && ::userClients[i]->getPassword() == password)
        {
            found = true;
            // string current user is equal to email
            ::currentUser = ::userClients[i]->getEmail();
            break;
        }
    }

    if (found == false)
    {
        cout << "Invalid email or password or Account not Approved Yet or Account Frozen!" << endl;

        system("pause");
        main();
    }
    else
    {
        cout << "Logged in Successfully!" << endl
             << endl;
        system("pause");
        user_menu_loggedin();
    }
}

void login_company()
{
    cout << "Enter your email: ";
    string email;
    cin.ignore();
    getline(cin, email);
    cout << "Enter your password: ";
    string password;
    getline(cin, password);

    bool found = false;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == email && ::companyClients[i]->getPassword() == password)
        {
            found = true;
            // string current user is equal to email
            ::currentCompany = ::companyClients[i]->getEmail();
            break;
        }
    }

    if (found == false)
    {
        cout << "Invalid email or password or Account not Approved Yet or Account Frozen!" << endl
             << endl;
        system("pause");
        main();
    }
    else
    {
        cout << "Logged in Successfully!" << endl;
        system("pause");
        company_menu_loggedin();
    }
}

void check_user_cards()
{
    system("cls");
    cout << endl;
    // loop through vector and find one with the same user email
    string useremail = ::currentUser;
    int size;
    long long card_num;
    string pin;
    int balance = 0;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getEmail() == useremail)
        {
            size = ::userClients[i]->card_vector_size();
            if (size > 0)
            {
                break;
            }
            else if (size == 0)
            {
                card_num = generate_card_number();
                cout << endl;
                cout << "Enter Card Pin for new Card (4 Digit): ";
                cin >> pin;
                while (!check_card_pin(pin))
                {
                    cout << "Invalid Pin! Please enter again: ";
                    cin >> pin;
                }
                Card newcard(card_num, pin);
                ::userClients[i]->add_card(newcard);
                cout << "Card Created Successfully!" << endl;
                system("pause");
                break;
            }
        }
    }
}

void check_company_cards()
{
    system("cls");
    cout << endl;
    // loop through vector and find one with the same user email
    string useremail = ::currentCompany;
    int size;
    long long card_num;
    string pin;
    int balance = 0;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == useremail)
        {
            size = ::companyClients[i]->card_vector_size();
            if (size > 0)
            {
                break;
            }
            else if (size == 0)
            {
                card_num = generate_card_number();
                cout << endl;
                cout << "Enter Card Pin for new Card (4 Digit): ";
                cin >> pin;
                while (!check_card_pin(pin))
                {
                    cout << "Invalid Pin! Please enter again: ";
                    cin >> pin;
                }
                Card newcard(card_num, pin);
                ::companyClients[i]->add_card(newcard);
                cout << "Card Created Successfully!" << endl;
                system("pause");
                break;
            }
        }
    }
}

bool check_card_pin(string pin)
{
    if (pin.length() != 4)
    {
        return false;
    }
    // check if all are numbers
    for (int i = 0; i < pin.length(); i++)
    {
        if (pin[i] < '0' || pin[i] > '9')
        {
            return false;
        }
    }
    return true;
}

long long generate_card_number()
{
    long long min_card_number = 1000000000000000;
    long long current_card_number = 1000000000000000;
    long long card_number;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        for (int j = 0; j < ::userClients[i]->card_vector_size(); j++)
        {
            current_card_number = ::userClients[i]->getCardNumber_per_index(j);
            if (current_card_number >= min_card_number)
            {
                min_card_number = current_card_number;
            }
        }
    }

    for (int i = 0; i < ::userClients_temp.size(); i++)
    {
        for (int j = 0; j < ::userClients_temp[i]->card_vector_size(); j++)
        {
            current_card_number = ::userClients_temp[i]->getCardNumber_per_index(j);
            if (current_card_number >= min_card_number)
            {
                min_card_number = current_card_number;
            }
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        for (int j = 0; j < ::userClients_frozen[i]->card_vector_size(); j++)
        {
            current_card_number = ::userClients_frozen[i]->getCardNumber_per_index(j);
            if (current_card_number >= min_card_number)
            {
                min_card_number = current_card_number;
            }
        }
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
        {
            current_card_number = ::companyClients[i]->getCardNumber_per_index(j);
            if (current_card_number >= min_card_number)
            {
                min_card_number = current_card_number;
            }
        }
    }

    for (int i = 0; i < ::companyClients_temp.size(); i++)
    {
        for (int j = 0; j < ::companyClients_temp[i]->card_vector_size(); j++)
        {
            current_card_number = ::companyClients_temp[i]->getCardNumber_per_index(j);
            if (current_card_number >= min_card_number)
            {
                min_card_number = current_card_number;
            }
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        for (int j = 0; j < ::companyClients_frozen[i]->card_vector_size(); j++)
        {
            current_card_number = ::companyClients_frozen[i]->getCardNumber_per_index(j);
            if (current_card_number >= min_card_number)
            {
                min_card_number = current_card_number;
            }
        }
    }

    card_number = min_card_number + 1;

    return card_number;
}

void comp_or_user()
{
    system("cls");
    cout << endl;
    cout << "1. Log into your User Account" << endl;
    cout << "2. Log into your Company Account" << endl;
    cout << "3. Back to Main" << endl;
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        login_user();
    }
    else if (choice == 2)
    {
        login_company_user_side();
    }
    else if (choice == 3)
    {
        main();
    }
}

void login_company_user_side()
{
    cout << "Enter Email: ";
    string email;
    cin.ignore();
    getline(cin, email);
    cout << "Enter Password: ";
    string password;
    getline(cin, password);

    bool found = false;
    bool found2 = false;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getEmail() == email && ::userClients[i]->getPassword() == password)
        {
            found = true;
            // string current user is equal to email
            ::currentUser = ::userClients[i]->getEmail();
            int user_id = ::userClients[i]->getUserID();
            int comp_id = ::userClients[i]->get_Comp_ID();
            ::currentUserID = user_id;
            ::currentCompanyID = comp_id;
            for (int j = 0; j < ::companyClients.size(); j++)
            {
                if (::companyClients[j]->getCompID() == comp_id)
                {
                    found2 = true;
                    ::currentCompany = ::companyClients[j]->getEmail();
                    break;
                }
            }
            break;
        }
    }

    if (found2 == false)
    {
        cout << "Company Client Not Available" << endl;
        system("pause");
        main();
    }

    if (found == false)
    {
        cout << "Invalid email or password or Account not Approved Yet or Account Frozen!" << endl;
        system("pause");
        main();
    }
    else
    {
        cout << "Logged in Successfully!" << endl
             << endl;
        system("pause");
        company_menu_loggedin_user_side();
    }
}

void company_menu_loggedin_user_side()
{
    system("cls");
    cout << endl;
    cout << "1. View Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transfer Money" << endl;
    cout << "5. View Transactions" << endl;
    cout << "6. Go Back to Main" << endl;
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;

    while (choice != 6 && choice != 5 && choice != 4 && choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        view_balance_user_side();
    }
    else if (choice == 2)
    {
        deposit_money_user_side();
    }
    else if (choice == 3)
    {
        withdraw_money_user_side();
    }
    else if (choice == 4)
    {
        transfer_money_user_side();
    }
    else if (choice == 5)
    {
        view_transactions_user_side();
    }
    else if (choice == 6)
    {
        ::currentCompany = "";
        ::currentUser = "";
        main();
    }
}

void view_balance_user_side()
{
    // view balance by looping
    cout << endl;
    // loop through user vector
    bool found = false;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        // if current user is equal to the email in the vector
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            // print out the limit
            cout << "Your Balance is: " << ::companyClients[i]->getBalance() << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No balance found!" << endl;
    }
    cout << endl;
    system("pause");
    company_menu_loggedin_user_side();
}

void deposit_money_user_side()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to deposit: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::currentCompany == ::companyClients[i]->getEmail())
        {

            // loop and ask which card to use
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::companyClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::companyClients[i]->getCompID();
                    long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::companycardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    company_menu_loggedin_user_side();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            ::companyClients[i]->deposit_card_by_index(index - 1, amount);
            string date = get_current_date();
            int userID = ::companyClients[i]->getCompID();
            string type = "Deposit";
            int recieverID = 0;
            Transaction transaction(date, userID, amount, type, recieverID);
            ::companyClients[i]->add_transaction(transaction);
            cout << endl
                 << "Deposit successful!" << endl;
            system("pause");
            company_menu_loggedin_user_side();
        }
    }
}

void withdraw_money_user_side()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to withdraw: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            double limit = ::companyClients[i]->get_withdraw_limit();
            string current_date = get_current_date();
            double amount_used = ::companyClients[i]->total_transactions_amount_on_day(current_date);

            if (amount_used + amount > limit)
            {
                cout << endl;
                cout << "You have exceeded your limit!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }

            // loop and ask which card to use
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            if (::companyClients[i]->get_card_balance_by_index(index - 1) < amount)
            {
                cout << endl;
                cout << "Insufficient funds in card!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::companyClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::companyClients[i]->getCompID();
                    long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::companycardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    company_menu_loggedin_user_side();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            ::companyClients[i]->withdraw_card_by_index(index - 1, amount);
            string date = get_current_date();
            int userID = ::companyClients[i]->getCompID();
            string type = "Withdraw";
            int recieverID = 0;
            Transaction transaction(date, userID, amount, type, recieverID);
            ::companyClients[i]->add_transaction(transaction);
            cout << endl
                 << "Withdraw successful!" << endl;
            system("pause");
            company_menu_loggedin_user_side();
        }
    }
}

void transfer_money_user_side()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to transfer: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            int temp_size = ::companyClients[i]->int_vector_size();

            if (temp_size == 0)
            {
                cout << endl;
                cout << "You have no employees to transfer to!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }

            double limit = ::companyClients[i]->get_withdraw_limit();
            string current_date = get_current_date();
            double amount_used = ::companyClients[i]->total_transactions_amount_on_day(current_date);

            if (amount_used + amount > limit)
            {
                cout << endl;
                cout << "You have exceeded your limit!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }

            // loop and ask which card to use
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            // check if card has balance
            while (::companyClients[i]->get_card_balance_by_index(index - 1) < amount)
            {
                cout << endl;
                cout << "Insufficient balance! Please enter again: ";
                cin >> amount;
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::companyClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::companyClients[i]->getCompID();
                    long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::companycardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    company_menu_loggedin_user_side();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            cout << endl;
            cout << "All Users with ID and Email are as Under: " << endl
                 << endl;

            if (userClients.size() == 0)
            {
                cout << "No users found!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }

            int num_accounts_available = 0;

            for (int k = 0; k < ::userClients.size(); k++)
            {
                if (::companyClients[i]->id_exists_in_list(::userClients[k]->getUserID()))
                {
                    cout << k + 1 << ". " << ::userClients[k]->getUserID() << ", " << ::userClients[k]->getEmail() << endl;
                    num_accounts_available++;
                }
            }

            if (num_accounts_available == 0)
            {
                cout << "-----------------------" << endl;
                cout << "No users found!" << endl;
                cout << "-----------------------" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }
            cout << endl;
            cout << "Enter UserID: ";
            int user_id_flag;
            cin >> user_id_flag;

            int index_flag = 0;

            bool found_flag = false;

            for (int k = 0; k < ::userClients.size(); k++)
            {
                if (::companyClients[i]->id_exists_in_list(::userClients[k]->getUserID()))
                {
                    if (user_id_flag == ::userClients[k]->getUserID())
                    {
                        index_flag = k;
                        found_flag = true;
                        break;
                    }
                }
            }

            if (found_flag == false)
            {
                cout << endl;
                cout << "Invalid UserID!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }
            int count = 0;
            cout << endl;
            cout << "Recievers cards numbers are below!" << endl
                 << endl;
            for (int l = 0; l < ::userClients[index_flag]->card_vector_size(); l++)
            {
                cout << l + 1 << ". " << ::userClients[index_flag]->getCardNumber_per_index(l) << endl;
                count++;
            }
            if (count == 0)
            {
                cout << "No cards found!" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }
            cout << endl;
            cout << "Enter index of the card you want to transfer to: ";
            int index2;
            cin >> index2;
            while (index2 > ::userClients[index_flag]->card_vector_size() || index2 < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index2;
            }

            // remove money using withdraw
            ::companyClients[i]->withdraw_card_by_index(index - 1, amount);

            // goto that user and add money using deposit
            ::userClients[index_flag]->deposit_card_by_index(index2 - 1, amount);

            string date = get_current_date();
            int userID = ::companyClients[i]->getCompID();
            string type = "Transfer";
            int recieverID = ::userClients[index_flag]->getUserID();
            Transaction transaction(date, userID, amount, type, recieverID);
            ::companyClients[i]->add_transaction(transaction);
            cout << endl
                 << "Transfer successful!" << endl;
            system("pause");
            company_menu_loggedin_user_side();
        }
    }
}

void view_transactions_user_side()
{
    system("cls");
    cout << endl;
    bool found = false;
    int size;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        // if current company is equal to the email in the vector
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            size = ::companyClients[i]->transaction_vector_size();
            if (size == 0)
            {
                cout << "--------------------------" << endl;
                cout << "No transactions found!" << endl;
                cout << "--------------------------" << endl;
                system("pause");
                company_menu_loggedin_user_side();
            }
            // print out the limit
            ::companyClients[i]->print_transactions();
            found = true;
            system("pause");
            company_menu_loggedin_user_side();
        }
    }

    if (found == false)
    {
        cout << "-------------------" << endl;
        cout << "Company not found!" << endl;
        cout << "-------------------" << endl;
        system("pause");
        company_menu_loggedin_user_side();
    }
}

void user_menu_loggedin()
{
    check_user_cards();
    system("cls");
    cout << endl;

    cout << "1. View Balance" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. View Transactions" << endl;
    cout << "6. Apply for a Card" << endl;
    cout << "7. Delete Card" << endl;
    cout << "8. Logout" << endl;

    int choice;
    cout << "Enter your choice (1-8): ";
    cin >> choice;

    while (choice != 8 && choice != 7 && choice != 6 && choice != 5 && choice != 4 && choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        user_view_balance();
    }
    else if (choice == 2)
    {
        user_withdraw();
    }
    else if (choice == 3)
    {
        user_deposit();
    }
    else if (choice == 4)
    {
        user_transfer();
    }
    else if (choice == 5)
    {
        user_view_transactions();
    }
    else if (choice == 6)
    {
        user_apply_card();
    }
    else if (choice == 7)
    {
        user_delete_card();
    }
    else if (choice == 8)
    {
        ::currentUser = "";
        main();
    }
}

void user_apply_card()
{
    system("cls");
    cout << endl;
    cout << "Enter 4 digit pin: ";
    string pin;
    cin >> pin;
    while (!check_card_pin(pin))
    {
        cout << endl;
        cout << "Invalid pin! Please enter again: ";
        cin >> pin;
    }
    cout << endl;
    long long card_num;
    card_num = generate_card_number();
    cout << "Your card number is: " << card_num << endl;
    Card newcard(card_num, pin);

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getEmail() == ::currentUser)
        {
            ::userClients[i]->add_card(newcard);
        }
    }
    cout << endl
         << "Card added successfully!" << endl;
    system("pause");
    user_menu_loggedin();
}

void user_delete_card()
{
    system("cls");
    cout << endl;
    // if the size of card vector is less then 1 give error

    for (int i = 0; i < userClients.size(); i++)
    {
        if (userClients[i]->getEmail() == ::currentUser)
        {
            if (userClients[i]->card_vector_size() < 2)
            {
                cout << "You must have extra cards to delete them!" << endl;
                system("pause");
                user_menu_loggedin();
            }
        }
    }
    // loop through card numbers
    for (int i = 0; i < userClients.size(); i++)
    {
        if (userClients[i]->getEmail() == ::currentUser)
        {
            for (int j = 0; j < userClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << userClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which Index do you want to delete? ";
            int index;
            cin >> index;
            while (index > userClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }
            userClients[i]->delete_card(index - 1);
        }
    }
    cout << endl
         << "Card deleted successfully!" << endl;
    system("pause");
    user_menu_loggedin();
}

void company_menu_loggedin()
{
    check_company_cards();
    system("cls");
    cout << endl;
    cout << "1. View Balance" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Transfer" << endl; // only to users inside the company
    cout << "5. Add Card" << endl;
    cout << "6. Delete Card" << endl;
    cout << "7. View Transactions" << endl;
    cout << "8. Apply for loan" << endl;
    cout << "9. Add User" << endl;
    cout << "10. Logout" << endl;
    int choice;
    cout << "Enter your choice (1-10): ";
    cin >> choice;

    while (choice != 10 && choice != 9 && choice != 8 && choice != 7 && choice != 6 && choice != 5 && choice != 4 && choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        company_view_balance();
    }
    else if (choice == 2)
    {
        company_withdraw();
    }
    else if (choice == 3)
    {
        company_deposit();
    }
    else if (choice == 4)
    {
        company_transfer();
    }
    else if (choice == 5)
    {
        company_add_card();
    }
    else if (choice == 6)
    {
        company_delete_card();
    }
    else if (choice == 7)
    {
        company_view_transactions();
    }
    else if (choice == 8)
    {
        company_apply_loan();
    }
    else if (choice == 9)
    {
        company_add_user();
    }
    else if (choice == 10)
    {
        ::currentCompany = "";
        main();
    }
}

void company_view_balance()
{
    // view balance by looping
    cout << endl;
    // loop through user vector
    bool found = false;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        // if current user is equal to the email in the vector
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            // print out the limit
            cout << "Your Balance is: " << ::companyClients[i]->getBalance() << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No balance found!" << endl;
    }
    cout << endl;
    system("pause");
    company_menu_loggedin();
}

void company_add_card()
{
    system("cls");
    cout << endl;
    cout << "Enter 4 digit pin: ";
    string pin;
    cin >> pin;
    while (!check_card_pin(pin))
    {
        cout << endl;
        cout << "Invalid pin! Please enter again: ";
        cin >> pin;
    }
    cout << endl;
    long long card_num;
    card_num = generate_card_number();
    cout << "Your card number is: " << card_num << endl;
    Card newcard(card_num, pin);

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == ::currentCompany)
        {
            ::companyClients[i]->add_card(newcard);
        }
    }
    cout << endl
         << "Card added successfully!" << endl;
    system("pause");
    company_menu_loggedin();
}

void company_delete_card()
{
    system("cls");
    cout << endl;
    // if the size of card vector is less then 1 give error

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == ::currentCompany)
        {
            if (::companyClients[i]->card_vector_size() < 2)
            {
                cout << "You must have extra cards to delete them!" << endl;
                system("pause");
                company_menu_loggedin();
            }
        }
    }
    // loop through card numbers
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getEmail() == ::currentCompany)
        {
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which Index do you want to delete? ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }
            ::companyClients[i]->delete_card(index - 1);
        }
    }
    cout << endl
         << "Card deleted successfully!" << endl;
    system("pause");
    company_menu_loggedin();
}

void company_withdraw()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to withdraw: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            double limit = ::companyClients[i]->get_withdraw_limit();
            string current_date = get_current_date();
            double amount_used = ::companyClients[i]->total_transactions_amount_on_day(current_date);

            if (amount_used + amount > limit)
            {
                cout << endl;
                cout << "You have exceeded your limit!" << endl;
                system("pause");
                company_menu_loggedin();
            }

            // loop and ask which card to use
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            if (::companyClients[i]->get_card_balance_by_index(index - 1) < amount)
            {
                cout << endl;
                cout << "Insufficient funds in card!" << endl;
                system("pause");
                company_menu_loggedin();
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::companyClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::companyClients[i]->getCompID();
                    long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::companycardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    company_menu_loggedin();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            ::companyClients[i]->withdraw_card_by_index(index - 1, amount);
            string date = get_current_date();
            int userID = ::companyClients[i]->getCompID();
            string type = "Withdraw";
            int recieverID = 0;
            Transaction transaction(date, userID, amount, type, recieverID);
            ::companyClients[i]->add_transaction(transaction);
            cout << endl
                 << "Withdraw successful!" << endl;
            system("pause");
            company_menu_loggedin();
        }
    }
}

void company_deposit()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to deposit: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::currentCompany == ::companyClients[i]->getEmail())
        {

            // loop and ask which card to use
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::companyClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::companyClients[i]->getCompID();
                    long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::companycardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    company_menu_loggedin();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            ::companyClients[i]->deposit_card_by_index(index - 1, amount);
            string date = get_current_date();
            int userID = ::companyClients[i]->getCompID();
            string type = "Deposit";
            int recieverID = 0;
            Transaction transaction(date, userID, amount, type, recieverID);
            ::companyClients[i]->add_transaction(transaction);
            cout << endl
                 << "Deposit successful!" << endl;
            system("pause");
            company_menu_loggedin();
        }
    }
}

void company_transfer()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to transfer: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            int temp_size = ::companyClients[i]->int_vector_size();

            if (temp_size == 0)
            {
                cout << endl;
                cout << "You have no employees to transfer to!" << endl;
                system("pause");
                company_menu_loggedin();
            }

            double limit = ::companyClients[i]->get_withdraw_limit();
            string current_date = get_current_date();
            double amount_used = ::companyClients[i]->total_transactions_amount_on_day(current_date);

            if (amount_used + amount > limit)
            {
                cout << endl;
                cout << "You have exceeded your limit!" << endl;
                system("pause");
                company_menu_loggedin();
            }

            int count = 0;

            // loop and ask which card to use
            for (int j = 0; j < ::companyClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::companyClients[i]->getCardNumber_per_index(j) << endl;
                count++;
            }

            if (count == 0)
            {
                cout << endl;
                cout << "You have no cards to transfer from!" << endl;
                system("pause");
                company_menu_loggedin();
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;

            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            // check if card has balance
            while (::companyClients[i]->get_card_balance_by_index(index - 1) < amount)
            {
                cout << endl;
                cout << "Insufficient balance! Please enter again: ";
                cin >> amount;
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::companyClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::companyClients[i]->getCompID();
                    long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::companycardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    company_menu_loggedin();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            cout << endl;
            cout << "All Users with ID and Email are as Under: " << endl
                 << endl;

            if (userClients.size() == 0)
            {
                cout << "No users found!" << endl;
                system("pause");
                company_menu_loggedin();
            }

            int num_accounts_available = 0;

            for (int k = 0; k < ::userClients.size(); k++)
            {
                if (::companyClients[i]->id_exists_in_list(::userClients[k]->getUserID()))
                {
                    cout << k + 1 << ". " << ::userClients[k]->getUserID() << ", " << ::userClients[k]->getEmail() << endl;
                    num_accounts_available++;
                }
            }

            if (num_accounts_available == 0)
            {
                cout << "-----------------------" << endl;
                cout << "No users found!" << endl;
                cout << "-----------------------" << endl;
                system("pause");
                company_menu_loggedin();
            }
            cout << endl;
            cout << "Enter UserID: ";
            int user_id_flag;
            cin >> user_id_flag;

            int index_flag = 0;

            bool found_flag = false;

            for (int k = 0; k < ::userClients.size(); k++)
            {
                if (::companyClients[i]->id_exists_in_list(::userClients[k]->getUserID()))
                {
                    if (user_id_flag == ::userClients[k]->getUserID())
                    {
                        index_flag = k;
                        found_flag = true;
                        break;
                    }
                }
            }

            if (found_flag == false)
            {
                cout << endl;
                cout << "Invalid UserID!" << endl;
                system("pause");
                company_menu_loggedin();
            }

            cout << endl;
            cout << "Recievers cards numbers are below!" << endl
                 << endl;
            int count_2 = 0;
            for (int l = 0; l < ::userClients[index_flag]->card_vector_size(); l++)
            {
                cout << l + 1 << ". " << ::userClients[index_flag]->getCardNumber_per_index(l) << endl;
                count_2++;
            }
            if (count_2 == 0)
            {
                cout << endl;
                cout << "No cards found!" << endl;
                system("pause");
                company_menu_loggedin();
            }
            cout << endl;
            cout << "Enter index of the card you want to transfer to: ";
            int index2;
            cin >> index2;
            while (index2 > ::userClients[index_flag]->card_vector_size() || index2 < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index2;
            }

            // remove money using withdraw
            ::companyClients[i]->withdraw_card_by_index(index - 1, amount);

            // goto that user and add money using deposit
            ::userClients[index_flag]->deposit_card_by_index(index2 - 1, amount);

            string date = get_current_date();
            int userID = ::companyClients[i]->getCompID();
            string type = "Transfer";
            int recieverID = ::userClients[index_flag]->getUserID();
            Transaction transaction(date, userID, amount, type, recieverID);
            ::companyClients[i]->add_transaction(transaction);
            cout << endl
                 << "Transfer successful!" << endl;
            system("pause");
            company_menu_loggedin();
        }
    }
}

void company_view_transactions()
{
    system("cls");
    cout << endl;
    bool found = false;
    int size;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        // if current company is equal to the email in the vector
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            size = ::companyClients[i]->transaction_vector_size();
            if (size == 0)
            {
                cout << "--------------------------" << endl;
                cout << "No transactions found!" << endl;
                cout << "--------------------------" << endl;
                system("pause");
                company_menu_loggedin();
            }
            // print out the limit
            ::companyClients[i]->print_transactions();
            found = true;
            system("pause");
            company_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << "-------------------" << endl;
        cout << "Company not found!" << endl;
        cout << "-------------------" << endl;
        system("pause");
        company_menu_loggedin();
    }
}

void company_apply_loan()
{
    system("cls");
    cout << endl;
    cout << "How much loan do you want to apply for: ";
    int amount;
    cin >> amount;
    while (amount < 0 || amount > 1000000000)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    bool found = false;
    int size = 0;
    int size_temp = 0;
    int id;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        // if current company is equal to the email in the vector
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            id = ::companyClients[i]->getCompID();
            // size = ::Loans.size();
            /*if (size == 0)
            {
                cout << "--------------------------" << endl;
                cout << "No loans found!" << endl;
                cout << "--------------------------" << endl;
                system("pause");
                company_menu_loggedin();
            }*/

            /*if (size > 0)
            {
                for (int j = 0; j < size; j++)
                {
                    if (::Loans[j]->getCompID() == id)
                    {
                        size_temp++;
                    }
                }

                if (size_temp == 1)
                {
                    cout << "--------------------------" << endl;
                    cout << "You already have a loan!" << endl;
                    cout << "--------------------------" << endl;
                    system("pause");
                    company_menu_loggedin();
                }
            }*/
            // print company cards
            if (::companyClients[i]->card_vector_size() == 0)
            {
                cout << "--------------------------" << endl;
                cout << "You have no cards!" << endl;
                cout << "--------------------------" << endl;
                system("pause");
                company_menu_loggedin();
            }
            else
            {
                cout << endl;
                ::companyClients[i]->print_cards();
            }
            cout << "Enter index of the card you want to apply loan for: ";
            int index;
            cin >> index;
            while (index > ::companyClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }
            // enter pin
            cout << endl;
            cout << "Enter pin: ";
            string pin;
            cin >> pin;
            long long card_num = ::companyClients[i]->getCardNumber_per_index(index - 1);
            while (pin != ::companyClients[i]->get_pin_by_index(index - 1))
            {
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }
            found = true;
            Loan *loan_new = new Loan(amount, id, card_num);
            ::Loans_temp.push_back(loan_new);
            cout << endl
                 << "Loan request sent successfully!" << endl;
            system("pause");
            company_menu_loggedin();
        }
    }
    if (found == false)
    {
        cout << "-------------------" << endl;
        cout << "Company not found!" << endl;
        cout << "-------------------" << endl;
        system("pause");
        company_menu_loggedin();
    }
}

void company_add_user()
{
    system("cls");
    cout << endl;
    // loop through userClient vector and display all users
    int size = ::userClients.size();
    if (size == 0)
    {
        cout << "---------------------------" << endl;
        cout << "No users available to add!" << endl;
        cout << "---------------------------" << endl;
        system("pause");
        company_menu_loggedin();
    }

    cout << "Order is: Email, Name, UserID" << endl
         << endl;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        cout << i + 1 << ". " << ::userClients[i]->getEmail() << ", " << ::userClients[i]->getName() << ", " << ::userClients[i]->getUserID() << endl;
    }
    cout << endl;
    cout << "Which user do you want to add? (Enter Index): ";
    int index;
    cin >> index;

    while (index > ::userClients.size() || index < 1)
    {
        cout << endl;
        cout << "Invalid index! Please enter again: ";
        cin >> index;
    }

    // get email and Userid from index
    string email = ::userClients[index - 1]->getEmail();
    int userid = ::userClients[index - 1]->getUserID();

    if (::userClients[index - 1]->get_Comp_ID() > 0)
    {
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "User already exists in an a Company!" << endl;
        cout << "------------------------------------" << endl;
        system("pause");
        company_menu_loggedin();
    }

    // loop through companyClients vector and check if userid already exists in vector
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->UserID_exists(userid) == true)
        {
            cout << endl;
            cout << "------------------------------------" << endl;
            cout << "User already exists in an a Company!" << endl;
            cout << "------------------------------------" << endl;
            system("pause");
            company_menu_loggedin();
        }
    }

    int CompanyID_temp = 0;

    // loop through companyClients
    for (int j = 0; j < ::companyClients.size(); j++)
    {
        // if current company is equal to the email in the vector
        if (::currentCompany == ::companyClients[j]->getEmail())
        {
            // add user to the company
            CompanyID_temp = ::companyClients[j]->getCompID();

            /*if (CompanyID_temp > 0)
            {
                cout << "Error: User Already added to a company!" << endl;
                system("pause");
                company_menu_loggedin();
            }*/
        }
    }

    // loop through companyClients
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        // if current company is equal to the email in the vector
        if (::currentCompany == ::companyClients[i]->getEmail())
        {
            // add compid to the user
            userClients[index - 1]->setCompanyID(CompanyID_temp);
            // add user to the company
            ::companyClients[i]->add_user_id(userid);
            cout << endl;
            cout << "------------------------" << endl;
            cout << "User added successfully!" << endl;
            cout << "------------------------" << endl;
            system("pause");
            company_menu_loggedin();
        }
    }

    cout << endl;
    cout << "------------------------" << endl;
    cout << "Company not found!" << endl;
    cout << "------------------------" << endl;
    system("pause");
    company_menu_loggedin();
}

void user_check_info()
{
    cout << endl;
    // loop through user vector
    bool found = false;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        // if current user is equal to the email in the vector
        if (::currentUser == ::userClients[i]->getEmail())
        {
            // print out the limit
            cout << "Your UserID is: " << ::userClients[i]->getUserID() << endl;
            cout << "Your account limit is: " << ::userClients[i]->getLimit() << endl;
            cout << "Your Account Type is: " << ::userClients[i]->getaccountname() << endl
                 << endl;
            found = true;
            system("pause");
            user_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << "User not found!" << endl;
        system("pause");
        user_menu_loggedin();
    }
}

void user_view_balance()
{
    cout << endl;
    // loop through user vector
    bool found = false;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        // if current user is equal to the email in the vector
        if (::currentUser == ::userClients[i]->getEmail())
        {
            // print out the limit
            cout << "Your account balance is: " << ::userClients[i]->getBalance() << endl;
            found = true;
            system("pause");
            user_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << "-------------------" << endl;
        cout << "User not found!" << endl;
        cout << "-------------------" << endl;
        system("pause");
        user_menu_loggedin();
    }
}

void user_withdraw()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to withdraw: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::currentUser == ::userClients[i]->getEmail())
        {
            double limit = ::userClients[i]->get_withdraw_limit();
            string current_date = get_current_date();
            double amount_used = ::userClients[i]->total_transactions_amount_on_day(current_date);

            if (amount_used + amount > limit)
            {
                cout << endl;
                cout << "You have exceeded your limit!" << endl;
                system("pause");
                user_menu_loggedin();
            }

            // loop and ask which card to use
            for (int j = 0; j < ::userClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::userClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::userClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }
            if (::userClients[i]->get_card_balance_by_index(index - 1) < amount)
            {
                cout << endl;
                cout << "Insufficient funds in card!" << endl;
                system("pause");
                user_menu_loggedin();
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::userClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::userClients[i]->getUserID();
                    long long card_num = ::userClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::usercardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    user_menu_loggedin();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            ::userClients[i]->withdraw_card_by_index(index - 1, amount);
            string date = get_current_date();
            int userID = ::userClients[i]->getUserID();
            string type = "Withdraw";
            int recieverID = 0;
            Transaction transaction(date, userID, amount, type, recieverID);
            ::userClients[i]->add_transaction(transaction);
            cout << endl
                 << "Withdraw successful!" << endl;
            system("pause");
            user_menu_loggedin();
        }
    }
}

void user_deposit()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to deposit: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::currentUser == ::userClients[i]->getEmail())
        {

            // loop and ask which card to use
            for (int j = 0; j < ::userClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::userClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::userClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::userClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::userClients[i]->getUserID();
                    long long card_num = ::userClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::usercardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    user_menu_loggedin();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            ::userClients[i]->deposit_card_by_index(index - 1, amount);
            string date = get_current_date();
            int userID = ::userClients[i]->getUserID();
            string type = "Deposit";
            int recieverID = 0;
            Transaction transaction(date, userID, amount, type, recieverID);
            ::userClients[i]->add_transaction(transaction);
            cout << endl
                 << "Deposit successful!" << endl;
            system("pause");
            user_menu_loggedin();
        }
    }
}

void user_transfer()
{
    system("cls");
    cout << endl;
    string pin;
    cout << "Enter amount to transfer: ";
    double amount;
    cin >> amount;
    while (amount < 1)
    {
        cout << endl;
        cout << "Invalid amount! Please enter again: ";
        cin >> amount;
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::currentUser == ::userClients[i]->getEmail())
        {
            double limit = ::userClients[i]->get_withdraw_limit();
            string current_date = get_current_date();
            double amount_used = ::userClients[i]->total_transactions_amount_on_day(current_date);

            if (amount_used + amount > limit)
            {
                cout << endl;
                cout << "You have exceeded your limit!" << endl;
                system("pause");
                user_menu_loggedin();
            }

            // loop and ask which card to use
            for (int j = 0; j < ::userClients[i]->card_vector_size(); j++)
            {
                cout << j + 1 << ". " << ::userClients[i]->getCardNumber_per_index(j) << endl;
            }
            cout << endl;
            cout << "Which card do you want to use? (Enter Index): ";
            int index;
            cin >> index;
            while (index > ::userClients[i]->card_vector_size() || index < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index;
            }

            // check if card has balance
            while (::userClients[i]->get_card_balance_by_index(index - 1) < amount)
            {
                cout << endl;
                cout << "Insufficient balance! Please enter again: ";
                cin >> amount;
            }

            cout << endl;
            cout << "Enter pin: ";
            cin >> pin;
            int error = 0;
            while (pin != ::userClients[i]->getCardPin_per_index(index - 1))
            {
                if (error >= 3)
                {
                    cout << endl;
                    int id = ::userClients[i]->getUserID();
                    long long card_num = ::userClients[i]->getCardNumber_per_index(index - 1);
                    cardWarning *card_warning = new cardWarning(id, card_num);
                    ::usercardWarnings.push_back(card_warning);
                    cout << "Too many errors! Please try again later!" << endl;
                    system("pause");
                    user_menu_loggedin();
                }
                error++;
                cout << endl;
                cout << "Invalid pin! Please enter again: ";
                cin >> pin;
            }

            cout << endl;
            cout << "All Users with ID and Email are as Under: " << endl
                 << endl;

            int count = 0;

            for (int k = 0; k < ::userClients.size(); k++)
            {
                cout << k + 1 << ". " << ::userClients[k]->getUserID() << ", " << ::userClients[k]->getEmail() << endl;
                count++;
            }
            if (count == 0)
            {
                cout << "No users found!" << endl;
                system("pause");
                user_menu_loggedin();
            }
            cout << endl;
            cout << "Enter index of the user you want to transfer to: ";
            int index1;
            cin >> index1;
            while (index1 > ::userClients.size() || index1 < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index1;
            }

            cout << endl;
            cout << "Recievers cards numbers are below!" << endl
                 << endl;
            int count_temp = 0;
            for (int l = 0; l < ::userClients[index1 - 1]->card_vector_size(); l++)
            {
                cout << l + 1 << ". " << ::userClients[index1 - 1]->getCardNumber_per_index(l) << endl;
                count_temp++;
            }

            if (count_temp == 0)
            {
                cout << "No cards found!" << endl;
                system("pause");
                user_menu_loggedin();
            }
            cout << endl;
            cout << "Enter index of the card you want to transfer to: ";
            int index2;
            cin >> index2;
            while (index2 > ::userClients[index1 - 1]->card_vector_size() || index2 < 1)
            {
                cout << endl;
                cout << "Invalid index! Please enter again: ";
                cin >> index2;
            }

            // remove money using withdraw
            ::userClients[i]->withdraw_card_by_index(index - 1, amount);

            // goto that user and add money using deposit
            ::userClients[index1 - 1]->deposit_card_by_index(index2 - 1, amount);

            string date = get_current_date();
            int userID = ::userClients[i]->getUserID();
            string type = "Transfer";
            int recieverID = ::userClients[index1 - 1]->getUserID();
            Transaction transaction(date, userID, amount, type, recieverID);
            ::userClients[i]->add_transaction(transaction);
            cout << endl
                 << "Transfer successful!" << endl;
            system("pause");
            user_menu_loggedin();
        }
    }
}

void user_view_transactions()
{
    cout << endl;
    // loop through user vector
    bool found = false;
    int size;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        // if current user is equal to the email in the vector
        if (::currentUser == ::userClients[i]->getEmail())
        {
            size = ::userClients[i]->transaction_vector_size();
            if (size == 0)
            {
                cout << "--------------------------" << endl;
                cout << "No transactions found!" << endl;
                cout << "--------------------------" << endl;
                system("pause");
                user_menu_loggedin();
            }
            // print out the limit
            ::userClients[i]->print_transactions();
            found = true;
            system("pause");
            user_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << "-------------------" << endl;
        cout << "User not found!" << endl;
        cout << "-------------------" << endl;
        system("pause");
        user_menu_loggedin();
    }
}

void user_menu()
{
    system("cls");
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Back to Main" << endl;
    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        register_user_menu();
    }
    else if (choice == 2)
    {
        login_user_menu();
    }
    else if (choice == 3)
    {
        main();
    }
}

void bank_employee_menu()
{
    system("cls");
    cout << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Back to Main" << endl;
    int choice;

    cout << "Enter your choice (1-3): ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        login_bank();
    }
    else if (choice == 2)
    {
        register_bank();
    }
    else if (choice == 3)
    {
        main();
    }
}

void login_bank()
{
    cout << endl;
    cout << "Enter Username: ";
    string username;
    cin.ignore();
    getline(cin, username);
    cout << "Enter Password: ";
    string password;
    getline(cin, password);

    bool found = false;
    for (int i = 0; i < ::bankEmployees.size(); i++)
    {
        if (::bankEmployees[i]->getUsername() == username && ::bankEmployees[i]->getPassword() == password)
        {
            found = true;
            ::currentBankEmployee = ::bankEmployees[i]->getName();
            cout << "Logged in Successfully!" << endl;
            system("pause");
            bank_employee_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << "Invalid Username or Password!" << endl;
        system("pause");
        bank_employee_menu();
    }
}

void register_bank()
{
    int employee_ID;
    string name;
    string username;
    string password;
    cout << endl;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your Username: ";
    getline(cin, username);

    while (bank_user(username) == true)
    {
        cout << "Username already exists!" << endl;
        cout << "Enter Username Again: ";
        getline(cin, username);
    }

    cout << "Enter your Password: ";
    getline(cin, password);

    int largest_employee_id = 0;
    for (int i = 0; i < ::bankEmployees.size(); i++)
    {
        if (::bankEmployees[i]->getEmployeeID() > largest_employee_id)
        {
            largest_employee_id = ::bankEmployees[i]->getEmployeeID();
        }
    }

    employee_ID = largest_employee_id + 1;

    BankEmployee *newEmployee = new BankEmployee(name, username, password, employee_ID);
    ::bankEmployees.push_back(newEmployee);

    cout << endl;
    cout << "Account created successfully!" << endl;
    system("pause");
    main();
}

bool bank_user(string username)
{
    for (int i = 0; i < ::bankEmployees.size(); i++)
    {
        if (::bankEmployees[i]->getUsername() == username)
        {
            return true;
        }
    }
    return false;
}

void bank_employee_menu_loggedin()
{
    system("cls");
    cout << endl;
    cout << "1. Check Account Requests" << endl;
    cout << "2. View All Accounts list" << endl;
    cout << "3. View Account Transactions" << endl;
    cout << "4. Freeze Account" << endl;
    cout << "5. Unfreeze Account" << endl;
    cout << "6. Check Loan Requests" << endl;
    cout << "7. Close Account" << endl;
    cout << "8. View Warning List" << endl;
    cout << "9. Back to Main" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    while (choice != 9 && choice != 8 && choice != 7 && choice != 6 && choice != 5 && choice != 4 && choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        check_account_requests();
    }
    else if (choice == 2)
    {
        view_all_accounts_list_menu();
    }
    else if (choice == 3)
    {
        view_account_transactions_menu();
    }
    else if (choice == 4)
    {
        freeze_account_menu();
    }
    else if (choice == 5)
    {
        unfreeze_account_menu();
    }
    else if (choice == 6)
    {
        check_loan_requests();
    }
    else if (choice == 7)
    {
        close_account_menu();
    }
    else if (choice == 8)
    {
        view_warning_list_menu();
    }
    else if (choice == 9)
    {
        main();
    }
}

void check_loan_requests()
{
    system("cls");
    cout << endl;

    if (::Loans_temp.size() == 0)
    {
        cout << "No Loan Requests!" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    cout << "The Order is: Index, CompanyId, Amount, Card Number" << endl;
    for (int i = 0; i < ::Loans_temp.size(); i++)
    {
        cout << i + 1 << ". " << ::Loans_temp[i]->getCompID() << ", " << ::Loans_temp[i]->getAmount() << ", " << ::Loans_temp[i]->getCardNum() << endl;
    }
    cout << endl;

    cout << "Enter Company ID: " << endl;
    int compID;
    cin >> compID;

    while (!existintemp(compID))
    {
        cout << "Invalid Company ID! Please enter again: ";
        cin >> compID;
    }

    cout << "1. Accept" << endl;
    cout << "2. Reject" << endl;
    cout << "Choice: ";
    int choice1;
    cin >> choice1;

    while (choice1 != 1 && choice1 != 2)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice1;
    }

    if (choice1 == 1)
    {
        for (int a = 0; a < ::Loans_temp.size(); a++)
        {
            if (::Loans_temp[a]->getCompID() == compID)
            {
                int id_new = ::Loans_temp[a]->getCompID();
                long long amount_new = ::Loans_temp[a]->getAmount();
                long long card_new = ::Loans_temp[a]->getCardNum();
                for (int b = 0; b < ::companyClients.size(); b++)
                {
                    if (::companyClients[b]->getCompID() == id_new)
                    {
                        ::companyClients[b]->setLoan(amount_new, card_new);
                        break;
                    }
                }
                // ::Loans.push_back(::Loans_temp[a]);
                ::Loans_temp.erase(::Loans_temp.begin() + a);
            }
        }
        cout << endl;
        cout << "Loan Accepted!" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }
    else if (choice1 == 2)
    {
        for (int i = 0; i < ::Loans_temp.size(); i++)
        {
            if (::Loans_temp[i]->getCompID() == compID)
            {
                ::Loans_temp.erase(::Loans_temp.begin() + i);
            }
        }
        cout << endl;
        cout << "Loan Rejected!" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }
}

bool existintemp(int compID)
{
    for (int i = 0; i < ::Loans_temp.size(); i++)
    {
        if (::Loans_temp[i]->getCompID() == compID)
        {
            return true;
        }
    }
    return false;
}

void view_account_transactions_menu()
{
    system("cls");
    cout << endl;
    cout << "1. View User Account Transactions" << endl;
    cout << "2. View Company Account Transactions" << endl;
    cout << "3. Back" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        view_user_account_transactions();
    }
    else if (choice == 2)
    {
        view_company_account_transactions();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void view_user_account_transactions()
{
    system("cls");
    cout << endl;
    cout << "Note: You can view transactions for frozen and active accounts\n"
         << endl;
    cout << "Enter UserID: ";
    int account_number;
    cin >> account_number;

    while (account_number < 1)
    {
        cout << endl;
        cout << "Invalid ID! Please enter again: ";
        cin >> account_number;
    }

    bool found = false;
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (::userClients[i]->getUserID() == account_number)
        {
            found = true;
            cout << endl;

            ::userClients[i]->print_transactions();

            system("pause");
            bank_employee_menu_loggedin();
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        if (::userClients_frozen[i]->getUserID() == account_number)
        {
            found = true;
            cout << endl;
            for (int j = 0; j < ::userClients_frozen[i]->getTransactions().size(); j++)
            {
                ::userClients_frozen[i]->print_transactions();
            }
            system("pause");
            bank_employee_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << endl;
        cout << "-----------------------" << endl;
        cout << "Account not found!" << endl;
        cout << "-----------------------" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }
}

void view_company_account_transactions()
{
    system("cls");
    cout << endl;
    cout << "Note: You can view tranactions for frozen and active accounts\n"
         << endl;
    cout << "Enter Company ID: ";
    int account_number;
    cin >> account_number;

    while (account_number < 1)
    {
        cout << endl;
        cout << "Invalid ID! Please enter again: ";
        cin >> account_number;
    }

    bool found = false;
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (::companyClients[i]->getCompID() == account_number)
        {
            found = true;
            cout << endl;
            for (int j = 0; j < ::companyClients[i]->getTransactions().size(); j++)
            {
                ::companyClients[i]->print_transactions();
            }
            system("pause");
            bank_employee_menu_loggedin();
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        if (::companyClients_frozen[i]->getCompID() == account_number)
        {
            found = true;
            cout << endl;
            for (int j = 0; j < ::companyClients_frozen[i]->getTransactions().size(); j++)
            {
                ::companyClients_frozen[i]->print_transactions();
            }
            system("pause");
            bank_employee_menu_loggedin();
        }
    }

    if (found == false)
    {
        cout << endl;
        cout << "-----------------------" << endl;
        cout << "Account not found!" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }
}

void view_warning_list_menu()
{
    system("cls");
    cout << endl;
    cout << "1. View User Warnings List" << endl;
    cout << "2. View Company Warnings List" << endl;
    cout << "3. Back" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        view_user_warnings_list();
    }
    else if (choice == 2)
    {
        view_company_warnings_list();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void view_user_warnings_list()
{
    system("cls");
    cout << endl;
    int size = ::usercardWarnings.size();

    if (size == 0)
    {
        cout << "--------------------" << endl;
        cout << "No warnings found!" << endl;
        cout << "--------------------" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    for (int i = 0; i < size; i++)
    {
        cout << "--------------------" << endl;
        cout << "Warning: "
             << "Wrong PIN entered 3 times" << endl;
        cout << "--------------------" << endl;
        cout << "Card Number: " << ::usercardWarnings[i]->getCardNum() << endl;
        cout << "User ID: " << ::usercardWarnings[i]->getID() << endl;
        cout << "--------------------" << endl;
    }

    system("pause");
    bank_employee_menu_loggedin();
}

void view_company_warnings_list()
{
    system("cls");
    cout << endl;
    int size = ::companycardWarnings.size();

    if (size == 0)
    {
        cout << "--------------------" << endl;
        cout << "No warnings found!" << endl;
        cout << "--------------------" << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    for (int i = 0; i < size; i++)
    {
        cout << "--------------------" << endl;
        cout << "Warning: "
             << "Wrong PIN entered 3 times" << endl;
        cout << "--------------------" << endl;
        cout << "Card Number: " << ::companycardWarnings[i]->getCardNum() << endl;
        cout << "User ID: " << ::companycardWarnings[i]->getID() << endl;
        cout << "--------------------" << endl;
    }

    system("pause");
    bank_employee_menu_loggedin();
}

void close_account_menu()
{
    system("cls");
    cout << endl;
    cout << "1. Close User Account" << endl;
    cout << "2. Close Company Account" << endl;
    cout << "3. Back" << endl;
    int choice;
    cout << "Choose an option: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        close_user();
    }
    else if (choice == 2)
    {
        close_company();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void close_user()
{
    system("cls");
    cout << endl;

    cout << "Enter UserID: ";
    int userID;
    cin >> userID;

    bool found = false;

    string userEmail;

    // loop through vector of class userClients
    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (userID == ::userClients[i]->getUserID())
        {
            userEmail = ::userClients[i]->getEmail();
            found = true;
            break;
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        if (userID == ::userClients_frozen[i]->getUserID())
        {
            userEmail = ::userClients_frozen[i]->getEmail();
            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "------------------" << endl;
        cout << "User not found!" << endl;
        cout << "------------------\n"
             << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        if (userID == ::userClients[i]->getUserID())
        {
            ::userClients.erase(::userClients.begin() + i);
            break;
        }
    }

    for (int i = 0; i < ::userClients.size(); i++)
    {
        ::userClients[i]->delete_user(userID);
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        if (userID == ::userClients_frozen[i]->getUserID())
        {
            ::userClients_frozen.erase(::userClients_frozen.begin() + i);
            break;
        }
    }

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        ::userClients_frozen[i]->delete_user(userID);
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        ::companyClients[i]->delete_user_ids(userID);
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        ::companyClients_frozen[i]->delete_user_ids(userID);
    }

    for (int i = 0; i < usercardWarnings.size(); i++)
    {
        if (userID == usercardWarnings[i]->getID())
        {
            usercardWarnings.erase(usercardWarnings.begin() + i);
            break;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Account closed successfully!" << endl;
    cout << "------------------------------------\n"
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void close_company()
{
    system("cls");
    cout << endl;

    cout << "Enter Company ID: ";
    int userID;
    cin >> userID;

    string compemail;

    bool found = false;

    // loop through vector of class userClients
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (userID == ::companyClients[i]->getCompID())
        {
            compemail = ::companyClients[i]->getEmail();
            found = true;
            break;
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        if (userID == ::companyClients_frozen[i]->getCompID())
        {
            compemail = ::companyClients_frozen[i]->getEmail();
            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "------------------" << endl;
        cout << "Company not found!" << endl;
        cout << "------------------\n"
             << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        if (userID == ::companyClients[i]->getCompID())
        {
            ::companyClients.erase(::companyClients.begin() + i);
            break;
        }
    }

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        ::companyClients[i]->delete_company_id(userID);
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        if (userID == ::companyClients_frozen[i]->getCompID())
        {
            ::companyClients_frozen.erase(::companyClients_frozen.begin() + i);
            break;
        }
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        ::companyClients_frozen[i]->delete_company_id(userID);
    }

    // delete loans
    for (int i = 0; i < ::Loans_temp.size(); i++)
    {
        if (userID == ::Loans_temp[i]->getCompID())
        {
            ::Loans_temp.erase(::Loans_temp.begin() + i);
            break;
        }
    }

    for (int i = 0; i < companycardWarnings.size(); i++)
    {
        if (userID == companycardWarnings[i]->getID())
        {
            companycardWarnings.erase(companycardWarnings.begin() + i);
            break;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Account closed successfully!" << endl;
    cout << "------------------------------------\n"
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void unfreeze_account_menu()
{
    system("cls");
    cout << endl;
    cout << "1. Unfreeze User Account" << endl;
    cout << "2. Unfreeze Company Account" << endl;
    cout << "3. Back" << endl;
    int choice;
    cout << "Choose an option: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        unfreeze_user();
    }
    else if (choice == 2)
    {
        unfreeze_company();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void unfreeze_user()
{
    system("cls");
    cout << endl;
    bool found = false;
    cout << "Enter UserID: ";
    int userID;
    cin >> userID;

    int index;

    for (int i = 0; i < userClients_frozen.size(); i++)
    {
        // get user ID from vector
        if (userID == ::userClients_frozen[i]->getUserID())
        {
            found = true;
            index = i;
            break;
        }
    }

    if (found == false)
    {
        cout << "----------------" << endl;
        cout << "User not found!" << endl;
        cout << "----------------\n\n"
             << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    // unfreeze account, by looping through the vector and removing the account
    for (int i = 0; i < userClients_frozen.size(); i++)
    {
        if (userID == ::userClients_frozen[i]->getUserID())
        {
            ::userClients.push_back(::userClients_frozen[i]);
            ::userClients_frozen.erase(::userClients_frozen.begin() + i);
            break;
        }
    }

    cout << "----------------" << endl;
    cout << "Account Restored!" << endl;
    cout << "----------------\n\n"
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void unfreeze_company()
{
    system("cls");
    cout << endl;
    bool found = false;
    cout << "Enter Company ID: ";
    int userID;
    cin >> userID;

    int index;

    for (int i = 0; i < companyClients_frozen.size(); i++)
    {
        // get user ID from vector
        if (userID == ::companyClients_frozen[i]->getCompID())
        {
            found = true;
            index = i;
            break;
        }
    }

    if (found == false)
    {
        cout << "----------------" << endl;
        cout << "Company not found!" << endl;
        cout << "----------------\n\n"
             << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    // unfreeze account, by looping through the vector and removing the account
    for (int i = 0; i < companyClients_frozen.size(); i++)
    {
        if (userID == ::companyClients_frozen[i]->getCompID())
        {
            ::companyClients.push_back(::companyClients_frozen[i]);
            ::companyClients_frozen.erase(::companyClients_frozen.begin() + i);
            break;
        }
    }

    cout << "----------------" << endl;
    cout << "Account Restored!" << endl;
    cout << "----------------\n\n"
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void freeze_account_menu()
{
    system("cls");
    cout << endl;
    cout << "1. Freeze User Account" << endl;
    cout << "2. Freeze Company Account" << endl;
    cout << "3. Back" << endl;
    int choice;
    cout << "Choose an option: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        freeze_user_account();
    }
    else if (choice == 2)
    {
        freeze_company_account();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void freeze_user_account()
{
    system("cls");
    cout << endl;
    bool found = false;
    cout << "Enter UserID: ";
    int userID;
    cin >> userID;

    int index;

    for (int i = 0; i < userClients.size(); i++)
    {
        // get user ID from vector
        if (userID == ::userClients[i]->getUserID())
        {
            found = true;
            index = i;
            break;
        }
    }

    if (found == false)
    {
        cout << "----------------" << endl;
        cout << "User not found!" << endl;
        cout << "----------------\n\n"
             << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    // remove index from userClients and add to userClients_frozen
    ::userClients_frozen.push_back(std::move(::userClients[index]));
    ::userClients.erase(::userClients.begin() + index);

    cout << "----------------" << endl;
    cout << "Account Frozen!" << endl;
    cout << "----------------\n\n"
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void freeze_company_account()
{
    system("cls");
    cout << endl;
    bool found = false;
    cout << "Enter Company ID: ";
    int userID;
    cin >> userID;

    int index;

    for (int i = 0; i < companyClients.size(); i++)
    {
        // get user ID from vector
        if (userID == ::companyClients[i]->getCompID())
        {
            found = true;
            index = i;
            break;
        }
    }

    if (found == false)
    {
        cout << "----------------" << endl;
        cout << "Company not found!" << endl;
        cout << "----------------\n\n"
             << endl;
        system("pause");
        bank_employee_menu_loggedin();
    }

    // remove index from userClients and add to userClients_frozen
    ::companyClients_frozen.push_back(::companyClients[index]);
    ::companyClients.erase(::companyClients.begin() + index);

    cout << "----------------" << endl;
    cout << "Account Frozen!" << endl;
    cout << "----------------\n\n"
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void view_all_accounts_list_menu()
{
    system("cls");
    cout << endl;
    cout << "1. User Accounts" << endl;
    cout << "2. Company Accounts" << endl;
    cout << "3. Back" << endl;
    int choice;
    cout << "Choose an option: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        user_accounts_view_list();
    }
    else if (choice == 2)
    {
        company_accounts_view_list();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void user_accounts_view_list()
{
    system("cls");
    cout << endl;

    int user_id;
    string name;
    string email;
    string cnic;
    string acc_type;
    double total_balance;

    int size;

    cout << "The format for this list is as under: " << endl;
    cout << "User ID, Name, Email, CNIC, Account Type, Balance\n"
         << endl;
    cout << "\nThe Active Accounts are: " << endl
         << endl;

    size = ::userClients.size();

    if (size == 0)
    {
        cout << "------------------------------" << endl;
        cout << "There are no active accounts!" << endl;
        cout << "------------------------------" << endl;
    }
    else
    {
        for (int i = 0; i < ::userClients.size(); i++)
        {
            user_id = ::userClients[i]->getUserID();
            name = ::userClients[i]->getName();
            email = ::userClients[i]->getEmail();
            cnic = ::userClients[i]->getCNIC();
            acc_type = ::userClients[i]->getaccountname();
            total_balance = ::userClients[i]->getBalance();
            cout << user_id << ", " << name << ", " << email << ", " << cnic << ", " << acc_type << ", " << total_balance << endl;
        }
        cout << endl;
    }

    cout << "\nThe Frozen Accounts are: " << endl
         << endl;

    size = ::userClients_frozen.size();

    if (size == 0)
    {
        cout << "--------------------------------------" << endl;
        cout << "There are no frozen accounts!" << endl;
        cout << "--------------------------------------" << endl;
    }
    else
    {

        for (int i = 0; i < ::userClients_frozen.size(); i++)
        {
            user_id = ::userClients_frozen[i]->getUserID();
            name = ::userClients_frozen[i]->getName();
            email = ::userClients_frozen[i]->getEmail();
            cnic = ::userClients_frozen[i]->getCNIC();
            acc_type = ::userClients_frozen[i]->getaccountname();
            total_balance = ::userClients_frozen[i]->getBalance();
            cout << user_id << ", " << name << ", " << email << ", " << cnic << ", " << acc_type << ", " << total_balance << endl;
        }
        cout << endl;
    }

    cout << "\nThe Pending Accounts are: " << endl
         << endl;

    size = ::userClients_temp.size();

    if (size == 0)
    {
        cout << "--------------------------------------" << endl;
        cout << "There are no pending accounts!" << endl;
        cout << "--------------------------------------" << endl;
    }
    else
    {

        for (int i = 0; i < ::userClients_temp.size(); i++)
        {
            user_id = ::userClients_temp[i]->getUserID();
            name = ::userClients_temp[i]->getName();
            email = ::userClients_temp[i]->getEmail();
            cnic = ::userClients_temp[i]->getCNIC();
            acc_type = ::userClients_temp[i]->getaccountname();
            total_balance = ::userClients_temp[i]->getBalance();
            cout << user_id << ", " << name << ", " << email << ", " << cnic << ", " << acc_type << ", " << total_balance << endl;
        }
        cout << endl;
    }
    cout << endl
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void company_accounts_view_list()
{
    system("cls");
    cout << endl;

    int company_id;
    string name;
    string tax_num;
    string email;
    double balance;
    string acc_type;

    int size;

    cout << "The format for this list is as under: " << endl;
    cout << "Company ID, Name, Email, Tax ID, Account Type, Balance\n"
         << endl;
    cout << "\nThe Active Accounts are: " << endl
         << endl;

    size = ::companyClients.size();

    if (size == 0)
    {
        cout << "------------------------------" << endl;
        cout << "There are no active accounts!" << endl;
        cout << "------------------------------" << endl;
    }
    else
    {
        for (int i = 0; i < ::companyClients.size(); i++)
        {
            company_id = ::companyClients[i]->getCompID();
            name = ::companyClients[i]->getName();
            email = ::companyClients[i]->getEmail();
            tax_num = ::companyClients[i]->getTaxNum();
            acc_type = ::companyClients[i]->getAccountTypeNamename();
            balance = ::companyClients[i]->getBalance();
            cout << company_id << ", " << name << ", " << email << ", " << tax_num << ", " << acc_type << ", " << balance << endl;
        }
        cout << endl;
    }

    cout << "\nThe Frozen Accounts are: " << endl
         << endl;

    size = ::companyClients_frozen.size();

    if (size == 0)
    {
        cout << "--------------------------------------" << endl;
        cout << "There are no frozen accounts!" << endl;
        cout << "--------------------------------------" << endl;
    }
    else
    {

        for (int i = 0; i < ::companyClients_frozen.size(); i++)
        {
            company_id = ::companyClients_frozen[i]->getCompID();
            name = ::companyClients_frozen[i]->getName();
            email = ::companyClients_frozen[i]->getEmail();
            tax_num = ::companyClients_frozen[i]->getTaxNum();
            acc_type = ::companyClients_frozen[i]->getAccountTypeNamename();
            balance = ::companyClients_frozen[i]->getBalance();
            cout << company_id << ", " << name << ", " << email << ", " << tax_num << ", " << acc_type << ", " << balance << endl;
        }
        cout << endl;
    }

    cout << "\nThe Pending Accounts are: " << endl
         << endl;

    size = ::companyClients_temp.size();

    if (size == 0)
    {
        cout << "--------------------------------------" << endl;
        cout << "There are no pending accounts!" << endl;
        cout << "--------------------------------------" << endl;
    }
    else
    {

        for (int i = 0; i < ::companyClients_temp.size(); i++)
        {
            company_id = ::companyClients_temp[i]->getCompID();
            name = ::companyClients_temp[i]->getName();
            email = ::companyClients_temp[i]->getEmail();
            tax_num = ::companyClients_temp[i]->getTaxNum();
            acc_type = ::companyClients_temp[i]->getAccountTypeNamename();
            balance = ::companyClients_temp[i]->getBalance();
            cout << company_id << ", " << name << ", " << email << ", " << tax_num << ", " << acc_type << ", " << balance << endl;
        }
        cout << endl;
    }

    cout << endl
         << endl;
    system("pause");
    bank_employee_menu_loggedin();
}

void check_account_requests()
{
    system("cls");
    cout << endl;
    cout << "1. User Accounts" << endl;
    cout << "2. Company Accounts" << endl;
    cout << "3. Back to Menu" << endl;
    int choice;
    cout << "Choose an option: ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        check_user_account_requests();
    }
    else if (choice == 2)
    {
        check_company_account_requests();
    }
    else if (choice == 3)
    {
        bank_employee_menu_loggedin();
    }
}

void check_company_account_requests()
{
    int size = companyClients_temp.size();
    if (size == 0)
    {
        cout << endl;
        cout << "----------------------" << endl;
        cout << "No requests to show!" << endl;
        cout << "----------------------" << endl;
        system("pause");
        check_account_requests();
    }
    else if (size > 0)
    {
        cout << "All accounts are as under: " << endl
             << endl;
        for (int i = 0; i < companyClients_temp.size(); i++)
        {
            cout << "Company ID: " << companyClients_temp[i]->getCompID() << ", "
                 << "Name: " << companyClients_temp[i]->getName() << ", "
                 << "Tax Number: " << companyClients_temp[i]->getTaxNum() << ", "
                 << "Type: " << companyClients_temp[i]->getAccountTypeNamename() << endl;
        }
    }

    cout << endl;
    cout << "Enter Company ID to accept or reject request: ";
    int company_id;
    cin >> company_id;

    while (!request_acc_comp(company_id))
    {
        cout << endl;
        cout << "Invalid Company ID! Please enter again: ";
        cin >> company_id;
    }

    cout << endl;
    cout << "1. Accept Request" << endl;
    cout << "2. Reject Request" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    while (choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        // find which index it is at
        int index;
        for (int i = 0; i < companyClients_temp.size(); i++)
        {
            if (companyClients_temp[i]->getCompID() == company_id)
            {
                index = i;
                break;
            }
        }
        companyClients.push_back(companyClients_temp[index]);
        // now remove from UserClients_temp
        companyClients_temp.erase(companyClients_temp.begin() + index);
        cout << endl;
        cout << "Request Accepted!" << endl;
        system("pause");
        check_account_requests();
    }
    else if (choice == 2)
    {
        // find which index it is at
        int index;
        for (int i = 0; i < companyClients_temp.size(); i++)
        {
            if (companyClients_temp[i]->getCompID() == company_id)
            {
                index = i;
                break;
            }
        }
        // remove from UserClients_temp
        companyClients_temp.erase(companyClients_temp.begin() + index);
        cout << endl;
        cout << "Request Rejected!" << endl;
        system("pause");
        check_account_requests();
    }
}

bool request_acc_comp(int id)
{
    bool found = false;
    for (int i = 0; i < companyClients_temp.size(); i++)
    {
        if (companyClients_temp[i]->getCompID() == id)
        {
            found = true;
            break;
        }
    }

    return found;
}

void check_user_account_requests()
{
    int size = userClients_temp.size();

    if (size == 0)
    {
        cout << endl;
        cout << "------------------------" << endl;
        cout << "No requests found!" << endl;
        cout << "------------------------" << endl
             << endl;
        system("pause");
        check_account_requests();
    }
    else if (size > 0)
    {
        cout << "All accounts are as under: " << endl
             << endl;
        for (int i = 0; i < userClients_temp.size(); i++)
        {
            cout << "User ID: " << userClients_temp[i]->getUserID() << ", "
                 << "Name: " << userClients_temp[i]->getName() << ", "
                 << "CNIC: " << userClients_temp[i]->getCNIC() << ", "
                 << "Type: " << userClients_temp[i]->getaccountname() << endl;
        }
    }
    cout << endl;
    cout << "Enter User ID to accept or reject request: ";
    int user_id;
    cin >> user_id;

    while (!request_acc(user_id))
    {
        cout << endl;
        cout << "Invalid User ID! Please enter again: ";
        cin >> user_id;
    }

    cout << endl;
    cout << "1. Accept Request" << endl;
    cout << "2. Reject Request" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;

    while (choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        // find which index it is at
        int index;
        for (int i = 0; i < userClients_temp.size(); i++)
        {
            if (userClients_temp[i]->getUserID() == user_id)
            {
                index = i;
                break;
            }
        }
        userClients.push_back(userClients_temp[index]);
        // now remove from UserClients_temp
        userClients_temp.erase(userClients_temp.begin() + index);
        cout << endl;
        cout << "Request Accepted!" << endl;
        system("pause");
        check_account_requests();
    }
    else if (choice == 2)
    {
        // find which index it is at
        int index;
        for (int i = 0; i < userClients_temp.size(); i++)
        {
            if (userClients_temp[i]->getUserID() == user_id)
            {
                index = i;
                break;
            }
        }
        // remove from UserClients_temp
        userClients_temp.erase(userClients_temp.begin() + index);
        cout << endl;
        cout << "Request Rejected!" << endl;
        system("pause");
        check_account_requests();
    }
}

bool request_acc(int id)
{
    bool found = false;
    for (int i = 0; i < userClients_temp.size(); i++)
    {
        if (userClients_temp[i]->getUserID() == id)
        {
            found = true;
            break;
        }
    }

    return found;
}

void save_user_clients()
{
    // empty the file users.txt
    string line;
    string line_temp;
    ofstream users_file("users.txt", ios::trunc);
    users_file.close();
    // open the users.txt file for writing
    ofstream users_file2("users.txt");
    for (int i = 0; i < ::userClients.size(); i++)
    {
        line_temp = to_string(::userClients[i]->getUserID());
        line_temp += ", ";
        line_temp += ::userClients[i]->getName();
        line_temp += ", ";
        line_temp += ::userClients[i]->getAddress();
        line_temp += ", ";
        line_temp += ::userClients[i]->getCNIC();
        line_temp += ", ";
        line_temp += ::userClients[i]->getEmail();
        line_temp += ", ";
        line_temp += ::userClients[i]->getPassword();
        line_temp += ", ";
        line_temp += to_string(::userClients[i]->getBalance());
        line_temp += ", ";
        line_temp += to_string(::userClients[i]->get_Comp_ID());
        line_temp += ", ";
        line_temp += ::userClients[i]->getaccountname();
        line = line_temp;
        line_temp = "";
        users_file2 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file2.close();
    // empty the file users_temp.txt
    ofstream users_file3("users_temp.txt", ios::trunc);
    users_file3.close();
    // open the users_temp.txt file for writing
    ofstream users_file4("users_temp.txt");
    for (int i = 0; i < ::userClients_temp.size(); i++)
    {
        line_temp = to_string(::userClients_temp[i]->getUserID());
        line_temp += ", ";
        line_temp += ::userClients_temp[i]->getName();
        line_temp += ", ";
        line_temp += ::userClients_temp[i]->getAddress();
        line_temp += ", ";
        line_temp += ::userClients_temp[i]->getCNIC();
        line_temp += ", ";
        line_temp += ::userClients_temp[i]->getEmail();
        line_temp += ", ";
        line_temp += ::userClients_temp[i]->getPassword();
        line_temp += ", ";
        line_temp += to_string(::userClients_temp[i]->getBalance());
        line_temp += ", ";
        line_temp += to_string(::userClients_temp[i]->get_Comp_ID());
        line_temp += ", ";
        line_temp += ::userClients_temp[i]->getaccountname();
        line = line_temp;
        line_temp = "";
        users_file4 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file4.close();
    // empty the file user_frozen.txt
    ofstream users_file5("user_frozen.txt", ios::trunc);
    users_file5.close();
    // open the user_frozen.txt file for writing
    ofstream users_file6("user_frozen.txt");
    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        line_temp = to_string(::userClients_frozen[i]->getUserID());
        line_temp += ", ";
        line_temp += ::userClients_frozen[i]->getName();
        line_temp += ", ";
        line_temp += ::userClients_frozen[i]->getAddress();
        line_temp += ", ";
        line_temp += ::userClients_frozen[i]->getCNIC();
        line_temp += ", ";
        line_temp += ::userClients_frozen[i]->getEmail();
        line_temp += ", ";
        line_temp += ::userClients_frozen[i]->getPassword();
        line_temp += ", ";
        line_temp += to_string(::userClients_frozen[i]->getBalance());
        line_temp += ", ";
        line_temp += to_string(::userClients_frozen[i]->get_Comp_ID());
        line_temp += ", ";
        line_temp += ::userClients_frozen[i]->getaccountname();
        line = line_temp;
        line_temp = "";
        users_file6 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file6.close();
    // empty the file user_warnings.txt
    ofstream users_file7("user_warnings.txt", ios::trunc);
    users_file7.close();
    // open the user_warnings.txt file for writing
    ofstream users_file8("user_warnings.txt");
    for (int i = 0; i < ::usercardWarnings.size(); i++)
    {
        line_temp = to_string(::usercardWarnings[i]->getID());
        line_temp += ", ";
        line_temp += to_string(::usercardWarnings[i]->getCardNum());
        line = line_temp;
        line_temp = "";
        users_file8 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file8.close();

    string file;

    file = "user_transactions.txt";

    ofstream fout_trans_1(file, ios::trunc);
    fout_trans_1.close();

    for (int i = 0; i < ::userClients.size(); i++)
    {
        ::userClients[i]->save_transactions(file);
    }

    file = "user_frozen_transactions.txt";

    ofstream fout_trans_3(file, ios::trunc);
    fout_trans_3.close();

    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        ::userClients_frozen[i]->save_transactions(file);
    }

    file = "users_cards.txt";

    ofstream fout_cards(file, ios::trunc);
    fout_cards.close();
    for (int i = 0; i < ::userClients.size(); i++)
    {
        ::userClients[i]->save_cards(file);
    }

    file = "users_frozen_cards.txt";

    ofstream fout_cards_3(file, ios::trunc);
    fout_cards_3.close();
    for (int i = 0; i < ::userClients_frozen.size(); i++)
    {
        ::userClients_frozen[i]->save_cards(file);
    }
}

void save_company_clients()
{
    // empty the file companies.txt
    string line;
    string line_temp;
    ofstream users_file("companies.txt", ios::trunc);
    users_file.close();
    // open the companies.txt file for writing
    ofstream users_file2("companies.txt");
    for (int i = 0; i < ::companyClients.size(); i++)
    {
        line_temp = to_string(::companyClients[i]->getCompID());
        line_temp += ", ";
        line_temp += ::companyClients[i]->getName();
        line_temp += ", ";
        line_temp += ::companyClients[i]->getAddress();
        line_temp += ", ";
        line_temp += ::companyClients[i]->getTaxNum();
        line_temp += ", ";
        line_temp += ::companyClients[i]->getEmail();
        line_temp += ", ";
        line_temp += ::companyClients[i]->getPassword();
        line_temp += ", ";
        line_temp += to_string(::companyClients[i]->getBalance());
        line_temp += ", ";
        line_temp += ::companyClients[i]->getAccountTypeNamename();
        line = line_temp;
        line_temp = "";
        users_file2 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file2.close();
    // empty the file companies_temp.txt
    ofstream users_file3("companies_temp.txt", ios::trunc);
    users_file3.close();
    // open the companies_temp.txt file for writing
    ofstream users_file4("companies_temp.txt");
    for (int i = 0; i < ::companyClients_temp.size(); i++)
    {
        line_temp = to_string(::companyClients_temp[i]->getCompID());
        line_temp += ", ";
        line_temp += ::companyClients_temp[i]->getName();
        line_temp += ", ";
        line_temp += ::companyClients_temp[i]->getAddress();
        line_temp += ", ";
        line_temp += ::companyClients_temp[i]->getTaxNum();
        line_temp += ", ";
        line_temp += ::companyClients_temp[i]->getEmail();
        line_temp += ", ";
        line_temp += ::companyClients_temp[i]->getPassword();
        line_temp += ", ";
        line_temp += to_string(::companyClients_temp[i]->getBalance());
        line_temp += ", ";
        line_temp += ::companyClients_temp[i]->getAccountTypeNamename();
        line = line_temp;
        line_temp = "";
        users_file4 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file4.close();
    // empty the file companies_frozen.txt
    ofstream users_file5("companies_frozen.txt", ios::trunc);
    users_file5.close();
    // open the companies_frozen.txt file for writing
    ofstream users_file6("companies_frozen.txt");
    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        line_temp = to_string(::companyClients_frozen[i]->getCompID());
        line_temp += ", ";
        line_temp += ::companyClients_frozen[i]->getName();
        line_temp += ", ";
        line_temp += ::companyClients_frozen[i]->getAddress();
        line_temp += ", ";
        line_temp += ::companyClients_frozen[i]->getTaxNum();
        line_temp += ", ";
        line_temp += ::companyClients_frozen[i]->getEmail();
        line_temp += ", ";
        line_temp += ::companyClients_frozen[i]->getPassword();
        line_temp += ", ";
        line_temp += to_string(::companyClients_frozen[i]->getBalance());
        line_temp += ", ";
        line_temp += ::companyClients_frozen[i]->getAccountTypeNamename();
        line = line_temp;
        line_temp = "";
        users_file6 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file6.close();
    // empty the file company_warnings.txt
    ofstream users_file7("company_warnings.txt", ios::trunc);
    users_file7.close();
    // open the company_warnings.txt file for writing
    ofstream users_file8("company_warnings.txt");
    for (int i = 0; i < ::companycardWarnings.size(); i++)
    {
        line_temp = to_string(::companycardWarnings[i]->getID());
        line_temp += ", ";
        line_temp += to_string(::companycardWarnings[i]->getCardNum());
        line = line_temp;
        line_temp = "";
        users_file8 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file8.close();

    string file;

    file = "companies_transactions";
    // empty the file
    ofstream transaction_file_1(file + ".txt", ios::trunc);
    transaction_file_1.close();

    file += ".txt";

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        ::companyClients[i]->save_transactions(file);
    }

    file = "companies_frozen_transactions";
    // empty the file
    ofstream transaction_file_3(file + ".txt", ios::trunc);
    transaction_file_3.close();

    file += ".txt";

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        ::companyClients_frozen[i]->save_transactions(file);
    }

    file = "companies_cards";
    // empty the file
    ofstream card_file_1(file + ".txt", ios::trunc);
    card_file_1.close();

    file += ".txt";

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        ::companyClients[i]->save_cards(file);
    }

    file = "companies_frozen_cards";

    // empty the file
    ofstream card_file_3(file + ".txt", ios::trunc);
    card_file_3.close();

    file += ".txt";

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        ::companyClients_frozen[i]->save_cards(file);
    }

    file = "user_employees_of_company";
    // empty the file
    ofstream employee_file_1(file + ".txt", ios::trunc);
    employee_file_1.close();

    file += ".txt";

    for (int i = 0; i < ::companyClients.size(); i++)
    {
        ::companyClients[i]->save_company_employees(file);
    }

    for (int i = 0; i < ::companyClients_frozen.size(); i++)
    {
        ::companyClients_frozen[i]->save_company_employees(file);
    }

    // empty the file loans_temp.txt
    ofstream laon_file("loans_temp.txt", ios::trunc);
    laon_file.close();
    // open the loans_temp.txt file for writing
    ofstream laon_file2("loans_temp.txt");

    line = "";
    line_temp = "";
    for (int i = 0; i < ::Loans_temp.size(); i++)
    {
        line_temp = to_string(::Loans_temp[i]->getAmount());
        line_temp += ", ";
        line_temp += to_string(::Loans_temp[i]->getCardNum());
        line_temp += ", ";
        line_temp += to_string(::Loans_temp[i]->getCompID());
        line = line_temp;
        line_temp = "";
        laon_file2 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    laon_file2.close();
}

void save_bank_employee()
{
    int employee_ID;
    string name;
    string username;
    string password;
    // bank_employee.txt, clear the file
    ofstream users_file("bank_employee.txt", ios::trunc);
    users_file.close();
    // open the bank_employee.txt file for writing
    ofstream users_file2("bank_employee.txt");
    string line = "";
    string line_temp = "";
    for (int i = 0; i < ::bankEmployees.size(); i++)
    {
        employee_ID = ::bankEmployees[i]->getEmployeeID();
        name = ::bankEmployees[i]->getName();
        username = ::bankEmployees[i]->getUsername();
        password = ::bankEmployees[i]->getPassword();
        line_temp = to_string(employee_ID);
        line_temp += ", ";
        line_temp += name;
        line_temp += ", ";
        line_temp += username;
        line_temp += ", ";
        line_temp += password;
        line = line_temp;
        line_temp = "";
        users_file2 << line << endl;
        line = "";
    }
    line = "";
    line_temp = "";
    users_file2.close();
}

void save_all()
{
    save_user_clients();
    save_company_clients();
    save_bank_employee();
}

void load_company()
{
    // open the companies.txt file for reading
    ifstream users_file("companies.txt");
    string line;

    while (getline(users_file, line))
    {
        stringstream ss(line);
        string token;

        // get compID
        getline(ss, token, ',');
        int compID = stoi(token);

        // remove the extra space
        ss.get();

        // get name
        getline(ss, token, ',');
        string name = token;

        // remove the extra space
        ss.get();

        // get address
        getline(ss, token, ',');
        string address = token;

        // remove the extra space
        ss.get();

        // get tax num
        getline(ss, token, ',');
        string taxNum = token;

        // remove the extra space
        ss.get();

        // get email
        getline(ss, token, ',');
        string email = token;

        // remove the extra space
        ss.get();

        // get password
        getline(ss, token, ',');
        string password = token;

        // remove the extra space
        ss.get();

        // get balance
        getline(ss, token, ',');
        double balance = stod(token);

        // remove the extra space
        ss.get();

        // get account type name
        getline(ss, token, ',');
        string accountTypeName = token;

        // Create a new account
        CompanyClient *company = new CompanyClient(compID, name, address, taxNum, email, password, balance, accountTypeName);
        ::companyClients.push_back(company);
    }
    users_file.close();

    line = "";

    ifstream users_file_1("companies_temp.txt");

    while (getline(users_file_1, line))
    {
        stringstream ss(line);
        string token;

        // get compID
        getline(ss, token, ',');
        int compID = stoi(token);

        // remove the extra space
        ss.get();

        // get name
        getline(ss, token, ',');
        string name = token;

        // remove the extra space
        ss.get();

        // get address
        getline(ss, token, ',');
        string address = token;

        // remove the extra space
        ss.get();

        // get tax num
        getline(ss, token, ',');
        string taxNum = token;

        // remove the extra space
        ss.get();

        // get email
        getline(ss, token, ',');
        string email = token;

        // remove the extra space
        ss.get();

        // get password
        getline(ss, token, ',');
        string password = token;

        // remove the extra space
        ss.get();

        // get balance
        getline(ss, token, ',');
        double balance = stod(token);

        // remove the extra space
        ss.get();

        // get account type name
        getline(ss, token, ',');
        string accountTypeName = token;

        // Craete a new company client
        CompanyClient *company = new CompanyClient(compID, name, address, taxNum, email, password, balance, accountTypeName);
        ::companyClients_temp.push_back(company);
    }
    users_file_1.close();
    line = "";
    ifstream users_file_2("companies_frozen.txt");

    while (getline(users_file_2, line))
    {
        stringstream ss(line);
        string token;

        // get compID
        getline(ss, token, ',');
        int compID = stoi(token);

        // remove the extra space
        ss.get();

        // get name
        getline(ss, token, ',');
        string name = token;

        // remove the extra space
        ss.get();

        // get address
        getline(ss, token, ',');
        string address = token;

        // remove the extra space
        ss.get();

        // get tax num
        getline(ss, token, ',');
        string taxNum = token;

        // remove the extra space
        ss.get();

        // get email
        getline(ss, token, ',');
        string email = token;

        // remove the extra space
        ss.get();

        // get password
        getline(ss, token, ',');
        string password = token;

        // remove the extra space
        ss.get();

        // get balance
        getline(ss, token, ',');
        double balance = stod(token);

        // remove the extra space
        ss.get();

        // get account type name
        getline(ss, token, ',');
        string accountTypeName = token;

        // Create a new company object
        CompanyClient *company = new CompanyClient(compID, name, address, taxNum, email, password, balance, accountTypeName);
        ::companyClients_frozen.push_back(company);
    }
    users_file_2.close();

    line = "";

    // open the company_warnings.txt file for reading
    ifstream users_file8("company_warnings.txt");
    string line_temp;
    // vector<pair<int, long long>> companycardWarningsFromFile;

    while (getline(users_file8, line))
    {
        stringstream ss(line);
        int id;
        long long cardNum;
        char comma;

        ss >> id >> comma >> cardNum;

        cardWarning *temp = new cardWarning(id, cardNum);
        ::companycardWarnings.push_back(temp);

        // companycardWarningsFromFile.push_back(make_pair(id, cardNum));
    }
    users_file8.close();

    line = "";

    vector<string> transactions;
    int Id = 0;
    double amount = 0.0;
    string date = "";
    string type = "";
    string recieverid = "";

    ifstream fin_10("companies_transactions.txt");
    while (getline(fin_10, line))
    {
        stringstream ss(line);
        getline(ss, date, ',');
        ss.ignore(1); // To ignore the space after the comma

        ss >> Id;
        ss.ignore(2); // To ignore the comma and the space after it

        ss >> amount;
        ss.ignore(2); // To ignore the comma and the space after it

        getline(ss, type, ',');
        ss.ignore(1); // To ignore the space after the comma

        getline(ss, recieverid);

        // Use the loaded data members as needed
        // Example: create a new transaction object and add it to the transactions vector
        Transaction transaction(Id, amount, date, type, recieverid);
        for (int i = 0; i < companyClients.size(); i++)
        {
            if (companyClients[i]->getCompID() == Id)
            {
                companyClients[i]->add_transaction(transaction);
                break;
            }
        }
        // clear values
        Id = 0;
        amount = 0.0;
        date = "";
        type = "";
        recieverid = "";
        transactions.clear();
    }
    fin_10.close();

    ifstream fin_11("companies_frozen_transactions.txt");
    while (getline(fin_11, line))
    {
        stringstream ss(line);
        getline(ss, date, ',');
        ss.ignore(1); // To ignore the space after the comma

        ss >> Id;
        ss.ignore(2); // To ignore the comma and the space after it

        ss >> amount;
        ss.ignore(2); // To ignore the comma and the space after it

        getline(ss, type, ',');
        ss.ignore(1); // To ignore the space after the comma

        getline(ss, recieverid);

        // Use the loaded data members as needed
        // Example: create a new transaction object and add it to the transactions vector
        Transaction transaction(Id, amount, date, type, recieverid);
        for (int i = 0; i < companyClients_frozen.size(); i++)
        {
            if (companyClients_frozen[i]->getCompID() == Id)
            {
                companyClients_frozen[i]->add_transaction(transaction);
                break;
            }
        }
        // clear values
        Id = 0;
        amount = 0.0;
        date = "";
        type = "";
        recieverid = "";
        transactions.clear();
    }
    fin_11.close();

    long long cardNumber = 0;
    string cardPin = "";
    double balance = 0.00;
    int userID = 0;
    char ch;
    line = "";

    ifstream cards_1("companies_cards.txt");

    while (getline(cards_1, line))
    {
        stringstream ss(line);

        ss >> userID >> ch;
        ss >> cardNumber >> ch;
        getline(ss, cardPin, ',');
        cardPin.erase(0, cardPin.find_first_not_of(' '));
        ss >> balance;

        // Do something with the loaded data (e.g., create a Card object and store it in a vector)
        // Example:
        // Card newCard(cardNumber, cardPin, balance, userID);
        // cards.push_back(newCard);

        for (int i = 0; i < ::companyClients.size(); i++)
        {
            if (::companyClients[i]->getCompID() == userID)
            {
                //(long long number, string pin, double bal)
                Card newCard(cardNumber, cardPin, balance);
                ::companyClients[i]->add_card(newCard);
                break;
            }
        }
        // reset values
        cardNumber = 0;
        cardPin = "";
        balance = 0.00;
        userID = 0;
        line = "";
    }
    cards_1.close();

    ifstream cards_2("companies_frozen_cards.txt");

    while (getline(cards_2, line))
    {
        stringstream ss(line);

        ss >> userID >> ch;
        ss >> cardNumber >> ch;
        getline(ss, cardPin, ',');
        cardPin.erase(0, cardPin.find_first_not_of(' '));
        ss >> balance;

        // Do something with the loaded data (e.g., create a Card object and store it in a vector)
        // Example:
        // Card newCard(cardNumber, cardPin, balance, userID);
        // cards.push_back(newCard);

        for (int i = 0; i < ::companyClients_frozen.size(); i++)
        {
            if (::companyClients_frozen[i]->getCompID() == userID)
            {
                //(long long number, string pin, double bal)
                Card newCard(cardNumber, cardPin, balance);
                ::companyClients_frozen[i]->add_card(newCard);
                break;
            }
        }
        // reset values
        cardNumber = 0;
        cardPin = "";
        balance = 0.00;
        userID = 0;
        line = "";
    }
    cards_2.close();

    ifstream loading_employee("user_employees_of_company.txt");
    int compID;
    userID = 0;
    char comma;

    while (loading_employee >> compID >> comma >> userID)
    {
        // Process the compID and userID as needed
        for (int i = 0; i < ::companyClients.size(); i++)
        {
            if (::companyClients[i]->getCompID() == compID)
            {
                ::companyClients[i]->add_user_id(userID);
            }
        }

        for (int i = 0; i < ::companyClients_frozen.size(); i++)
        {
            if (::companyClients_frozen[i]->getCompID() == compID)
            {
                ::companyClients_frozen[i]->add_user_id(userID);
            }
        }
    }

    loading_employee.close();
}

void load_users()
{
    string line, token;
    vector<string> tokens;
    int userID, comp_ID;
    string name, address, CNIC, email, password, accountName;
    double balance;

    // Load user information from the file users.txt
    ifstream users_file("users.txt");
    while (getline(users_file, line))
    {
        istringstream ss(line);
        while (getline(ss, token, ','))
        {
            token = token.substr(token.find_first_not_of(' ')); // Remove leading spaces
            tokens.push_back(token);
        }

        userID = stoi(tokens[0]);
        name = tokens[1];
        address = tokens[2];
        CNIC = tokens[3];
        email = tokens[4];
        password = tokens[5];
        balance = stod(tokens[6]);
        comp_ID = stoi(tokens[7]);
        accountName = tokens[8];

        // Create a new user object with the loaded information
        UserClient *user = new UserClient(userID, name, address, CNIC, email, password, balance, comp_ID, accountName);

        // Add the user object to the userClients vector
        ::userClients.push_back(user);

        // Clear the tokens vector for the next iteration
        tokens.clear();
    }
    users_file.close();
    line = "";
    token = "";
    tokens.clear();
    userID = 0;
    comp_ID = 0;
    name = "";
    address = "";
    CNIC = "";
    email = "";
    password = "";
    accountName = "";
    balance = 0.0;
    // Load user information from the file user_frozen.txt
    ifstream users_file_2("user_frozen.txt");
    while (getline(users_file_2, line))
    {
        istringstream ss(line);
        while (getline(ss, token, ','))
        {
            token = token.substr(token.find_first_not_of(' ')); // Remove leading spaces
            tokens.push_back(token);
        }

        userID = stoi(tokens[0]);
        name = tokens[1];
        address = tokens[2];
        CNIC = tokens[3];
        email = tokens[4];
        password = tokens[5];
        balance = stod(tokens[6]);
        comp_ID = stoi(tokens[7]);
        accountName = tokens[8];

        // Create a new user object with the loaded information
        UserClient *user = new UserClient(userID, name, address, CNIC, email, password, balance, comp_ID, accountName);

        // Add the user object to the userClients vector
        ::userClients_frozen.push_back(user);

        // Clear the tokens vector for the next iteration
        tokens.clear();
    }
    users_file_2.close();
    line = "";
    token = "";
    tokens.clear();
    userID = 0;
    comp_ID = 0;
    name = "";
    address = "";
    CNIC = "";
    email = "";
    password = "";
    accountName = "";
    balance = 0.0;
    // Load user information from the file users_temp.txt
    ifstream users_file_3("users_temp.txt");
    while (getline(users_file_3, line))
    {
        istringstream ss(line);
        while (getline(ss, token, ','))
        {
            token = token.substr(token.find_first_not_of(' ')); // Remove leading spaces
            tokens.push_back(token);
        }

        userID = stoi(tokens[0]);
        name = tokens[1];
        address = tokens[2];
        CNIC = tokens[3];
        email = tokens[4];
        password = tokens[5];
        balance = stod(tokens[6]);
        comp_ID = stoi(tokens[7]);
        accountName = tokens[8];

        // Create a new user object with the loaded information
        UserClient *user = new UserClient(userID, name, address, CNIC, email, password, balance, comp_ID, accountName);

        // Add the user object to the userClients vector
        ::userClients_temp.push_back(user);

        // Clear the tokens vector for the next iteration
        tokens.clear();
    }
    users_file_3.close();
    line = "";
    token = "";
    tokens.clear();
    userID = 0;
    comp_ID = 0;
    name = "";
    address = "";
    CNIC = "";
    email = "";
    password = "";
    accountName = "";
    balance = 0.0;
    // this part ends here
    // open the user_warnings.txt file for reading
    ifstream users_warning("user_warnings.txt");
    if (users_warning.is_open())
    {
        string line;
        while (getline(users_warning, line))
        {
            stringstream ss(line);
            string temp;
            int userId_1;
            long long cardNum_1;
            getline(ss, temp, ',');
            userId_1 = stoi(temp);
            getline(ss, temp, ',');
            cardNum_1 = stoll(temp);
            cardWarning *tempWarning = new cardWarning(userId_1, cardNum_1);
            ::usercardWarnings.push_back(tempWarning);
        }
    }
    users_warning.close();

    line = "";
    vector<string> transactions;
    int Id = 0;
    double amount = 0.0;
    string date = "";
    string type = "";
    string recieverid = "";

    ifstream fin("user_transactions.txt");
    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, date, ',');
        ss.ignore(1); // To ignore the space after the comma

        ss >> Id;
        ss.ignore(2); // To ignore the comma and the space after it

        ss >> amount;
        ss.ignore(2); // To ignore the comma and the space after it

        getline(ss, type, ',');
        ss.ignore(1); // To ignore the space after the comma

        getline(ss, recieverid);

        // Use the loaded data members as needed
        // Example: create a new transaction object and add it to the transactions vector
        Transaction transaction(Id, amount, date, type, recieverid);
        for (int i = 0; i < userClients.size(); i++)
        {
            if (userClients[i]->getUserID() == Id)
            {
                userClients[i]->add_transaction(transaction);
                break;
            }
        }
        // clear values
        Id = 0;
        amount = 0.0;
        date = "";
        type = "";
        recieverid = "";
        transactions.clear();
    }
    fin.close();

    ifstream fin2("user_frozen_transactions.txt");
    while (getline(fin2, line))
    {
        stringstream ss(line);
        getline(ss, date, ',');
        ss.ignore(1); // To ignore the space after the comma

        ss >> Id;
        ss.ignore(2); // To ignore the comma and the space after it

        ss >> amount;
        ss.ignore(2); // To ignore the comma and the space after it

        getline(ss, type, ',');
        ss.ignore(1); // To ignore the space after the comma

        getline(ss, recieverid);

        // Use the loaded data members as needed
        // Example: create a new transaction object and add it to the transactions vector
        Transaction transaction(Id, amount, date, type, recieverid);
        for (int i = 0; i < userClients_frozen.size(); i++)
        {
            if (userClients_frozen[i]->getUserID() == Id)
            {
                userClients_frozen[i]->add_transaction(transaction);
                break;
            }
        }
        // clear values
        Id = 0;
        amount = 0.0;
        date = "";
        type = "";
        recieverid = "";
        transactions.clear();
    }
    fin2.close();

    long long cardNumber = 0;
    string cardPin = "";
    balance = 0.00;
    userID = 0;
    char ch;
    line = "";

    ifstream fin_5("users_cards.txt");

    while (getline(fin_5, line))
    {
        stringstream ss(line);

        ss >> userID >> ch;
        ss >> cardNumber >> ch;
        getline(ss, cardPin, ',');
        cardPin.erase(0, cardPin.find_first_not_of(' '));
        ss >> balance;

        // Do something with the loaded data (e.g., create a Card object and store it in a vector)
        // Example:
        // Card newCard(cardNumber, cardPin, balance, userID);
        // cards.push_back(newCard);

        for (int i = 0; i < ::userClients.size(); i++)
        {
            if (::userClients[i]->getUserID() == userID)
            {
                //(long long number, string pin, double bal)
                Card newCard(cardNumber, cardPin, balance);
                ::userClients[i]->add_card(newCard);
                break;
            }
        }
        // reset values
        cardNumber = 0;
        cardPin = "";
        balance = 0.00;
        userID = 0;
        line = "";
    }
    fin_5.close();

    ifstream fin_6("users_frozen_cards.txt");

    while (getline(fin_6, line))
    {
        stringstream ss(line);

        ss >> userID >> ch;
        ss >> cardNumber >> ch;
        getline(ss, cardPin, ',');
        cardPin.erase(0, cardPin.find_first_not_of(' '));
        ss >> balance;

        // Do something with the loaded data (e.g., create a Card object and store it in a vector)
        // Example:
        // Card newCard(cardNumber, cardPin, balance, userID);
        // cards.push_back(newCard);

        for (int i = 0; i < ::userClients_frozen.size(); i++)
        {
            if (::userClients_frozen[i]->getUserID() == userID)
            {
                //(long long number, string pin, double bal)
                Card newCard(cardNumber, cardPin, balance);
                ::userClients_frozen[i]->add_card(newCard);
                break;
            }
        }
        // reset values
        cardNumber = 0;
        cardPin = "";
        balance = 0.00;
        userID = 0;
        line = "";
    }
    fin_6.close();
}

void load_loan()
{
    // open the loans_temp.txt file for reading
    ifstream loan_file("loans_temp.txt");

    // clear the Loans_temp vector
    ::Loans_temp.clear();

    string line;
    while (getline(loan_file, line))
    {
        stringstream ss(line);
        string token;

        // parse the amount
        getline(ss, token, ',');
        long long amount = stoll(token);

        // remove the extra space
        ss.get();

        // parse the card_num
        getline(ss, token, ',');
        long long card_num = stoll(token);

        // remove the extra space
        ss.get();

        // parse the Comp_ID
        getline(ss, token, ',');
        int comp_id = stoi(token);

        // create a new Loan object and add it to Loans_temp vector
        Loan *loan = new Loan(amount, comp_id, card_num);
        ::Loans_temp.push_back(loan);
    }

    // close the loan_file
    loan_file.close();
}

void load_bank_employee()
{
    int employee_ID;
    string name;
    string username;
    string password;
    // open the bank_employee.txt file for reading
    ifstream users_file("bank_employee.txt");
    string line = "";
    string line_temp = "";
    while (getline(users_file, line))
    {
        stringstream ss(line);
        getline(ss, line_temp, ',');
        employee_ID = stoi(line_temp);
        getline(ss, line_temp, ',');
        name = line_temp.substr(1); // remove the unnecessary space
        getline(ss, line_temp, ',');
        username = line_temp.substr(1); // remove the unnecessary space
        getline(ss, line_temp);
        password = line_temp.substr(1); // remove the unnecessary space

        // create a new BankEmployee object and add it to the vector
        BankEmployee *employee = new BankEmployee(employee_ID, name, username, password);
        ::bankEmployees.push_back(employee);

        line = "";
        line_temp = "";
    }
    users_file.close();
}

void load_files()
{
    load_bank_employee();
    load_loan();
    load_users();
    load_company();
}

void check_files()
{
    // check if users.txt exists, if not create it
    ifstream users_file("users.txt");
    if (!users_file)
    {
        ofstream users_file("users.txt");
        users_file.close();
    }
    else
    {
        users_file.close();
    }
    /*// check if admin.txt exists, if not create it
    ifstream admin_file("admin.txt");
    if (!admin_file)
    {
        ofstream admin_file("admin.txt"); // }-> Name Changed to bank_employee.txt
        admin_file.close();
    }
    else
    {
        admin_file.close();
    }*/
    // check if companies.txt exists, if not create it
    ifstream companies_file("companies.txt");
    if (!companies_file)
    {
        ofstream companies_file("companies.txt");
        companies_file.close();
    }
    else
    {
        companies_file.close();
    }
    // check if users_temp.txt exists, if not create it
    ifstream users_temp_file("users_temp.txt");
    if (!users_temp_file)
    {
        ofstream users_temp_file("users_temp.txt");
        users_temp_file.close();
    }
    else
    {
        users_temp_file.close();
    }
    // check if companies_temp.txt exists, if not create it
    ifstream companies_temp_file("companies_temp.txt");
    if (!companies_temp_file)
    {
        ofstream companies_temp_file("companies_temp.txt");
        companies_temp_file.close();
    }
    else
    {
        companies_temp_file.close();
    }
    // check if companies_frozen.txt exists, if not create it
    ifstream companies_frozen_file("companies_frozen.txt");
    if (!companies_frozen_file)
    {
        ofstream companies_frozen_file("companies_frozen.txt");
        companies_frozen_file.close();
    }
    else
    {
        companies_frozen_file.close();
    }
    // check if user_frozen.txt exists, if not create it
    ifstream user_frozen_file("user_frozen.txt");
    if (!user_frozen_file)
    {
        ofstream user_frozen_file("user_frozen.txt");
        user_frozen_file.close();
    }
    else
    {
        user_frozen_file.close();
    }
    // check if user_warnings.txt exists, if not create it
    ifstream user_warnings_file("user_warnings.txt");
    if (!user_warnings_file)
    {
        ofstream user_warnings_file("user_warnings.txt");
        user_warnings_file.close();
    }
    else
    {
        user_warnings_file.close();
    }
    // check if company_warnings.txt exists, if not create it
    ifstream company_warnings_file("company_warnings.txt");
    if (!company_warnings_file)
    {
        ofstream company_warnings_file("company_warnings.txt");
        company_warnings_file.close();
    }
    else
    {
        company_warnings_file.close();
    }
    /*// check if loans.txt exists, if not create it
    ifstream loans_file("loans.txt");
    if (!loans_file)
    {
        ofstream loans_file("loans.txt");
        loans_file.close();
    }
    else
    {
        loans_file.close();
    }*/
    // check if loans_temp.txt exists, if not create it
    ifstream loans_temp_file("loans_temp.txt");
    if (!loans_temp_file)
    {
        ofstream loans_temp_file("loans_temp.txt");
        loans_temp_file.close();
    }
    else
    {
        loans_temp_file.close();
    }

    // check if companies_transactions.txt exists, if not create it
    ifstream companies_transactions_file("companies_transactions.txt");
    if (!companies_transactions_file)
    {
        ofstream companies_transactions_file("companies_transactions.txt");
        companies_transactions_file.close();
    }
    else
    {
        companies_transactions_file.close();
    }

    // check if companies_frozen_transactions.txt exists, if not create it
    ifstream companies_frozen_transactions_file("companies_frozen_transactions.txt");
    if (!companies_frozen_transactions_file)
    {
        ofstream companies_frozen_transactions_file("companies_frozen_transactions.txt");
        companies_frozen_transactions_file.close();
    }
    else
    {
        companies_frozen_transactions_file.close();
    }
    // check if companies_cards.txt exists, if not create it
    ifstream companies_cards_file("companies_cards.txt");
    if (!companies_cards_file)
    {
        ofstream companies_cards_file("companies_cards.txt");
        companies_cards_file.close();
    }
    else
    {
        companies_cards_file.close();
    }
    // check if companies_frozen_cards.txt exists, if not create it
    ifstream companies_frozen_cards_file("companies_frozen_cards.txt");
    if (!companies_frozen_cards_file)
    {
        ofstream companies_frozen_cards_file("companies_frozen_cards.txt");
        companies_frozen_cards_file.close();
    }
    else
    {
        companies_frozen_cards_file.close();
    }

    // check if user_employees_of_company.txt exists, if not create it
    ifstream user_employees_of_company_file("user_employees_of_company.txt");
    if (!user_employees_of_company_file)
    {
        ofstream user_employees_of_company_file("user_employees_of_company.txt");
        user_employees_of_company_file.close();
    }
    else
    {
        user_employees_of_company_file.close();
    }
    // check if user_transactions.txt exists, if not create it
    ifstream user_transactions_file("user_transactions.txt");
    if (!user_transactions_file)
    {
        ofstream user_transactions_file("user_transactions.txt");
        user_transactions_file.close();
    }
    else
    {
        user_transactions_file.close();
    }

    // check if user_frozen_transactions.txt exists, if not create it
    ifstream user_frozen_transactions_file("user_frozen_transactions.txt");
    if (!user_frozen_transactions_file)
    {
        ofstream user_frozen_transactions_file("user_frozen_transactions.txt");
        user_frozen_transactions_file.close();
    }
    else
    {
        user_frozen_transactions_file.close();
    }
    // check if users_cards.txt exists, if not create it
    ifstream users_cards_file("users_cards.txt");
    if (!users_cards_file)
    {
        ofstream users_cards_file("users_cards.txt");
        users_cards_file.close();
    }
    else
    {
        users_cards_file.close();
    }
    // check if users_frozen_cards.txt exists, if not create it
    ifstream users_frozen_cards_file("users_frozen_cards.txt");
    if (!users_frozen_cards_file)
    {
        ofstream users_frozen_cards_file("users_frozen_cards.txt");
        users_frozen_cards_file.close();
    }
    else
    {
        users_frozen_cards_file.close();
    }

    // bank_employee.txt exists, if not create it
    ifstream bank_employee_file("bank_employee.txt");
    if (!bank_employee_file)
    {
        ofstream bank_employee_file("bank_employee.txt");
        bank_employee_file.close();
    }
    else
    {
        bank_employee_file.close();
    }
}

int main()
{
    if (::startCheck == true)
    {
        check_files();
        load_files();
        ::startCheck = false;
    }

    system("cls");
    cout << endl;
    cout << "1. I'm a User" << endl;
    cout << "2. I'm a Bank Employee" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    while (choice != 3 && choice != 2 && choice != 1)
    {
        cout << endl;
        cout << "Invalid choice! Please enter again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        user_menu();
    }
    else if (choice == 2)
    {
        bank_employee_menu();
    }
    else
    {
        cout << "Exiting..." << endl;
    }
    save_all();
    system("pause");
    std::exit(0); // exit program (0 = no errors)
    return 0;
}
