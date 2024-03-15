import sys

base = int(sys.stdin.readline())
digits = sys.stdin.readline().split()
number = sys.stdin.readline().strip()

values = []
while len(number) > 0:
    for i in range(len(digits)):
        digit = digits[i]
        if number[0:len(digit)] == digit:
            values.append(i)
            number = number[len(digit):]
            break

pos_values = [base ** i for i in range(len(values))][::-1]

result = sum([p * v for (p, v) in zip(pos_values, values)])
print(result)
