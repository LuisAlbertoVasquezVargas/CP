#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cout << #x << " " << (x) << endl;
#define N 100000

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int main(){
	int n = 5000 , R = 10000000;
	REP( i , n ) cout << (rand() % 10000000 + 1) << ',';
	cout << endl;
	cout << R << endl;
}
