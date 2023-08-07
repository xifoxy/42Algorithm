N = int(input())
for i in range(N):
    for j in range(N):
        if j < N - i:
            print("*", end="")
    print("");
