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

int M[N][N];

int main()
{
	int n ,m ;
	scanf( "%d%d" , &n , &m );
	REP( i ,  n )REP( j , m )
		sc( M[i][j] );
	if( n > 2 )
	{
		REP( i ,  n )REP( j , m )
			printf( "%d%s" , M[i][j] , (j+1==m?"\n":" ") );
	}
	else
	{
		vi I;
		REP( j , m )
			if( M[0][j] == M[1][j] ) I.pb( j );
		int nI = I.size();
		REP( i , nI - 1 )
			swap( M[0][I[i]] , M[0][I[(i+1)%nI]] ),swap( M[1][I[i]] , M[1][I[(i+1)%nI]] );
		REP( i ,  n )REP( j , m )
			printf( "%d%s" , M[i][j] , (j+1==m?"\n":" ") );
	}
}


