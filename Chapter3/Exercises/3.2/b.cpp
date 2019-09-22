#include <iostream>
#include "list"
#include "iterator"
/*
3.2
Swap two adjacent elements by adjusting only the links (and not the data) using
a. singly linked lists
b. doubly linked lists

Traduccion

3.2
Intercambiar los elementos adjacente por configuracion de solo direccion (y no los datos) usando
a. lista simple enlazada
b. lista doble enlazada

http://ms.ntub.edu.tw/~spade/ referencia!

*/
// creado por yersonapazat@gmail.com en 16/09/2019
struct node
{
    int dato;
    node* izq = nullptr;
    node* der = nullptr;
};

class listnodedoble
{
private:
    node* primero = nullptr;
    node* ultimo = nullptr;
public:
    listnodedoble(){}
    node *begin();
    void add_node(int a);
    ~listnodedoble();
    node *getPrimero() const;
};

node *listnodedoble::getPrimero() const
{
    return primero;
}


void listnodedoble::add_node(int a){

    node *apunt = new node();
    apunt->dato = a;
    apunt->izq = ultimo;
    if(ultimo){
        ultimo->der = apunt;
    }else {
        primero = apunt;
    }
    ultimo=apunt;
}


void showlist(listnodedoble *g)
{
    node* it_a = g->getPrimero();
    while((it_a) != nullptr){
           std::cout<<it_a->dato<<" "<<&(*it_a)<<" ";
           it_a = it_a->der;
    }
}

void SwapTwoAdjacentNodes_Double(node* P)
{
    node* izquierdaP, *derechaP;

    izquierdaP = P->izq;
    derechaP = P->der;


    P->der = derechaP->der;//1

    izquierdaP->der = derechaP;//2 Este Paso Va A variar

    derechaP->der = P;//3
    //
    P->der->izq = P;//4

    P->izq = derechaP;//5
    derechaP->izq = izquierdaP;//6

}
void test(listnodedoble *g)
{
    std::cout<<"\nCambio\n";
    int posicion= 2;
    node* it_a = g->getPrimero();
    for (int i=0;i < posicion;i++) {
           it_a = it_a->der;
    }
    SwapTwoAdjacentNodes_Double(it_a);
}
int main(){
    listnodedoble *L;
    int size= 0,item;
    L = new listnodedoble();
    std::cout<<"Ingrese Cantidad :";
    std::cin>>size;
    std::cout<<"Ingrese Lista L: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin>>item;
        L->add_node(item);
    }
    std::cout<<"\nCambio de Memoria en la posicion 2\n";
    showlist(L);
    test(L);
    showlist(L);
    std::cout<<"\nFinal\n";
}

