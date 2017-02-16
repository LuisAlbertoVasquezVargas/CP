#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pii;
typedef pair<pii,pii> rect;
//1 1 10 1
//5 5 5 10
/*
rect R1(pii(1,1),pii(10,1));
rect R2(pii(5,5),pii(5,10));
*/
//2 2 2 2
//3 4 3 5

rect R1(pii(2,2),pii(2,2));
rect R2(pii(3,4),pii(3,5));

int isInside(rect A , rect B){
	return A.fi.fi <= B.fi.fi && B.se.fi <= A.se.fi && A.fi.se <= B.fi.se && B.se.se <= A.se.se;
}
int count(rect A){
	pii lo = A.fi , hi = A.se;
	cout << "? " << lo.fi << " " << lo.se << " " << hi.fi << " " << hi.se << '\n';
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
	return isInside(A , R1) + isInside(A , R2);
}
int n;
int f(int flagX , int flagY, int r){
	pii lo(1,1), hi(n,n);
	if(flagX == 1){
		hi.fi = r;
	}else if(flagX == 2){
		lo.fi = n - r + 1;
	}
	
	if(flagY == 1){
		hi.se = r;
	}else if(flagY == 2){
		lo.se = n - r + 1;
	}
	
	return count(rect(lo,hi));
}
vi X , Y;
void insert(int flagX , int flagY , int r){
	if(flagY == 0){
		if(flagX == 1) X.pb(r);
		else X.pb(n - r);
	}else{
		if(flagY == 1) Y.pb(r);
		else Y.pb(n - r);
	}
}
int bSearch(int flagX, int flagY, int target){
	
	int lo = 1 , hi = n;
	if(f(flagX,flagY,lo) >= target) {
		insert(flagX,flagY,lo);
		return lo;
	}
	
	while(hi - lo > 1){
		int med = (lo + hi) >> 1;
		if(f(flagX,flagY,med) >= target) hi = med;
		else lo = med;
	}
	insert(flagX,flagY,hi);
	return hi;
}
void fix(vi &v){
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
}
int Q[5][5][5][5];
int main(){
	while(cin >> n){
		
		bSearch(1,0,1);
		bSearch(1,0,2);
		bSearch(2,0,1);
		bSearch(2,0,2);
		
		bSearch(0,1,1);
		bSearch(0,1,2);
		bSearch(0,2,1);
		bSearch(0,2,2);
		
		fix(X);
		fix(Y);
		
		REP(i2,SZ(X))REP(i1,i2)REP(j2,SZ(Y))REP(j1,j2){
			rect cur = rect(mp(X[i1] + 1,Y[j1] + 1),mp(X[i2],Y[j2]));
			Q[i2][i1][j2][j1] = (count(cur) == 1);
		}
		
		ll mini = LLONG_MAX;
		rect rect1;
		REP(i2,SZ(X))REP(i1,i2)REP(j2,SZ(Y))REP(j1,j2){
			rect cur = rect(mp(X[i1] + 1,Y[j1] + 1),mp(X[i2],Y[j2]));
			if(Q[i2][i1][j2][j1]){
				ll S = (ll)(X[i2] - X[i1] + 2) * (Y[j2] - Y[j1] + 2);
				if(S < mini){
					mini = S;
					rect1 = cur;
				}
			}
		}
		mini = LLONG_MAX;
		rect rect2;
		REP(i2,SZ(X))REP(i1,i2)REP(j2,SZ(Y))REP(j1,j2){
			rect cur = rect(mp(X[i1] + 1,Y[j1] + 1),mp(X[i2],Y[j2]));
			if(Q[i2][i1][j2][j1]){
				ll S = (ll)(X[i2] - X[i1]) * (Y[j2] - Y[j1]);
				if(S < mini && !isInside(cur,rect1)){
					mini = S;
					rect2 = cur;
				}
			}
		}
		
		
		cout << "!";
		cout << " " << rect1.fi.fi << " " << rect1.fi.se << " " << rect1.se.fi << " " << rect1.se.se;
		cout << " " << rect2.fi.fi << " " << rect2.fi.se << " " << rect2.se.fi << " " << rect2.se.se;
		cout << "\n";
		fflush(stdout);
		return 0;
	}
}

