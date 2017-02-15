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

#define N 100
#define M 200
#define MOD 199

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool valid1( string s ){
	REP( i , SZ(s) ){
		if( s[ i ] == ' ' ) continue;
		if( isdigit( s[ i ] ) ) continue;
		return 0;
	}
	return 1;
}
int tos( string s ){
	istringstream in( s );
	int x;
	in >> x;
	return x;
}
bool validAsNum( string t , int &val ){
	if( t == "0" ){
		val = 0;
		return 1;
	}
	if( t[ 0 ] == '0' ) return 0;//validing no trailing zeros , no dicen :P
	if( SZ( t ) >= 3 ) return 0;
	val = tos( t );
	return 1;
}
vi validKeys( string s ){
	istringstream in( s );
	string t;
	vi v;
	while( in >> t ){
		int val;
		if( validAsNum( t , val ) ){
			v.pb( val );
		}else{
			return vi();
		}
	}
	return v;
}
void impr( vi &a ){
	REP( i , SZ( a ) ) cout << a[ i ] << " "; cout << endl;
}
int INF = INT_MAX/2;
int INV[ MOD + 5 ];
int n;
vi A;
bool used[ N + 1 ][ N + 1 ][ M + 1 ];
int memo[ N + 1 ][ N + 1 ][ M + 1 ];
int dp( int lo , int hi , int mod ){
	if( lo == hi ) return ((A[ lo ] == mod) ? 0 : -INF);
	if( used[ lo ][ hi ][ mod ] ) return memo[ lo ][ hi ][ mod ];
	used[ lo ][ hi ][ mod ] = 1;
	
	int &dev = memo[ lo ][ hi ][ mod ] = -INF;
	for( int k = lo ; k < hi ; ++k )
		REP( mod2 , MOD ){
			int mod3 = (mod * INV[ mod2 ])%MOD;
			dev = max( dev , mod2 * mod3 + dp( lo , k , mod2 ) + dp( k + 1 , hi , mod3 ) );
		}
	return dev;
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
ll mod_inv( ll numa , ll mod ){	return pow( numa , mod - 2 , mod );	}


int main(){
	REP( i , MOD ) INV[ i ] = mod_inv( i , MOD );
	string s , t;
	while( getline( cin , s ) ){
		getline( cin , t );
		if( !valid1( s ) || !valid1( t ) ){
			cout << "INVALID INPUT\n";
			continue;
		}
		vi a = validKeys( s ) , b = validKeys( t );
		//impr( a );
		//impr( b );
		if( a == vi() || b == vi() ){
			cout << "INVALID INPUT\n";
			continue;
		}
		if( SZ( a ) != 1 ){
			cout << "INVALID INPUT\n";
			continue;
		}
		n = a[ 0 ];
		if( SZ( b ) != n ){
			cout << "INVALID INPUT\n";
			continue;
		}
		if( !(1 < n && n < 1000) ){
			cout << "INVALID INPUT\n";
			continue;
		}
		bool ok = 1;
		REP( i , n ){
			if( !(0 < b[ i ] && b[ i ] < 199) ){
				ok = 0;
				break;
			}
		}
		if( !ok ){
			cout << "INVALID INPUT\n";
			continue;
		}
		assert( n <= N );
		A = b;
		clr( used , 0 );
		int ans = INT_MIN;
		REP( i , MOD ) 
			if( i ) ans = max( ans , dp( 0 , n - 1 , i ) );
		cout << ans << '\n';
	}
}




