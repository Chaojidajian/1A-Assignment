//
//  main.cpp
//  Project 2
//
//  Created by chaojidajian on 2018-11-15.
//  Copyright © 2018 chaojidajian. All rights reserved.
//

#include <iostream>
#include "Polynomial.h"
#ifndef MARMOSET_TESTING
int main();
#endif
void init_poly( poly_t &p, double const init_coeffs[],
               unsigned int const init_degree )
{
    if (p.a_coeffs!=nullptr){
        delete[] p.a_coeffs;
        p.a_coeffs=nullptr;
    }
        p.degree=init_degree;
        p.a_coeffs=new double[p.degree+1];
    for(int k{0};k<=p.degree;++k){
            p.a_coeffs[k]=init_coeffs[k];


    }
}
void destroy_poly( poly_t &p )
{
    delete[] p.a_coeffs;
    p.a_coeffs=nullptr;
}
unsigned int poly_degree( poly_t const &p )
{
    if(p.a_coeffs==nullptr){
        throw 0;
    }else{
        return p.degree;
    }
}
double poly_coeff ( poly_t const &p, unsigned int n )
{
    if(p.a_coeffs==nullptr){
        throw 0;
    }else if(n>p.degree){
        return 0;
    }else{
        return p.a_coeffs[n];
    }
}
double poly_val( poly_t const &p, double x )
{
    if(p.a_coeffs==nullptr){
        throw 0;}
    else{double sum{0};
    for(int i=p.degree;i>=0;i--){
        sum=p.a_coeffs[i]+x*sum;
    }
    return sum;
    }
}
void poly_add( poly_t &p, poly_t const &q )
{
    if((p.a_coeffs==nullptr)||(q.a_coeffs==nullptr))
    {
        throw 0;}
    else
    { unsigned int n=p.degree;
        if (p.degree<q.degree)
        {
            n=q.degree;
        }
        if (p.degree==q.degree){
            while((p.a_coeffs[n]==-q.a_coeffs[n])&&(n!=0)){
                n--;
            }
        }
        double *n_array{new double[n+1]};
        for(int i=n;i>=0;i--){
            n_array[i]=0;
        }
        for (int i=n;i>=0;i--){
            if(i>p.degree){
                n_array[i]=q.a_coeffs[i];
            }else if(i>q.degree){
                n_array[i]=p.a_coeffs[i];
            }else{
            n_array[i]=p.a_coeffs[i]+q.a_coeffs[i];
            }
        }
        delete[] p.a_coeffs;
        p.a_coeffs=nullptr;
        p.degree=n;
        p.a_coeffs=n_array;
    }
}
void poly_subtract( poly_t &p, poly_t const &q ){

    if((p.a_coeffs==nullptr)||(q.a_coeffs==nullptr))
    {
        throw 0;}
    else
    {unsigned int n=p.degree;
        if (p.degree<q.degree)
        {
            n=q.degree;
        }
        if (p.degree==q.degree){
            while((p.a_coeffs[n]==q.a_coeffs[n])&&(n!=0)){
                n--;
            }
        }
        double *n_array{new double[n+1]};
        for(int i=n;i>=0;i--){
            n_array[i]=0;
        }
        for (int i=n;i>=0;i--){
            if(i>p.degree){
                n_array[i]=-q.a_coeffs[i];
            }else if(i>q.degree){
                n_array[i]=p.a_coeffs[i];
            }else{
                n_array[i]=p.a_coeffs[i]-q.a_coeffs[i];
            }
        }
        delete[] p.a_coeffs;
        p.a_coeffs=nullptr;
        p.degree=n;
        p.a_coeffs=n_array;
    }
}
void poly_multiply( poly_t &p, poly_t const &q ){
    if((p.a_coeffs==nullptr)||(q.a_coeffs==nullptr))
    {
        throw 0;}
    else {
        unsigned int n;

        if((p.degree==0&&p.a_coeffs[0]==0)||(q.degree==0&&q.a_coeffs[0]==0))
        {
            n=0;
            double *n_array{new double[n+1]};
            for(int i=n;i>=0;i--)
            {
                n_array[i]=0;
            }
            delete[] p.a_coeffs;
            p.a_coeffs=nullptr;
            p.degree=n;
            p.a_coeffs=n_array;
        }
        else
        {   n=p.degree+q.degree;
            double *n_array{new double[n+1]};
            for(int i=n;i>=0;i--){
                n_array[i]=0;
            }
            for (int i=0;i<=p.degree;++i){
                for(int k=0;k<=q.degree;++k){
                    // if((k<=p.degree)&&((i-k)<=q.degree)){
                    n_array[i+k]+=p.a_coeffs[i]*q.a_coeffs[k];
                  // }
                  // else{break;}
                }
            }
            delete[] p.a_coeffs;
            p.a_coeffs=nullptr;
            p.degree=n;
            p.a_coeffs=n_array;
        }
    }

}
double poly_divide( poly_t &p, double r )
{
    if(p.a_coeffs==nullptr){
        throw 0;}
    else if (p.degree==0) {
      int a=0;
      a=p.a_coeffs[0];
      p.a_coeffs[0]=0;
      return a;

    }else{
        int n=p.degree-1;
        double *n_array{new double[n+1]};
        for(int i=n;i>=0;i--){
            n_array[i]=0;
        }

        for(int i=n;i>=0;i--){
            if(i==n){
                n_array[i]=p.a_coeffs[i+1];
            }else{
                n_array[i]=n_array[i+1]*r+p.a_coeffs[i+1];}
        }
        double a=p.a_coeffs[0]+r*n_array[0];
        delete[] p.a_coeffs;
        p.a_coeffs=nullptr;
        p.degree=n;
        p.a_coeffs=n_array;
        if(poly_val(p, r)==0){
            return 0;
        }else{
            return a;
        }
    }
}
void poly_diff( poly_t &p ){
    if(p.a_coeffs==nullptr){
        throw 0;}
    else if(p.degree==0){
        p.a_coeffs[0]=0;
    }else{
        int n=p.degree-1;
        double *n_array{new double[n+1]};
        for(int i=n;i>=0;i--){
            n_array[i]=0;
        }
        for(int i=n;i>=0;i--){
            n_array[i]=p.a_coeffs[i+1]*(i+1);
        }
        delete[] p.a_coeffs;
        p.a_coeffs=nullptr;
        p.degree=n;
        p.a_coeffs=n_array;
    }

}
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n ){
    if(p.a_coeffs==nullptr){
        throw 0;}
    else{
        double h=(b-a)/n;
        double result=0;
        double k;
        for (double i=1;i<=n-1;++i){
            k=a+i*h;
            result=result+poly_val(p, k);
        }
        result=h/2*(poly_val(p, a)+2*result+poly_val(p, b));
        return result;
    }
}
// int main(){
//   double a[7]{1.1231,1,1,1,1,1,1.12312};
//   int b{6};
//   double c[2]{1.43,1.123};
//   int d{1};
//   poly_t p,q;
//   init_poly(p,a,b);
//   init_poly(q,c,d);
//
//   poly_multiply(p,q);
//   for(int i{0};i<=p.degree;i++){
//     std::cout<<p.a_coeffs[i]<<std::endl;
//   }
// }
