#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[8];
int visited[8];
int recursive(int count, vector<int>& v)
{
    int ret = 0;
    if (count == 0)
    {
        int sum = 0;
        for (int i = 0 ; i < n - 1 ; ++i)
            sum += abs(v[i] - v[i + 1]);
        return sum;
    }
    for (int i = 0 ; i < n ; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(arr[i]);
            ret = max(recursive(count - 1, v), ret);
            v.pop_back();
            visited[i] = false;
        }
    }
    return ret;
}


int main()
{
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);
    vector<int> v;
    printf("%d\n", recursive(n, v));
}

// 모든 경우의 수를 만들고 최소값을 구함.