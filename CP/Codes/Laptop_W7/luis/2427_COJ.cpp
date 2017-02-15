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

#define N 1000005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int a ,b ;

int main()
{
	vi P( N , 1 );
	for( int i = 2 ; i*i < N ; ++i )
		if( P[i] )
			for( int j = 2*i ; j < N ; j+=i )
				P[j] = 0;
	P[0] = P[1] = 0;
	vi T( N , 0 );
	for( int i = 1 ; i < N ; ++i )
		T[i] = T[i-1] + P[i];
	while( scanf( "%d%d" , &a , &b ) == 2 )
	{
		if( !a )break;
		cout << T[b] - T[a-1] << endl;
	}
}


