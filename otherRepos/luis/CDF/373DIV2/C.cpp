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
typedef vector<ll> vll;

int main(){
	ios_base :: sync_with_stdio(0);
	int n , T;
	string s;
	while(cin >> n >> T >> s){
		int pos = s.find('.');
		assert(pos >= 0 && pos < n);
		int ind = -1;
		for(int k = pos + 1 ; k < n ; ++k)
			if(s[k] >= '5'){
				ind = k;
				break;
			}
		if(ind == -1){
			cout << s << '\n';
			continue;
		}
		
		while(1){
			if(T == 0) break;
			while(ind < SZ(s) - 1) s.pop_back();
			if(s[ind - 1] == '4'){
				s[ind - 1] = '5';
				s.pop_back();
				T --;
				ind --;
				continue;
			}
			if(s[ind - 1] == '.'){
				//caso especial : poner un cerito adelante
				while(pos < SZ(s) - 1) s.pop_back();
				s.pop_back();
				s = "0" + s;
				for(int k = SZ(s) - 1; k >= 0 ; --k){
					if(s[k] == '9') s[k] = '0';
					else{
						s[k] ++;
						break;
					}
				}
				if(s[0] == '0') s = s.substr(1);
				//assert(0);
				break;
			}
			s[ind - 1] ++;
			s.pop_back();
			ind --;
			break;
		}
		cout << s << '\n';
	}
}



