#include<bits/stdc++.h>
#include<unordered_map>
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

#define N 20
#define MOD 99991

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

void fix( string &s ){
	for( auto &x : s ) x -= 'a';
}
void defix( string &s ){
	for( auto &x : s ) x += 'a';
}
vi Fill( string &s ){
	vi F( 26 );
	for( auto x : s ) F[ x ] ++;
	return F;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	vector< string > S( 3 );
	while( cin >> S[ 0 ] ){
		REP( i , 3 ){
			if( !i ) continue;
			cin >> S[ i ];
		}
		REP( i , 3 ) fix( S[ i ] );
		vvi F( 3 );
		REP( i , 3 ) F[ i ] = Fill( S[ i ] );
		int best = -1 , inda = -1 , indb = -1;
		for( ll len = 0 ; len <= SZ( S[ 0 ] ) ; ++len ){
			bool ok1 = 1;
			vi freq( 26 );
			ll len2 = LLONG_MAX;
			REP( i , 26 )
				if( (ll)F[ 1 ][ i ] * len <= F[ 0 ][ i ] ){
					freq[ i ] = F[ 0 ][ i ] - (F[ 1 ][ i ] * len);
					if( F[ 2 ][ i ] ) len2 = min( len2 , (ll) freq[ i ] / F[ 2 ][ i ] );
				}else ok1 = 0;
			if( !ok1 ) break;
			if( best < len + len2 ){
				best = len + len2;
				inda = len;
				indb = len2;
			}
		}
		REP( i , 3 ) defix( S[ i ] );
		REP( i , 26 ) F[ 0 ][ i ] -= F[ 1 ][ i ] * inda;
		REP( i , 26 ) F[ 0 ][ i ] -= F[ 2 ][ i ] * indb;
		REP( i , inda ) cout << S[ 1 ];
		REP( i , indb ) cout << S[ 2 ];
		REP( i , 26 ) REP( j , F[ 0 ][ i ] ) cout << char( 'a' + i );
		cout << '\n';
	}
}


