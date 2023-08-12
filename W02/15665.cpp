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
void recursive(int n, int m, vector<int> &v)
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

    for (int i = 0 ; i < n ; ++i)
    {
        // visited가 사라진 지점.
         v.push_back(arr[i]);
         recursive(n, m - 1, v);
         v.pop_back();
    }
}


int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    lim = m;
    for (int i = 0 ; i < n ; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    
    vector<int> v;
    recursive(n, m, v);

    for (set<Data>::iterator it = s.begin() ; it != s.end() ; ++it)
    {
        for (int i = 0 ; i < m ; ++i)
            printf("%d ", it->arr[i]);
        printf("\n");
    }
}

// 이번에는 같은 인덱스를 방문해도 되므로, visited 배열을 사용하지 않고, 모든 인덱스를 돌음.