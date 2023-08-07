# 이건 2중 for문으로 풀 시 시간초과가 나서 인터넷 검색했더니 dp로 푸는 문제였음(dp 잘 못품)

n = int(input())
nums = list(map(int, input().split(' ')))

for i in range(1, n):
  nums[i] = max(nums[i], nums[i - 1] + nums[i])

print(max(nums))