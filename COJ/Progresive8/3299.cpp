#include<bits/stdc++.h>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cerr << #x << " " << x << endl;

typedef long long ll;
typedef pair< ll , ll > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvi > vvvi;



int main(){
	vll vec;
	for( ll i = 1 ; ; ++i ){
		if( i * (i + 1) > 1e13 ) break;
		vec.pb( (i * (i + 1LL)) >> 1 );
	}
	ll lo , hi;
	while( cin >> lo >> hi ){
		if( !lo && !hi ) break;
		int ans = upper_bound( all( vec ) , hi ) - lower_bound( all( vec ) , lo );
		printf( "%d\n" , ans );
	}
}


