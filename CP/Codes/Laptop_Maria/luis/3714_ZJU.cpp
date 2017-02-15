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

#define N 205
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int tc , n , m ;
int A[ N ];

int main()
{
	sc( tc );
	while( tc -- )
	{
		sc( n ) , sc( m );
		REP( i , n ) sc( A[i] );
		int sum = 0, maxi = 0;
		REP( i , m )
			sum += A[i];
		maxi = sum;
		REP( i , n )
		{
			sum += A[(i+m)%n] - A[i%n];
			maxi = max( maxi , sum );
		}
		printf( "%d\n" , maxi );
	}
}

