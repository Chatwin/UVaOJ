#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node {
	char s[55];
	int  v,id;
}node;
node D[105];

int calc( node a ) {
	int count = 0;
	for ( int i = 0 ; a.s[i] ; ++ i )
		for ( int j = 0 ; j < i ; ++ j )
			if ( a.s[j] > a.s[i] )
				count ++;
	return count;
}

bool cmp( node a, node b ) {
	return (a.v==b.v)?(a.id<b.id):(a.v<b.v);
}

int main() {
	int M,n,m;
	while ( cin >> M )
	while ( M -- ) {
		cin >> n >> m;
		for ( int i = 0 ; i < m ; ++ i ) {
			cin >> D[i].s;
			D[i].v = calc( D[i] );
			D[i].id = i;
		}

		sort( D, D+m, cmp );
		for ( int i = 0 ; i < m ; ++ i )
			cout << D[i].s << endl;
		if ( M ) cout << endl;;
	}
	return 0;
}
