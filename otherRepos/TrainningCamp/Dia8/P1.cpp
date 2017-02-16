#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3048;

int n , x;
int A[2*MAXN];

int main(){
  scanf("%d",&n);
  memset(A,0,sizeof(A));
  for(int i=0; i<n; ++i){
    scanf("%d",&x);
	A[x]++;
  }
  int ans = 0;
  
  for(int i=1; i<=n; ++i){
    if(A[i] > 1){
      for(int j=i+1;j<=2*n+5;++j){
        if(A[j] == 0){
          A[j]++;
          A[i]--;
          ans += (j-i);
          if(A[i] == 1)break;
		}
	  }
	}
  }
  cout<<ans<<"\n";  
  
}

