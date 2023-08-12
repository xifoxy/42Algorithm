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
        for (int i = 0 ; i < 8 ; ++i)
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

    for (int i = st ; i < n ; ++i)
    {
         v.push_back(arr[i]);
         recursive(n, m - 1, v, i);
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
    recursive(n, m, v, 0);

    for (set<Data>::iterator it = s.begin() ; it != s.end() ; ++it)
    {
        for (int i = 0 ; i < m ; ++i)
            printf("%d ", it->arr[i]);
        printf("\n");
    }
}

// 다음 수는 시작 인덱스부터 돌게하면 이전 인덱스를 볼 수 없음.