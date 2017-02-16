#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

#define N 55

char s1[N][N], s2[N][N];
int frec[6][N], C[N], ways[N];

bool vis1[N], vis2[N];
vector<char>L[N];

int main(){
	
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		int k;
		scanf("%d", &k);
		
		for(int i = 0; i < 26; i++)L[i].clear();
		memset(C, 0, sizeof C);
		
		memset(frec, 0, sizeof frec);
		
		
		for(int i = 0; i < 6; i++)scanf("%s", s1[i]);
		for(int i = 0; i < 6; i++)scanf("%s", s2[i]);
		
		for(int j = 0; j < 5; j++){
			
			memset(vis1, false, sizeof vis1);
			memset(vis2, false, sizeof vis2);
		
			for(int i = 0; i < 6; i++){
				
				int c1 = s1[i][j] - 'A';
				int c2 = s2[i][j] - 'A';
				
				if(!vis1[c1])frec[j][c1]++, vis1[c1] = true;
				if(!vis2[c2])frec[j][c2]++, vis2[c2] = true;
			}
		}
		
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 26; j++){
				
				if(frec[i][j] >= 2){
					
					L[i].pb(char('A' + j));
					C[i]++;
				}
			}
		}
		/*
		for(int i = 0; i < 5; i++){
			printf("col : %d\n", i);
			for(int j = 0; j < L[i].size(); j++)cout << L[i][j];
			puts("");
		}
		*/
		ways[5] = 1;
		for(int i = 4; i >= 0; i--)ways[i] = ways[i + 1] * C[i];
		
		string res = "";
		for(int i = 0; i < 5; i++){
			
			int aux = 0;	
			for(int j = 0; j < L[i].size(); j++){
				
				if(aux + ways[i + 1] >= k){
					
					k -= aux;
					res += L[i][j];
					//cout << L[i][j];
					break;	
				}
				else aux += ways[i + 1];
			}
			
		}
		
		if(k == 1)cout << res << endl;
		else puts("NO");

	}	 
}



