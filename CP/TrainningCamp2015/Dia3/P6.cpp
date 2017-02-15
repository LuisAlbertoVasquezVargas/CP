#include<bits/stdc++.h>

using namespace std;

const long long INF = (1LL<<62);

#define eps 1e-9
#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())



const int MAXN = 32;
const int MAXW = 99;

int n;
long long H ,S;
long long a[MAXN] , w[MAXN];

vector<long long> A[MAXW], B[MAXW];

long long getUpper( vector<long long> &v , long long x ){
	return upper_bound( all( v ) , x ) - v.begin();
}
long long getLower( vector<long long> &v , long long x ){
	int pos = lower_bound( all( v ) , x ) - v.begin();
	if( binary_search( all( v ) , x ) ) return pos;
	return pos - 1;
}

long long getX(vector<long long> &v, long long x){
  long long a  = -INF , b = -INF ;
  if(getLower(v,x) != -1){
    a = v[getLower(v,x)];
  }
  if(getUpper(v,x) != v.size()){
    b = v[getUpper(v,x)];
  }
  if( abs(a-x) <= abs(b-x))
    return a;
  return b;
}


int main(){
  while( scanf("%d%lld%lld",&n,&H,&S) == 3){
  	for(int i=0;i <=90;++i)
  	  A[i].clear(),B[i].clear();
    for(int i=0; i<n; ++i)
	  scanf("%lld%lld",&a[i],&w[i]);
	double ansH = INF, ansS = INF;
	long long suma = 0 ;
	int peso = 0;
	
	for(int i=1; i<(1<<(n/2));++i){
	  suma = 0 , peso = 0;
	  for(int j=0; j<n/2; ++j){
	    if((i>>j)&1){
	      suma += a[j]*w[j];
	      peso += w[j];
		}
	  }
	  A[peso].push_back(suma);
	  ansH = min(ansH , abs(1.0*H - 1.0*suma/peso));
	  ansS = min(ansS , abs(1.0*S - 1.0*suma/peso));
	}
	
	for(int i=1; i<(1<<(n/2 + n%2));++i){
		suma = 0 , peso = 0;
		for(int j=0; j<n/2+n%2; ++j){
		  if(( i >> j)&1){
		    suma += a[n/2+j]*w[n/2+j];
		    peso += w[n/2+j];
		  }
		}
		B[peso].push_back(suma);
	  ansH = min(ansH , abs(1.0*H - 1.0*suma/peso));
	  ansS = min(ansS , abs(1.0*S - 1.0*suma/peso));
	}
    
    for(int i=1; i<=45; ++i){
	  sort(A[i].begin(), A[i].end());  	
      sort(B[i].begin(), B[i].end());
	}
	long long NH , NS , NNH, NNS;
	for(int i=1;i<=45;++i){
	  for(int j=1;j<=45;++j){
        NH = (i+j)*H , NS = (i+j)*S;
        for(int r=0;r<A[i].size(); ++r){
          NNH = NH - A[i][r];
          
          NNS = NS - A[i][r];
		  if(B[j].size() != 0){
			  long long NNNH  = getX(B[j],NNH);
		      long long NNNS  = getX(B[j],NNS);
		     
		      ansH = min(ansH , 1.0*abs((A[i][r]+NNNH)/(i+j)-H));
			  ansS = min(ansS , 1.0*abs((A[i][r]+NNNS)/(i+j)-S));
		  }
		}
	  }
	}
	
	
	if( abs(ansH-ansS) < eps ){
	  puts("Tie");
	}
	else{
	  if(ansH < ansS )
	    puts("Hawks");
	  else puts("Swans");
	}
	
  }
}
