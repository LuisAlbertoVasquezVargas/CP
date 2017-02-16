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

ll mulmod(ll a, ll b, ll c){
	ll x = 0, y = a % c;
	while(b > 0){
		if(b & 1){
			x += y;
			if(x >= c) x -= c;
		}
		y = y + y;
		if(y >= c) y -= c;
		b >>= 1;
	}
	return x % c;
}
ll modulo(ll a, ll b, ll c){
	ll x = 1, y = a;
	while(b){
		if(b & 1) x = mulmod(x, y, c);
		y = mulmod(y, y, c);
		b >>= 1;
	}
	return x % c;
}
bool miller(ll p, int it = 20){
	if(p < 2) return false;
	if(p != 2 && p % 2 == 0) return false;
	ll s = p - 1;
	while(s % 2 == 0) s /= 2;
	while( it-- ){
		ll a = rand() % (p - 1) + 1, temp = s;
		ll mod = modulo(a, temp, p);
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = mulmod(mod, mod, p);
			temp *= 2;
		}
		if(mod != p - 1 && temp % 2 == 0) return false;
	}
	return true;
}
int main()
{
	int tc;
	cin >> tc;
	while( tc-- )
	{
		ll n ;
		cin >> n; 
		for( ll i = n ; i >= 2 ; --i )
			if( miller(i) )
			{
				cout << i << endl;
				break;
			} 
	}
}
