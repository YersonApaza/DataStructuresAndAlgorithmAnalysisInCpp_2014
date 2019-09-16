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
    node* sig = nullptr;
};

class listnode
{
private:
    node* head = nullptr;
    node* iterador = nullptr;
public:
    listnode(){}
    node *begin();
    void add_node(int a);
    ~listnode();
};
void listnode::add_node(int a){
    if(head == nullptr){
        head = new node;
        head -> dato = a;
        iterador = head;
        return;
    }
    node* temp = new node();
    temp->dato = a;

    iterador->sig = temp;
    iterador = temp;
}
node* listnode::begin(){
    return head;
}

void showlist(listnode *g)
{
    node* it_a = g->begin();
    while((it_a) != nullptr){
           std::cout<<it_a->dato<<" "<<&(*it_a)<<" ";
           it_a = it_a->sig;
    }
}

void SwapTwoAdjacentNodes_Single(node *BeforeP)
{
    node *P, *AfterP;
    P = BeforeP->sig;
    AfterP = P->sig;
    P->sig = AfterP->sig;
    BeforeP->sig = AfterP;
    AfterP->sig = P;
}
void test(listnode *g)
{
    std::cout<<"\nCambio\n";
    int posicion= 1;
    node* it_a = g->begin();
    for (int i=0;i < posicion;i++) {
           it_a = it_a->sig;
    }
    SwapTwoAdjacentNodes_Single(it_a);
}
int main(){
    listnode *L;
    int size= 0,item;
    L = new listnode();
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
