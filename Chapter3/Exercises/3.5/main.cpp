/*3.5
Given two sorted lists, L 1 and L 2 , write a procedure to compute L 1 U L 2 using only
the basic list operations.
3.5 traduccion
Dadas dos listas ordenadas, L 1 y L 2, escriba un procedimiento para calcular L 1 U L 2 usando solo
las operaciones básicas de la lista*/

#include <iostream>
using namespace  std;

template  <class Object>
struct node{
    node *siguiente = nullptr;
    Object dato;
    node& operator++();
};

template  <class Object>
node<Object>& node<Object>::operator++(){
    if(siguiente->siguiente != nullptr){
        node<Object>* node_tmp = new node<Object>*;
        siguiente = siguiente->siguiente;
    }

}

template <class Object>
class listMia{
private:
    node<Object>* inicio = nullptr;
    node<Object>* fin = nullptr;
    node<Object>* it = nullptr;
public:
    node<Object>* begin();
    node<Object>* end();
    void push_back(Object T);
    listMia();
};

template <class Object>
node<Object>* listMia<Object>::begin(){
    return  inicio;
}
template <class Object>
listMia<Object>::listMia(){
}


template<class Object>
void listMia<Object>::push_back(Object T){
    node<Object>* temp = nullptr;
    temp = new node<Object>;
    temp->dato = T;
    if(inicio == nullptr){
        inicio = temp;
        fin = temp;
        return;
    }
    fin->siguiente = temp;
    fin = temp;
}

template <class Object>
node<Object>* listMia<Object>::end(){
    return fin;
}

template <class Object>
listMia<Object>* listUnion(listMia<Object> * L1,
                        listMia<Object> * L2)
{
    listMia<Object>* result = new  listMia<Object>;
    node<Object>* iterL1 = L1->begin();
    node<Object>* iterL2 = L2->begin();
    while(!(iterL1 == nullptr && iterL2  == nullptr)) //Esta linea en el solucionario es && pero no funciona.. con || si!
    {
        if(iterL1 == nullptr || iterL2 == nullptr){
            if(iterL1 == nullptr){
            result->push_back((*iterL2).dato);
            iterL2 = iterL2->siguiente;
            }else {
                result->push_back((*iterL1).dato);
                iterL1 = iterL1->siguiente;
            }
        }else {
        if ( (*iterL1).dato == (*iterL2).dato)
        {
            result->push_back((*iterL1).dato);
            if(iterL1 != nullptr){
                iterL1 = iterL1->siguiente;
            }
            if(iterL2 != nullptr){
                iterL2 = iterL2->siguiente;
            }
        }
        else if ((*iterL1).dato < (*iterL2).dato)
        {

            result->push_back((*iterL1).dato);
            if(iterL1 != nullptr){
                iterL1 = iterL1->siguiente;
            }
        }
        else
        {
            result->push_back((*iterL2).dato);
            if(iterL2 != nullptr){
                iterL2 = iterL2->siguiente;
            }
        }
    }

    }
    return result;
}
template <class Object>
void showlist(listMia<Object> *g)
{
    node<Object>* it_a = g->begin();
    while((it_a) != nullptr){
        //std::cout<<it_a->dato<<" "<<&(*it_a)<<" ";//mostrar dato y direccion
        std::cout<<it_a->dato<<" ";//mostrar solo dato

        it_a = it_a->siguiente;
    }
}
int main()
{
    listMia<int> *listA,*listB,*listC;
    listA = new listMia<int>;
    listB = new listMia<int>;

    listA->push_back(3);
    listA->push_back(4);
    listA->push_back(5);
    listA->push_back(6);
    listA->push_back(7);


    listB->push_back(6);
    listB->push_back(7);
    listB->push_back(8);
    listB->push_back(9);
    listB->push_back(10);

    listC = listUnion<int>(listA,listB);
    showlist(listC);
}
template class listMia<int>;
