#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "node.h"

using namespace std;


class List
{
public:
    List();
    ~List();

    void add_head(int);
    void add_end(int);
    void del_position(int);
    void fill_by_user(int);
    void fill_random(int);
    void print();
    void sort();

    //sus
    Node* end_n();
    Node* begin_n();

private:
    Node* m_head;
    int m_num_nodes;
};

class iterator_list
{
public:
    void operator =(Node*);
    void operator ++(int);
    int operator *();
    bool operator ==(Node*);
    bool operator!=(Node*);

private:
    Node* p_node;

};


#endif 

