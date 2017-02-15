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

#define N 5
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int v[N] , ind;
map< string , int >M;
string S[] = { "S" , "M" , "L" , "XL" , "XXL" };

void doit()
{
	for( int k = 1 ; k < N ; ++k )
		for( int j = 1 ; j >= -1 ; --j )
		{
			if( j == 0 )continue;
			int ni = ind +j*k;
			if( ni >= 0 && ni < N )
			{
				if( v[ni] )
				{
					v[ni]--;
					cout << S[ni] << endl;
					return;	
				}
			}
		}	
}
int main()
{
	for( int i = 0 ; i < N ; ++i )M[S[i]] = i;
	while( cin >> v[0] )
	{
		for( int i = 1 ; i < N ; ++i )cin >> v[i];
		int n ; 
		cin >> n;
		for( int i = 0 ; i < n ; ++i )
		{
			string s;
			cin >> s;
			ind = M[s];
			if( v[ind] )
			{
				v[ind]--;
				cout << s << endl;
				continue;	
			}
			doit();
		}
	}
}
