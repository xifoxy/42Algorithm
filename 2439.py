N = int(input())
for i in range(N):
    for j in range(N):
        print(" " if j < N - i - 1 else "*",end="")
    print("");
