#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;


// Segment Tree

long long arr[10000000];

vector<long long> tree;

int N, M, K;

// initialize tree with summation of two nodes
long long init(int node, int nStart, int nEnd) {
    if (nStart == nEnd) {
        return tree[node] = arr[nStart];
    } else {
        return tree[node] = init(node*2, nStart, (nStart+nEnd)/2) + init(node*2+1, (nStart+nEnd)/2+1, nEnd);
    }
}

// update from top to down
void update(int node, int nStart, int nEnd, int index, long long int diff) {

    if ((index < nStart) || (index > nEnd)) return;

    tree[node] = tree[node] + diff;

    if (nStart != nEnd) {
        update((node*2), nStart, (nStart+nEnd)/2, index, diff);
        update(((node*2)+1), ((nStart+nEnd)/2)+1, nEnd,  index, diff);
    }
}

// get sum of range (left ~ right)
long long sum(int node, int nStart, int nEnd, int left, int right) {
    // [left, right]와 [start, end]가 겹치지 않는 경우
    // [left, right]가 [start,end]를 완전히 포함하는 경우
    // [start,end]가 [left, right]를 완전히 포함하는 경우
    // [left, right]와 [start, end]가 겹쳐져 있는 경우 (1,2,3 제외한 나머지 경우)

    // [left, right]와 [start, end]가 겹치지 않는 경우
    if (left > nEnd || right < nStart) {
        return 0;
    }
    if (left <= nStart && nEnd <= right) {
        return tree[node];
    }
    return sum(node*2, nStart, (nStart+nEnd)/2, left, right) + sum(node*2+1, (nStart+nEnd)/2+1, nEnd, left, right);
}
/*
int main() {

    scanf("%d %d %d", &n, &m, &k);

    int h = (int)ceil(long2(n));
    int treeSize = (1 << (h+1));

    tree.resize(treeSize);

    m += k;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    init(1 , 0, n-1);
}
*/

// 2042

int main() {

    scanf("%d %d %d", &N, &M, &K);

    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h+1));

    tree.resize(treeSize);

    M += K;

    for(int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    init(1, 0, N-1);

/*
    for(int i = 1; i <= tree.size(); i++) {
        printf("%lld ", tree[i]);
    }*/
    int a;
    

    for(int i = 0; i < M; i++) {
        scanf("%d", &a);

        if (a == 1) {
            int b;
            long long int c;
            scanf("%d %lld", &b, &c);
            b -= 1;
            long long int dif = c - arr[b];
            arr[b] = c;
            update(1, 0, N-1, b, dif);
/*
            for(int i = 1; i <= tree.size(); i++) {
                printf("%lld ", tree[i]);
            }*/
        }
        else if (a == 2) {
            int b,c;
            scanf("%d %d", &b, &c);
            b -= 1;
            printf("%lld", sum(1, 0 , N-1, b, c));
        }

    }

   return 0;
}