// O( nlogn ) time , O( n ) memory
// by Chen

int LIS( vi &a ){
	vi b;
	for( auto x : a ){
		int j = upper_bound( all( b ) , x ) - b.begin();
		// (lower) a < b < c 
		// (upper) a <= b <= c 
		if( j == SZ(b) ) b.pb( x );
		else b[ j ] = x;
	}
	return SZ(b);
}
