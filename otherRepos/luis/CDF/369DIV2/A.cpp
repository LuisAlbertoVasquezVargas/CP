#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

int main(){
	int n;
	while(cin >> n){
		string s;
		bool ok = 0;
		vector<string> vec;
		REP(i , n){
			cin >> s;
			if(!ok){
				if(s.substr(0,2) == "OO"){
					s[0] = s[1] = '+';
					ok = 1;
				}else if(s.substr(3,2) == "OO"){
					s[3] = s[4] = '+';
					ok = 1;
				}
			}
			vec.push_back(s);
		}
		if(!ok){
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		REP(i , n) cout << vec[ i ] << '\n';
	}
}


