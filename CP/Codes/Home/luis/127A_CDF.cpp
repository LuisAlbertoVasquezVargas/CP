#include<iostream>
#include<cmath>
#include<cstdio>
#define MAXN 100
using namespace std;
int main(){

     int n,k;
     
     cin>>n>>k;

     int x[MAXN],y[MAXN];       
     
     double d=0;
     
     for( int i = 0 ; i < n ;++i){

   
          cin>>x[i]>>y[i];          
          
          if(i!=0)
               d+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
               
     }     
     
     printf("%.10lf",(d/50.0)*k);

     
     
}
