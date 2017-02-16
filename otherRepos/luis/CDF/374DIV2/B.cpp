#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; ++i)
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<string> > vvs;

int solve(vvs T,int K,string target){
	int tries = 0;
	REP(k,101){
		for(auto x : T[k]){
			tries ++;
			if(x == target){
				return ((tries - 1)/K) * 5 + tries;
			}
		}
	}
	assert(0);
}
int main(){
	int n , K;
	while(cin >> n >> K){
		vs passwords(n + 1);
		REP(i,n + 1) cin >> passwords[i];
		
		vvs T(101);
		REP(i,n){
			if(passwords[i] == passwords[n]) continue;
			T[SZ(passwords[i])].pb(passwords[i]);
		}
		vvs Q(T);
		Q[SZ(passwords[n])].pb(passwords[n]);
		
		vvs P(Q);
		int id = SZ(passwords[n]);
		swap(P[id][0],P[id][SZ(P[id]) - 1]);
		
		int ans1 = solve(P,K,passwords[n]);
		int ans2 = solve(Q,K,passwords[n]);
		cout << ans1 << " " << ans2 << '\n';
	}
}


