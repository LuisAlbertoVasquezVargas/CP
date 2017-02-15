#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	string s , t;
	while(cin >> s >> t){
		int index = 0;
		for(auto c : t){
			if(index >= SZ(s))break;
			if(c == s[index]) index ++;
		}
		puts(index == SZ(s) ? "Yes" : "No");
	}
}
