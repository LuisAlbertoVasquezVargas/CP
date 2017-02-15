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
int n,m,u,v,it=0;
string s[MAXN],s1,s2;
map< string , int >M;

void init()
{
	for( int i = 0 ; i < n ; ++i )
		G[i].clear();
	memset( in , 0 , sizeof(in) );	
	M.clear();	
}
int main() 
{
    while( cin >> n )
    {
		init();
		for( int i = 0 ; i < n ; ++i )
			cin >> s[i] , M[s[i]] = i;
		cin >> m;
		for( int i = 0 ; i < m ; ++i )
		{
			cin >> s1 >> s2;
			u = M[s1];
			v = M[s2];
			G[u].push_back(v);
			in[v]++;
		}
		priority_queue <int> Q;
		for( int i = 0 ; i < n ; ++i )
			if( in[i] == 0 )
				Q.push(-i);
		vector< int >orden;
		while( !Q.empty() )
		{
			int u = Q.top();
			u = -u;
			Q.pop();    
			orden.push_back(u);
			int nG = G[u].size();
			for( int i = 0 ; i < nG ; ++i )
			{
				int v = G[u][i];
				in[v]--;
				if( in[v] == 0 )
				Q.push(-v);
			}
		}
		
		int nv = orden.size();
		cout << "Case #"<<++it<<": Dilbert should drink beverages in this order:";
		if( !orden.empty())
			cout << " " << s[orden[0]];
		for( int i = 1 ; i < nv ; ++i )
			cout << " " << s[orden[i]];
		cout << "." << endl << endl ;
	}
}
