#include<stdio.h> 
#include <iostream>
using namespace std;

int fac(int x) {
    if (x < 1)
        return 1;
    
    return x*fac(x-1);

} 
  
int main () 
{
    int n ;
    scanf("%d", &n);
  
    if ((n < 0) || (n > 12))
        return 0;
    printf("%d", fac(n)); 
    
    return 0; 
} 