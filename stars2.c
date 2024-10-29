#include <stdio.h>
#include <cs50.h>
#include <cs50.c>
#include <stdlib.h>

int main() {
int n;
n = get_int("enter the height: ", &n);
// printf("enter the height: ");
// scanf("%d", &n);

for (int i = 1; i <= n; i++) {
    for (int j = n; j > i; j--){
        printf(" ");
    }
    for (int k = 1; k <= i; k++){
        printf("*");
    }
    printf("\n");
    
}
system("pause");
return 0;

}