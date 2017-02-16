#include<bits/stdc++.h>

using namespace std;

#define oo "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"

int S[]={6,2,5,5,4,5,6,3,7,6};

string dp[105][2];
string dp2[105][2];
bool done1[105][2];
bool done2[105][2];

bool menor(string a,string b){
	
	for(int i=0;i<b.length();i++)
		if(b[i]=='-')return 1;
	if(b.length()<a.length())return 1;
	if(b.length()>a.length())return 0;
	//if(a=="7111111")
	//cout<<a<<" "<<b<<endl;
	for(int i=0;i<a.length();i++){
		if(a[i]<b[i])return 0;
	}
	return 1;
}

string f(int n,bool emp){
	
	if(n==0)return "";
	if(n<2)return oo;
	if(done1[n][emp])return dp[n][emp];
	
	string ans=oo;
	string ax="";
	if(emp){
		for(int i=0;i<=9;i++){
			ax=char(i+'0')+f(n-S[i],1);
			
			if(menor(ans,ax))ans=ax;
		}
	}
	else{
		for(int i=1;i<=9;i++){
			ax=char(i+'0')+f(n-S[i],1);
		//	cout<<ax<<" "<<menor(ax,ans)<<endl;
			if(menor(ans,ax))ans=ax;
		}
	}
	done1[n][emp]=1;
	return dp[n][emp]=ans;
}

string F(int n,bool emp){
	
	if(n==0)return "";
	if(n<2)return "-";
	if(done2[n][emp])return dp2[n][emp];
	
	string ans="";
	string ax="";
	if(emp){
		for(int i=0;i<=9;i++){
			ax=char(i+'0')+F(n-S[i],1);
			
			if(!menor(ans,ax))ans=ax;
		}
	}
	else{
		for(int i=1;i<=9;i++){
			ax=char(i+'0')+F(n-S[i],1);
		//	cout<<ax<<" "<<menor(ax,ans)<<endl;
			//if(i==7)cout<<ax<<" "<<ans<<endl;
			if(!menor(ans,ax))ans=ax;
		}
	}
	done2[n][emp]=1;
	return dp2[n][emp]=ans;
}


int n,T;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(done1,0,sizeof(done1));
		memset(done2,0,sizeof(done2));
		cout<<f(n,0)<<" "<<F(n,0)<<endl;
	}

}
