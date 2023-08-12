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
        v.push_back(i + 1);
        recursive(n, m - 1, i);
        v.pop_back();
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    v.reserve(m);
    recursive(n, m, 0);
}

// 전에꺼와 다른 부분은 앞의 인덱스를 보면 안되므로 시작 인덱스 제한.