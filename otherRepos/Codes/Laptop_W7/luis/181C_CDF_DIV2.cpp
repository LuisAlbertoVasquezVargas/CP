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

#define N 1000005
#define MOD 1000000007

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

using namespace std;

int n , A , B;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
ll F[N],FP[N];
bool f( ll x )
{
	while( x > 0 )
	{
		if( x%10 != A && x%10 != B )return 0;
		x/= 10;
	}
	return 1; 
}
long long pow( long long a, long long b, long long c){
    long long x = 1, y = a;	
    while(b>0){
        if(b&1) x = (x*y)%c;
        y = (y*y)%c;
        b >>= 1;
    }	
    return x;
}
int main()
{
	F[0] = 1;
	for( int i = 1 ; i < N ; ++i ) 
	{
		F[i] = i*F[i-1];
		if( F[i] >= MOD ) F[i]%= MOD;
	}
	FP[N-1] = pow( F[N - 1] , MOD - 2 , MOD );
	for( int i = N - 2 ; i >= 0 ; --i ) 
	{
		FP[i] = FP[i+1]*(i+1) ;
		if( FP[i] >= MOD ) FP[i] %= MOD;
	}
	while( cin >> A >> B >> n )
	{
		ll cnt = 0;
		for( int i = 0 ; i <= n ; ++i )
			if( f(i*A+(n-i)*B) )
			{
				ll num = F[n] , den = FP[i]*FP[n-i];
				if( den >= MOD ) den %= MOD;
				num *= den;
				if( num >= MOD )num%= MOD;
				cnt += num; 
				if( cnt >= MOD )cnt -= MOD;
			}
		cout << cnt << endl;
	}
}
