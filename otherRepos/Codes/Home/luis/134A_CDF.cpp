#include<iostream>
#include<vector>
#define MAXN 200000

using namespace std;

int a[MAXN];
vector< int >v;

int main(){
     
     int n,s=0;
     cin>>n;
     
     for( int i = 0 ; i < n ; ++i){

          cin>>a[i];     
          s+=a[i];          
     }
     

     
     for( int i = 0 ;i < n ; ++i)
          if(s==a[i]*n)
               v.push_back(i+1);
     
     cout<<v.size()<<"\n";
     
     bool in=true;
     for(int i = 0 ; i < v.size() ; ++i){

          if(in)
               in = false;
          else
               cout<<" ";
          
          cout<<v[i];
          
     }
     
                    
               
}
