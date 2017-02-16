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
#define INF 1e100
#define EPS (1e-5)

using namespace std;

int A , n , m ;
char c1 , c2;
vi R1,R2;

double mini( int i , int Hi , int Ri , int Si , int j , int Hj , int Rj , int Sj )
{
	
}

void doit()
{
	vi S1(n) , S2(m);
	S1[0] = c1 == 'N';
	S2[0] = c2 == 'N';
	for( int i = 1 ; i < n ; ++i )S1[i] = S1[i-1]^1;
	for( int i = 1 ; i < m ; ++i )S2[i] = S2[i-1]^1;
	double best = INF;
	int i = 0 , j = 0 ;
	while( 1 )
	{
		best = min( best , mini( i , , R1[i] , S1[i] , j ,, R2[j] , S2[j] ) );
	}
}
int main()
{
	sync
	while( cin >> A )
	{
		if( A == -1 )break;
		cin >> n >> c1;
		R1.resize( n );
		for( int i = 0 ; i < n ; ++i )cin >> R1[i];
		cin >> m >> c2;
		R2.resize( m );
		for( int i = 0 ; i < m ; ++i )cin >> R2[i];
		doit();
	}
}
