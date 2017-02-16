#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define v1 ((node<<1) + 1)
#define v2 (v1+1)
#define mid ((a+b)>>1)
#define LEFT v1,a,mid
#define RIGHT v2,mid+1,b

typedef long long ll;

const int N = 1e5;
const int MOD = (int)(1e9) + 7;
const int TAM = 2;

int A[N + 5];
struct Matrix{
	int M[2][2];
	Matrix(){//get Zero
		M[0][1] = M[1][0] = 0;
		M[0][0] = M[1][1] = 0;
	}
	Matrix(int x){
		if(x == 1){//get Identity
			M[0][1] = M[1][0] = 0;
			M[0][0] = M[1][1] = 1;
		}
		if(x == 2){//get fibo(1)
			M[0][0] = M[0][1] = M[1][0] = 1;
			M[1][1] = 0;
		}
	}
};
Matrix operator +(const Matrix &A, const Matrix &B){
	Matrix C;
	REP(i,TAM)REP(j,TAM){
		C.M[i][j] = A.M[i][j] + B.M[i][j];
		if(C.M[i][j] >= MOD) C.M[i][j] -= MOD;
	}
	return C;
}
Matrix operator *(const Matrix &A, const Matrix &B){
	Matrix C;
	REP(i,TAM)REP(j,TAM){
		ll cur = 0;
		REP(k,TAM){
			ll prod = (ll)A.M[i][k] * (ll)B.M[k][j];
			cur += prod;
		}
		if(cur >= MOD)cur %= MOD;
		C.M[i][j] = cur;
	}
	return C;
}
Matrix pow(Matrix A,int b){
	Matrix ans(1);
	while(b){
		if(b&1) ans = ans * A;
		A = A * A;
		b >>= 1;
	}
	return ans;
}
struct Node{
	Matrix sum;
	Matrix prod;
	bool flag;
	Matrix flagMat;
	Node(){
		sum = Matrix();
		prod = Matrix(1);
		flag = 0;
		flagMat = Matrix(1);
	}
	Node(int x){
		Matrix F(2);
		F = pow(F,x);
		sum = prod = F;
		flag = 0;
		flagMat = Matrix(1);
		//get matrix with fibonacci(x)
	}
}T[4 * N + 5];
Node operator +(const Node &A,const Node &B){
	Node C;
	C.flag = 0;
	C.flagMat = Matrix(1);
	C.sum = A.sum + B.sum;
	C.prod = A.prod * B.prod;
	return C;
}
void build(int node, int a , int b){
	if(a == b){
		T[node] = Node(A[a]);
		return;
	}
	build(LEFT);
	build(RIGHT);
	T[node] = T[v1] + T[v2];
}
void push(int node,int a,int b){
	if(T[node].flag){
		T[node].prod = T[node].prod * pow(T[node].flagMat,b - a + 1);
		T[node].sum = T[node].sum * T[node].flagMat;
		if(a != b){
			T[v1].flag = T[v2].flag = 1;
			T[v1].flagMat = T[v1].flagMat * T[node].flagMat;
			T[v2].flagMat = T[v2].flagMat * T[node].flagMat;
		}
		T[node].flag = 0;
		T[node].flagMat = Matrix(1);
	}
}
Node get(int node,int a, int b,int lo, int hi){
	push(node,a,b);
	if(a > hi || lo > b) return Node();
	if(lo <= a && b <= hi) return T[node];
	return get(LEFT,lo,hi) + get(RIGHT,lo,hi);
}
void update(int node,int a , int b, int lo , int hi, Matrix &val){
	push(node,a,b);
	if(a > hi || lo > b) return;
	if(lo <= a && b <= hi) {
		T[node].flag = 1;
		T[node].flagMat = val;
		push(node,a,b);
		return;
	}
	update(LEFT,lo,hi,val);
	update(RIGHT,lo,hi,val);
	T[node] = T[v1] + T[v2];
}
int main(){
	int n,m;
	while(scanf("%d%d" , &n,&m) == 2){
		REP(i,n) scanf("%d" , &A[i]);
		build(0,0,n-1);
		
		REP(i,m){
			int type,L,R,X;
			scanf("%d%d%d",&type,&L,&R);
			L--,R--;
			if(type==1) scanf("%d",&X);
			
			if(type==1){
				//add +x from L to R
				Matrix F(2);
				F = pow(F,X);
				update(0,0,n-1,L,R,F);
				//puts("");
			}else{
				//get sum from L to R
				Node q=get(0,0,n-1,L,R);
				printf("%d\n",q.sum.M[0][1]);
			}
		}
	}
}
