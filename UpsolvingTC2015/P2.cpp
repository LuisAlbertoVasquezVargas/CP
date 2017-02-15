#include <bits/stdc++.h>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )
 
#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second
 
#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

ll MOD;
 
struct Matrix{
    ll M[ 2 ][ 2 ];
    Matrix(){
        M[ 0 ][ 0 ] = M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = 1 % MOD;
        M[ 1 ][ 1 ] = 0 % MOD;
    }
    Matrix( ll t ){
        M[ 0 ][ 0 ] = M[ 1 ][ 1 ] = 1 % MOD;
        M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = 0 % MOD;
    }
};
Matrix operator * ( const Matrix &a , const Matrix &b ){
    Matrix C;
    REP( i , 2 )REP( j , 2 ){
        ll dev = 0;
        REP( k , 2 ) dev = ( dev + a.M[ i ][ k ] * b.M[ k ][ j ] )%MOD;
        C.M[ i ][ j ] = dev;
    }
    return C;
}
Matrix pow( Matrix a , ll b ){
    Matrix ans( 1 );
    while( b ){
        if( b & 1 ) ans = ans * a;
        a = a * a;
        b >>= 1 ;
    }
    return ans;
}
ll pow( ll a , ll b , ll c ){
    ll ans = 1;
    while( b ){
        if( b&1 ) ans = ( ans * a )%c;
        a = ( a*a )%c;
        b >>= 1;
    }  
    return ans;
}
ll fib( ll n ){
    if( n == 2 ) return 3 % MOD;
    if( n == 3 ) return 5 % MOD;
    Matrix mat;
    mat = pow( mat , n - 3 );
    return (mat.M[ 0 ][ 0 ] * 5LL + mat.M[ 0 ][ 1 ] * 3LL )%MOD;
}
int solve( int n ){
    int cnt =0 ;
    REP( mask , (1<<n) ){
        vi vec( n );
        REP( i , n )
            if( mask & (1 << i) ) vec[ i ] = 1;
        int cur = 0;
        REP( i , n - 1 )
            cur = cur or (vec[ i ] and vec[ i + 1 ]);
        if( cur == 0 ) cnt++;
        
    }
    return cnt;
}
int main(){
    /*
    MOD = 12345678;
    for( int i = 2;  i <= 4 ; ++i ) cout << i << " " << fib( i ) << " "  << solve( i ) << endl;
    */
    ull n , K , L , m;
    while( cin >> n >> K >> L >> m ){
        if( m == 1 ){
            cout << '0' << '\n';
            continue;
        }
        bool fail = 0;
        for( int i = L ; i <= 62 ; ++i )
            if( K & (1LL << i) ) fail = 1;
        if( fail ){
            cout << '0' << '\n';
            continue;
        }
        MOD = m;
        ll a = fib( n ) , b = (pow( 2 , n , MOD) -  a + MOD)%MOD;
        ull ans = 1;
        for( int i = 0 ; i < L ; ++i )
            if( K & (1ULL << i) ) ans = (ans * b)%MOD;
            else ans = (ans * a)%MOD;
        cout << ans << '\n';
    }
}
