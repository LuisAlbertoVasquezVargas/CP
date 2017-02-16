#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)

#define pb push_back
#define all(v) v.begin(),v.end()
#define SZ( v ) ((int)(v).size())

#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector<int> vi;

//vi V={3,2,1,2,3};
//vi V={1,2,3,4,5};
vi V={1,2,3,4,5,6};
int cnt=0;
string query(int x,int y){
	/*
	cnt++;
	x--,y--;
	if(V[x]==V[y])return "=";
	if(V[x]<V[y])return "<";
	if(V[x]>V[y])return ">";
	*/
	cout<<"? "<<x<<" "<<y<<'\n';
	fflush(stdout);
	string ans;
	cin>>ans;
	return ans;
}
void respond(int x,int y){
	cout<<"! "<<x<<" "<<y<<'\n';
	/*
	//DEBUG2(x,y);
	x--,y--;
	int maxi=*max_element(all(V));
	int mini=*min_element(all(V));
	DEBUG2(V[x],V[y]);
	DEBUG2(mini,maxi);
	assert(V[x]==mini&&V[y]==maxi);
	return;
	*/
	fflush(stdout);
}
int ceiling(int a,int b){
	return (a-1)/b+1;
}
int main(){
	int cases;
	cin>>cases;
	REP(tc,cases){
		int n;
		cin>>n;
		/*
		n=SZ(V);
		n=1+rand()%50;
		V.resize(n);
		REP(i,n)V[i]=rand();
		*/
		string s;
		cnt=0;
		vector<int>menor, mayor;
		if(n > 1){
			for(int i = 1; i + 1 <= n; i += 2){
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
			//for(auto x:menor)DEBUG(x);
			//for(auto y:mayor)DEBUG(y);
			for(int i = 1; i < menor.size(); i++){
				s=query(menor[i],pos1);
				if(s == "<" || s == "=")pos1 = menor[i];
			}
			int pos2 = mayor[0];
			
			for(int i = 1; i < mayor.size(); i++){
				s=query(mayor[i],pos2);
				if(s == ">" || s == "=")pos2 = mayor[i];
			}
			respond(pos1,pos2);
			assert(cnt<=ceiling(3*n,2)-2);
		}
		else{
			respond(1,1);
		}
	}
}
