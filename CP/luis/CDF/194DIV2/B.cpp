#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;

vi fix(vi X){
	sort(all(X));
	X.resize(unique(all(X)) - X.begin());
	return X;
}
int main(){
	int x , y;
	while( cin >> x >> y ){
		vi X(1,x) , Y(1,y);
		REP(k , 8){
			if(!k) continue;
			cin >> x >> y;
			X.pb(x) , Y.pb(y);
		}
		
		vi a = fix(X);
		vi b = fix(Y);
		
		if(SZ(a) != 3 || SZ(b) != 3){
			cout << "ugly\n";
			continue;
		}
		bool ok = 1;
		REP(i , 3) REP(j , 3){
			if(i == 1 && j == 1) continue;
			bool found = 0;
			REP(k , 8)
				if(X[ k ] == a[ i ] && Y[ k ] == b[ j ]) found = 1;
			if(!found) ok = 0;
		}
		if( ok ) cout << "respectable\n";
		else cout << "ugly\n";
	}
}


