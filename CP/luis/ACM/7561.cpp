#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0 ; i <n ; ++i)

string f( map< string , int > &mapa ){
	string L;
	while( 1 ){
		if( mapa[ "aa" ] >= 2 ){
			L += "aa";
			mapa[ "aa" ] -= 2;
			continue;
		}
		if( mapa[ "aa" ] == 1 ){
			if( (mapa[ "ab" ] && mapa[ "ba" ]) || mapa[ "bb" ] >= 2 ){
				//
			}else{
				L += "a";
				break;
			}
			mapa[ "aa" ] = 0;
			continue;
		}
		if( mapa[ "ab" ] && mapa[ "ba" ] ){
			L += "ab";
			mapa[ "ab" ] --;
			mapa[ "ba" ] --;
			continue;
		}
		REP( it , mapa[ "bb" ] ) L += "b";
		mapa[ "bb" ] = 0;
		break;
		//aa ab bb ba aa
		//aa bb (ab , ba)
	}
	string R = L;
	reverse( R.begin() , R.end() );
	string ans = L + R;
	return ans;
}
string inv( string s ){
	REP( i , s.size() ) s[ i ] = (s[ i ] == 'a' ? 'b' : 'a');
	return s;
}
int main(){
	char cad[ 10 ];
	int cases;
	scanf( "%d" , &cases );
	REP( tc , cases ){
		int n;
		scanf( "%d" , &n );
		map< string , int > mapa;
		REP( i , n ){
			scanf( "%s" , cad );
			string str(cad , cad + 2);
			mapa[ str ] ++;
		}
		string L , R;
		while( 1 ){
			if( mapa[ "aa" ] >= 2 ){
				mapa[ "aa" ] -= 2;
				L += "aa";
				continue;
			}
			if( mapa[ "ab" ] && mapa[ "ba" ] ){
				mapa[ "ab" ] -- , mapa[ "ba" ] --;
				L += "ab";
				continue;
			}
			if( mapa[ "bb" ] >= 2 ){
				mapa[ "bb" ] -= 2;
				L += "bb";
				continue;
			}
			if( mapa[ "aa" ] ){
				L += "a";
				break;
			}
			if( mapa[ "bb" ] ){
				L += "b";
				break;
			}
			break;
		}
		R = L;
		reverse( R.begin() , R.end() );
		string ans = L + R;
		printf( "%s\n" , ans.c_str() );
	}
}


