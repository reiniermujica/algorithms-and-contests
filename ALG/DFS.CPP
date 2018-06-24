void dfs( int x ) {
	 mark[x] = true;
	 for ( i = 1; i <= N; i++ )
		if ( !mark[i] ) dfs( i );
}

int main() {

	return 0;
}
