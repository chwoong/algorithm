# 정답 확인용 magatonman 님의 코드
import sys
n=int(sys.stdin.readline())
Tree={}
for i in range(n+1):
  Tree[i]=[]
for i in range(n-1):
  parent, child, l=map(int, sys.stdin.readline().split())
  Tree[parent].append((child, l))
  Tree[child].append((parent, l))

def dfs(x, Tree):
  visited=[0 for i in range(10002)]
  stack=[]
  stack.append((x, 0))
  visited[x]=1
  maxlen=0
  node=1
  while stack:
    p=stack.pop()
    if maxlen<p[1]:
      maxlen=p[1]
      node=p[0]
    for i in range(len(Tree[p[0]])):
      t=Tree[p[0]][i]
      if visited[t[0]]==0:
        visited[t[0]]=1
        stack.append((t[0], t[1]+p[1]))
  return (node, maxlen)
print(dfs(dfs(1, Tree)[0], Tree)[1])