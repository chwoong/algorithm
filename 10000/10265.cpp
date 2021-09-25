/* 답 확인하기 위해 출처: https://jason9319.tistory.com/107 [ACM-ICPC 상 탈 사람]*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#define MAX_N 1000
using namespace std;
int n, k, disc[MAX_N + 1], scc[MAX_N + 1], x, c, s, cost[MAX_N + 1], ma[MAX_N + 1], mi[MAX_N + 1], in[MAX_N + 1], dx[MAX_N + 1], dy[MAX_N + 1], r, dp[MAX_N + 1][MAX_N + 1];
vector<vector<int>> vt;
vector<vector<int>> svt;
stack<int> st;
int dfs(int here) {
    st.push(here);
    disc[here] = ++c;
    int ret = disc[here];
    for (int there : vt[here]) {
        if (!disc[there])
            ret = min(ret, dfs(there));
        else if (!scc[there])
            ret = min(ret, disc[there]);
    }
    if (ret == disc[here]) {
        s++;
        while (1) {
            int v = st.top();
            st.pop();
            scc[v] = s;
            cost[s]++;
            if (v == here)break;
        }
    }
    return ret;
}
int df(int here) {
    int ret = ma[here];
    for (int there : svt[here]) {
        ma[here] += ma[there];
        df(there);
    }
    return ret;
}
int knapsack(int pos, int val) {
    if (pos > r)
        return 0;
    int &ret = dp[pos][val];
    if (ret != -1)return ret;
    ret = knapsack(pos + 1, val);
    if (val >= dx[pos]) {
        for (int i = dx[pos]; i <= dy[pos]; i++) {
            if (i > val)
                break;
            ret = max(ret, knapsack(pos + 1, val - i) + i);
        }
    }
    return ret;
}
int main() {
    scanf("%d%d", &n, &k);
    vt.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        vt[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!disc[i])
            dfs(i);
    svt.resize(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int next : vt[i]) {
            if (scc[next] == scc[i])
                continue;
            svt[scc[i]].push_back(scc[next]);
            in[scc[next]]++;
        }
    }
    for (int i = 1; i <= s; i++)
        ma[i] = mi[i] = cost[i];
    for (int i = 1; i <= s; i++) 
            df(i);
    for (int i = 1; i <= s; i++) {
        if (!in[i]) {
            dx[++r] = mi[i];
            dy[r] = ma[i];
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", knapsack(1, k));
    return 0;
}