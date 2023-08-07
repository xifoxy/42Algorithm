N = int(input())
for i in range(N):
    for j in range((2 * N) // 2 + i):
        print(" " if j  < ((2 * N) // 2 - i - 1) else "*", end="")
    print("")
