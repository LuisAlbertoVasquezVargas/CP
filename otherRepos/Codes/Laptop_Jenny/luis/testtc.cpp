#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int K , A , B , C , D;
	while( cin >> K >> A >> B >> C >> D )
	{
		vector< ll > X( K );
		X[ 0 ] = A;
		int cntZero = 0;
		ll ans = 0;
		int maxMod = 0;
		for( int i = 1 ; i < K ; ++i ){
			X[ i ] = ( X[ i - 1 ] *B + C )%D + 1;
			ans += (X[ i ]/K);
			maxMod = max( maxMod , (int)X[ i ] % K );
			if( X[ i ] % K == 0 ) cntZero ++;
		}
		cout << cntZero << endl;
		cout << ans << endl;
		cout << ans + min( K - cntZero , maxMod )<< '\n';
	}
}
