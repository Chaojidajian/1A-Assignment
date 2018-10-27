//
//  main.cpp
//  partb
//
//  Created by chaojidajian on 2018-10-08.
//  Copyright © 2018 chaojidajian. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <string>

int main();
double min(double a, double b, double c, double d);
double max(double a, double b, double c, double d);
void interval_calculator();
double min(double a, double b, double c, double d){
    double result=a;
    if (result>b){result=b;}
    if (result>c){result=c;}
    if (result>d){result=d;}
    return result;
}
double max(double a, double b, double c, double d){
    double result=a;
    if (result<b){result=b;}
    if (result<c){result=c;}
    if (result<d){result=d;}
    return result;
}
void interval_calculator(){
    std::string command;
    double a{1},b{0},c{0.0},d{0.0};
    double memory_stored[2]{1,0};
    do{std::cout<<"input :> ";
        std::cin>>command;
        int t=0;
        
        if (command=="enter") {
            double num1,num2;
            t++;
            
            std::cin>>num1;
            std::cin>>num2;
            
            
            
            if(num1>num2)
            {
                std::cout<<"Error:invalid interval as "<<num1<<" > "<<num2<<std::endl;
                if(a>b){
                    std::cout<<"--";
                } else{
                    std::cout<<"["<<a<<", "<<b<<"]";
                    
                }
            }else{ a=num1;
                b=num2;std::cout<<"["<<a<<", "<<b<<"]";}
            
        }
        
        
        if (command=="negate"){
            t++;
            if(a<=b){
                double num3,num4;
                num3=-b;num4=-a;
                a=num3;b=num4;
                std::cout<<"["<<a<<", "<<b<<"]";
            }else{std::cout<<"--";
            }
        }
        if (command=="invert"){
            t++;
            if(a>b){std::cout<<"--";}
            else{
                if((a<=0)&&(b>=0))
                {
                    std::cout<<"Error: division by zero"<<std::endl<<"--";
                    a=b;
                }else{std::cout<<"["<<1/b<<", "<<1/a<<"]";
                }
            }
        }
        if (command=="ms"){
            t++;
            if(a<=b){
                memory_stored[0]=a;
                memory_stored[1]=b;
                std::cout<<"["<<memory_stored[0]<<", "<<memory_stored[1]<<"]";
            }
            else{std::cout<<"--";
            }
        }
        if (command=="mr"){
            t++;
            if (memory_stored[0]>memory_stored[1]){
                
            }else{a=memory_stored[0];b=memory_stored[1];
            }
            if(a>b){std::cout<<"--";}
            else{std::cout<<"["<<a<<", "<<b<<"]";}
            
            
        }
        if (command=="mc"){
            t++;
            memory_stored[0]=1;memory_stored[1]=0;
            if(a<=b){std::cout<<"["<<a<<", "<<b<<"]";}
            else {std::cout<<"--";}
            
        }
        if (command=="m+"){
            t++;
            if((a<=b)&&(memory_stored[0]<=memory_stored[1])){memory_stored[0]+=a;memory_stored[1]+=b;std::cout<<"["<<a<<", "<<b<<"]";
            }else{std::cout<<"--";}
        }
        if (command=="m-"){
            t++;
            if((a<=b)&&(memory_stored[0]<=memory_stored[1]))
            {memory_stored[0]-=a;memory_stored[1]-=b;std::cout<<"["<<a<<", "<<b<<"]";
            }else{std::cout<<"--";}
        }
        if (command=="scalar_add"){
            t++;
            std::cin>>c;
            if (a>b){
                std::cout<<"--";
            } else {a+=c;b+=c;std::cout<<"["<<a<<", "<<b<<"]";}
        }
        
        if (command=="scalar_substract"){
            t++;
            std::cin>>c;
            if (a>b){
                std::cout<<"--";
            } else {a-=c;b-=c;std::cout<<"["<<a<<", "<<b<<"]";}
        }
        if (command=="scalar_multiply"){
            t++;
            std::cin>>c;
            if (a>b){
                std::cout<<"--";
            } else {
                double num3,num4;
                num3=min(a*c, a*c, b*c, b*c);
                num4=max(a*c, a*c, b*c, b*c);
                std::cout<<"["<<num3<<", "<<num4<<"]";
                a=num3;b=num4;
            }
        }
        if (command=="scalar_divide"){
            t++;
            std::cin>>c;
            if (a>b){
                std::cout<<"--";
            }else if(c==0){a=1;b=0;std::cout<<"Error: division by zero"<<std::endl<<"--";}
            else if(c>0){a/=c;b/=c;std::cout<<"["<<a<<", "<<b<<"]";}
            else {double num3,num4;
                num3=b/c;num4=a/c;
                a=num3;b=num4;
                std::cout<<"["<<a<<", "<<b<<"]";}
        }
        if (command=="scalar_divided_by"){
            t++;
            std::cin>>c;
            if (a>b){
                std::cout<<"--";
            }else if((a<=0) &&(0<=b)){a=1;b=0;std::cout<<"Error: division by zero"<<std::endl<<"--";}
            else if(c>0){a=c/b;b=c/a;std::cout<<"["<<a<<", "<<b<<"]";}
            else {double num3,num4;
                num3=c/a;num4=c/b;
                a=num3;b=num4;
                std::cout<<"["<<a<<", "<<b<<"]";}
        }
     
        
        if (command=="interval_add"){
            t++;
            std::cin>>c>>d;
            if(c>d){std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (a>b){
                    std::cout<<"--";
                }else{std::cout<<"["<<a<<", "<<b<<"]";
                }
                
            }else{
                if (a>b){
                    std::cout<<"--";
                }else{a+=c;b+=d;std::cout<<"["<<a<<", "<<b<<"]";}
            }
        }
        
        if (command=="interval_substract"){
            t++;
            std::cin>>c>>d;
            if(c>d){std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (a>b){
                    std::cout<<"--";
                }else{std::cout<<"["<<a<<", "<<b<<"]";
                }
            }else {
                if (a>b){
                    std::cout<<"--";
                }else{a-=d;b-=c;std::cout<<"["<<a<<", "<<b<<"]";}
            }
        }
        if (command=="interval_multiply"){
            t++;
            std::cin>>c>>d;
            if(c>d){std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (a>b){
                    std::cout<<"--";
                }else{std::cout<<"["<<a<<", "<<b<<"]";
                }
            }else {
                if (a>b){
                    std::cout<<"--";
                }else{double num3,num4;num3=min(a*c, a*d, b*c, b*d);num4=max(a*c, a*d, b*c, b*d);std::cout<<"["<<num3<<", "<<num4<<"]";a=num3;b=num4;}
                
            }
        }
        if (command=="interval_divide"){
            t++;
            std::cin>>c>>d;
            if(c>d){std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (a>b){
                    std::cout<<"--";
                }else{std::cout<<"["<<a<<", "<<b<<"]";
                }
            }else if((c<=0) &&(0<=d)){
                a=1;b=0;std::cout<<"Error: division by zero"<<std::endl<<"--";}
            else{
                if (a>b){
                    std::cout<<"--";
                }else{double num3,num4;
                    num3=min(a/c,a/d,b/c,b/d);
                    num4=max(a/c,a/d,b/c,b/d);
                    std::cout<<"["<<num3<<", "<<num4<<"]";a=num3;b=num4;}
            }
        }
        if (command=="intersect"){
            t++;
            std::cin>>c>>d;
            if(c>d){std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (a>b){
                    std::cout<<"--";
                }else{std::cout<<"["<<a<<", "<<b<<"]";
                }
            }else {
                if (a>b){
                    std::cout<<"--";
                }else{
                    if (((b>=c)&&(b<=d))||((a>=c)&&(a<=d))){
                        a=max(a,c,a,c);b=min(b,d,b,d);std::cout<<"["<<a<<", "<<b<<"]";}
                    else {a=1;b=0;std::cout<<"--";}
                    
                }
            }
        }
        if(command=="integers"){
            t++;
            if (a>b){
                std::cout<<"--";
            }else{
                int i=std::ceil(a);
                
                std::cout<<i;
                for(int i=std::ceil(a)+1;i<=std::floor(b);i++){
                    std::cout<<", "<<i;}
                std::cout<<std::endl<<"["<<a<<", "<<b<<"]";
            }
            
        }
        if(command=="cartesian_integers"){
            t++;
            std::cin>>c>>d;
            if(c>d){std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
                if (a>b){
                    std::cout<<"--";
                }else{std::cout<<"["<<a<<", "<<b<<"]";
                }
            }else {
                if (a>b){
                    std::cout<<"--";
                }else{
                    
                    for(int i=std::ceil(a);i<=std::floor(b);i++){
                        
                        for(int j=std::ceil(c);j<=std::floor(d);j++){
                            if((j==std::floor(d))&&(i==std::floor(b))){
                                std::cout<<"("<<i<<","<<j<<")";
                            }
                            else{ std::cout<<"("<<i<<","<<j<<"), ";
                            }
                        }
                    }    std::cout<<std::endl<<"["<<a<<", "<<b<<"]";
                }
            }
        }
        if((command!="exit")&&(t!=1)){std::cout<<"Error: illegal command";}
        std::cout<<std::endl;
        
        
    }
    while (command != "exit");
    std::cout<<"Bye bye: Terminating interval calculator program.";
    
}


int main(){
    interval_calculator();
    return 0;
    
}

