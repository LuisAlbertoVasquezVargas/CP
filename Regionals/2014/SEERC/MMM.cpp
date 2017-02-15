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

#define N 10000
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int n ;
int v[ N + 2  ] ;
int memo[ N + 2 ] ;
bool used[ N + 2  ] ;

bool positivos(){
	REP( i , n ) if( v[ i ] < 0 ) return 0 ;
	return 1 ;
}

int dp( int pos ){
//	cout << "el min es : "<< min_element( v , v + n ) << endl ;
	if( positivos() ) return 0 ;
	if( used[ pos ] ) return memo[ pos ] ;
	used[ pos ] = 1 ;
	int &ans = memo[ pos ] = 0 ;
	if( v[ pos ] < 0 ){
		v[ pos ] = abs( v[ pos ] ) ;
		v[ ( pos - 1 )%n ] = v[ ( pos - 1 )%n ] - v[ pos ] ;
		v[ ( pos + 1 )%n ] = v[ ( pos + 1 )%n ] - v[ pos ] ;
		ans = 1 + dp( ( pos - 1 )%n ) ;
	}else{
		ans = dp( ( pos + 1 )%n ) ;
	}
	
	return ans ;
}


int main(){
	
	cin >> n ;
//	REP( i , N + 2 ) v[ i ] = 999 ;
	REP( i  , n ) cin >> v[ i ] ;
	
	cout << dp( 0 ) << '\n' ;
	
	return 0;
}

