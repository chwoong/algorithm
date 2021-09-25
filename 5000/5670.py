'''
 author: chw0501
 reference:
 created: 2020-12-21 04:02:04(UTC)
'''
import sys
# import bisect
input = sys.stdin.readline
# sys.setrecursionlimit(100000)
# MOD = 1000000007
# INF ArithmeticError

class Node:
    def __init__(self, cnt = 0, terminal = False):
        self.cnt = cnt
        self.terminal = terminal
        self.children = {}

class Trie:
    def __init__(self):
        self.head = Node()
    # 이 노드를 루트로 하는 트라이에 번호 idx인 string을 추가
    def insert(self, string):
        curr_node = self.head
        for w in string:
            if w not in curr_node.children:
                curr_node.children[w] = Node()
                curr_node.cnt += 1
            curr_node = curr_node.children[w]
        curr_node.terminal = True

    def query(self, string):
        ret = 0
        curr_node = self.head
        for w in string:
            if curr_node.cnt > 1 or curr_node.terminal:
                ret += 1
            curr_node = curr_node.children[w]
        return ret


while True:
    try:
        n = int(input())
    except:
        break
    trie = Trie()
    ans = 0
    arr = []
    for _ in range(n):
        s = input().rstrip()
        trie.insert(s)
        arr.append(s)
    if trie.head.cnt == 1:
        ans += n
    for i in range(n):
        ans += trie.query(arr[i])
    print(f'{ans / n:.2f}')
