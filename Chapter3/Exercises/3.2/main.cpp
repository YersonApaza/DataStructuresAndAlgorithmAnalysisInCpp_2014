#include <iostream>
#include "list"
#include "iterator"

// creado por yersonapazat@gmail.com en 13/09/2019
struct node
{
    int dato;
    node* sig; 
};

class listnode
{
private:
    node* head = nullptr;
public:
    listnode();
    void add_node()
    ~listnode();
};
listnode::add_node(){
    if(head == nullptr)
        node.dato = 1;
    head.sig = new node();
    head.dato = 1;
}
 1 -> 2 -> 3

 11 -> 22 -> 33


void aSinglyLinkedLists(std::list <int> *a,std::list <int> *b){
    std::list <int> :: iterator it_a,it_b;
    it_a = a->begin();
    it_b = b->begin();
    for(; it_a != a->end(); ++it_a){
            std::cout << ' ' << *it;
    }
}


int main()
{
    std::list<int> L,P;
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
        L.push_back(item);

    }
    std::cout<<"\nIngrese Lista P: ";
    for (int i = 0; i < sizeP; ++i)
    {
        std::cin>>item;
        std::cout<<item<<" ";
        P.push_back(item);
    } 

    printLots(&L,&P);

    return 0;
}
