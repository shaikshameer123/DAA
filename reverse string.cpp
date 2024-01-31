#include <stdio.h>

int reverseNumber(int num) {
    static int reversed = 0;

    if (num != 0) {
        reversed = reversed * 10 + num % 10;
        reverseNumber(num / 10);
    }

    return reversed;
}

int main() {
    int num;

    
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
    
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    
    int reversed = reverseNumber(num);
    printf("The reverse of %d is: %d\n", num, reversed);

    return 0;
}
