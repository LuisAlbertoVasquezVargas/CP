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

#define N 200005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int I[ N ];
ll k;
void impr( vi v ){
	int nv = v.size();
	REP( i , nv ) printf( "%d%c" , v[ i ] , i + 1 == nv ? 10 : 32 );
}
int main()
{
	while( cin >> n >> k )
	{
		vi A( n );
		if( k == 0 )
		{
			REP( i , n ) A[ i ] = i + 1;
			impr( A );
			continue;
		}
		int i = 0;
		while( 1 )
		{
			if( k == 0 ) break;
			if( k >= n ){
				A[ i++ ] = n;
				n--;
				k -= n;
			}else
			{
				//cout << "inv : " << k << endl;
				//cout << "fase 1 " << endl;
				//impr( A );
				int t = 1;
				REP( it , n ) A[ i++ ] = t++;
				//cout << "fase 2 " << endl;;
				//impr( A );
				i--;
				for( int it = i - 1 ; it >= i - k ; it-- ) swap( A[ it ] , A[ it + 1 ] );
				break;
			}
		}
		impr( A );
	}
}


