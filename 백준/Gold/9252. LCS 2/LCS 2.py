str1 = input()
str2 = input()

dp = [[0] * (len(str2)+1) for _ in range(len(str1)+1)]


for i in range(1, len(str1) + 1):
    for j in range(1, len(str2) + 1):
        if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

ans = ""


i = len(str1)
j = len(str2)

print(dp[i][j])

while i > 0 and j > 0:
    if i > 0 and dp[i-1][j] == dp[i][j]:
        i -= 1
    elif j > 0 and dp[i][j-1] == dp[i][j]:
        j -= 1
    elif i > 0 and j > 0:
        ans = str1[i-1] + ans
        i -= 1
        j -= 1
    else:
        if i == 0:
            ans = str2[j-1] + ans
            break
        else:
            ans = str1[i-1] + ans
            break

if dp[len(str1)][len(str2)] > 0:
    print(ans)