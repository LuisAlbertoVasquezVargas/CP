#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))
#define pb push_back
#define SZ(v) ((int)v.size())

string get(int x){
	string s(2,'0');
	s[0] += x / 10;
	s[1] += x % 10;
	return s;
}
void init(vector<string> &T, int flag){
	int lo = ((!flag) ? 1 : 0 );
	int hi = ((!flag) ? 12 : 23 );
	for(int h = lo ; h <= hi ; ++h){
		for(int m = 0; m <= 59; ++m){
			T.push_back(get(h) + ":" + get(m));
		}
	}
}
int getDif(string a, string b){
	int ans = 0;
	REP(i,SZ(a))
		if(a[i] != b[i]) ans ++;
	return ans;
}
vector<string> T[2];
int main(){
	init(T[0],0);
	init(T[1],1);
	int mode;
	string s;
	while(cin >> mode >> s){
		if(mode == 12) mode = 0;
		else mode = 1;
		int best = INT_MAX;
		string cad;
		for(auto x : T[mode]){
			int cur = getDif(x,s);
			if(best>cur) best=cur,cad = x;
		}
		cout << cad << '\n';
	}
}


