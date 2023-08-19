#include <iostream>
using namespace std;
int n, m;
int dist[10][10];
bool visited[10];
int recursive(int start, int sum)
{
    int ret = 1000000 * 10;
    if (visited[0])
    {
        for (int i = 0 ; i < n ; ++i)
        {
            if (!visited[i])
                return 1e7 + 1;
        }
        return sum;
    }
    for (int i = 0 ; i < n ; ++i)
    {
        if (!visited[i] && dist[start][i])
        {
            // printf("start:%d dest%d  vis[%d] dist:%d\n", start, i, visited[i], dist[start][i]);
            visited[i] = true;
            ret = min(recursive(i, sum + dist[start][i]), ret);
            visited[i] = false;
        }
    }
    return ret;
}


int main()
{
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
        {
            scanf("%d", &dist[i][j]);
        }
    printf("%d\n", recursive(0, 0));
}

// 0으로 시작하면서 방문한 곳에는 visit체크 후 다 돌았을 때 0으로 끝나는 곳만 확인하여 최소비용 확인.