#include <stdio.h>

int isEven(int n) { return n % 2 == 0; }
int isOdd(int n) { return n % 2 != 0; }

int count (int a[], int len, int (*pred)(int)) {
    // TODO: Complete this function
    int total = 0;
    for (int i = 0; i < len; i++) {
        if (pred(a[i]) != 0) {
            total++;
        }
    }
    return total;
}

int main(void) {
    int a[5] = {1, 3, 4, 6, 3};
    int noOfEvenElems = count(a, 5, &isEven);
    int noOfOddElems = count(a, 5, &isOdd);

    printf("There are %d even elements and %d odd",
                    noOfEvenElems, noOfOddElems);
}
