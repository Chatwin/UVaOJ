/* 三维map上的 搜索， BFS水过*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int map[100][100][100];
int vis[100][100][100];
int dis[100][100][100];
int h, m, n;
int d[6][3] = {	{-1,0,0}, {1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
struct queue
{
	int h, x, y;
};
struct queue u, v, q[30000];
void bfs( int w, int x, int y )
{
		int front, rear, nh, nx, ny, i;
		front = rear = 0;
		vis[w][x][y] = 1;
		dis[w][x][y] = 0;
		u.h = w; u.x = x; u.y = y;
		q[front++] = u;
		while( front > rear )
		{
			u = q[rear++];
			w = u.h; x = u.x; y = u.y;
			for( i = 0; i < 6; i++ )
			{
				nh = w + d[i][0];
				nx = x + d[i][1];
				ny = y + d[i][2];
				if( nh >= 0 && nh <= h && nx >= 0 && nx <= m && ny >= 0 && ny <= n && !vis[nh][nx][ny] && map[nh][nx][ny] )
				{
					v.h = nh; v.x = nx; v.y = ny;
					q[front++] = v;
					vis[nh][nx][ny] = 1;
					dis[nh][nx][ny] = dis[w][x][y]+1;
				}
			}
		}
}
int main()
{
	char temp;
	int i, j, k, h_start, m_start, n_start, h_end, m_end, n_end;
	while( scanf( "%d%d%d\n", &h, &m, &n )!=EOF && h && m && n )
	{
		memset( dis, -1, sizeof(dis) );
		memset( map, 0, sizeof(map) );
		memset( vis, 0, sizeof(vis) );
		for( i = 0; i < h; i++ )
		{
			for( j = 0; j < m; j++ )
			{
				for( k = 0; k < n; k++ )
				{
					scanf( "%c", &temp );
					if( temp == 'S' )
					{
						h_start = i;
						m_start = j;
						n_start = k;
						map[i][j][k] = 1;
					}
					if( temp == 'E' )
					{
						h_end = i;
						m_end = j;
						n_end = k;
						map[i][j][k] = 1;
					}
					if( temp == '.' )
						map[i][j][k] = 1;
				}
				scanf( "\n" );
			}
			scanf( "\n" );
		}
		bfs( h_start, m_start, n_start );
		if( dis[h_end][m_end][n_end] == -1 )
			printf( "Trapped!\n" );
		else
			printf( "Escaped in %d minute(s).\n", dis[h_end][m_end][n_end] );

	}
	return 0;
}
