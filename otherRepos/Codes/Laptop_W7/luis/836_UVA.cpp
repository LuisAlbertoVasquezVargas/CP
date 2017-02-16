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
#define rall(v)  v.rbegin() , v.rend()
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

using namespace std;

int tc;

int main()
{
	while( cin >> tc )
	{
		bool ok = 0;
		while( tc-- )
		{
			if( !ok )ok^=1;
			else cout << endl;
			vector< string > v(1);
			cin >> v[0];
			int n = v[0].size();
			v.resize( n );
			for( int i = 1 ; i < n ; ++i ) cin >> v[i];
			vector< vi >A( n + 1 , vi(n + 1) );
			for( int i = n-1 ; i >= 0 ; --i)
    			for( int j = n-1 ; j >= 0 ; --j )
        			A[i][j] = (v[i][j]=='1') + A[i+1][j]+A[i][j+1]-A[i+1][j+1];
        	int maxi = 0;
        	for( int i = 0 ; i < n ; ++i )
        		for( int I = i ; I < n ; ++I )
        			for( int j = 0 ; j < n ; ++j )
        				for( int J = i ; J < n ; ++J )
        				{
							int sum = A[i][j] - A[i][J+1] - A[I+1][j] + A[I+1][J+1];
							if( sum == (I - i + 1)* (J - j + 1) ) maxi = max( maxi , sum );	
						}
			cout << maxi << endl;
		}		
	}
}
