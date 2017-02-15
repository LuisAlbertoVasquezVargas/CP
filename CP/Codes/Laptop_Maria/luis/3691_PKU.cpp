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

#define N 55
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)
#define MAX_NOD 1005

using namespace std;

string ADN = "AGCT";
map< char , int >M;
 
int n , ns ;
char T[ N ][ 25 ];
char S[ 1005 ];
int next[ MAX_NOD ][ 10 ] , term[ MAX_NOD ] , NODE ;
int memo[ MAX_NOD ][ 1005 ];

int dp( int node , int pos )
{
	cout << node << " " << pos << endl;
	if( pos == ns ) return 0;
	int &dev = memo[ node ][ pos ];
	if( dev == -1 )
	{
		dev = INF;
		REP( k , 4 )
		{
			int sig = next[ node ][ k ];
			if( sig == -1 )
				dev = min( dev , (ADN[k]!=S[pos]) + dp( 0 , pos + 1 ) );
			else if( !term[sig] )
				dev = min( dev , (ADN[k]!=S[pos]) + dp( sig , pos + 1 ) );
		}
	}
	return dev;
}
void init()
{
	NODE = 1;
	me( next , -1 );
	me( term , 0 );
}

void add( int ind )
{
	int sz = strlen( T[ind] ) , ac = 0;
	REP( i , sz )
	{ 
		int j = M[T[ind][i]];
		
		if( next[ac][ j ] == -1 )next[ac][ j ] = NODE++;
		ac = next[ac][ j ];
		//cout << j << " " << ac << " " << NODE << endl;
	}
	//cout << endl;
	cout << "term: " << ac << endl; 
	term[ac] = 1;
}
void build()
{
	init();
	REP( i , n )add( i );
	REP( i , 6 )REP( j , 6 ) cout << setw( 2 ) <<next[i][j] << (j==5?"\n":" ");
}
int main()
{
	REP( i , 4 )M[ADN[i]] = i;
	while( scanf( "%d" , &n ) == 1 && n )
	{
		REP( i , n )scanf( "%s" , T[i] );
		scanf( "%s" , S );
		ns = strlen( S );
		me( memo , -1 );
		build();
		printf( "ans: %d\n" , dp( 0 , 0 ) );
	}
}

