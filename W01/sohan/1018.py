# 1. 8 x 8 보드판을 상수로 미리 만들어 놓고 (W 먼저인 버전, B 먼저인 버전)
# 2. 입력 보드판을 8 x 8씩 확인하면서 몇개가 다른지 각각 카운트
# 3. 다 세고나면 둘 중에 작은 값을 배열에 저장
# 4. 보드판 끝까지 반복한 뒤 최솟값을 출력

N, M = map(int, input().split(' '))
board = [list(input()) for i in range(N)]

WB = ['W','B','W','B','W','B','W','B']
BW = ['B','W','B','W','B','W','B','W']

white = [WB,BW,WB,BW,WB,BW,WB,BW]
black = [BW,WB,BW,WB,BW,WB,BW,WB]

def cut_board(board, i, j):
    new_board = list(board[row][i:i + 8] for row in range(j,j + 8))
    return new_board

def count_paint(board):
    count_white = 0
    count_black = 0
    for ai, bi, ci in zip(board, white, black):
        for ci, di, ei in zip(ai, bi, ci):
            count_white += (ci != di)
            count_black += (ci != ei)
    return min(count_white, count_black)

def solution(board):
    col_max = M - 7
    row_max = N - 7
    answer = []
    for j in range(row_max):
        for i in range(col_max):
            answer.append(count_paint(cut_board(board, i, j)))
    return (min(answer))

print(solution(board))