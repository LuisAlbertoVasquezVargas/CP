#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef long long ll;

int main(){
	ios_base :: sync_with_stdio(0);
	string s;
	while(cin >> s){
		int n = SZ(s);
		bool found=0;
		REP(i,n+1-26){
			map<int,int>F;
			REP(k,26)
				F[s[i+k]] ++;
			bool ok = 1;
			REP(k,26)
				if(F['A'+k] > 1) ok = 0;
			if(ok){
				int cur = 0;
				REP(k,26){
					if(s[i+k]=='?'){
						while(F['A'+cur]==1)cur++;
						F['A'+cur] = 1;
						s[i+k] = 'A' + cur;
					}
				}
				found = 1;
				break;
			}
		}
		for(auto &x : s)
			if(x == '?') x = 'A';
		if(!found) cout << "-1\n";
		else cout << s << endl;
	}
}



