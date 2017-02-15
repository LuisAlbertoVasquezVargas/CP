#include<bits/stdc++.h>

using namespace std;


#define all(v)  v.begin() , v.end()

const int MAXN = 128;

int N;
long long a, b, c, d, e, f; 
int S[MAXN];

vector<long long> A , B;

int main(){
  scanf("%d",&N);
  for(int i=0; i<N; ++i)
    scanf("%d",&S[i]);
  A.clear();
  B.clear();
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
	  for(int r=0; r<N; ++r){
	    a = S[i]; f = S[i];
	    b = S[j]; e = S[j];
	    c = S[r]; d = S[r];
	    A.push_back(1LL*a*b + 1LL*c);
	    if( d != 0 )B.push_back(((f+e)*d));
	  }
	}
  }
  sort(A.begin() , A.end());
  sort(B.begin() , B.end());
  long long ans = 0LL;
  int p1 , p2 ;
  for(int i = 0; i < A.size(); ++i){
	ans += upper_bound(all(B) , A[i]) - lower_bound(all(B) , A[i]);
  }
  
  cout<<ans<<"\n";
  
}
