#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define all( v ) v.begin() , v.end()
#define pb push_back

#define N 1005

typedef long long ll;
typedef vector< ll > vll;
ll n , k;
vll target;
vll base( ll num , ll b )
{
    vll ans;
    while( num )
    {
        ans.pb( num % b );
        num /= b;
    }
    reverse( all( ans ) );
    return ans;
}
ll memo[ N ][ 2 ];
ll dp( int pos , int menor )
{
    if( pos == n ) return 1;
    ll &dev = memo[ pos ][ menor ];
    if( dev == -1 )
    {
        if( ( n - pos )%2 == 0 ) 
            if( !menor )
                dev = dp( pos + 1 , target[ pos ] != 0 );
            else dev = dp( pos + 1 , 1 );
        else
        {
            if( menor ) dev = k*dp( pos + 1 , menor );
            else dev = dp( pos + 1 , 0 ) + target[ pos ]*dp( pos + 1 , 1 );
        }
    }
    return dev; 
}
void impr( vll v ){
    int nv = v.size();
    REP( i , nv ) cout << v[ i ] << char( i + 1 == nv ? 10 : 32 ); 
    cout << endl;
}
int main()
{
    freopen("great.in", "r", stdin);
    freopen("great.out", "w", stdout);
    ll num;
    while( cin >> num >> k )
    {   
        target = base( num , k );
        //cout << target << endl;
        //impr( target );
        clr( memo , -1 );
        n = target.size();
        cout << dp( 0 , 0 ) << '\n';
    }
}
