#include <bits/stdc++.h>
using namespace std;
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )
long long n,sx,sy,dx,dy,t;

#define N 6
	
//F[0]=sx-1;F[1]=sy-1;F[2]=dx;F[3]=dy;F[4]=1; F[5]=0;
long long matt[ N ][ N ] = {
	{ 2 , 1 , 1 , 1 , 0 , 0 } ,
	{ 1 , 2 , 1 , 1 , 0 , 0 } ,
	{ 1 , 0 , 1 , 0 , 0 , 0 } ,
	{ 0 , 1 , 0 , 1 , 0 , 0 } ,
	{ 2 , 2 , 2 , 2 , 1 , 1 } ,
	{ 1 , 1 , 1 , 1 , 0 , 1 } ,

};

struct Matrix
{
    long long M[ 6 ][ 6 ];
    Matrix(){
    	REP ( i, 6 ) REP ( j, 6 ) M[i][j] = ( i == j ? 1 : 0 );
    }
	Matrix(int gg){
        REP(i,6)REP(j,6)M[i][j]=matt[ i ][ j ]%n;
    }
    void print(){
        REP( i , N )REP( j , N ) cout << setw(6) << M[i][j] << (j+1==N?"\n":"" );
    }
};
Matrix operator *( const Matrix &A , const Matrix &B )
{
    Matrix Mat;
    REP( i , N )REP( j , N )
    {
        long long sum = 0;
    	REP( k , N ) sum = ( sum + (A.M[i][k]*B.M[k][j]) %n)%n;
        Mat.M[i][j] = sum;
    }
    return Mat;
}
Matrix pow( Matrix A , long long b )
{
    Matrix M;
    //A.print();
    //puts("");
    while( b > 0 )
    {
        if( b%2 == 1 ){
		    M = M*A;
        }
        b /= 2;
        A = A*A;
    }
    //A.print();
    return M;
}


long long F[6];

int main()
{
	
	cin>>n>>sx>>sy>>dx>>dy>>t;
	if(t==0){
		cout<<sx<<" "<<sy<<endl;
		return 0;	
	}
	Matrix Mx=Matrix(1);
	

	F[0]=sx-1;
	F[1]=sy-1;
	F[2]=dx;
	F[3]=dy;
	F[4]=1;
	F[5]=0;
	REP( i , 6 ) F[ i ] = ( F[ i ] %n + n )%n;

	Mx=pow(Mx,t);
	long long sum;
	int ans[2];
	for ( int k = 0; k < 2; ++k ) {
		ans[k] = 0;
		for ( int i = 0; i < N; ++i )
			ans[k] = ( ans[k] + F[i]*Mx.M[i][k] ) % n;
	}
	
	cout<<ans[0]+1<<" "<<ans[1]+1<<endl;
	
}



