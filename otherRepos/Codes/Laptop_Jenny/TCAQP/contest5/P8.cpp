#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define pb push_back
#define ll long long
using namespace std;

ll lcm(ll a, ll b){
	ll gcd =__gcd(a,b);
	return  a/(gcd)*b;
}

int main(){
	string s;
	while(cin>>s){
		if(s=="*")break;
		int sz=s.size();
		ll mcm=1;
		for(int i=0;i<sz;++i){
			if(s[i]=='Y')mcm=lcm(mcm,(ll) (i+1));
		}
		bool ok=1;
		vector<ll>inval;
		for(int i=0;i<sz;++i){
			if(s[i]=='N'){
				if(mcm%(i+1)==0)ok=0;
				else{
					ll aux= __gcd(mcm, (ll) (i+1));
					inval.pb( mcm / aux);
				}
			}
		}
		sort(inval.begin(),inval.end());
		ll cur=1;
		for(int i=0;i<inval.size();++i){
			if(cur!=inval[i]){
				break;
			}
			else cur++;
		}	
		if(!ok)puts("-1");
		else{
			cout<<mcm*cur<<endl;
		}	
	}
}


