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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int ns , nt;
char s[N] , t[N];

int main()
{
	while( scanf( "%s%s" , s , t ) == 2 )
	{
		ns = strlen( s ) , nt = strlen( t );
		vvi T( ns + 1 , vi(27,0) ),R( nt + 1 , vi(27 ,0) );
		REP( i , ns )
			REP( j , 27 )
				T[i+1][j] = T[i][j] + (('a'+j)==s[i]);
		REP( i , nt )
			REP( j , 27 )
				R[i+1][j] = R[i][j] + (('a'+j)==t[i]);
		bool ok = 0;
		for( int i = 0 ; i + nt <= ns ; ++i )
		{
			bool solve = 1;
			REP( j , 27 )
			{
				if( !R[nt][j] )continue;
				if( R[nt][j] != T[i+nt][j] - T[i][j] )solve = 0;
			}
			if( solve )ok = 1;
		} 
		puts( (ok?"YES":"NO") );
	}
}


