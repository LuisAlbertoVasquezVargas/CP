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

int tc , n , m , bud ,c,k;
string dumm;
string s;
string S[MAXN],T[MAXN];
map< string , int >Cost;
vector< pair< int , string > >Ans;

void doit ( int i )
{
	int sz = S[i].size();
	for( int j = 0 ; j < sz ; ++j )
		S[i][j] = toupper(S[i][j]);
}

int main()
{
	cin >> tc;
	getline( cin , dumm );
	for( int t = 0 ; t < tc ; ++t )
	{
		getline( cin , S[t] );
		doit(t);
		cin >> m >> n >> bud;
		getline( cin , dumm );
		Cost.clear();
		Ans.clear();
		for( int i = 0 ; i < m ; ++i )
		{
			cin >> s >> c;
			Cost[s] = c;
		}
		getline( cin , dumm );
		for( int i = 0 ; i < n ; ++i )
		{
			getline( cin , T[i] );
			cin >> k;
			getline( cin , dumm );
			int sum = 0;			
			for( int j = 0 ; j < k ; ++j )
			{
				cin >> s >> c;
				sum += Cost[s]*c;
			}
			getline( cin , dumm );
			if( sum <= bud )
				Ans.push_back( make_pair( sum,T[i]) );
		}
		sort( Ans.begin() , Ans.end() );
		cout << S[t] << "\n";
		int nv = Ans.size();
		if( nv )
		{
			for( int i = 0 ; i < nv ; ++i )
				cout << Ans[i].second << "\n";
		}else	puts("Too expensive!");	
		puts("");
	}
}
