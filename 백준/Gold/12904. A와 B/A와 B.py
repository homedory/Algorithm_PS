S = input()
T = input()

S_len = len(S)
T_len = len(T)

while T_len > S_len:
    if T[-1] == 'A':
        T = T[:-1]
    else:
        T = T[:-1]
        T = T[::-1]
    T_len -= 1

if T == S:
    print(1)
else:
    print(0)
