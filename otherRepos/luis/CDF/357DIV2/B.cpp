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
		for(int a = 0 ; a * 1234567 <= n ; ++a )
			for(int b = 0 ; a * 1234567 + b * 123456 <= n ; ++b ){
				int cur = n - (a * 1234567 + b * 123456);
				if( cur % 1234 == 0 ){
					ok = 1;
					break;
				}
			}
		puts( ok ? "YES" : "NO" );
	}

}

