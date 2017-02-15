#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD2 1000000009

string s;
typedef long long ll;
int T;
int caso=0;

int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s;
		int l=0,r=int(s.size())-1;
		long long H1=0,H2=0;
		ll H3=0,H4=0;
		int ans=0;
		for(int i=0;i<s.length();i++){
			s[i]-='A';
			s[i]++;
		}
		ll pot=1,pot2=1;
		while(l<r){	
			H1=(s[l]*pot+H1)%MOD;
			H2=(27*H2+(s[r]))%MOD;
			H3=(s[l]*pot2+H3)%MOD2;
			H4=(27*H4+(s[r]))%MOD2;
			
			if(H1==H2&&H3==H4){
				//cout<<l<<" "<<r<<endl;
				ans+=2;
				pot=1;
				pot2=1;
				H3=H4=0;
				H1= H2 =0;
			}
			else {
				pot=(pot*27)%MOD;
				pot2=(pot2*27)%MOD2;
			}
			r--;l++;
		}
		
		if(H1!=0 ||H2!=0 || r==l)ans++;
		printf("Case #%d: %d\n",++caso,ans);
	}
}
