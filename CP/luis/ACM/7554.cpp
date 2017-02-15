#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr( t , val ) memset( t , val , sizeof(t) )

#define mp make_pair
#define fi first
#define se second

#define pb push_back

#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

const int N = 20000;
int get( string s , map< string , int > &mapa , int &n ){
	if( mapa.count(s) ) return mapa[ s ];
	return mapa[ s ] = n ++;
}
vi G[ N + 5 ];
int ones[ N + 5 ] , zeroes[ N + 5 ];
bool used[ N + 5 ][ 3 ];
int memo[ N + 5 ][ 3 ];
vvi Cost = {
	{0 , 1},
	{1 , 0},
};
vvi Y = {
	{1 , 0},
	{1 , 0}
};
vvi X = {
	{0 , 1},
	{0 , 1}
};

int dp( int u , int x ){
	if( used[ u ][ x ] ) return memo[ u ][ x ];
	used[ u ][ x ] = 1;
	
	int &dev = memo[ u ][ x ] = 1e5;
	REP( y , 2 ){
		int sum = 0;
		for( auto v : G[ u ] ) sum += dp( v , y );
		int cur = Cost[ x ][ y ] + sum + Y[ x ][ y ] * ones[ u ] + X[ x ][ y ] * zeroes[ u ];
		dev = min( dev , cur );
	}
	return dev;
}
set< int > SET[ N + 5 ];
int main(){
	ios_base :: sync_with_stdio(0);
	int cases;
	cin >> cases;
	REP(tc , cases){
		int paths;
		cin >> paths;
		
		map< string , int > mapa;
		clr( ones , 0 );
		clr( zeroes , 0 );
		REP( u , N ) G[ u ].clear() , SET[ u ].clear();
		
		int n = 0;
		get( "/" , mapa , n );
		
		REP(k , paths){
			string cond;
			cin >> cond;
			string path;
			cin >> path;
			REP(i , SZ(path))
				if( path[ i ] == '/' ) path[ i ] = ' ';
			istringstream in(path);
			string cur;
			vector< string > vec(1 , "");
			while( in >> cur ) vec.push_back( cur );
			int u , v;
			//REP( i , SZ(vec) ) cout << vec[ i ] << " ";
			//cout << endl;
			REP( i , SZ(vec) - 2 ){
				string a , b;
				for( int k = 0 ; k <= i ; ++k ) a += vec[ k ] + "/";
				for( int k = 0 ; k <= i + 1 ; ++k ) b += vec[ k ] + "/";
				//cout << a << endl;
				//cout << b << endl;
				u = get( a , mapa , n );
				v = get( b , mapa , n );
				if(!SET[ u ].count( v ) ){
					SET[ u ].insert( v );
					G[ u ].pb( v );
					//cout << u << "---" << v << endl;
				}
			}
			//cout << v << endl;
			if( cond == "unstage" ) zeroes[ v ] ++;
			else ones[ v ] ++;
		}
		//REP( u , n ) cout << u << " " << zeroes[ u ] << " " << ones[ u ] << endl;
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , 0 ) );
	}
}



