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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int f( int n , int k )
{
	vi R( n + 1 ) , L( n + 1 );
	REP( i , n + 1 ) R[ i ] = ( i + 1 )%( n + 1 ) , L[ i ] = ( i - 1 + n + 1 )%( n + 1 );
	R[ n ] = 2 , L[ 2 ] = n;
	int i = 1;
	REP( x , n - 1 )
	{
		REP( y , k ) i = R[ i ];
		int j = L[ i ] , k = R[ i ];
		L[ k ] = j , R[ j ] = k;
	}
	//cout << i << endl;
	return i;
}
int main()
{
	int n;
	while( sc( n ) == 1 && n )
	{
		REP( i , N ) 
			if( f( n , i + 1 ) == 2 ) 
			{
				cout << i + 1 << endl;
				break;
			}
	}
}


