//
//  main.cpp
//  12
//
//  Created by chaojidajian on 2018-10-03.
//  Copyright © 2018 chaojidajian. All rights reserved.
//

#include <iostream>
int main();
double a{1};
double b{0};
double c{0};
double d{0};

int main(){
    std::cout<<"enter a number"<<std::endl;
    std::cin>>d;
    std::cout<<"the sequence is ";
    while (b<d){
        c=a;
        
        
        a=b;
        b=a+c;
        std::cout<<b<<",";
        
        
        
        
    }
}
