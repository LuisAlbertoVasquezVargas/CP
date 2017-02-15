#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
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

int L , R , C ;
pair< pii , int >I , F;
int dx[] = { 0 , 0 , -1, 1 , 0 , 0 };
int dy[] = { -1 , 1 , 0 , 0 , 0 , 0 };
int dz[] = { 0 , 0 , 0, 0 , -1 , 1 };
bool in( int x , int n )
{
	return x >= 0 && x < n ;	
}
int main()
{
	while( cin >> L >> R >> C )
	{
		if( L == 0 )break;
		vector< vector< string > >S( L , vector< string >( R ) );
		for( int i = 0 ; i < L ; ++i )
			for( int j = 0 ; j < R ; ++j )
				cin >> S[i][j];
		for( int i = 0 ; i < L ; ++i )
			for( int j = 0 ; j < R ; ++j )
				for( int k = 0 ; k < C ; ++k )
					if( S[i][j][k] == 'S' ) I = mp( mp( i , j ) , k );
					else if( S[i][j][k] == 'E') F = mp( mp( i , j ) , k );
		queue< pair< pii , int > >Q;
		int dist[L][R][C], ans ;
		bool solve = 0;
		me( dist , -1 );
		dist[I.fi.fi][I.fi.se][I.se] = 0;
		Q.push( I );
		while( !Q.empty() )
		{
			pair< pii , int >node = Q.front();
			Q.pop();
			int x = node.fi.fi , y = node.fi.se , z = node.se;
			if( node == F )
			{
				solve = 1;
				ans = dist[x][y][z];
			}
			for( int k = 0 ; k < 6 ; ++k )
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				int nz = z + dz[k];
				if( in( nx , L ) && in( ny , R ) && in( nz , C ) && dist[nx][ny][nz] == -1 && S[nx][ny][nz] != '#' )
				{
					dist[nx][ny][nz] = dist[x][y][z] + 1;
					Q.push( mp( mp( nx , ny ) , nz ) );
				}
			}
		}
		if( solve )
			cout << "Escaped in " << ans << " minute(s)." << endl;
		else	cout << "Trapped!" << endl;
	}
}
