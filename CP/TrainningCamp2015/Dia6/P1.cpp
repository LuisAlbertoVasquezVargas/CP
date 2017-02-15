#include <bits/stdc++.h>
using namespace std;

int T;
int n , m , A[128][128];

int main(){
  scanf("%d",&T);
  while( T-- ){
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i)
      for(int j=0; j<m; ++j)
        scanf("%d",&A[i][j]);
    int ans = 0;
    
    for(int j=0; j<m; ++j){
      int tot = 0;
	  for(int i=n-1; i>=0; --i){
        if( A[i][j] == 1){
          ans = ans + (n-1-i-tot);
		  tot++;
		}
      }
	}
    cout<<ans<<"\n";
  }
}

