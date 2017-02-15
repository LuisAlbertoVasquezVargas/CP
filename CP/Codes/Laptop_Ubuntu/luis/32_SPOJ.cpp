#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 1000005

using namespace std;

// Prints the zero based index of
//  the start of each match of the string s( pattern ) in Text.
//  Matches may overlap
int* getBoard( char *s , int n ){
	int* T = new int[ n + 1 ];
	T[ 1 ] = 0;
	for( int v = 2 , p = 0 ; v <= n ; ++v )
	{
		while( p && ( s[ v - 1 ] != s[ p ] ) )
			p = T[ p ];
		if( s[ v - 1 ] == s[ p ] ) p++;
		T[ v ] = p;
	}
	return T;
}
void match( char* Text , int nT , char *s , int n , int *T )
{
	for( int i = 0 , j = 0 ; i < nT ; ++i )
	{
		while( j && Text[ i ] != s[ j ] ) j = T[ j ];
		if( Text[ i ] == s[ j ] )j++;
		if( j == n )printf( "%d\n" , i + 1 - j );
	}
}
int main()
{
	sync
	char s[ N ] , Text[ N ];
	int n;
	bool ok = 0;
	while( cin >> n >> s >> Text )
	{
		if( !ok ) ok = 1;
		else puts("");
		int nT = strlen( Text );
		match( Text , nT , s , n , getBoard( s , n ) );
	}
}


