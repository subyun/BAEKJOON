#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 2170 선 긋기
/*
typedef struct l {
    int x, y;
} Line;

Line line [10000000];

bool comp(Line a, Line b) {
    return a.x < b.x;
}

int main() {

    int n;
    int newY = -10000000;
    int newX = -10000000;
    long long result;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &line[i].x, &line[i].y);

    }
    
    sort(line, line+n, comp);

    for (int i = 0; i < n; i++) {
        
        if (line[i].x <= newY) {
            newY = max(newY, line[i].y);
            // result = newY - line[1].x;
        }
        else {
            
            result += (newY - newX);
            newX = line[i].x;
            newY = line[i].y;
        }
    }
    result += (newY - newX);

    printf("%lld\n", result);

    return 0;

}*/

int INF = 1000000000;
vector<pair<int, int> > arr;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(), arr.end());

    int newY = -INF;
    int newX = -INF;
    int result = 0;

    for (int i = 0; i < n; i++) {
        
        if (arr[i].first <= newY) {
            newY = max(newY, arr[i].second);
        }
        else {
            
            result += (newY - newX);
            newX = arr[i].first;
            newY = arr[i].second;
        }
    }
    result += (newY - newX);
    printf("%d\n", result);

    return 0;

}

