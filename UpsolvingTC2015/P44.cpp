#include<bits/stdc++.h>

using namespace std;

int main(){
  int T , n , x;
  scanf("%d",&T);
  while( T-- ){
    scanf("%d",&n);
    int ans = 0;
	for(int i=0; i<n; ++i){
    	scanf("%d",&x);
    	ans = __gcd(x,ans);
    }
    cout<<ans<<"\n";
  }
}
