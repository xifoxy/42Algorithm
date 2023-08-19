#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct Data
{
    int arr[8];

    bool operator<(const Data &copy) const
    {
        for (int i = 0 ; i < 7 ; ++i)
        {
           if (arr[i] != copy.arr[i])
                return arr[i] < copy.arr[i];
        }
        return arr[7] < copy.arr[7];
    }
};

int lim;
bool visited[8];
int arr[8];
set<Data> s;
void recursive(int n, int m, vector<int> &v, int st)
{
    if (m == 0)
    {
        Data tmp;
        for (int i = 0 ; i < lim ; ++i)
        {
            tmp.arr[i] = v[i];
        }
        s.insert(tmp);
        return ;
    }

    // 시작점을 지정.
    for (int i = st ; i < n ; ++i)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(arr[i]);
            recursive(n, m - 1, v, i + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}


int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    lim = m;
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);

    // 정렬 필요
    sort(arr, arr + n);
    
    vector<int> v;
    recursive(n, m, v, 0);

    for (set<Data>::iterator it = s.begin() ; it != s.end() ; ++it)
    {
        for (int i = 0 ; i < m ; ++i)
            printf("%d ", it->arr[i]);
        printf("\n");
    }
}

// 이전 방식과 동일하나, start 지점을 지정하여서 동일한 방식으로 풀음