#include <iostream>
#include "list"
#include "iterator"

// creado por yersonapazat@gmail.com en 13/09/2019

void showlist(std::list <int> *g,int stop)
{
    std::list <int> :: iterator it;
    int a = 0;
    for(it = g->begin(); it != g->end(); ++it){
        a++;    
        if( a == stop)
            std::cout << ' ' << *it;
    }
}
void printLots (std::list <int> *L, std::list <int>*P){
    std::cout << "\nprintLots:";
    std::list <int> :: iterator it;
    for(it = P->begin(); it != P->end(); ++it) {
        showlist(L,*it);
    }
    std::cout << '\n';
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
