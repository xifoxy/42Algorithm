#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool visited[8];
void recursive(int n, int m, int start)
{
    if (m == 0)
    {
        for (int i = 0 ; i < v.size() ; ++i)
            printf("%d ", v[i]);
        printf("\n");
        return ;
    }
    for (int i = start ; i < n ; ++i)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(i + 1);
            recursive(n, m - 1, i + 1);
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
    recursive(n, m, 0);
}

// 15649에서 시작점만 제한.