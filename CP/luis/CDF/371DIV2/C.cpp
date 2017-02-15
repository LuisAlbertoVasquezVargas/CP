#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define all(v) v.begin(),v.end()

const int L = 18;

void fix(string &s){
	int len = (int)s.size();
	s = string(L - len,'0') + s;
	REP(i , L)
		s[i] = '0' + ((s[i] - '0')&1);
}

int T[1 << (L + 2)];
void update(string s , int val){
	int node = 0;
	REP(k , L){
		node = (node << 1) + (s[k] == '0' ? +1 : +2);
		T[ node ] += val;
	}
}
int get(string s){
	int node = 0;
	REP(k , L)
		node = (node << 1) + (s[k] == '0' ? +1 : +2);
	return T[node];
}
int main(){
	ios_base :: sync_with_stdio(0);
	int Q;
	while(cin >> Q){
		//clr(T,0);
		REP(it, Q){
			string op , number;
			cin >> op >> number;
			fix(number);
			if(op == "+") update(number, +1);
			if(op == "-") update(number, -1);
			if(op == "?") cout << get(number) << '\n';
		}
	}
}

