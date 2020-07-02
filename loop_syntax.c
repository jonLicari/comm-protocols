#include<stdio.h>

int main(void){
    int a = 5, b = 10;

    if (a < b){
        printf("True");
    }


    while (a < b); /* infinite loop */
        printf("This print will never execute\n");

    return 0;
}

