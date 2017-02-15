#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; ++i)
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector<int> vi;

int count(string s){
	REP(i,SZ(s))
		if(s[i]=='_')s[i]=' ';
	istringstream in(s);
	int ans=0;
	string t;
	while(in>>t)ans++;
	return ans;
}
int main(){
	string s;
	int n;
	while(cin>>n>>s){
		assert(SZ(s)==n);
		int longestWordsOutside=0;
		int cntWordsInside=0;
		REP(i,SZ(s)){
			if(s[i]=='_')continue;
			if(s[i]=='('){
				int ind=-1;
				for(int j=i;j<SZ(s);++j){
					if(s[j]==')'){
						ind=j;
						break;
					}
				}
				assert(ind!=-1);
				cntWordsInside+=count(s.substr(i+1,(ind-1)-(i+1)+1));
				i=ind;
			}else{
				int ind=-1;
				for(int j=i;j<SZ(s);++j){
					if(!isalpha(s[j])){
						break;
					}else{
						ind=j;
					}
				}
				assert(ind!=-1);
				longestWordsOutside=max(longestWordsOutside,ind-i+1);
				i=ind;
			}
		}
		cout<<longestWordsOutside<<" "<<cntWordsInside<<'\n';
	}
}


