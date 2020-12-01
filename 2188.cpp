#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 2188
// 최대 유량으로 풀어보기

int MAX = 1000;
int INF = 987654321;

int n = 6, result;
int c[1000][1000], f[1000][1000], d[1000];
vector<int> a[500];

void maxFlow(int start, int end) {

    while(1) {
        fill(d, d+MAX, -1);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];
                // 방문하지 않은 노드 중에서 용량이 남은 경우
                if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    
                    q.push(y);
                    d[y] = x; // 경로를 기억합니다.
                    if (y == end) break; // 도착지에 도달한 경우
                }
            }
        }
        // 모든 경우를 다 찾은 뒤 탈출 합니다.
        if (d[end] == -1) break;
        int flow = INF;
        // 거꾸로 최소 유량을 탐색합니다.
        for (int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        // 최소 유량만큼 추가합니다.
        for (int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        c[0][i] = 1;
        a[0].push_back(i);
    }

    for(int i = N+1; i <= N+M; i++) {
        c[i][N+M+1] = 1;
        a[i].push_back(N+M+1);
    }

    for (int i = 1; i <= N; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            int k;
            scanf("%d", &k);
            a[i].push_back(k+N);
            a[k+N].push_back(i);
            c[i][k+N] = 1;
        }
    }

    maxFlow(0, N+M+1);
    printf("%d\n", result);

    return 0;
}

// Bipartite matching
// 2188

/*
bool visited[1000];
int A[1000], B[1000];
vector<int> vc[1000];
int N, M;

bool dfs(int v) {

    visited[v] = true;
    
    for (int i = 0; i < vc[v].size(); i++) {
        if ((B[i] == -1)||((!visited[B[i]]) && (dfs(B[i])))) {
            A[v] = i;
            B[i] = v;
            return true;
        }
    }
    return false;
}

int main() {
    
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int k;
            scanf("%d", &k);
            vc[i].push_back(k-1);
        }
    }

    int result = 0;

    fill(A, A+N, -1);
    fill(B, B+M, -1);

    for(int i = 0; i < N; i++) {
        if (A[i] == -1) {
            fill(visited, visited+N, false);
            if(dfs(i))
                result++;
        }
    }

    printf("%d\n", result);

    return 0;

}

*/
