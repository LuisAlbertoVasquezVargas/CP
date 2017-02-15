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

#define N 200000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

string A , B;

bool solve( int la , int ra , int lb , int rb ){
	int n = ra - la + 1;
	if( n & 1 ){
		REP( i , n )
			if( A[ la + i ] != B[ lb + i ] ) return 0;
		return 1;
	}
	int meda = (la + ra) >> 1;
	int medb = (lb + rb) >> 1;
	return ( solve( la , meda , lb , medb ) && solve( meda + 1 , ra , medb + 1 , rb ) ) ||
		   ( solve( la , meda , medb + 1 , rb ) && solve( meda + 1 , ra , lb , medb ) ) ;
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	while( cin >> A >> B ){
		int n = SZ(A);
		cout << (solve( 0 , n - 1 , 0 , n - 1 ) ? "YES" : "NO" ) << '\n';
	}	
}


