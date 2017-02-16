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

int main(){
	int n , m;
	while(cin >> n >> m){
		vvi T(n , vi(4));
		int cur = 1;
		REP( k , 2 ){
			for(int i = n - 1; i >= 0 ; --i){
				if( k == 0 ){
					T[i][0] = cur ++;
					T[i][3] = cur ++;
				}else{
					T[i][1] = cur ++;
					T[i][2] = cur ++;
				}
			}
		}
		vi ans;
		for(int i = n - 1 ; i >= 0 ; --i){
			for(auto ind : {1 , 0 , 2 , 3})
				if(T[ i ][ ind ] <= m) ans.pb(T[i][ind]);
		}
		for(auto p : ans) cout << p << " ";
		cout << endl;
	}
}

