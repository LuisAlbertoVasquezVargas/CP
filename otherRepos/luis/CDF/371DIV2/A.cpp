#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	ll L1 , R1 , L2 , R2 , K;
	while(cin >> L1 >> R1 >> L2 >> R2 >> K){
		if(L1 >= L2){
			swap(L1,L2);
			swap(R1,R2);
		}
		
		if(R1 < L2){
			cout << "0\n";
			continue;
		}
		ll L = max(L1,L2) , R = min(R1,R2);
		ll ans = R - L + 1;
		if(L <= K && K <= R) ans --;
		
		cout << ans << '\n';
	}
}


