#include<bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d" , &x)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

ld toDouble(string s){
	istringstream in(s);
	ld x;
	in >> x;
	return x;
}
ld f(string s){
	if(s[0] != '(') return toDouble(s);
	s = s.substr(1,SZ(s)-2);
	int pos = s.find(' ');
	ld p = toDouble(s.substr(0,pos));
	s = s.substr(pos + 1);
	int cur = 0;
	REP(i , SZ(s)){
		if(s[i] == '(') cur ++;
		if(s[i] == ')') cur --;
		
		if(cur == 0 && i){
			pos = i;
			break;
		}
	}
	ld a = f(s.substr(0,pos + 1));
	ld b = f(s.substr(pos + 2));
	cout << s.substr(0,pos + 1) << "-" << s.substr(pos + 2) << "-" << p << endl;
	return -1;
}
int main(){
	string s;
	while(getline(cin,s)){
		if(s == "()")break;
		printf("%.2f\n" , (double)f(s));
	}
}


