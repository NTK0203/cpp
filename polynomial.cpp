#include <iostream>
#include <string>
#include <fstream>
#include "polynomial.h"

using namespace std;

Polynomial::Polynomial():capacity(1), terms(0)
{
    termarray=new term[capacity];
}

void Polynomial::LoadPolynomial(std::string& filename)
{
    ifstream ifs(filename);
    int terms_,coef_,exp_;
    ifs>>(terms_);
    for(int i=0;i<terms_;i++)
    {
        ifs>>(coef_);
        ifs>>(exp_);
        newterm(coef_,exp_);
    }
}
void Polynomial::PrintPolynomial()
{
    int temp_e=0;
    int temp_c=0;
    for(int i=0;i<(terms-1);i++)
    {
        for(int j=i+1;j<terms;j++)
        {
            if(termarray[i].exp<termarray[j].exp)
            {
                temp_e=termarray[i].exp;
                temp_c=termarray[i].coef;
                termarray[i].exp=termarray[j].exp;
                termarray[i].coef=termarray[j].coef;
                termarray[j].exp=temp_e;
                termarray[j].coef=temp_c;
            }
        }
    }
    for(int i=0;i<terms;i++)
        cout<<termarray[i].coef<<" "<<termarray[i].exp<<endl;
}

void Polynomial::newterm(const int thecoef, const int theexp)
{
    if(terms==capacity)
    {
        capacity*=2;
        term *temp=new term[capacity];
        copy(termarray,termarray+terms,temp);
        delete [] termarray;
        termarray=temp;
    }
    termarray[terms].coef=thecoef;
    termarray[terms].exp=theexp;
    terms++;
}

void Polynomial::add(Polynomial a, Polynomial b)
{
    a=sort(a);
    b=sort(b);
    int apos=0,bpos=0;
    while((apos<a.terms)&&(bpos<b.terms))
    {
        if(a.termarray[apos].exp==b.termarray[bpos].exp)
        {
            if(a.termarray[apos].coef+b.termarray[bpos].coef)
            {
                newterm(a.termarray[apos].coef+b.termarray[bpos].coef,a.termarray[apos].exp);
            }
            apos++;
            bpos++;
        }
        else if(a.termarray[apos].exp>b.termarray[bpos].exp)
        {
            newterm(a.termarray[apos].coef,a.termarray[apos].exp);
            apos++;
        }
        else
        {
            newterm(b.termarray[bpos].coef,b.termarray[bpos].exp);
            bpos++;
        }
    }
    for (;apos<a.terms;apos++)
        newterm(a.termarray[apos].coef, a.termarray[apos].exp);
    for (;bpos<b.terms;bpos++)
        newterm(b.termarray[bpos].coef, b.termarray[bpos].exp);
}

Polynomial Polynomial::sort(Polynomial a)
{
    int temp_e=0;
    int temp_c=0;
    for(int i=0;i<(a.terms-1);i++)
    {
        for(int j=i+1;j<a.terms;j++)
        {
            if(a.termarray[i].exp<a.termarray[j].exp)
            {
                temp_e=a.termarray[i].exp;
                temp_c=a.termarray[i].coef;
                a.termarray[i].exp=a.termarray[j].exp;
                a.termarray[i].coef=a.termarray[j].coef;
                a.termarray[j].exp=temp_e;
                a.termarray[j].coef=temp_c;
            }
        }
    }
    return a;
}