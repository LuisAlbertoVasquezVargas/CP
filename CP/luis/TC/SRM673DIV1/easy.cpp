#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i = 0; i < n ; ++i)
#define SZ(v) ((int)v.size())

typedef long long ll;
const int N = 50;
const int MOD = (int)1e9 + 7;

int solve(vector<int>W,vector<int>H,int target,int n){
	sort(W.begin(),W.end());
	sort(H.begin(),H.end());
	deque<int>L(n);
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j)
			if(W[i]*H[j] < target) L[i] ++;
			else break;
	}
	REP(i,n-1) if(L[i] < L[i + 1]) return 0;
	ll ans = 1;
	while(1){
		if(L.empty()) break;
		ll cnt = 0;
		if(L[0] <= 0) return 0;
		REP(k,SZ(L))
			if(L[k] == L[0]) cnt ++;
			else break;
		ans *= cnt;
		ans %= MOD;
		REP(k,cnt)L[k] --;
		L.pop_front();
		
	}
	return ans;
}
class BearCavalry {
public:
	int countAssignments(vector <int> warriors, vector <int> horses) {
		int n = (int)warriors.size();
		int ans = 0;
		for(int k = 0 ; k < n ; ++k){
			vector<int>W(warriors.begin()+1,warriors.end());
			vector<int>H;
			for(int i = 0 ; i < n ; ++i)
				if(i != k) H.push_back(horses[i]);
			ans = (ans + solve(W,H,warriors[0] * horses[k],n-1))%MOD;
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
