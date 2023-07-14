import sys

N, K = map(int, input().split())
s = input()

stack = []

for digit in s:
    digit_int = int(digit)

    while K > 0 and stack:
        if stack[-1] < digit_int:
            stack.pop()
            K -= 1
        else:
            break
    stack.append(digit_int)

#corner case: if not removed K numbers, remove left things 
while K > 0:
    stack.pop()
    K -= 1

for i in stack:
    print(i,end='')
