#include <iostream>
#include "list"
#include "iterator"

// creado por yersonapazat@gmail.com en 13/09/2019
struct node
{
    int dato;
    node* sig = nullptr; 
};
void showlist(listnode *g,int stop)
{
    node* it_a = nullptr;
    it_a = iterator_node(a);
    for(int i = 0; i < stop;i++){
        std::cout<<" "<<&(*it_a);
    }
    std::cout<<endl;
}

class listnode
{
private:
    node* head = nullptr;
public:
    listnode();
    node *begin()
    void add_node()
    ~listnode();
};

listnode::add_node(int a){
    if(head == nullptr)
        node.dato = a;
    head.sig = new node();
    head.dato = a;
}
node* listnode::begin(){
    return head;
}

//head --> 1 --> 2 --> 3

//head -> 11 -> 22 -> 33

//head -> 11 -> 22 -> 33

//head --> 1 --> 2 --> 3

//head -> 11 --> 2 --> 3

//head --> 1 -> 22 -> 33


node* iterador_node(std::list <int> *a){
    return a->begin();
}
void iterador_avanzar(node *a){
    node* temp = a->sig;
    a = temp;
}

void swapBylink(std::list <int> *a,std::list <int> *b,int size){
    
    node* it_a,*it_b;
    node* temp_dirc = nullptr;
    node* temp_dirc2 = nullptr;
    node* temp_dirc3 = nullptr;
    it_a = iterator_node(a);
    it_b = iterator_node(b);
    for (int i = 0; i < size; ++i)
    {
        temp_dirc = it_a->sig;
        if(!(temp_dirc == nullptr)){
            temp_dirc2 = *(it_a->sig).sig;
            temp_dirc3 = *(it_b->sig).sig;

            it_a->sig = it_b->sig;
            it_b->sig = temp_dirc;

            if(!temp_dirc == nullptr){
                *(it_b->sig).sig = temp_dirc2;
                *(it_a->sig).sig = temp_dirc3:
            }
        }
        if(!it_a == nullptr){
            iterador_avanzar(it_a);
            iterador_avanzar(it_b);
        }
    }

}




int main()
{
    listnode *L,*P;
    P = new listnode();
    L = new listnode();
    int sizeL,sizeP,item;
    std::cout<<"Ingrese Cantidad L:";
    std::cin>>sizeL;
    std::cout<<sizeL<<std::endl;
    std::cout<<"Ingrese Cantidad P:";
    std::cin>>sizeP;
    std::cout<<sizeP<<std::endl;
    std::cout<<"Ingrese Lista L: ";
    for (int i = 0; i < sizeL; ++i)
    {
        std::cin>>item;
        std::cout<<item<<" ";
        L.add_node(item);

    }
    std::cout<<"\nIngrese Lista P: ";
    for (int i = 0; i < sizeP; ++i)
    {
        std::cin>>item;
        std::cout<<item<<" ";
        P.add_node(item);
    } 
    swapBylink(L,P,sizeL);
    showlist(L,sizeL);
    showlist(P,sizeL);
    
    return 0;
}
