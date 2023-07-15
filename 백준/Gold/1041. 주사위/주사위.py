n = int(input())
numbers = list(map(int, input().split()))

if n == 1:
    max_num = 0
    s = 0

    for i in range(6):
        if numbers[i] > max_num:
            max_num = numbers[i]
        s += numbers[i]

    print(s - max_num)
else:
    small_nums = []
    max_num = 0
    min_num = 55
    s = 0

    for i in range(3):
        small_nums.append(min(numbers[i], numbers[5 - i]))

    for i in range(3):
        if small_nums[i] > max_num:
            max_num = small_nums[i]
        if small_nums[i] < min_num:
            min_num = small_nums[i]
        s += small_nums[i]

    print((n-2) * (5*n - 6) * min_num + 4 * (2 * n - 3) * (s - max_num) + 4 * s)
