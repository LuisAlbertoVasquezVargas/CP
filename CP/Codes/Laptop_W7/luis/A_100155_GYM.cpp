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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int C , V ;
int A[N][N];

int main()
{
	while( scanf( "%d%d" , &C , &V ) == 2 )
	{
		REP( i , V )REP( j , C )sc( A[i][j] ),A[i][j]--;
		if( C == 1 )
		{
			cout << 1 << " " << 1 << endl;
			continue;
		}
		vi F( C );
		REP( i , V )F[A[i][0]]++;
		vector< pii >P(C);
		REP( i , C )P[i] = mp( F[i] , i );
		sort( all(P) );
		int L = P[C-1].se , R = P[C-2].se;
		if( 2*P.back().fi > V )
			cout << L + 1 << " 1" << endl;
		else
		{
			F = vi( C , 0 );
			REP( i , V )REP( j , C )
				if( A[i][j] == L || A[i][j] == R )
				{
					F[A[i][j]]++;
					break;
				}
			int ans = max_element( all(F) ) - F.begin();
			cout << ans + 1 << " 2\n"; 
		}
	}
}


