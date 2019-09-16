#include <iostream>
#include "list"
#include "iterator"
/*
3.4
Given two sorted lists, L 1 and L 2 , write a procedure to compute L 1 ∩ L 2 using only
the basic list operations.
3.4 traduccion

Dadas dos listas ordenadas, L 1 y L 2, escriba un procedimiento para calcular L 1 ∩ L 2 usando solo
las operaciones básicas de la lista

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
bool find( Iterator *start, Iterator *end, const Object & x ){
    while(start != end){
        if(start->dato == x){
            return true;
        }
        start = start->der;
    }
    return false;
}
void interseccionlista(listnodedoble* A, listnodedoble* B){
    node *iterador_union = A->getPrimero();
    std::cout<<"union:";
    while (iterador_union != A->getUltimo()) {
        if(find(B->getPrimero(),B->getUltimo(),iterador_union->dato)){
            std::cout<<iterador_union->dato<<" ";
        }
        iterador_union = iterador_union->der;
    }
}

int main(){
    listnodedoble *L,*P;
    int size= 0,item;
    L = new listnodedoble();
    P = new listnodedoble();
    std::cout<<"Ingrese Cantidad :";
    std::cin>>size;
    std::cout<<"Ingrese Lista L: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin>>item;
        L->add_node(item);
    }
    std::cout<<"Ingrese Cantidad :";
    std::cin>>size;
    std::cout<<"Ingrese Lista P: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin>>item;
        P->add_node(item);
    }
    interseccionlista(L,P);
}
