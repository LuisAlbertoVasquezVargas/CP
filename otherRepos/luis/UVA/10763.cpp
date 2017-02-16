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

typedef pair<int,int>pii;

int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		if(n == 0) break;
		map<pii, int> mapa;
		REP(i  ,n){
			int a , b;
			scanf("%d%d" , &a , &b);
			mapa[mp(a,b)]++;
		}
		bool ok = 1;
		for(auto p : mapa){
			int a = p.fi.fi , b = p.fi.se;
			if(mapa[mp(a,b)] != mapa[mp(b,a)]){
				ok = 0;
				break;
			}
		}
		puts(ok ? "YES" : "NO" );
	}
}



