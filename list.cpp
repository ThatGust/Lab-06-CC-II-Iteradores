#include "list.h"

using namespace std;

// Constructor por defecto
List::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
void List::add_head(int data)
{
    Node* new_node = new Node;
    Node* temp = m_head;

    if (!m_head) {
        m_head = new_node;
    }
    else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

// Insertar al final
void List::add_end(int data)
{
    Node* new_node = new Node;
    Node* temp = m_head;

    if (!m_head) {
        m_head = new_node;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
        temp->data = data;
    }
    m_num_nodes++;
}


// Eliminar por posición del nodo
void List::del_position(int pos)
{
    Node* temp = m_head;
    Node* temp1 = temp->next;

    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    }
    else if (pos == 1) {
        m_head = temp->next;
    }
    else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node* aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

// Llenar la Lista por teclado
void List::fill_by_user(int dim)
{
    int ele;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        add_end(ele);
    }
}

// Llenar la Lista aleatoriamente para enteros
void List::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100);
    }
}


// Imprimir la Lista
void List::print()
{
    Node* temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    }
    else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

// Ordenar
void List::sort()
{
    int temp_data;
    Node* aux_node = m_head;
    Node* temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->next) {
            temp = temp->next;

            if (aux_node->data > temp->data) {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }

        aux_node = aux_node->next;
    }
}


// Iterador

// Primer nodo
Node* List::begin_n()
{
    Node* temp = m_head;
    return temp;
}

// Ultimo nodo
Node* List::end_n()
{
    Node* temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    }
    else
    {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }
}

// Operador igual
void iterator_list::operator=(Node* node)
{
    p_node = node;
}

// Desplazar un nodo

void iterator_list::operator++(int)
{
    p_node = p_node->next;
}


// Retornar valor
int iterator_list::operator*()
{
    return p_node->data;
}

// Operador comparativo
bool iterator_list::operator==(Node* node)
{
    return p_node == node;
}


//Operador de diferencia
bool iterator_list::operator!=(Node* node)
{
    return p_node != node;
}



List::~List() {}