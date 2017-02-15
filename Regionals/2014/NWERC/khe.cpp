#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define REP(i, a, b) \
for(int i = int(a); i < int(b); i++)
#define pb(v,e) v.push_back(e)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
struct nodo{
	char E;
	int left;
	int rigth;
	int balls;
};
vector<nodo> V;
void recurs(int nodo,long long bolas){
	V[nodo].balls+=bolas;
	int j=0,k=0;
	if(V[nodo].E=='L'){
		j++;
	}else{
		k++;
	}
	//cout<<"**"<<V[nodo].left<<" "<<V[nodo].rigth<<endl;
	if(V[nodo].left!=0 && bolas/2+j>0){
		recurs(V[nodo].left,bolas/2+j);
	}
	if(V[nodo].rigth!=0 and bolas/2+k>0) {
		recurs(V[nodo].rigth,bolas/2+k);
	}
	
}
int main(){
	ios_base::sync_with_stdio(0);
	long long balls;
	int numnodos;
	//
	nodo un_nodo;
	
	char x;
	int l,r;
	un_nodo.E='X';
	un_nodo.rigth=0;
	un_nodo.left=0;
	while(cin>>balls>>numnodos){
		V.push_back(un_nodo);
		REP(i,0,numnodos){
			cin>>x;
			cin>>l;
			cin>>r; 
			un_nodo.E=x;
			un_nodo.left=l;
			un_nodo.rigth=r;
			V.push_back(un_nodo);
		}
		recurs(1,balls);
		V[1].balls=balls%2;
		REP(i,1,numnodos+1){
			if(V[i].balls%2==0){
				cout<<V[i].E;
			}else{
				if(V[i].E=='R')cout<<'L';
				if(V[i].E=='L')cout<<'R';
			}
		}
		cout<<"\n";
		V.clear();
	}
	
	return 0;
}

