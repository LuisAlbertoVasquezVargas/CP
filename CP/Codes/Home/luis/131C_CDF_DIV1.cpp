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

#define N 305

using namespace std;

int n;
int a[N][N];
int memo[N][N][N];
int dx[] = {0,1};
int dy[] = {1,0};

bool f( int k )
{
	if( k < 0 || k >= n )return 0;
	return 1;	
}
int dp( int x , int y , int posx )
{
	int posy = x + y - posx ;
	if( x == n - 1 && y == n - 1 )return a[x][y];
	int &dev = memo[x][y][posx];
	if( dev != -1 )return dev;
	dev = -1<<30;
	for( int i = 0 ; i < 2 ; ++i )
		for( int j = 0 ; j < 2 ; ++j )
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nposx = posx + dx[j];
			int nposy = posy + dy[j];
			if( !f(nx) ) continue;
			if( !f(ny) ) continue;
			if( !f(nposx) ) continue;			
			if( !f(nposy) ) continue;			
			dev = max( dev , dp(nx,ny,nposx) );
			
		}
	if( x == posx && y == posy )
		dev += a[x][y];
	else 	dev += a[x][y] + a[posx][posy];		
	return dev;
}

int main()
{
        while( cin >> n )
        {
	        for( int i = 0 ; i < n ; ++i )
		        for( int j = 0 ; j < n ; ++j )
			        cin >> a[i][j];
		memset( memo , -1 , sizeof( memo ) );
		cout << dp( 0 , 0 , 0 ) << endl;
        }
}
