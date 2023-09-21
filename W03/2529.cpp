#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int op[9];
int visited[10];
long long min_value = 9999999999;
long long max_value = -1;

void recursive(int size, long long value, vector<int> &v)
{
    if (size == n + 1)
    {
        int flag = true;
        for (int i = 0 ; i < n ; ++i)
        {
            // printf("op:%d", op[i]);
            if (op[i] == 0)
            {
                if (v[i] >= v[i + 1])
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (v[i] <= v[i + 1])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
            return ;
        // printf("%lld\n", value);
        max_value = max(max_value, value);
        min_value = min(min_value, value);
        return ;
    }

    for (int i = 0 ; i < 10 ; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(arr[i]);
            recursive(size + 1, value * 10 + arr[i], v);
            v.pop_back();
            visited[i] = false;
        }
    }
    
    return ;
}


int main()
{
    scanf("%d", &n);
    char ch;
    for (int i = 0 ; i < n ; ++i)
    {
        scanf(" %c", &ch);
        if (ch == '<')
            op[i] = 0;
        else
            op[i] = 1;
    }
    vector<int> v;
    recursive(0, 0, v);
    if (op[0] == 0)
        printf("%lld\n0%lld", max_value, min_value);
    else
        printf("%lld\n%lld", max_value, min_value);
}
