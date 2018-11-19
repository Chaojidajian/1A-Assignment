//
//  main.cpp
//  project1
//
//  Created by chaojidajian on 2018-10-08.
//  Copyright © 2018 chaojidajian. All rights reserved.
//
#include <iostream>
#include <cmath>
#ifndef MARMOSET_TESTING
int main();
#endif
int a;
double n;
double iterative_factorial (double n);
double recursive_factorial (double n);
int pascal_triangle(int a);
int pascal_triangle_recursive(int a);

double iterative_factorial (double n){
    double result = 1;
    for (int i=1; i<=n; i++){
        result = result * i;
    }
    return result;
}
double recursive_factorial (double n){
    if(n==0){return 1;}
    else {return n*recursive_factorial(n-1);}
}

int pascal_triangle(int a) {
    a++;
    for (int n=1;n<=a;n++){
        for (int k=1;k<=n;k++){
            std::cout<< iterative_factorial(n-1)/(iterative_factorial(k-1)*iterative_factorial(n-k))<<" ";
        }
        std::cout<<std::endl;
    }
    return ((a*(a+1))/2);
    
}

int pascal_triangle_recursive(int a){
    
    int b=1;
    if (a==0){
        std::cout<<1;
        std::cout<<std::endl;
    } else {
        b=pascal_triangle_recursive(a-1);
        for (int k=0;k<=a;k++){
            std::cout<< recursive_factorial(a)/(recursive_factorial(k)*recursive_factorial(a-k))<<" ";
            b++;
            
        }
        std::cout<<std::endl;
    }
    
    return b;
}
#ifndef MARMOSET_TESTING
int main(){
    
    a=5;
    //    std::cin>>a;
    std::cout<<
    pascal_triangle(a)<<std::endl<<pascal_triangle_recursive(a);
    
}
#endif
