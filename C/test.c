#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter array size: ");
    scanf("%d", &n);

    // Now that we know the size, declare the array
    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

