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
        v.push_back(i + 1);
        recursive(n, m - 1);
        v.pop_back();
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    v.reserve(m);
    recursive(n, m);
}

// 모든 점들을 중복해서 돌아야하므로 모든 재귀문에서 for문을 다 돌면서 값을 채우면 됨.