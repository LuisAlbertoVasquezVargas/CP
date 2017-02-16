#include<iostream>
#include<cstdio>
 
using namespace std;
 
int n , m;
 
int main()
{
    while( scanf( "%d" , &n ) == 1 )
    {
        if( !n )break;
        if( n < 4 || n % 2 == 1 )puts("Impossible");
        else
        {
            cout << n + n/2 << endl;
            for( int i = 0 ; i < n ; ++i )
                cout << i + 1 << " " << (i+1)%n + 1 << endl;
            for( int i = 0 ; i < n/2 ; ++i )
                cout << i + 1 << " " << i + n/2 + 1<< endl;
        }
    }
}
 
