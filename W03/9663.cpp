#include <iostream>
#include <vector>
using namespace std;
int n, m;

int visited[16];
int idx[16];
int recursive(int size)
{
    int ret = 0;
    if (size == n + 1)
    {
        return 1;
    }

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        if (visited[i] == 0)
        {
            bool flag = false;
            for (int j = 1 ; j < size ; ++j)
            {
                if (idx[j] == i - (size - j) || idx[j] == i + (size - j))
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                idx[size] = i;
                visited[i] = 1;
                ret += recursive(size + 1);
                visited[i] = 0;
            }
        }
    }
    
    return ret;
}


int main()
{
    scanf("%d", &n);
    printf("%d\n", recursive(1));
}

// 방문 배열과 놓은 위치의 인덱스를 비교하는데 바로 윗값이면 -1, +1 그 다음 윗값이면 -2 +2이런식으로 쭉쭉 비교