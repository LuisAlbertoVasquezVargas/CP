#include<iostream>
 
using namespace std;
 
int tc , n , m , k ;
 
int main()
{
    cin >> tc;
    while( tc-- )
    {
        cin >> n >> m >> k;
        if( n*m <= 2 ) cout << 0 << endl;
        else if( n == 1 || m == 1 ) cout << k << endl;
        else cout << (k-1)/2 + 1 << endl;
    }
} 
