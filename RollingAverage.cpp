//
//  main.cpp
//  tutorial
//
//  Created by chaojidajian on 2018-09-24.
//  Copyright © 2018 chaojidajian. All rights reserved.
//

#include <iostream>
#include <cmath>
#ifndef MARMOSET_TESTING
int main ();
#endif
float input1{0.0};
float input2{0.0};
float input3{0.0};
float calculated_average(float input1, float input2, float input3){
    return (input1+input2+input3)/3;
}
    #ifndef MARMOSET_TESTING
int main () {
        float input1{0.0};
        float input2{0.0};
        float input3{0.0};
        float input_number{0.0};
    int i=0;
    float rolling_average{0.0};
    
    while(i<5&input_number >= 0)
    {std::cout<<"Enter a number."<<std::endl;
        std::cin>>input_number;
        input1=input2;
        input2=input3;
        input3=input_number;
        i=i+1;
        if(i>=3){
            rolling_average=calculated_average(input1,input2,input3);
            std::cout<<"rolling average is:"<<rolling_average<<std::endl;
    
    
    }
    
    }
        
        
    }
#endif
