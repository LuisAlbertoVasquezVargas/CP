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
int s( int x )
{
	int sum = 0;
	while( x )
		sum += x%10 , x/= 10;
	return sum;
}
bool f( int x )
{
	int sx = s( x );
	vi v;
	for( int i = 2 ; i*i <= x ; ++i )
	{
		while( x%i == 0 )
		{
			x/= i;
			v.pb( i );			
		}
	}
	if( x > 1 ) v.pb( x );
	int st = 0;
	int nv = v.size();
	REP( i , nv ) st += s( v[ i ] );
	return nv > 1 && sx == st;
}
int main()
{
	int n;
	while( sc( n ) == 1 && n )
	{
		n++;
		while( 1 )
		{
			if( f( n ) )
			{
				printf( "%d\n" , n );
				break;
			}
			n++;
		}
	}
}


