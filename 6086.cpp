#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// maximum 
// Ford-Fulkerson algorithm
/*
start with 0 flow
whie ther exists zn augmenting path:
    -find an agumenting path
    -compute vottleneck capacity
    -increase flow on that path by bottleneck capacity
*/

// 6086 최대 유량

// 입력 값 문자 대신 숫자로

int MAX = 100;
int INF = 987654321;

int n = 6, result;
int c[100][100], f[100][100], d[100];
vector<int> a[100];

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
        for (int i = end; i != start; i =d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        // 최소 유량만큼 추가합니다.
        for (int i = end; i != start; i =d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}

int main() {

    int N;

    scanf("%d", &N);

    int k, l;
    int o;

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &k, &l, &o);
        a[k].push_back(l);
        a[l].push_back(k);
        c[k][l] = o;
    }

    maxFlow(1,4);
    printf("%d\n", result);

    return 0;
}

/*
input

5
A B 3
B C 3
C D 5
D Z 4
B Z 6

3
*/


// 문자로 시도
/*
int MAX = 100;
int INF = 987654321;

int n = 6, result;
int c[100][100], f[100][100], d[100];
vector<int> a[100];

char ctoi(char x)
{
	if (x <= 'Z') {
		return x - 'A';
	}
	return x - 'a' + 26;
}

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

    int N;

    scanf("%d", &N);
    getchar();

    char k, l;
    int o;

    for(int i = 1; i <= N; i++) {
        scanf("%c %c %d", &k, &l, &o);
        getchar();

        k = ctoi(k), l = ctoi(l);
        a[k].push_back(l);
        a[l].push_back(k);
        c[k][l] = o;
    }

    maxFlow(ctoi('A'),ctoi('Z'));
    printf("%d\n", result);

    return 0;
}

*/