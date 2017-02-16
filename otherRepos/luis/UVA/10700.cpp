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
typedef vector< ll > vll;

ll make_operation(ll a , ll b, bool flag){
	if(!flag) return a + b;
	return a * b;
}
ll eval(string s , int flag){
	vll STACK;
	int lastOp = -1;
	REP(i , SZ(s)){
		if(isdigit(s[ i ])){
			ll num;
			if(i + 1 < SZ(s) && isdigit(s[i + 1]) ){
				num = (s[i] - '0') * 10 + (s[i + 1] - '0');
				i ++;
			}else{
				num = (s[i] - '0');
			}
			if(lastOp == -1){
				STACK.pb(num);
			}else {
				if( (lastOp == 0) ^ flag ){//+
					STACK.pb(num);
				}else{
					ll val = STACK.back();
					STACK.pop_back();
					val = make_operation(val , num , !flag);
					STACK.pb(val);
				}
			}
		}else{
			if(s[ i ] == '+') lastOp = 0;
			else lastOp = 1;
		}
	}
	ll ans = (flag == 0 ? 0 : 1);
	for(auto x : STACK) ans = make_operation(ans , x , flag);
	return ans;
}
int main(){
	ios_base :: sync_with_stdio(0);
	int cases;
	cin >> cases;
	REP(tc , cases){
		string s;
		cin >> s;
		cout << "The maximum and minimum are " << eval(s , 1) << " and " << eval(s , 0) << ".\n";
	}
}


