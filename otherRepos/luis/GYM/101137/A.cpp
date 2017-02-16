#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF (1<<30)

int a[N], b[N];
#define cout2(x, y) cout << x << " " << y << " " << endl

int n;

bool isCrec(){
	
	sort(b, b + n);
	for(int i = 0; i < n; i++)if(a[i] != b[i])return false;	
	return true;
}
bool isDec(){
	
	sort(b, b + n);
	for(int i = 0; i < n; i++)if(a[i] != b[n - i])return false;	
	return true;
}

int main(){
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)scanf("%d", &a[i]), b[i] = a[i];
	
	if(isCrec())printf("%d %d %d\n", n - 1, n, 1);
	else if(isDec())printf("%d %d %d\n", n, 1, 2);
	else{
	
		for(int i = 0; i < n; i++){
			if(a[i] < a[(i + 1)%n] && a[(i + 1)%n] > a[(i + 2)%n]){
				
				printf("%d %d %d\n", i + 1, (i + 1)%n + 1, (i + 2)%n + 1);
				return 0;
			}
		}
		printf("%d %d %d\n", n - 1, n, 1);
	}
}
