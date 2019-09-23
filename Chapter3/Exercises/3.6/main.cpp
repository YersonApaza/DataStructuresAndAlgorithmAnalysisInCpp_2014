/*
3.6
The Josephus problem is the following game: N people, numbered 1 to N, are sitting
in a circle. Starting at person 1, a hot potato is passed. After M passes, the person
holding the hot potato is eliminated, the circle closes ranks, and the game con-
tinues with the person who was sitting after the eliminated person picking up the
hot potato. The last remaining person wins. Thus, if M = 0 and N = 5, players
are eliminated in order, and player 5 wins. If M = 1 and N = 5, the order of
elimination is 2, 4, 1, 5.
a. Write a program to solve the Josephus problem for general values of M and N.
Try to make your program as efficient as possible. Make sure you dispose of
cells.
b. What is the running time of your program?
c. If M = 1, what is the running time of your program? How is the actual speed
affected by the delete routine for large values of N (N > 100,000)?

3.6
El problema de Josephus es el siguiente juego: N personas, numeradas del 1 al N, están sentadas
en un círculo. Comenzando en la persona 1, se pasa una papa caliente. Después de que M pasa, la persona
se elimina sostener la papa caliente, el círculo cierra filas y el juego continúa
continúa con la persona que estaba sentada después de que la persona eliminada recogiera el
patata caliente. La última persona restante gana. Por lo tanto, si M = 0 y N = 5, los jugadores
son eliminados en orden, y el jugador 5 gana.
Si M = 1 y N = 5, el orden de la eliminación es 2, 4, 1, 5.

a. Escriba un programa para resolver el problema de Josephus para valores generales de M y N.
Intenta hacer que tu programa sea lo más eficiente posible. Asegúrese de deshacerse de
Células.
b. ¿Cuál es el tiempo de ejecución de su programa?
C. Si M = 1, ¿cuál es el tiempo de ejecución de su programa? ¿Cómo es la velocidad real?
afectado por la rutina de borrado para valores grandes de N (N> 100,00s0)?

*/
#include <iostream>
using namespace  std;

//creado por yersonapazat@gmail.com
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
    int tamano =0;
public:
    node<Object>* begin();
    node<Object>* end();
    int size();
    void push_back(Object T);
    listMia();
    void Eliminar_posicion(int posicion);

};

template <class Object>
int listMia<Object>::size(){
    return  tamano;
}
template <class Object>
void listMia<Object>::Eliminar_posicion(int posicion){
    if(posicion == tamano){
        tamano--;
        return;
    }
    node<int>* temporal = inicio;
    if(posicion == 0){
        inicio = inicio->siguiente;
        tamano--;
        return;
    }else{
        for (int i = 1;i < posicion ; i++) {
            temporal = temporal->siguiente;
        }
    }
    //if(temporal->siguiente == nullptr)
    temporal->siguiente = temporal->siguiente->siguiente;
    tamano--;
}

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
        tamano++;
        return;
    }
    fin->siguiente = temp;
    fin = temp;
    tamano++;
}
template <class Object>
node<Object>* listMia<Object>::end(){
    return fin;
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
    cout<<endl;
}
void Juego_patata(listMia<int>* tmp, int n){
    int corre = n;
    while(tmp->size() != 1){
        if(corre >= tmp->size()){
            corre = corre- tmp->size();
        }
        tmp->Eliminar_posicion(corre);
        corre = corre + n;
        showlist(tmp);
    }
}
int main()
{
    listMia<int> *listA;
    listA = new listMia<int>;
    listA->push_back(1);
    listA->push_back(2);
    listA->push_back(3);
    listA->push_back(4);
    listA->push_back(5);
    showlist(listA);
    Juego_patata(listA,1);
}

template class listMia<int>;
