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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int Used[ N ][ N ][ N ];
int Wtile[ N ] , Htile[ N ];
string roomid[ N ];
int tileidused[ N ];
int Wroom[ N ] , Hroom[ N ];

vector< pii > V[ N ];
int ans[ N ] , vis[ N ];
int t , ct;
void busqueda( int W , int H , int X , int Y , int id )
{
	bool search = 0;
	if( Used[ H ][ W ][ id ] )
	{
		Used[ H ][ W ][ id ]--;
		return;
	}
	for( int i = H ; i <= Y ; ++i )
		for( int j = W ; j <= X ; ++j )
			if( Used[ i ][ j ][ id ] )
			{
				if( i == H && j == W ) continue;
				if( i == H )
				{
					Used[ i ][ j ][ id ]--;
					Used[ i ][ j - W ][ id ]++;
			 		search = 1;
			 		break;
			 	}
			 	if( j == W )
			 	{
					Used[ i ][ j ][ id ]--;
					Used[ i - H ][ j ][ id ]++; 
					search = 1;
			 		break;
				}
				Used[ i ][ j ][ id ]--;
				Used[ i - H ][ j ][ id ]++;
				Used[ H ][ j - W ][ id ]++;
				search = 1;
			 	break;
			}
	if( search == 0 )
	{
		if( X == W )
			Used[ Y - H ][ W ][ id ]++;
	 	else if( Y == H )
			Used[ Y ][ X - W ][ id ]++; 
		else Used[ Y - H ][ X ][ id ]++ , Used[ H ][ X - W ][ id ]++;
		ct++;
	}
}
void solve( int id )
{
	cout << roomid[ id ] << endl;
	int n = Hroom[ id ] , m = Wroom[ id ];
	int x = Htile[ tileidused[ id ] ] , y = Wtile[ tileidused[ id ] ];

	clr( Used , 0 );
	vector< string > S( n , string( m , '+' ) );
	t = 1 , ct = 0;
	for( int i = 0 ; i < n ; i += x )
	{
		int tt = t;
		for( int j = 0 ; j < m ; j += y )
		{
			if( i + x <= n && j + y <= m )
			{
				for( int I = i ; I < i + x ; I++ )
					for( int J = j ; J < j + y ; ++J )
						S[ I ][ J ] = ( t ? 'X' : 'O' );
				ct++;
			}
			else
			{
				if( !(j + y <= m ) && i + x <= n )
				{
					for( int I = i ; I < i + x ; I++ )
						for( int J = j ; J < m ; ++J )
							S[ I ][ J ] = ( t ? 'X' : 'O' , tileidused[ id ] );
					busqueda( x , ( m - j ) , x , y , tileidused[ id ] );
				}
				else if( j + y <= m && !( i + x <= n ) )
				{
					for( int I = i ; I < n ; I++ )
						for( int J = j ; J < j + y ; ++J )
							S[ I ][ J ] = ( t ? 'X' : 'O' , tileidused[ id ] );
					busqueda( n - i , y , x , y , tileidused[ id ] );

				}
				else if( !(j + y <= m ) && !( i + x <= n ) )
				{
					for( int I = i ; I < n ; I++ )
						for( int J = j ; J < m ; ++J )
							S[ I ][ J ] = ( t ? 'X' : 'O' , tileidused[ id ] );
					busqueda( n - i , m - j , x , y , tileidused[ id ] );

				}
			}
			t ^= 1;
		}
		t = tt^1;
	}
	vis[ tileidused[ id ] ] = 1;
	ans[ tileidused[ id ] ] += ct;
	REP( i , n ) cout << S[ i ] << "|\n"; 
	for( int i = 1 ; i < N ; ++i )
		for( int j = 1 ; j < N ; ++j )
			if( Used[ i ][ j ][ tileidused[ id ] ] ) V[ tileidused[ id ] ].pb( mp( i , j ) );
	sort( all( V[ tileidused[ id ] ] ) );
	reverse( all( V[ tileidused[ id ] ] ) );
}
void print( int id )
{
	cout << id << endl;
	cout << ans[ id ] << endl;
	if( V[ id ].empty() ) cout << "-\n" ;
	else
	{
		int nv = V[ id ].size();
		REP( i , nv )
			cout << V[ id ][ i ].fi << " " << V[ id ][ i ].se << "\n";
	}
}
int main()
{
	int ntiles , nrooms;
	cin >> ntiles >> nrooms;
	REP( i , ntiles )
	{
		int tileid;
		cin >> tileid ; cin >> Wtile[ tileid ] >> Htile[ tileid ];
	}
	REP( i , nrooms )
		cin >> roomid[ i ] >> tileidused[ i ] >> Wroom[ i ] >> Hroom[ i ];
	REP( i , nrooms )
		solve( i );
	REP( i , N )
		if( vis[ i ] )print( i );
}


