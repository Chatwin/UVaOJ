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
    //����ж��ѣ���������еĺ���
    if( visit[map[num]] != -1 )
    {
        Queue[visit[map[num]]][rear[visit[map[num]]]++] = num ;
    }
    else//���û�У��ڶ�ά����������µĶ��У�����Ƕ������ڵ��У���������������ԣ�
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
    cout << Queue[qfront][front[qfront]++] << endl ;//�������ǰ�˵�Ԫ��
    //����ö���Ԫ��Ϊ�գ��ö��г���ά���У�����Ϊ�����wa�˺ö��ѽ
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
                map[team[j]] = i ;//ӳ���Ԫ�����ڵĶӺ�
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
