#include <iostream>
#include <vector>
#include <list>
#include <iterator>

#include "list.h"

using namespace std;


void print_list(list <int> element)
{
    list <int> ::iterator it;
    for (it = element.begin(); it != element.end(); ++it)
        cout << *it << " ";
}

int main()
{
    List list_1;
    iterator_list It;
    int dim;
    int pos;

    list <int> gqlist;
    //int sus;

    cout << "Ingresa la dimension de la lista: " << endl;
    cin >> dim;

    list_1.fill_random(dim);

    cout << "Lista A al inicio " << endl;
    list_1.print();

    cout << "Lista ordenada" << endl;
    list_1.sort();
    list_1.print();


    cout << "Elimina un elemento por posición: " << endl;
    cin >> pos;
    list_1.del_position(pos);
    list_1.print();


    cout << "---------------------------------------" << endl;
    cout << "Begin y End custom: " << endl;
    It = list_1.begin_n();
    cout << *It << endl;
    It = list_1.end_n();
    cout << *It << endl;
    cout << "Lista Imprimida con iteradores: ";
    for (It = list_1.begin_n(); It != list_1.end_n(); It++)
    {
        cout << *It << " ";
    }

    //----------------------------------------------


    for (int i = 0; i < 10; ++i)
    {
        gqlist.push_back(rand() % 100);

    }

    cout << "\nLista 1 STL: ";
    print_list(gqlist);

    cout << "Lista ordenada";
    cout << "\ngqlist.sort(): ";
    gqlist.sort();
    print_list(gqlist);


    

    return 0;
}