#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int a[500];

int main()
{
     int t;
     cin>>t;
     
     for( int  i = 0 ; i <  t ; ++i )
     {
          int n;
          cin>>n;
          
          for(int j = 0 ; j < n ; ++j)     
               cin>>a[j];
          sort(a,a+n);               
          int med;
          if( n%2 == 0)
               med = (a[n/2-1]+a[n/2])/2;     
          else               
               med = a[n/2]; 

          int sum  = 0 ;

          for( int j = 0 ; j < n ; ++j)
               sum +=abs(a[j] - med);                         
          
          cout<<sum<<endl;               
     }     
}
