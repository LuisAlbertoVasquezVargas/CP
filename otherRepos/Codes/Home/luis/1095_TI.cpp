#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
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

int main()
{
	sync
	string s;
	int cases;
	cin >> cases;
	while( cases-- )
	{
		cin >> s;
		int n = s.size();
		string cad = "1234";
		vi pos( 4 , -1 );
		REP( i , 4 ) pos[ i ] = s.find( cad[ i ] ) , swap( s[ i ] , s[ pos[ i ] ] );
		string t = s.substr( 4 );
		int pot = 1 , u = 0 ;
		for( int i = 4 ; i < n ; ++i ) u = ( u * 10 + s[ i ] - '0' )%7 , pot = ( pot * 10 )%7;
		do
		{
			int r = 0;
			REP( j , 4 ) r = ( r * 10 + cad[ j ] - '0' );
			if( ( r*pot + u )%7 == 0 )
			{
				cout << cad << t << '\n';
				break;
			}
		}while( next_permutation( all( cad ) ) );
	}
}

