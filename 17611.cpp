#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 17611

pair<int, int> v[100001];
int vCnt[2][1000001];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
        v[i].first += 500000;
        v[i].second += 500000;
    }

    v[n] = v[0];

    for (int i = 0; i < n; i++) {

        if (v[i].second == v[i+1].second) {

            if (v[i].first < v[i+1].first) {
                vCnt[0][v[i].first]++;
                vCnt[0][v[i+1].first]--;
            } else {
                vCnt[0][v[i].first]--;
                vCnt[0][v[i+1].first]++;
            }
        }
        else {
            if (v[i].second < v[i+1].second) {
                vCnt[1][v[i].second]++;
                vCnt[1][v[i+1].second]--;
            } else {
                vCnt[1][v[i].second]--;
                vCnt[1][v[i+1].second]++;
            }
        }
        
    }

    int result = 0;

    for (int i = 0; i < 2; i++) {

        int cnt = 0;
        for (int j = 0; j <= 1000000; j++) {
            cnt += vCnt[i][j];
            if (cnt > result) {
                result = cnt;
            }
        }
    }

    printf("%d", result);

    return 0;
}