#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d" , &x)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef long long ll;
ll get(ll x){
	return (x * (x - 1)) >> 1;
}
int main(){
	int n;
	while(sc(n) == 1){
		vi F(100);
		REP(i , n){
			int x;
			sc(x);
			F[__builtin_popcount(x)] ++;
		}
		ll ans = 0;
		REP(i,100) ans += get(F[ i ]);
		cout << ans << '\n';
	}
}
