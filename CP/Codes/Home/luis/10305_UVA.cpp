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
 
#define MAXN 100
 
using namespace std;

vector< int >G[ MAXN ];
int in[ MAXN ];
bool existe[ MAXN ];
int n,m,u,v;

int main() 
{
    while( cin >> n >> m )
    {
		if( n == 0 && m == 0 )return 0;
		for( int i = 0 ; i < n ; ++i )
			G[i].clear();
		memset( in , 0 , sizeof(in) );
		for( int i = 0 ; i < m ; ++i )
		{
			cin >> u >> v;
			u--;v--;
			G[u].push_back(v);
			in[v]++;
			existe[u] = existe[v] = 1;
		}
		queue <int> Q;
		for( int i = 0 ; i < n ; ++i )
			if( in[i] == 0 && existe[i] )
				Q.push(i);
		vector< int >orden;
		while( !Q.empty() )
		{
			int u = Q.front();
			Q.pop();    
			orden.push_back(u);
			int nG = G[u].size();
			for( int i = 0 ; i < nG ; ++i )
			{
				int v = G[u][i];
				in[v]--;
				if( in[v] == 0 )
				Q.push(v);
			}
		}
/*		for( int i = 0 ; i < n ; ++i )
			if( in[i] != 0 && existe[i] )   
				cout << "ciclo" << endl ;*/
		int nv = orden.size();
		if( !orden.empty())
			cout << orden[0] + 1;
		for( int i = 1 ; i < nv ; ++i )
			cout << " " << orden[i] + 1 ;
		for( int i = 0 ; i < n ; ++i )
			if( !existe[i] )
				cout << " " << i + 1 ;
		cout << endl;
	}
}
 
