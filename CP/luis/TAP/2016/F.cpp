#include <bits/stdc++.h>
using namespace std;

#define all(v)  v.begin() , v.end()
#define pb push_back

#define N 1005

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

char s[N];
int frec[4];

int main(){

	int F;
	while(scanf("%d", &F) == 1){
		
		int n, ans = 0;
		memset(frec, 0, sizeof frec);
		//RD   DR   DD   RR
		for(int i = 0; i < F; i++){
			
			scanf("%s", s);
			n = strlen(s);
			
			int ct = 0, p1 = -1, p2 = -1;
			char car = 'D';
			
			for(int j = 0; j < n; j++){
				
				if(s[j] == car){
					
					if(car == 'D' && p1 == -1)p1 = j;	
					if(car == 'R')p2 = j;
					
					if(car == 'D')car = 'R';
					else car = 'D';
					ct++;
				}
			}
			
			int type = -1;
			if(ct == 0){
				
				p1 = -1; p2 = -1;
				for(int j = 0; j < n; j++)if(s[j] == 'R' && p1 == -1)p1 = j; 
				for(int j = n - 1; j >= 0; j--)if(s[j] == 'D' && p2 == -1)p2 = j;
				
				if(p1 != -1 && p2 != -1)type = 0;
				else if(p1 != -1)type = 3;
				else if(p2 != -1)type = 2;
			}
			else{
				
				ans += ct/2;

				bool foundR = false, foundD = false; 
				for(int j = 0; j < p1; j++)if(s[j] == 'R')foundR = true;
				
				if(ct%2 == 0){
					for(int j = p2 + 1; j < n; j++)if(s[j] == 'D')foundD = true;
				}
				else foundD = true;
				
				if(foundR && foundD)type = 0;
				else{
					
					if(foundR)type = 3;
					else if(foundD)type = 2;	
				}
			}
			if(type >= 0)frec[type]++;
		}
		
	
		int mini = min(min(frec[0], frec[2]), frec[3]);
		ans += 2 * mini;
		
		frec[0] -= mini;
		frec[3] -= mini;
		frec[2] -= mini;
		
		if(frec[2] > 0 && frec[0] > 0)ans += min(frec[2], frec[0]);
		if(frec[0] > 0 && frec[3] > 0)ans += min(frec[3], frec[0]);
		if(frec[2] > 0 && frec[3] > 0)ans += min(frec[2], frec[3]);
		
		printf("%d\n", ans);
	}
}


