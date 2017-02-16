#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){
	int n;
	while(cin >> n){
		bool ok = 0;
		REP(i , n){
			string s;
			int a , b;
			cin >> s >> a >> b;
			if(a >= 2400 && a < b) ok = 1;
		}
		puts( ok ? "YES" : "NO" );
	}

}

