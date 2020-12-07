#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 2357

long long int arr[1000000];
vector<long long> treeMin;
vector<long long> treeMax;
int INF = 10000000;

// initialize tree with summation of two nodes
long long initMin(int node, int nStart, int nEnd) {
    if (nStart == nEnd) {
        return treeMin[node] = arr[nStart];
    } else {
        return treeMin[node] = min(initMin(node*2, nStart, (nStart+nEnd)/2), initMin(node*2+1, (nStart+nEnd)/2+1, nEnd));
    }
}

// initialize tree with summation of two nodes
long long initMax(int node, int nStart, int nEnd) {
    if (nStart == nEnd) {
        return treeMax[node] = arr[nStart];
    } else {
        return treeMax[node] = max(initMax(node*2, nStart, (nStart+nEnd)/2), initMax(node*2+1, (nStart+nEnd)/2+1, nEnd));
    }
}

int queryMin(int node, int nStart, int nEnd, int left, int right) {
    if ((right < nStart) || (nEnd < left)) return INF;
    if ((nStart >= left) && (right >= nEnd)) return treeMin[node];
    int mid = (nStart+nEnd)/2;
    return min(queryMin(node*2, nStart, mid, left, right), queryMin(node*2+1, mid+1, nEnd, left, right));
}

int queryMax(int node, int nStart, int nEnd, int left, int right) {
    if((right < nStart) || (nEnd < left)) return -INF;
    if ((nStart >= left) && (right >= nEnd)) return treeMax[node];
    int mid = (nStart+nEnd)/2;
    return max(queryMax(node*2, nStart, mid, left, right), queryMax(node*2+1, mid+1, nEnd, left, right));
}

int main() {

    int N, M;
    int a, b;

    scanf("%d %d", &N, &M);

    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h+1));

    treeMin.resize(treeSize);
    treeMax.resize(treeSize);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    initMin(1, 0, N-1);
    initMax(1, 0, N-1);

    for(int i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b);
        printf("%d %d\n", queryMin(1, 0, N-1, a-1, b-1), queryMax(1, 0, N-1, a-1, b-1));
    }

    return 0;
}

