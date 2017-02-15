#include <bits/stdc++.h>
#define N 405

using namespace std;

char T[N][N];
int n, m;

void opera(int fil, int col){

	for(int i = 0; i <= col; i++)T[fil][i] = char('0' + 1 - (T[fil][i] - '0'));
	for(int i = fil + 1; i < n; i++)T[i][col] = char('0' + 1 - (T[i][col] - '0'));	
}

int main(){
	
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)scanf("%s", T[i]);
		
		int ans = 0, fil = 0, col = m - 1;
		while(fil < n && col >= 0){
		
			for(int i = col; i >= 0; i--)if(T[fil][i] == '0')opera(fil, i), ans++;	
			for(int i = fil + 1; i < n; i++)if(T[i][col] == '0')opera(i, col), ans++;
			fil++;
			col--;
		}
		
		printf("%d\n", ans);
	}
	
}
