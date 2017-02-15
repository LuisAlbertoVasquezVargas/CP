#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector<int> vi;

int main(){
	int n , m;
	while(scanf("%d%d" , &n , &m) == 2){
		set<int> X , Y;
		REP(i , m){
			int x , y;
			scanf("%d%d" , &x , &y);
			X.insert(x);
			Y.insert(y);
			ll a = SZ(X) , b = SZ(Y);
			ll ans = (ll)n * (ll) n - (a + b) * (ll)n + a * b;
			printf("%I64d%c" , ans , i + 1 == m ? 10 : 32);
		}
	}
}


