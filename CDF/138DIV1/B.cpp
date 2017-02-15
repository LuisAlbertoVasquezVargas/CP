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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

bool f( string &s , string &t ){
	deque< int > Q( all( t ) );
	for( auto x : s ){
		if( x == Q.front() ) Q.pop_front();
	}
	return !SZ(Q);
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s , t;
	while( cin >> s >> t ){
		set< char > A( all( s ) ) , B( all( t ) );
		if( A != B ){
			cout << "No\n";
			continue;
		}
		string rs = s , rt = t;
		reverse( all( rs ) );
		reverse( all( rt ) );
		if( f( s , t ) && f( rs , rt ) ){
			cout << "Yes\n"; 
		}else{
			cout << "No\n";
		}
	}
}
