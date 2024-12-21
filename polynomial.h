#include <iostream>
#include <string>

using namespace std;

class Polynomial;

class term
{
    friend Polynomial;
    private:
        int coef;
        int exp;
};

class Polynomial
{
    private:
        term *termarray;
        int capacity;
        int terms;
    public:
        Polynomial();
        void LoadPolynomial(std::string& filename);
        void PrintPolynomial();
        void newterm(const int thecoef, const int theexp);
        void add(Polynomial a, Polynomial b);
        Polynomial sort(Polynomial a);
};