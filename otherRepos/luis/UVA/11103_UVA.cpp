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
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string S;
const int N = 100;
bool used[N + 5][N + 5];
string memo[N + 5][N + 5];
void relax(string &s,string t){
	if(SZ(t) > SZ(s)) s = t;
}
string dp(int lo,int hi){
	if(lo>hi) return "";
	if(lo==hi){
		if(S[lo] >= 'p'&& S[lo] <= 't') return string(1,S[lo]);
		return "";
	}
	if(used[lo][hi]) return memo[lo][hi];
	used[lo][hi] = 1;
	string &ans = memo[lo][hi] = "";
	relax(ans,dp(lo+1,hi));
	relax(ans,dp(lo,hi-1));
	if(S[lo]=='N'){
		string expr = dp(lo + 1,hi);
		if(!expr.empty())relax(ans,"N"+expr);
	}else if(S[lo]=='K'||S[lo]=='A'||S[lo]=='C'||S[lo]=='E'){
		for(int k=lo+1;k<hi;++k){
			string exprL = dp(lo + 1,k);
			string exprR = dp(k + 1,hi);
			if(!exprL.empty()&&!exprR.empty())
				relax(ans,string(1,S[lo])+exprL+exprR);
		}
	}
	return ans;
}
int main(){
	while(getline(cin , S)){
		if(S=="0") break;
		clr(used,0);
		string ans = dp(0,SZ(S)-1);
		cout << (ans.empty()?"no WFF possible":ans) << '\n';
	}
}


