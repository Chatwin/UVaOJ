#include <iostream>
#include <string>
#include <cstring>
using namespace std ;

const int maxn = 1000 + 10 ;

int r , c ;
int qfront ;
int team[maxn] ;
int Queue[maxn][maxn] ;
int visit[maxn] ;
int map[maxn * maxn] ;
int rear[maxn] ;
int front[maxn] ;

void init()
{
    r = 0 ; qfront = 0 ;
    memset( team , 0 , sizeof( team ) ) ;
    memset( Queue , 0 , sizeof( Queue ) ) ;
    memset( map , 0 , sizeof( map ) ) ;
    memset( visit , -1 , sizeof( visit ) ) ;
    memset( rear , 0 , sizeof( rear ) ) ;
    memset( front , 0 , sizeof( front ) ) ;
    return ;
}

void enqueue( int num )
{
    //如果有队友，插入队友列的后面
    if( visit[map[num]] != -1 )
    {
        Queue[visit[map[num]]][rear[visit[map[num]]]++] = num ;
    }
    else//如果没有，在二维队列中添加新的队列，并标记队列所在的行（即标记他的优先性）
    {
        Queue[r][0] = num ;
        visit[map[num]] = r ;
        rear[r]++ ;
        r++ ;
    }
    return ;
}
void dequeue()
{
    cout << Queue[qfront][front[qfront]++] << endl ;//输入队列前端的元素
    //如果该队列元素为空，该队列出二维队列，就因为这个才wa了好多次呀
    if( front[qfront] >= rear[qfront] ) { visit[map[Queue[qfront][front[qfront]-1]]] = -1 ; qfront++ ; }
    return ;
}

int main()
{
    int t ;
    int icase = 1 ;
    while( cin >> t )
    {
        if( !t ) break ;
        cout << "Scenario #" << icase++ << endl ;
        init() ;
        int n ;
        for( int i = 0 ; i < t ; i++ )
        {
            cin >> n ;
            for( int j = 0 ; j < n ; j++ )
            {
                cin >> team[j] ;
                map[team[j]] = i ;//映射队元素所在的队号
            }
        }

        string command ;
        int member ;
        while( cin >> command )
        {

            if( command == "STOP" ) { cout << endl ; break ; }
            if( command == "ENQUEUE" )
            {
                cin >> member ;
                enqueue( member ) ;
            }
            if( command == "DEQUEUE" ) dequeue() ;
        }
    }
    return 0 ;
}
