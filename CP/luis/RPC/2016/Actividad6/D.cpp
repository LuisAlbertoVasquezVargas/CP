#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define N 105

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int>Q[N * N];
bool vis[N][N];
int deep[N][N];

char T[N][N];

string toString(int num, int len){

	string ans = "";
	while(num > 0)ans += char('0' + num%10), num /= 10;
	int n = ans.size();
	for(int i = 0; i < len - n; i++)ans += '.';
	reverse(all(ans));
	return ans;

}
int main(){
	
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
	
		for(int i = 1; i <= n; i++)
			scanf("%s", T[i] + 1);
			
		for(int i = 0; i <= n + 1; i++)T[i][0] = T[i][m + 1] = '.';
		for(int i = 0; i <= m + 1; i++)T[0][i] = T[n + 1][i] = '.';
		

		int tail = 0, head = 0;
		
		for(int i = 0; i <= n + 1; i++){
			for(int j = 0; j <= m + 1; j++){
				deep[i][j] = vis[i][j] = 0;
				if(T[i][j] == '.')vis[i][j] = true, Q[tail++] = make_pair(i, j);
			}
		}
		
		int d, fil, col, maxi = 0;
		pair<int, int>u, v;
		
		while(tail > head){
		
			u = Q[head++];
			for(int i = 0; i < 4; i++){
				
				fil = u.first + dx[i];
				col = u.second + dy[i];
				v = make_pair(fil, col);
				
				if(fil >= 1 && fil <= n && col >= 1 && col <= m && !vis[fil][col] ){
					
					Q[tail++] = v;
					deep[fil][col] = deep[u.first][u.second] + 1;
					maxi = max(maxi, deep[fil][col]);
					vis[fil][col] = true;
				}
			}
		}
		
		string res;
		if(maxi < 10){
		
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					
					res = toString(deep[i][j], 2);
					printf("%s", res.c_str());
				}
				puts("");
			}
		
		}
		else{
			
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					
					res = toString(deep[i][j], 3);
					printf("%s", res.c_str());
				}
				puts("");
			}
		}
	}

}
