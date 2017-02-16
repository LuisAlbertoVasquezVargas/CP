#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

int main(){
	int n;
	while( cin >> n ){
		cout << (n/3) * 2 + (n % 3 > 0) << '\n';
	}
}
