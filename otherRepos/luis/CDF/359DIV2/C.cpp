#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void doIt(string &s , vi &F){
	REP(i , SZ(s)) F[ s[ i ] - '0' ] ++;
}
bool valid(string a , string b){
	vi F(10);
	doIt(a , F);
	doIt(b , F);
	REP(k , 10)
		if( F[ k ] > 1 ) return 0;
	return 1;
}
string toBase7(int x){
	if(x == 0) return "0";
	string cad;
	while( x ){
		cad.pb('0' + x % 7);
		x /= 7;
	}
	reverse(all(cad));
	return cad;
}
string fix(string s, int len){
	if(len - SZ(s) < 0) return "-1";
	return string(len - SZ(s) , '0') + s;
}
int main(){
	int n , m;
	while(scanf("%d%d" , &n , &m) == 2){
		vi vec = {0,1,2,3,4,5,6};
		int len = SZ(vec);
		set< string > SET;
		int lenA = SZ(toBase7(n - 1));
		int lenB = SZ(toBase7(m - 1));
		do{
			for(int a = 0 ; a <= len ; ++a)
				for(int b = 0 ; a + b <= len ; ++b){
					int L = 0 , R = 0;
					int cur = 0;
					REP( k , a ) L = L * 7 + vec[cur ++];
					REP( k , b ) R = R * 7 + vec[cur ++];
					string sL = fix(toBase7(L) , lenA);
					string sR = fix(toBase7(R) , lenB);
					if(L < n && R < m && valid(sL , sR)) 
						SET.insert(sL + ":" + sR);
				}
		}while(next_permutation(all(vec)));
		printf("%d\n" , SZ(SET));
	}
}


