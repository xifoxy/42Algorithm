N = int(input())
for i in range(N):
    for j in range(N):
        print(" " if j < i else "*",end="")
    print("");
