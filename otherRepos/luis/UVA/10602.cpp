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

typedef vector<string> vs;
typedef vector<int> vi;

int getDif(string s,string t){
	int ans = 0;
	REP(i,min(SZ(s),SZ(t)))
		if(s[i] == t[i]) ans ++;
		else break;
	return ans;
}
int main(){
	int cases;
	cin >> cases;
	REP(tc,cases){
		int n;
		cin >> n;
		vs S(n);
		REP(i,n) cin >> S[i];
		vi used(n);
		string last = S[0];
		int cur = SZ(last);
		used[0] = 1;
		vs T(1,last);
		while(1){
			if(used==vi(n,1)) break;
			int maxi = INT_MIN;
			int index = -1;
			REP(k,n){
				int dif = getDif(S[k],last);
				if(!used[k] && dif > maxi){
					maxi = dif;
					index = k;
				}
			}
			used[index] = 1;
			last = S[index];
			cur += SZ(last) - maxi;
			T.pb(last);
		}
		cout << cur << '\n';
		for(auto x : T) cout << x << '\n';
	}
}


