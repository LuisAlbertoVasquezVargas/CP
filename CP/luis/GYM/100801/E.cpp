#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)v.size())
#define all(v) v.begin(),v.end()

void solve(char c,string s,bool &flag){
	if(c == '+'){
		if(flag){
			cout << s;
			flag = 0;
		}else{
			cout << c << s;
		}
	}else{
		if(SZ(s) == 1){
			cout << c << s;
			return;
		}
		cout << c << s[0];
		for(int i = 1 ; i < SZ(s) ; ++i){
			if(s[i] == '0') cout << '+' << s[i];
			else{
				cout << '+' << s.substr(i);
				break;
			}
		}
		//assert(0);
	}
}

int main(){
	
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	
	string s;
	while(getline(cin,s)){
		bool flag = 0;
		if(isdigit(s[0])){
			s = "+" + s;
			flag = 1;
		}
		REP(i,SZ(s)){
			int ind;
			for(int j = i + 1; j < SZ(s);++j)
				if(isdigit(s[j])) ind = j;
				else break;
			solve(s[i],s.substr(i+1,ind-(i+1)+1),flag);
			i = ind;
		}
		cout << '\n';
	}
}


