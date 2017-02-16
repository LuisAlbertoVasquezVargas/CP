#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){
	ios_base :: sync_with_stdio(0);
	int n;
	while(cin >> n){
		vi VAL;
		vector<string> OP;
		priority_queue<int, std::vector<int>, std::greater<int> > Q;
		REP(i , n){
			string op;
			cin >> op;
			if(op == "removeMin"){
				if(Q.empty()){
					OP.pb("insert");
					VAL.pb(-1);
					Q.push(-1);
				}
				OP.pb("removeMin");
				VAL.pb(-1);
				Q.pop();
			}else if(op == "insert"){
				int x;
				cin >> x;
				OP.pb("insert");
				VAL.pb(x);
				Q.push(x);
			}else{//getMin
				int x;
				cin >> x;
				if(!SZ(Q)){
					OP.pb("insert");
					VAL.pb(x);
					Q.push(x);
				}else{
					while(SZ(Q) && Q.top() < x){
						OP.pb("removeMin");
						VAL.pb(-1);
						Q.pop();
					}
					if(!(SZ(Q) && Q.top() == x)){
						OP.pb("insert");
						VAL.pb(x);
						Q.push(x);
					}
				}
				OP.pb("getMin");
				VAL.pb(x);
			}
		}
		cout << SZ(OP) << '\n';
		REP(i , SZ(OP))
			if( OP[ i ] == "removeMin" ) cout << OP[ i ] << '\n';
			else cout << OP[ i ] << " " << VAL[ i ] << '\n';
	}
}



