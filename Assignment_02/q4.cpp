#include <iostream>
using namespace std;

class Polynomial
{
private:
    int totalTerms; // Total terms in polynomial
    int *coeff;     // To save array of coefficients
    int *exp;       // To save array of exponents

public:
    // Constructor
    Polynomial(int terms, int *c, int *e) : totalTerms(terms)
    {
        coeff = new int[totalTerms];
        exp = new int[totalTerms];
        for (int i = 0; i < totalTerms; i++)
        {
            coeff[i] = c[i];
            exp[i] = e[i];
        }
    }

    // Copy constructor
    Polynomial(const Polynomial &P) : totalTerms(P.totalTerms)
    {
        coeff = new int[totalTerms];
        exp = new int[totalTerms];
        for (int i = 0; i < totalTerms; i++)
        {
            coeff[i] = P.coeff[i];
            exp[i] = P.exp[i];
        }
    }

    // Destructor
    ~Polynomial()
    {
        delete[] coeff;
        delete[] exp;
    }

    // Overload the << operator to display the polynomial
    friend ostream &operator<<(ostream &out, const Polynomial &P)
    {
        for (int i = 0; i < P.totalTerms; i++)
        {
            if (i > 0 && P.coeff[i] >= 0)
            {
                out << " + ";
            }
            if (P.exp[i] == 0)
            {
                out << P.coeff[i];
            }
            else if (P.coeff[i] != 1)
            {
                out << P.coeff[i] << "x^" << P.exp[i];
            }
            else
            {
                out << "x^" << P.exp[i];
            }
        }
        return out;
    }

    // Overload the ! operator to check if the polynomial is zero
    bool operator!() const
    {
        for (int i = 0; i < totalTerms; i++)
        {
            if (coeff[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    // Overload the != operator to check if two polynomials are not equal
    bool operator!=(const Polynomial &P) const
    {
        if (totalTerms != P.totalTerms)
        {
            return true;
        }
        for (int i = 0; i < totalTerms; i++)
        {
            if (coeff[i] != P.coeff[i] || exp[i] != P.exp[i])
            {
                return true;
            }
        }
        return false;
    }

    // Overload the + operator to add two polynomials
    Polynomial operator+(const Polynomial &P) const
    {
        int terms = totalTerms + P.totalTerms;
        int *c = new int[terms];
        int *e = new int[terms];

        int i = 0, j = 0, k = 0;
        while (i < totalTerms && j < P.totalTerms)
        {
            if (exp[i] > P.exp[j])
            {
                c[k] = coeff[i];
                e[k] = exp[i];
                i++;
            }
            else if (exp[i] < P.exp[j])
            {
                c[k] = P.coeff[j];
                e[k] = P.exp[j];
                j++;
            }
            else
            {
                c[k] = coeff[i] + P.coeff[j];
                e[k] = exp[i];
                i++;
                j++;
            }
            k++;
        }

        while (i < totalTerms)
        {
            c[k] = coeff[i];
            e[k] = exp[i];
            i++;
            k++;
        }

        while (j < P.totalTerms)
        {
            c[k] = P.coeff[j];
            e[k] = P.exp[j];
            j++;
            k++;
        }

        Polynomial result(k, c, e);
        delete[] c;
        delete[] e;
        return result;
    }

    // Overload the ++ operator to add 1 to all coefficients (prefix)
    Polynomial &operator++()
    {
        for (int i = 0; i < totalTerms; i++)
        {
            coeff[i]++;
        }
        return *this;
    }

    // Overload the ++ operator to add 1 to all coefficients (postfix)
    Polynomial operator++(int)
    {
        Polynomial temp(*this);
        for (int i = 0; i < totalTerms; i++)
        {
            coeff[i]++;
        }
        return temp;
    }

    // Overload the + operator to add a number to constant in the polynomial
    friend Polynomial operator+(int num, const Polynomial &P)
    {
        if (P.exp[P.totalTerms - 1] == 0)
        {
            int *c = new int[P.totalTerms];
            int *e = new int[P.totalTerms];
            for (int i = 0; i < P.totalTerms; i++)
            {
                c[i] = P.coeff[i];
                e[i] = P.exp[i];
            }
            c[P.totalTerms - 1] = c[P.totalTerms - 1] + num;
            Polynomial result(P.totalTerms, c, e);
            delete[] c;
            delete[] e;
            return result;
        }
        else
        {
            int *c = new int[P.totalTerms + 1];
            int *e = new int[P.totalTerms + 1];
            for (int i = 0; i < P.totalTerms; i++)
            {
                c[i] = P.coeff[i];
                e[i] = P.exp[i];
            }
            c[P.totalTerms] = num;
            e[P.totalTerms] = 0;
            Polynomial result(P.totalTerms + 1, c, e);
            delete[] c;
            delete[] e;
            return result;
        }
    }

    // overload = operator
    Polynomial &operator=(const Polynomial &P)
    {
        if (this != &P)
        {
            totalTerms = P.totalTerms;
            delete[] coeff;
            delete[] exp;
            coeff = new int[totalTerms];
            exp = new int[totalTerms];
            for (int i = 0; i < totalTerms; i++)
            {
                coeff[i] = P.coeff[i];
                exp[i] = P.exp[i];
            }
        }
        return *this;
    }
};

int main()
{
    int coeff_P1[] = {1, 2, 5}; // Coefficient of P1
    int exp_P1[] = {4, 2, 0};   // Exponent of P1

    int coeff_P2[] = {4, 3}; // Coefficient of P2
    int exp_P2[] = {6, 2};   // Exponent of P2

    Polynomial P1(3, coeff_P1, exp_P1); // Creates P1 with 3 terms, (P1 = 1x^4+ 2x^2 + 5x^0)
    Polynomial P2(2, coeff_P2, exp_P2); // Creates P2 with 2 terms (P2 = 4x^6 + 3x^2)

    cout << "P1 = " << P1 << endl; // Prints P1, x^4 + 2x^2 + 5
    cout << "P2 = " << P2 << endl; // Prints P2, 4x^6 + 3x^2

    if (!P1)
    {
        cout << "P1 is zero" << endl;
        /*
        If polynomial has only 1 term and it's coeff and exp are also zero, ie if P1 = 0
        */
    }

    if (P1 != P2)
    {
        cout << "P1 and P2 are not equal" << endl;
    }

    Polynomial P3 = P1 + P2; // Adds P1 and P2 and saves result in P3,

    cout << "P3 = " << P3 << endl; // Prints P3, 4x^6 + x^4 + 5x^2 + 5

    cout << ++P1 << endl; // Adds 1 in all coefficients

    cout << P1 << endl;

    cout << P1++ << endl; // Adds 1 in all coefficients

    cout << P1 << endl;

    P3 = 2 + P1; // Assume P1 already has a constant term, add 2 to it

    cout << "P3 = " << P3 << endl
         << endl; // Added and extra endl for better readability

    system("pause"); // To pause the console before exiting (added as extra)
    return 0;
}