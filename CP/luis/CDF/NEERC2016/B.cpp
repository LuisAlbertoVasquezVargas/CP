#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)

#define pb push_back

const int N=100;
const int INF=(1<<20);

string query(int x,int y){
	//
	cout<<"? "<<x<<" "<<y<<'\n';
	fflush(stdout);
	string ans;
	cin>>ans;
	return ans;
}
void respond(int x,int y){
	cout<<"!"<<x<<" "<<y<<'\n';
	fflush(stdout);
}
int main(){
	int cases;
	cin>>cases;
	REP(tc,cases){
		int n;
		cin>>n;
		string s;
		vector<int>menor, mayor;
		if(n > 1){
			for(int i = 1; i <= n; i += 2){

				string s=query(i,i+1);
				if(s == "<" || s == "="){
					menor.pb(i);
					mayor.pb(i + 1);
				}
				else{
					menor.pb(i + 1);
					mayor.pb(i);
				}
			}
			if(n&1)mayor.pb(n), menor.pb(n);
			int pos1 = menor[0];
			for(int i = 1; i < menor.size(); i++){
				s=query(i,pos1);
				if(s == "<" || s == "=")pos1 = i;
			}
			int pos2 = mayor[0];
			for(int i = 1; i < mayor.size(); i++){
				s=query(i,pos2);
				if(s == ">" || s == "=")pos2 = i;
			}
			respond(pos1,pos2);
		}
		else{
			respond(1,1);
		}
	}
}
