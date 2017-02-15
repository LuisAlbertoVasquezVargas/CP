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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

string S[ N ] , t ;
bool solve( int n , int m , int L , int x , int y )
{
	if( (x - L) < 0 ) return 0;
	if( (x - L) >= n ) return 0;
	if( (x + L) < 0 ) return 0;
	if( (x + L) >= n ) return 0;
	if( (y - L) < 0 ) return 0;
	if( (y - L) >= m ) return 0;
	if( (y + L) < 0 ) return 0;
	if( (y + L) >= m ) return 0;
	for( int i = x - L ; i <= x + L ; ++i )
		if( S[ i ][ y - L ] != S[ x ][ y ] ) return 0;
	for( int i = x - L ; i <= x + L ; ++i )
		if( S[ i ][ y + L ] != S[ x ][ y ] ) return 0;
	for( int j = y - L ; j <= y + L ; ++j )
		if( S[ x - L ][ j ] != S[ x ][ y ] ) return 0;
	for( int j = y - L ; j <= y + L ; ++j )
		if( S[ x + L ][ j ] != S[ x ][ y ] ) return 0;
	return 1;
}
int main()
{
	int tc , n , m ,Q;
	cin >> tc ;
	while( tc-- )
	{
		cin >> n >> m >> Q;
		cout << n << " " << m << " " << Q << endl;
		getline( cin , t );
		REP( i , n ) getline( cin , S[ i ] );
		while( Q-- )
		{
			int x , y;
			cin >> x >> y;
			int maxi = 0 ;
			for( int L = 0 ; ; L ++ )
				if( solve( n , m , L , x , y ) ) maxi = 2*L + 1 ;
				else break;
			cout << maxi << endl;
		}
	}
}


