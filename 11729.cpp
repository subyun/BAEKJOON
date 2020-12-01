#include<stdio.h> 
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int mid, int end) {
	if (n == 1) 
        printf("%d %d\n", start, end);
	else {
		hanoi(n - 1, start, end, mid);
        printf("%d %d\n", start, end);
		hanoi(n - 1, mid, start, end);
	}
}
  
int main () 
{
    int n ;
    scanf("%d", &n);
  
    if ((n < 0) || (n > 20))
        return 0;
    
    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 2, 3);
    
    return 0; 
} 