#include<iostream>

using namespace std;
long long a,b;
long long mask( long long n)
{
     long long pot = 1,num = 0;
     while( n > 0 )
     {
          long long r = n%10;
          if( r == 7 || r == 4 )
          {
               num = r*pot + num;
               pot*=10;
          }
          n/=10;
     }
     return num;
}
int main()
{
     while( cin >> a >> b )
     {
          if( a < b )
          {
               cout<<b<<endl;
               continue;     
          }
          long long i;
          for( i = a + 1 ;mask(i)!=b ;i++);
          cout<<i<<endl;
     }
}
