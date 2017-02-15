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

int main(){
	ios_base :: sync_with_stdio(0);
	ll n , x;
	while(cin >> n >> x){
		int ans = 0;
		REP(i , n){
			char c;
			int d;
			cin >> c >> d;
			if(c == '+') x += d;
			else{
				if( x >= d ) x -= d;
				else ans ++;
			}
		}
		cout << x << " " << ans << '\n';
	}
}


