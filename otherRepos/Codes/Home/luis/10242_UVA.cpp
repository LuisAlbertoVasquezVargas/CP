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

pair< double , double >P[4];

int main()
{
	while( scanf( "%lf%lf" , &P[0].fi , &P[0].se ) == 2 )
	{
		for( int i = 1 ; i < 4 ; ++i )
			scanf( "%lf%lf" , &P[i].fi , &P[i].se );
		int ind;
		for( int i = 0 ; i < 2 ; ++i )
			for( int j = 0 ; j < 2 ; ++j )
				if( P[i] == P[2+j] )ind = i;
		double x = 0 , y = 0;
		REP( i , 4 ) x+= P[i].fi , y += P[i].se;
		x -= 3*P[ind].fi , y-= 3*P[ind].se;
		printf( "%.3lf %.3lf\n" , x , y );
	}
}



