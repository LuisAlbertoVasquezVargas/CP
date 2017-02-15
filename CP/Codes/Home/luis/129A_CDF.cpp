#include<iostream>
#define MAXN 100

using namespace std;

int a[MAXN];

int main(){
     
     int n,x;
     cin>>n;
     
     for(int i = 1 ; i <= n ; ++i){
               
          cin>>x;
          a[x]=i;               
     }     
     
     bool in=true;
     for(int i = 1 ; i <= n ; ++i){
          
          if(in)
               in=false;
          else
               cout<<" ";
               
          cout<<a[i];                                   
          
     }
     
}
