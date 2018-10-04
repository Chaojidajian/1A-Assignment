//
//  main.cpp
//  test
//
//  Created by chaojidajian on 2018-09-24.
//  Copyright © 2018 chaojidajian. All rights reserved.
//

#include <iostream>
#include <cmath>
int main();
int input_number;
int get_reverse(int input_number);
int get_reverse(int input_number){
    int result{0};
    result= input_number%10;
    while (input_number >= 10){
        input_number=input_number/10;
        result=result*10+input_number%10;
        
    }
    return result;
}

int main (){
    std::cin>> input_number;
    std::cout<< get_reverse(input_number);
}
