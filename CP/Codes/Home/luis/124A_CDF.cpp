#include<iostream>
#include<algorithm>
using namespace std;
int main(){
     
     int n,a,b;
     
     cin>>n>>a>>b;
     
     int i=0;
     
     while(i <= b){
          
          if(n-1-i<a)
               break;     
               
          i++;
          
     }
     
     cout<<i;
}
