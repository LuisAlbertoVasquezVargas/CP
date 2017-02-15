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


int main(){
	/*
	cout << (int)string("0011").find( "00" , 1 ) << endl;
	cout << string :: npos << endl;
	*/
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string s;
		cin >> s;
		int a = 0 , b = 0;
		bool win = 0;
		REP( i , SZ( s ) ){
			int x = s[ i ];
			if( x == '0' ) a ++;
			else b ++;
			if( a == 10 && b == 10 ){
				int posa = (int)s.find( "00" , i + 1 );
				int posb = (int)s.find( "11" , i + 1 );
				if( posa == -1 ) win = 1;
				if( posb == -1 ) win = 0;
				if( posa != -1 && posb != -1 ){
					if( posa < posb ) win = 0;
					else win = 1;
				}
				break;
			}
			if( a == 11 ){	
				win = 0;
				break;
			}
			if( b == 11 ){
				win = 1;
				break;
			}
		}
		cout << (win ? "WIN" : "LOSE" ) << '\n';
	}
}


