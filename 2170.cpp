#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 17611 직각다각형 - pass

// 2170 선 긋기

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
    int result = 0;
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

    printf("%d", result);

    return 0;

}