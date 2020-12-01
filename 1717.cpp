#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int p[10000000];

int find(int n) {

    if(p[n] < 0){      // -1 means itself
        return n;
    }  

    p[n] = find(p[n]);
    return p[n];

}

void merge(int a, int b) {

    a = find(a);
    b = find(b);
    if (a == b) return;
    p[b] = a;

}

int main() {

    fill(p, p+10000000, -1);    // -1 means itself

    int n, m;

    scanf("%d %d", &n, &m);

    int k, a, b;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &k, &a, &b);

        if (k == 0) {

            merge(a, b);

        }
        else if (k == 1) {

            if (find(a) == find(b)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
    }

    return 0;

}