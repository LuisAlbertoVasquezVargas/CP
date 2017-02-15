#include<bits/stdc++.h>

using namespace std;

#define MAXN 100410

long long A[MAXN],B[MAXN];
int N,M;
int tc=0;

int main(){
	while(scanf("%d%d",&N,&M)==2){
		for(int i=0;i<N;i++)
			scanf("%lld",&A[i]);
		for(int i=0;i<M;i++)
			scanf("%lld",&B[i]);
		sort(A,A+N);
		sort(B,B+M);
		int caso=0;
		int ap=N-1,bp=M-1;
		while(ap>=0&&bp>=0){
			if(!caso){
				if(A[ap]>B[bp]&&(bp<3||ap<1||((B[bp-1]+B[bp-2]+B[bp-3])<A[ap]+A[ap-1])))bp--;
				else{
					if(ap>0)A[ap-1]=A[ap-1]+A[ap];
					ap--;
				}
			}
			else{
				if(B[bp]>A[ap]&&(ap<3||bp<1||((A[ap-1]+A[ap-2]+A[ap-3])<B[bp]+B[bp-1])))ap--;
				else{
					if(bp>0)B[bp-1]=B[bp-1]+B[bp];
					bp--;
				}
			}
			caso=!caso;
		}
		if(bp<0)printf("Case %d: Takeover Incorporated\n",++tc);
		else printf("Case %d: Buyout Limited\n",++tc);
	}
}
