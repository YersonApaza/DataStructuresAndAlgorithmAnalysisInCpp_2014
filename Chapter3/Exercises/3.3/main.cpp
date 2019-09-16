#include <iostream>
#include "list"
#include "iterator"
/*
3.3
Implement the STL find routine that returns the iterator containing the first occur-
rence of x in the range that begins at start and extends up to but not including end .
If x is not found, end is returned. This is a nonclass (global function) with signature

template <typename Iterator, typename Object>
iterator find( Iterator start, Iterator end, const Object & x );

3.3 (traduccion)
Implemente la rutina de búsqueda de STL que devuelve el iterador que contiene la primera aparición de x en el rango que comienza en el inicio y se extiende hasta el final, pero sin incluirlo.
Si no se encuentra x, se devuelve el final. Esta es una no clase (función global) con firma

template <typename Iterator, typename Object>
iterator find( Iterator start, Iterator end, const Object & x );


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
    node *getUltimo() const;
};

node *listnodedoble::getPrimero() const
{
    return primero;
}


node *listnodedoble::getUltimo() const
{
    return ultimo;
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
//rpt
template <typename Iterator, typename Object>
Iterator* find( Iterator *start, Iterator *end, const Object & x ){
    while(start != end){
        if(start->dato == x){
            return start;
        }
        start = start->der;
    }
    return end;
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
    std::cout<<"\nBuscar el 4\n";
    showlist(L);
    node* resp = nullptr;
    resp = find(L->getPrimero(),L->getUltimo(),4);
    std::cout<<"\niterador temporal: "<<resp<<" "<<resp->dato;
    std::cout<<"\nFinal\n";
}