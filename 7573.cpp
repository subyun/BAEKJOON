#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 7573

typedef struct f {
    int x, y;
} Fish;

Fish fish[1000];

bool comp(Fish a, Fish b) {
    return a.x < b.x;
}

int h;
int result, cnt;
int x[1000], y[1000];

int main() {

    int n, l, m;
    
    scanf("%d %d %d", &n, &l, &m);
    result = 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &fish[i].x, &fish[i].y);
        x[i] = fish[i].x;
        y[i] = fish[i].y;
    }

    sort(x, x+m);
    sort(y, y+m);

    l /= 2;

    for (int w = 1; w < l; w++) {
        h = l - w;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cnt = 0;
                for (int k = 0; k < m; k++) {
                    if (((x[i] <= fish[k].x) && (fish[k].x <= x[i]+w)) && ((y[j] <= fish[k].y) && (fish[k].y <= y[j]+h))) {
                        cnt++;
                    }
                }
                
                if (result < cnt) {
                    result = cnt;
                }
            }
        }
    }

    printf("%d", result);

    return 0;
}