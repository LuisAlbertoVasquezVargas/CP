#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for( int i = 1 ; i <= n ; i++ ) 
	{
		int a,b,c;          
		cin >> a >> b >> c;        
		// Sea Y el numero  buscado y X,Z (X<Z)  los otros numeros se cumple que X < Y < Z
		//
		if( ( a < b && b < c ) || ( c < b && b < a ) )
			cout << "Case " << i << ": " << b << endl;
		else if( ( b < a && a < c ) || ( c < a && a  < b ) )
			cout << "Case " << i << ": " << a << endl;
		else cout << "Case " << i << ": " << c << endl;
	}
}
