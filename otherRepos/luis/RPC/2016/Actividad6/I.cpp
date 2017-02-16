#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ;i < n; ++i)

#define mp make_pair
#define fi first
#define se second

#define pb push_back

typedef long long ll;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

void doit(vs &ans , vs &S , int &cur , int n , string &cad ){
	REP(i , n) REP(j , n){
		if(S[ i ][ j ] == '.') ans[ i ][ j ] = cad[ cur ++ ];
	}
}
int main(){
	int n;
	while( cin >> n ){
		vector< string > S(n);
		REP(i , n) cin >> S[ i ];
		string text;
		cin >> text;
		vs vis = S;
		vvi ind(n , vi(n , -1) );
		int flag = 0 , cur = 0;
		vs ans(n , string(n,'*'));
		doit(ans , S , cur , n , text);
		REP(k , 3){
			vector< string > T(n , string(n , 'X'));
			REP(i , n)REP(j , n)
				if(S[ i ][ j ] == '.'){ 
					T[ j ][ n - 1 - i ] = '.';
					if( vis[ j ][ n - 1 - i ] == '.' ) flag = 1;
					vis[ j ][ n - 1 - i ] = '.';
				}
			doit(ans , T , cur , n , text);
			S = T;
		}
		if( flag || vis != vector<string>(n , string(n ,'.')) ){
			cout << "invalid grille" << '\n';
			continue;
		}
		REP(i , n) cout << ans[ i ];
		cout << '\n';
	}
}



