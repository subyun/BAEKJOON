#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int p[101000];

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

typedef struct t {
    int x1, x2, y;
    int num;
} Timber;

bool comp(Timber a, Timber b) {
    return a.x1 < b.x1;
}

Timber timber[101000];

int n,q;

int main() {

    int N, Q;
    // vector<pair<int, int> > vp;
    int x1, x2, y;
    int a, b;
    int p1, p2;

    int gnum = 1;
    int newX2;

    fill(p, p+101000, -1);                                             // -1 means itself

    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &timber[i].x1, &timber[i].x2, &timber[i].y);
        timber[i].num = i;                                              // number of timber
        // if (x1 >= x2) return -1;
        // if ((0 > x1) && (0 > x2) && (pow(10,9) < x1) && (pow(10,9) < x2)) return -1;
    }

    sort(timber+1, timber+N+1, comp);                                    // sort by x1

    newX2 = timber[1].x2;

    for (int i = 2; i <= N; i++) {
        /*
        if (i == 1) {
            merge(timber[i].num, timber[i].num);
            timber[i].x2 = timber[i-1].x2;
        }*/
        if (timber[i].x1 <= newX2) {
            merge(timber[i-1].num, timber[i].num);
            newX2 = max(newX2, timber[i].x2);
        }
        else {
            newX2 = timber[i].x2;
        }
    }

    for (int i = 0; i < Q; i++) {

        scanf("%d %d", &a, &b);
        /*
        if ( find(a) == find(b)) {
            printf("\n1\n");
        }
        else {
            printf("\n0\n");
        } 
        */
       printf("%d\n", find(a) == find(b));
    }

    return 0;
}