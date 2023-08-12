#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[8];
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
            v.push_back(arr[i]);
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
    for (int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    v.reserve(m);
    recursive(n, m);
}

// N과 M 4까지는 인덱스로 처리했다면 값이 주어진 것만 다름