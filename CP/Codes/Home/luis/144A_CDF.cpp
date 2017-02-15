#include<iostream>
#define MAXN 100
using namespace std;

int a[MAXN];

int main(){
     
     int n,maxi,mini,pmaxi,pmini;
     cin>>n;
     
     for( int  i = 0 ; i < n ; ++i){
          
          cin>>a[i];
          
          if( i == 0 ){
               
               maxi=mini=a[0];
               pmaxi=pmini=0;               
               
          } else{
          
               if( a[i] > maxi ){

                    maxi=a[i];
                    pmaxi=i;                         
                    
               }                         
               
               if( a[i] <= mini ){
                    
                    mini=a[i];
                    pmini=i;
                         
               }
          }    
     }          
     
     if( pmaxi <= pmini ){

          cout<<n-1-pmini+pmaxi;     
          
     }else{
 
          cout<<n-2-pmini+pmaxi;          
          
     }
     
}
