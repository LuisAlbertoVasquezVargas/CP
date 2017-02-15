#include<iostream>
#include<algorithm>

using namespace std;

int a[50];

int main()
{
     int n,k,p,t;     
     cin>>n>>k;
     
     for( int i = 0 ; i < n ; ++i)
     {
          cin>>p>>t;          
          a[i]=p*100-t;
     }
     
     sort(a,a+n);
     reverse(a,a+n);
     int e=a[k-1],cont=0;
     
     for( int i = 0 ; i < n ; ++i)
          if(a[i]==e)
               cont++;
     
     cout<<cont;
}
