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

vi B;

int main()
{
	sync
	string P , T;
	int nP;
	bool ok = 0;
	while( cin >> nP >> P >> T )
	{
		if( !ok ) ok = 1;
		else puts("");
		B = vi( nP + 1 , -1 );
		for( int i = 0 , j = -1 ; i < nP ; ++i )
		{
			while( j != -1 && P[i] != P[j] ) j = B[j];
			j++;
			B[ i + 1 ] = j;
		}
		int nT = T.size();
		for( int i = 0 , j = 0 ; i < nT ; ++i )
		{
			while( j != -1 && T[i] != P[j] )j = B[j];
			j++;
			if( j == nP )printf( "%d\n" , i + 1 - j );
		}
	}
}


