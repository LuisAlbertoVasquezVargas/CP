#include<iostream>
using namespace std;
int main(){
     
     long long k,l;     
     cin>>k>>l;
     
     long long s=0,i;
     for( i = 1 ; i < l ; i*=k)
          s++;

     if(i==l)
          cout<<"YES\n"<<s-1;
     else 
          cout<<"NO";               
     
}
