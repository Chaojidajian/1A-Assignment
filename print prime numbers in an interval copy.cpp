//
//  main.cpp
//  4
//
//  Created by chaojidajian on 2018-10-03.
//  Copyright © 2018 chaojidajian. All rights reserved.
//

#include <iostream>
#include<cmath>
int main();
int main(){
    unsigned int a,b,c,d;
    std::cout<<"enter 2 numbers"<<std::endl;
    std::cin>>c>>d;
    if (c>d){
        a=d;
    } else {
        a=c;
        c=d;
        d=a;
       }
    while(a<=c){
    b=a/2;
    while (a%b != 0){
        b--;}
    if(b==1){
        std::cout<<a<<std::endl;
        a++;
    } else {
        a++;
    }
    
}
    

}
