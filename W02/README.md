# 02주차 재귀
<hr/>

### 문제 리스트
>1.  [N과 M (1)](https:noj.am/15649)
>2.  [N과 M (2)](https:noj.am/15650)
>3.  [N과 M (3)](https:noj.am/15651)
>4.  [N과 M (4)](https:noj.am/15652)
>5.  [N과 M (5)](https:noj.am/15654)
>6.  [N과 M (6)](https:noj.am/15655)
>7.  [N과 M (7)](https:noj.am/15656)
>8.  [N과 M (8)](https:noj.am/15657)
>9.  [N과 M (9)](https:noj.am/15663)
>10. [N과 M (10)](https://noj.am/15664)
>11. [N과 M (11)](https://noj.am/15665)
>12. [N과 M (12)](https://noj.am/15666)


### 재귀
재귀는 설계만 잘 해주면, 아주 좋은 메커니즘 입니다. 설계도 쉬워지고, 무엇보다 Graph파트에서 재귀가 베이스가 되는 DFS(Depth First Search)같은 탐색은 절대적인 파워를 갖기도 하며, 단점으론 Depth가 깊어지면 반복문 보다 큰 오버헤드를 가지기도 하고 stack memory를 쓰는 특성상 stackoverflow도 발생 시킬 수 있고, 디버깅을 직접하기도 힘든 부분이 있습니다. 

```c++
void recursive(int depth) {
  if (depth == 8)
    return;
  for (int i = 0; i < range; ++;) {
    recursive(depth + 1);
  }
}

// 이 두 함수는 비슷하게 작동합니다.

void repeat() {
  for (int r1 = 0; r1 < range; ++r1) {
    for (int r2 = 0; r2 < range; ++r2) {
      for (int r3 = 0; r3 < range; ++r3) {
        for (int r4 = 0; r4 < range; ++r4) {
          for (int r5 = 0; r5 < range; ++r5) {
            for (int r6 = 0; r6 < range; ++r6) {
              for (int r7 = 0; r7 < range; ++r7) {
                for (int r8 = 0; r8 < range; ++r8) {

                }
              }
            }
          }
        }
      }
    }
  }
}
```