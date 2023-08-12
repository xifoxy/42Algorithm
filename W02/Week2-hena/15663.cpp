#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct Data
{
    int arr[8];

    // Set에 구조체를 넣으려면 기준이 필요함.
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
            // vector에 저장한 값을 tmp의 데이터에 옮김.
            tmp.arr[i] = v[i];
        }
        // insert를 하면 알아서 정렬이 될거임.
        s.insert(tmp);
        return ;
    }

    for (int i = 0 ; i < n ; ++i)
    {
        // 선택된 index를 가져가면 안되기 때문에 visit로 방지.
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(arr[i]);
            recursive(n, m - 1, v);
            // 쓴 값은 맨마지막부터 빼고, 방문값도 바꿈.
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

    // 정렬 함수
    sort(arr, arr + n);
    
    vector<int> v;
    recursive(n, m, v);

    // set에 저장되어있는 값들을 하나씩 차례대로 읽음.
    for (set<Data>::iterator it = s.begin() ; it != s.end() ; ++it)
    {
        for (int i = 0 ; i < m ; ++i)
            printf("%d ", it->arr[i]);
        printf("\n");
    }
}

// 정렬을 한 후 m의 개수만큼 차면 set에 넣는 방식을 사용하였고, 중복된 index가 사용되는 것을 막기 위해 visited배열을 사용하였음