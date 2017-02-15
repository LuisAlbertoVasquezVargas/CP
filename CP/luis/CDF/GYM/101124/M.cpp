#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll target;

map<pair<long long, int>, int>mapa;

int f(ll p, int x){
	if(p>=target)return 1 - x;
	if(mapa.find(make_pair(p, x)) != mapa.end())return mapa[make_pair(p, x)];
	int ans = 1 - x;
	for(ll k=2;k<=9;++k){
		if(f(p*k, 1 - x) == x)return x;
	}
	return mapa[make_pair(p, x)] =  ans;
}

int main(){
	ll n;
	while(cin>>n){
		target=n;
		mapa.clear();
		if(f(1, 1) == 1)puts("Stan wins.");
		else puts("Ollie wins.");

	}
}

