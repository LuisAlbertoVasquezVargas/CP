#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>V(12);

int main()
{
     int k;
     cin>>k;
     
     for( int  i = 0 ; i < 12 ; ++i)
          cin>>V[i];
          
     sort(V.rbegin(),V.rend());
     
     int s = 0;
     int cont = 0;
     
     for( int  i = 0 ; i < 12 ; ++i)
          if( s < k )
               s+=V[i],cont++;
               
     if( s >= k )   cout<<cont;
     else cout<<"-1";                         
     
}
