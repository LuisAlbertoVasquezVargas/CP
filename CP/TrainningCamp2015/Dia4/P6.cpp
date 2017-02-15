#include<bits/stdc++.h>

using namespace std;

const int MAXPOS = 2900;
const int MAXL = 32;

string a , b;
long double memo[MAXPOS + 5][MAXL][MAXL];
int B[2][35];

void process(string &s, int id){
	
	B[id][0] = -1;
	for(int i = 1, j = -1; i <= s.size(); i++){
			
		while(j != -1 && s[j] != s[i - 1])j = B[id][j];
		B[id][i] = ++j;
		
		if(j == s.size())j = B[id][j];
	}
}

long double f(int pos, int pa, int pb){
  if( pa == a.size() ) return 1.0;
  if( pos == MAXPOS )return 0.0;
  if( pb == b.size())return 0.0;
  
  if( memo[pos][pa][pb] > -0.5)
    return memo[pos][pa][pb];
  long double ans = 0.0;
  int pa0= pa,pa1=pa,pb0=pb,pb1=pb;
  while( pa0 != -1 && '0' != a[pa0]) pa0 = B[0][pa0];
  pa0++;
  while( pa1 != -1 && '1' != a[pa1]) pa1 = B[0][pa1];
  pa1++;
  while( pb0 != -1 && '0' != b[pb0]) pb0 = B[1][pb0];
  pb0++;
  while( pb1 != -1 && '1' != b[pb1]) pb1 = B[1][pb1];
  pb1++;
  
  ans += 0.5 * f(pos+1,pa0,pb0);
  ans += 0.5* f(pos+1,pa1,pb1);
  
  return memo[pos][pa][pb] = ans;
}


int main(){
  	while( cin>>a>>b ){
  	  
	  if( a == "0" && b == "0" )break;
	  process(a,0); process(b,1);
	  for(int i=0; i < MAXPOS; ++i)
	    for(int j=0; j <= a.size(); ++j)
		  for(int r =0; r<= b.size(); ++r)
		    memo[i][j][r] = -1.0;
		
	  long double ans = f(0,0,0);
	  printf("%.3Lf\n", ans); 
	}
}
