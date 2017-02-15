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

int m;
char s[ 15 ];
int memo[ 1005 ][ 25 ][ 2 ];
string T[] = { "0" , "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "10" };

bool dp( int pos , int delta , int last )
{
	if( pos == m )return 1;
	int &dev = memo[ pos ][ delta + 10 ][ last ];
	if( dev == -1 )
	{
		dev = 0;
		for( int i = 1 ; i <= 10 ; ++i )
			if( s[i] == '1' && i != last )
			{
				if( !(pos&1) && delta - i < 0 )
					dev |= dp( pos + 1 , delta - i , i );
				if( pos&1 && delta + i > 0 )
					dev |= dp( pos + 1 , delta + i , i );
			}
	}
	return dev;
}

string f( int pos , int delta , int last )
{
	if( pos == m )return "";
	for( int i = 1 ; i <= 10 ; ++i )
		if( s[i] == '1' && i != last )
		{
			if( !(pos&1) && delta - i < 0 )
			{
				if( dp( pos + 1 , delta - i , i ) )return T[i] + ((pos+1)==m?"":" ") + f( pos + 1 , delta - i , i );
			}
			if( (pos&1) && delta + i > 0 )
			{
				if( dp( pos + 1 , delta + i , i ) )return T[i] + ((pos+1)==m?"":" ") + f( pos + 1 , delta + i , i );
			}
		}
	return "";
}
int main()
{
	while( scanf( "%s%d" , s + 1  , &m ) == 2 )
	{
		clr( memo , -1 );
		bool ans = dp( 0 , 0 , 0 );
		if( ans )
		{
			puts( "YES" );
			printf( "%s\n" , f( 0 , 0 ,  0 ).c_str() );
		}
		else puts( "NO" );
	}
}


