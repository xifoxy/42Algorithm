n = int(input())
arr = [int(x) for x in input().split()]
now = 0
mx = arr[0]
for n in arr:
    now += n
    if now > mx:
        mx = now
    if now < 0:
        now = 0
print(mx)

# 인덱스 2개가 필요한가? 했다가 생각해보니 그냥 1번만 순회하면 됐음 ㄷㄷ
