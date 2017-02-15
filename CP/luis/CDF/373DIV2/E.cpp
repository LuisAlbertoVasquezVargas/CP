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
	/*
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
	*/
	int M00,M01,M10,M11;
	Matrix(){//get Zero
		M01 = M10 = 0;
		M00 = M11 = 0;
	}
	Matrix(int x){
		if(x == 1){//get Identity
			M01 = M10 = 0;
			M00 = M11 = 1;
		}
		if(x == 2){//get fibo(1)
			M00 = M01 = M10 = 1;
			M11 = 0;
		}
	}
	
};
inline void sumMod(int a,int b,int &c){
	c = a + b;
	if(c >= MOD) c-= MOD;
}
Matrix operator +(const Matrix &A, const Matrix &B){
	Matrix C;
	sumMod(A.M00,B.M00,C.M00);
	sumMod(A.M01,B.M01,C.M01);
	sumMod(A.M10,B.M10,C.M10);
	sumMod(A.M11,B.M11,C.M11);
	return C;
}
Matrix operator *(const Matrix &A, const Matrix &B){
	Matrix C;
	ll prod;
	
	prod = (ll)A.M00 * (ll)B.M00;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M00,prod,C.M00);
	
	prod = (ll)A.M01 * (ll)B.M10;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M00,prod,C.M00);

	prod = (ll)A.M00 * (ll)B.M01;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M01,prod,C.M01);
	
	prod = (ll)A.M01 * (ll)B.M11;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M01,prod,C.M01);

	prod = (ll)A.M10 * (ll)B.M00;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M10,prod,C.M10);
	
	prod = (ll)A.M11 * (ll)B.M10;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M10,prod,C.M10);
	
	prod = (ll)A.M10 * (ll)B.M01;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M11,prod,C.M11);
	
	prod = (ll)A.M11 * (ll)B.M11;
	if(prod >= MOD)prod %= MOD;
	sumMod(C.M11,prod,C.M11);
	
	return C;
}
Matrix pow(Matrix A,ll b){
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
	ll flag;
	Node(){
		sum = Matrix();
		prod = Matrix(1);
		flag = 0;
	}
	Node(int x){
		Matrix F(2);
		F = pow(F,x);
		sum = prod = F;
		flag = 0;
		//get matrix with fibonacci(x)
	}
}T[4 * N + 5];
Node operator +(const Node &A,const Node &B){
	Node C;
	C.flag = 0;
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
//2000000016
inline void push(int node,int a,int b){
	if(T[node].flag){
		Matrix F(2);
		//F = pow(F,T[node].flag);
		T[node].prod = T[node].prod * pow(F,(T[node].flag *(ll)(b - a + 1))%2000000016);
		T[node].sum = T[node].sum * pow(F,T[node].flag);
		if(a != b){
			T[v1].flag += T[node].flag;
			T[v2].flag += T[node].flag;
			
			T[v1].flag %= 2000000016;
			T[v2].flag %= 2000000016;
		}
		T[node].flag = 0;
	}
}
Node get(int node,int a, int b,int lo, int hi){
	push(node,a,b);
	if(a > hi || lo > b) return Node();
	if(lo <= a && b <= hi) return T[node];
	return get(LEFT,lo,hi) + get(RIGHT,lo,hi);
}
void update(int node,int a , int b, int lo , int hi, ll val){
	push(node,a,b);
	if(a > hi || lo > b) return;
	if(lo <= a && b <= hi) {
		T[node].flag = val;
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
				/*
				Matrix F(2);
				F = pow(F,X);
				*/
				update(0,0,n-1,L,R,X);
				//puts("");
			}else{
				//get sum from L to R
				Node q=get(0,0,n-1,L,R);
				printf("%d\n",q.sum.M01);
			}
		}
	}
}


