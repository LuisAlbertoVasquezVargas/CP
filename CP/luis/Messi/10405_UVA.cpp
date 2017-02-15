#include<bits/stdc++.h>
using namespace std;

string getLCS(string a,string b){
	//fill DP table
	int n=(int)a.size(),m=(int)b.size();
	int DP[n+1][m+1];//create a table
	memset(DP,0,sizeof(DP));//setting DP table to 0
	for(int lenN=1;lenN<=n;++lenN)
		for(int lenM=1;lenM<=m;++lenM){
			DP[lenN][lenM]=max(DP[lenN-1][lenM],DP[lenN][lenM-1]);
			if(a[lenN-1]==b[lenM-1])
				DP[lenN][lenM]=max(DP[lenN][lenM],1+DP[lenN-1][lenM-1]);
		}
	string ans;
	int x=n,y=m;
	while(1){
		if(x==0&&y==0)break;
		if(x-1>=0&&DP[x][y]==DP[x-1][y]){
			x=x-1;
			continue;
		}
		if(y-1>=0&&DP[x][y]==DP[x][y-1]){
			y=y-1;
			continue;
		}
		ans+=a[x-1];
		x=x-1;
		y=y-1;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	string a,b;
	while(getline(cin,a)){
		getline(cin,b);
		cout<<getLCS(a,b)<<'\n';	
	}
}
