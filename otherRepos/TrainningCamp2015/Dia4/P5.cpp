#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100500;

vector<int>primes;
int p[2*MAXN ];

void sieve(){
  memset(p,0,sizeof(p));
  for(int i=2; i*i <= MAXN; ++i)
    if( !p[i])
      for(int j=i*i; j<=MAXN; j+=i)
        p[j] = i;
  for(int i=2; i<=MAXN; ++i)
    if(p[i] == 0)
      primes.push_back(i);
}

int getX(int p , int num){
  int ret = 0;
  while( num > 0){
    ret += num/p;
    num /= p;
  }
  return ret;
}

int main(){
  int N , C, A;
  cin>>C;
  sieve();
  while( C-- ){
    scanf("%d",&N);
    long long ans1 = 0 , ans2 = 0;
	for(int i=0; i<primes.size(); ++i){
      
	  A = getX(primes[i],N);
      if( A != 0 )ans1++;
      ans2 = ans2 + 1LL*A;
	}
	printf("%lld %lld\n",ans1,ans2);
  }
}
