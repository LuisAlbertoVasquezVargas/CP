#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>
using namespace std;

#define REP(i, n) for(int i = 0; i < n ; ++i)

const int N = 100000;
long long A[ N + 5 ] , B[ N + 5 ] , rB[ N + 5 ];
int n;
bool f( long long t ){
	REP(i , n){
		int p = -1 , cnt;
		if(A[ i ] > 0){
			p = upper_bound(B , B + n , t/A[ i ]) - B;
			cnt = n - i;
		}else if(A[ i ] == 0){
			if(t < 0) return 0;
			else continue;
		}else{
			//cout << -t/A[ i ] << " ";
			p = upper_bound(rB , rB + n , -t/A[ i ]) - rB;
			cnt = i + 1;
		}
		if(p >= cnt) continue;
		return 0;
	}
	return 1;
}
int main(){
	while( scanf( "%d" , &n ) == 1 ){
		REP(i , n){
			int x;
			scanf("%d" , &x);
			A[ i ] = x;
		}
		REP(i , n){
			int x;
			scanf("%d" , &x);
			B[ i ] = x;
		}
		sort(A , A + n);
		sort(B , B + n);
		REP(i , n) rB[ i ] = -B[n - 1 - i];
		long long tope = 2*(1e18);
		tope += 10;
		long long lo = -tope , hi = +tope;
		/*
		for(int k = lo ; k <= hi ; ++k) cout << f(k) << " ";
		cout << endl;
		*/
		/*
		cout << f(5) << endl;
		continue;
		*/
		//cout << f(lo) << " " << f(hi) << endl;
		while(hi - lo > 1){
			long long med = (lo + hi) >> 1;
			if( f(med) ) hi = med;
			else lo = med;
		}
		printf( "%lld\n" , hi );
	}
}

