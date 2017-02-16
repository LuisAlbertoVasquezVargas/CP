#include<iostream>
#include<algorithm>
#define MAXN 1000
using namespace std;
int a[MAXN],b[MAXN];
int main(){
     
     int n;
     cin>>n;
     
     for(int i = 0 ; i < n ; ++i)
          cin>>a[i]>>b[i];     
     
     int cap=0;     
     int maxi=0;
     
     for(int i = 0 ; i < n ; ++i){
          
          cap-=a[i];
          cap+=b[i];
          maxi=max(maxi,cap);
     
     }
     
     cout<<maxi;
     
}
