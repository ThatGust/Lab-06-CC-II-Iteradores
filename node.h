#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


class Node
{
public:
    Node();
    ~Node();

    Node* next;
    int data;

    void print();

    void s_delete_all();
};

#endif