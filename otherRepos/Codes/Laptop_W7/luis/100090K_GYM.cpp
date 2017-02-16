#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

string doit( string &s )
{
    int ns = s.size() , cnt = 0;
    REP( i , ns )
    {
        if( s[ i ] == '(' ) cnt++;
        else cnt--;
        if( cnt < 0 ) return "IMPOSSIBLE";
    }
    return s + string( cnt , ')' );
}
int main()
{
    ios_base::sync_with_stdio( 0 );
    string s;
    while( cin >> s )
        cout << doit( s ) << '\n';
}
