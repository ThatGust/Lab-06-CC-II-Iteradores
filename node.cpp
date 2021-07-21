#include "node.h"

// Constructor por defecto
Node::Node()
{
    data = NULL;
    next = NULL;
}


// Imprimir un Nodo
void Node::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << data << "-> ";
}

//Eliminar todos los nodos
void Node::s_delete_all()
{
    if (next)
        next->s_delete_all();
    delete this;
}


Node::~Node() {}