S = ' ' + input()
N = int(input())
A = [None]
for i in range(N):
   A.append(input())
length = len(S) - 1

dp = [[False] * (length+1) for i in range(N+1)]
# (N+1) x (length+1) matrix
# dp[i][j]: 1 ~ i 번째 단어로 S[1] ... S[j] 단어를 완성할 수 있는지
# answer: dp[N][length]

for i in range(0, N+1):
   dp[i][0] = True
   
   
for i in range(1, N+1):
   for j in range(1, length+1):
       if(i-1 >=0): # in the range
           dp[i][j] = dp[i][j] or dp[i-1][j] # i번째 단어를 사용하지 않을 경우 고려
       for text in A:
           if(text == None):
               continue
           else:
               if(j+1-len(text)>=0 and S[j+1-len(text) : j+1] == text): # 마지막 부분이 같을 경우
                       dp[i][j] = dp[i][j] or dp[i][j-len(text)]

if(dp[N][length]):
   print(1)
else:
   print(0)