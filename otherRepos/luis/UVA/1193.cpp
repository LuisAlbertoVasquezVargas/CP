#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0; i < n ;++i)

#define all(v) v.begin(),v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

typedef pair<int , int> pii;
typedef vector<pii> vpii;

int main(){
	int n , d , tc = 0;
	while(scanf( "%d%d" , &n , &d ) == 2){
		if(n == 0 && d == 0) break;
		bool possible = 1;
		vpii vec;
		REP(i , n){
			int x , y;
			scanf( "%d%d" , &x , &y );
			if(y > d) possible = 0;
			int dx = floor(sqrt(d * d - y * y));
			int lo = x - dx , hi = x + dx;
			vec.pb(mp(lo , hi));
		}
		if(!possible){
			printf("Case %d: %d\n" , ++tc , -1 );
			continue;
		}
		sort(all(vec));
		int tope = INT_MIN , ans = 0;
		for(auto p : vec){
			if(tope < p.fi){
				ans ++;
				tope = p.se;
			}else{
				tope = min(tope , p.se);
			}
		}
		printf("Case %d: %d\n" , ++tc , ans );
	}
}

