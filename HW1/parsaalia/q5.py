def lower_digit(number):
  return int(str(number)[-1])

n = int(input())
dp = [1, 1]
result = sum(dp)
for i in range(2, n):
  dp.append(lower_digit(dp[i-1] + dp[i-2]))     # we just store the lowest digit 
  result = lower_digit(result + dp[i])   # lowest_digit(a1+a2) equals lowest_digit(a1) + lowest_digit(a2)
print(result)