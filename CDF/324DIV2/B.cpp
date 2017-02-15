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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define MOD 1000000007

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll pow( ll a , ll b , ll c ){
    ll ans = 1;	
    while( b ){
        if( b&1 ) ans = ( ans * a )%c;
        a = ( a*a )%c;
        b >>= 1;
    }	
    return ans;
}

int main(){
	int cnt = 0;
	for( int i = 1 ; i <= 3 ; ++i )
		for( int j = 1 ; j <= 3 ; ++j )
			for( int k = 1 ; k <= 3 ; ++k )
				if( i + j + k == 6 ) cnt ++;
	//cout << cnt << '\n';
	int n;
	while( sc( n ) == 1 ){
		cout << ( pow( 3 , 3 * n , MOD ) - pow( cnt , n , MOD ) + MOD ) %MOD << '\n';
	}
}
