#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF (1<<30)

#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

#define cout2(x, y) cout << x << " " << y << " " << endl

long double f1[N], f2[N], res[N]; 
char op[N][2];
int t[N];

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < 2 * n; i++)f1[i] = f2[i] = INF;
	
	int ct = 0, top = 0, temp;
	long double prod = 1;
	
	for(int i = 0; i < 2 * n; i++){
		
		scanf("%s %d", op[i], &temp);
		if(op[i][0] == '+')ct++, t[top++] = temp;
		else{
			
			if(ct == 0)f2[i] = 1.0;
			else f2[i] = prod/ct, prod *= (1 - 1.0/(1.0 * ct));
			
			ct--;	
			f1[i] = temp * f2[i];
			printf("%Lf %Lf\n", f1[i], f2[i]);
		}
		
	}
	
	ct = n;
	long double ac1 = 0, ac2 = 0;
	for(int i = 2 * n - 1; i >= 0; i--){
		
		if(op[i][0] == '-'){
			
			ac1 += f1[i], ac2 += f2[i];
			cout << ac1 << " " <<  ac2 << endl;
		}
		else{
			
			res[ct - 1] = ac1 - ac2 * t[ct - 1];
			ct--;
			
		}	
	}
	
	for(int i = 0; i < n; i++)printf("%.6lf\n", double(res[i]));
}
