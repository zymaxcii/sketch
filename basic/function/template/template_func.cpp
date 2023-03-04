// https://www.w3schools.in/cplusplus/templates

// #include<iostream.h>
// #include<conio.h>    // for windows?

using namespace std;     // using, not use and must add ;

#include <iostream>
// #include <conio>

// function template
template <class swap>

void swapp(swap &i, swap &j)
{
    swap t;
    t=i;
    i=j;
    j=t;
}
 
int main() {
    int e,f;
    char g,r;
    float x,y;

    std::cout<<"\n Please insert 2 Integer Values:";
    std::cin>>e>>f;
    swapp(e,f);

    std::cout<<"\nInteger values after Swapping:";
    std::cout<<e<<"\t"<<f<<"\n\n";
    
    std::cout<<"\n Please insert 2 Character Values:";
    std::cin>>g>>r;
    swapp(g,r);
    std::cout<<"\n Character Values after Swapping:";
    
    std::cout<<g<<"\t"<<r<<"\n\n";
    std::cout<<"\n please insert 2 Float Values:";
    std::cin>>x>>y;
    swapp(x,y);
    std::cout<<"\n The resultatnt float values after swapping:";
    std::cout<<x<<"\t"<<y<<"\n\n";
}
