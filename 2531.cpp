#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 2531
int n, d, k, c;
int sushi[6006100];
int cnt[6100], curRes;
int result;

void push(int sNum) {
    if(cnt[sNum] == 0) 
        curRes++;
    cnt[sNum]++;
}

void pop(int sNum) {
    cnt[sNum]--;
    if(cnt[sNum] == 0) 
        curRes--;
}


int main() {

    scanf("%d %d %d %d", &n, &d, &k, &c);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &sushi[i]);
    }

    // add last k to the end of sushi to make like circular
    for (int i = n+1; i < n+k; i++) {
        sushi[i] = sushi[i-n];
    }

    // push upon
    push(c);

    for (int i = n+1; i < n+k; i++) {
        push(sushi[i]);
    }

    for (int i = 1; i <= n; i++) {
        push(sushi[i+k-1]);
        result = max(result, curRes);
        pop(sushi[i]);
    }

    printf("%d", result);

    return 0;

}