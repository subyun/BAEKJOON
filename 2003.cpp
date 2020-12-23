#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 2003

int main () {

    int n, m;
    int result = 0;
    int a = 0, b = 0;
    int temp = 0;
    scanf("%d %d", &n, &m);

    int A[10000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    while(true){

        if (a == n) break;

        if (temp >= m) {
            temp -= A[b];
            b++;
        } else if (a == n) break;
        else {
            temp += A[a];
            a++;
        }

        if (temp == m) {
            result++;
        }

    }

    printf("%d", result);

    return 0;

}