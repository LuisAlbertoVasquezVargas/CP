#include<iostream>
#include<algorithm>
using namespace std;
int main(){

     int a[2],n;
     
     cin>>a[0]>>a[1]>>n;

     int i=1,x;
     
     while(1){
          
          i=1-i;
          x=__gcd(a[i],n);
          
          if(n >= x){
               n-=x;     
          }else  if(i==1){
                    
                    cout<<"0";
                    break;
               }
               else {
                    cout<<"1";               
                    break;
               }         
          
     }
}
