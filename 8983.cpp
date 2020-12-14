#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <string>
using namespace std;

// 8983

typedef struct p {
    int x, y;
} Animal;

Animal animal[10000];

bool comp(Animal a, Animal b) {
    return a.x < b.x;
}

int hunt[100000];
// vector<pair<int, int> > animal;
int j;

int main() {

    int m, n, l;
    scanf("%d %d %d", &m, &n, &l);

    for (int i = 0; i < m; i++) {
        scanf("%d", &hunt[i]);
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &animal[i].x, &animal[i].y);
        // animal.push_back(make_pair(x,y));
        // arr[i] = make_pair(a,b);
    }

    sort(hunt, hunt+m);
    sort(animal, animal+n, comp);

    int result = 0;
 
    for (int i = 0; i < n; i++) {
        /*
        if (l >= animal[i].second) {
            for (int j = 0; j < m; j++) {
                if (abs(hunt[j]-animal[i].first)+animal[i].second <= l) {
                    result++;
                    break;
                }

            }

        }
        */
        j = 0;
        while ((j<m) && (hunt[j] < animal[i].x)) j++;

        bool flag = false;
        if ((j>0) && (animal[i].x - hunt[j-1]+ animal[i].y <= l)) // j-1 hunt
            flag = true;
        if ((j<m) && (hunt[j] - animal[i].x + animal[i].y<= l)) // j hunt
            flag = true;
        if (flag)
            result++;
        
    }

    printf("%d\n", result);

    return 0;


}