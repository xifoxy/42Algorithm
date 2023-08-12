#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool visited[8];
void recursive(int n, int m)
{
    if (m == 0)
    {
        for (int i = 0 ; i < v.size() ; ++i)
            printf("%d ", v[i]);
        printf("\n");
        return ;
    }
    for (int i = 0 ; i < n ; ++i)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(i + 1);
            recursive(n, m - 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    v.reserve(m);
    recursive(n, m);
}

// visited 배열을 두고 매 재귀마다 for문을 n까지 돌면서 방문한 적이 있다면 
// vector에 넣지 않는다.