#include<bits/stdc++.h>
#define N 1000005

using namespace std;

int B[N];
char s[N];

void process(){
	
	int n = strlen(s);
	B[0] = -1;
	
	for(int i = 1, j = -1; i <= n; i++){
		
		while(j!= -1 && s[i - 1] != s[j])j = B[j];
		B[i] = ++j;
	}
}

int main(){
	
	int m;
	while(scanf("%d%s", &m, s) == 2){
		
		if(m == -1)break;
		int n = strlen(s);
		process();
		
		int b = B[n];
		
		int ans = m/(n - B[n]);
		if(B[n] > m%(n - B[n]))ans--;
		
		printf("%d\n", ans);
	}
	
	
}
