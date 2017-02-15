#include<cstdio>

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

const int N = 30000;
int A[N + 5];

int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n;
		scanf("%d" , &n);
		REP(i , n) scanf("%d" , &A[ i ]);
		int dir = 0 , ans = 1;//0 > , 1 <
		int last = A[ 0 ];
		for(int i = 1 ; i < n ; ++i){
			int ind;
			int cond = (last < A[ i ]);
			for(int j = i ; j < n ; ++j)
				if( (!cond) ^ (A[j - 1] < A[ j ]) ){
					ind = j;
				}else break;
			if( (last > A[ind]) ^ dir ){
				dir ^= 1;
				ans ++;
			}
			last = A[ ind ];
			i = ind;
		}
		printf("%d\n" , ans);
	}
}




