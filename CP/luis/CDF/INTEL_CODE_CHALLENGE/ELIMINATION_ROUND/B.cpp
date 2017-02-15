#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))
#define pb push_back
#define SZ(v) ((int)v.size())

int getCount(string s){
	int ans = 0;
	for(auto x : s)
		if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y') ans ++;
	return ans;
}
int main(){
	ios_base :: sync_with_stdio(0);
	int n;
	while(cin >> n){
		vector<int> A(n);
		REP(i,n) cin >> A[i];
		string dummy;
		getline(cin,dummy);
		bool ok = 1;
		REP(i,n){
			string s;
			getline(cin,s);
			int cnt = getCount(s);
			if(cnt != A[i]) ok = 0;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}
