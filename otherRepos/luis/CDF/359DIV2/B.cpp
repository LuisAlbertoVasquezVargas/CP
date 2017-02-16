#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector<int> vi;

int main(){
	ios_base :: sync_with_stdio(0);
	int n;
	while(cin >> n){
		vi A(n);
		REP(i , n) cin >> A[ i ];
		REP(i , n){
			int pos = min_element(A.begin()+i,A.end()) - A.begin();
			if(A[ pos ] == A[ i ]) continue;
			for(int j = pos - 1 ; j >= i ; --j){
				swap(A[ j ] , A[ j + 1 ]);
				cout << j + 1 << " " << j + 1 + 1 << '\n';
			}
		}
		/*
		REP(i , n) cout << A[ i ] << " ";
		cout << endl;
		*/
	}
}


