#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;
/*
int done[ N ];
int memo[ N ];
int dp( int n ){
    if( n == 0 ) return 0;
    int &dev = memo[ n ];
    if( !done[ n ] ){
        done[ n ] = 1;
        dev = 0;
        set< int > S;
        for( int i = 1 ; i * i <= n ; ++i ) S.insert( dp( n - i ) );
        while( S.count( dev ) )dev++;
    }
    return dev;
}
int main()
{
    vi v;
    REP( i ,  100000 ) if( !dp( i ) ) cout << i << " " , v.pb( i );
    cout << endl;
    int nv = v.size();
    REP( i , nv - 1 ) cout << v[ i + 1 ] - v[ i ] << " ";
    cout << "total : " << nv << endl;
}
*/

int main(){
    /*ll p = 0;
    for( ll t = 2 ; p <= 1000000000000LL ;  )
    {
        if( ones( t ) == 1 ) {
            p += t;
            cout << p << " " ;
            t++;
        }
        else  {
            p += t;
            cout << p << " " ;
            p += t;
            cout << p << " " ;
            t++;
        }
    }*/
    //nim.in
    //nim.out
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    ll n;
    cin >> n;
    ll p = 0;
    for( ll t = 2 ; p <= n ;  )
    {
        if( ones( t ) == 1 ) {
            p += t;
            
            if( p == n ){
                puts( "LOSE" );
                return 0;
            }
            t++;
        }
        else  {
            p += t;
            if( p == n ){
                puts( "LOSE" );
                return 0;
            }
            p += t;
            if( p == n ){
                puts( "LOSE" );
                return 0;
            }
            t++;
        }
    }
    puts( "WIN" );
}
