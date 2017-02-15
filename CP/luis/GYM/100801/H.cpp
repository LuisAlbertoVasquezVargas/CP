#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

vs T=  {"edHs","mENAGeS","fEHs","edIT"};

int Hash(string s){
	int pot = 1;
	int ans = 0;
	for(int i = SZ(s) - 1; i >= 0; --i){
		pot *= 31;
		ans = ans + pot * s[i];
	}
	return ans;
}
unordered_map<int,vs>myMap;
int N = 8;
string S;
//string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alpha = "abcABC";
void back(int pos){
	if(pos == N){
		int h = Hash(S);
		myMap[h].push_back(S);
		return;
	}
	for(auto c : alpha){
		S.pb(c);
		back(pos + 1);
		S.pop_back();
	}
}
int main(){
	cin >> N;
	double t = clock();
	back(0);
	printf("%.10f\n" , (clock() - t)/CLOCKS_PER_SEC);
	int maxi = 0;
	vs best;
	for(auto x : myMap){
		vs v = x.se;
		/*
		sort(all(v));
		v.resize(unique(all(v))-v.begin());
		*/
		if(SZ(v) > maxi){
			maxi = SZ(v);
			best = v;
		}
	}
	cout << maxi << endl;
	for(auto x : best) cout << x << endl;
}


