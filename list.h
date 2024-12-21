#include <iostream>

using namespace std;

class LinkedList;

class Node
{
    friend LinkedList;
    private:
        int data;
        Node *next;
        Node *prev;
    public:
        Node(int data_, Node *next_, Node *prev_);
};

class LinkedList
{
    private:
        Node *head;
        Node *tail; 
    public:
        LinkedList();
        void Append(int data);
        void Prepend(int data);
        int Length();
        void Print();
        void PrintReverse();
};