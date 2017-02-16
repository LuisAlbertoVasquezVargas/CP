#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000000005;

set<int>s;
map<int,bool>M;
int n,k,x;

int main(){
	cin>>n>>k;
	for(int i=0; i<n; ++i){
	  cin>>x;
	  M[x] = 1;
	  if(k != 1)while(x%k == 0)x/=k;
	  s.insert(x);
	  
	}
	if( k == 1){
	  cout<<n<<endl;
	  return 0;	
	}
	long long ax = 0;
	int ans = 0;	
	for( set<int>::iterator it = s.begin(); it != s.end(); ++it){
	  ax = *it;
	  int ct = 0;
	  while( ax < MAXN ){
	    
		if( M[ax] == 1){
	      ct++;
		}
	    else{
	      ans = ans + ct/2 + ct%2;
	      ct = 0;	
	    }
	    ax *= k;
	    
      }
      ans = ans + ct/2 + ct%2;
	}
	cout<<ans<<"\n";
}
