#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d" , &x)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;
typedef vector< vi > vvi;

const int N = 100000;
vi G[N + 5];
int A[N + 5];

int main(){
	int n , m;
	while(sc(n) == 1){
		sc(m);
		REP(i , n) G[i].clear();
		vi ind(n);
		REP(i , m){
			int u , v;
			sc(u) , sc(v);
			u-- , v --;
			G[ u ].pb( v );
			ind[ v ] ++;
		}
		REP( i , n ) sc(A[ i ]) , A[i]--;
		queue<int> Q;
		vi ans;
		vi h(n) , used(n);
		bool possible = 1;
		REP(i , n)
			if(ind[i] == 0) Q.push(i) , used[i] = 1 , ans.pb(i);
		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			for(auto v : G[u]){
				h[v] = h[u] + 1;
				if(h[A[v]] + 1 > h[A[u]]){
					Q.push(v);
					if(!used[A[v]])ans.pb(A[v]);
					used[A[v]] = 1;
				}else{
					//cout << h[A[v]] << " " << h[u] << " " << h[A[u]] << endl;
					//cout << u << " " << v << endl;
					possible = 0;
				}
			}
		}
		if(!possible) puts("-1");
		else{
			reverse(all(ans));
			printf("%d\n" , SZ(ans));
			REP(i , SZ(ans)) printf("%d\n" , ++ans[i]);
		}
	}
}


