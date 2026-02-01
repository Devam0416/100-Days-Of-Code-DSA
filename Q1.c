/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, x;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr = (int *)malloc(n * sizeof(int));
    printf("Memory allocated for %d elements.\n", n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
	{
        	scanf("%d", &arr[i]);
    	}

    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Reallocate memory
    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    printf("Memory reallocated for %d elements.\n", n + 1);

    printf("Shifting elements to the right...\n");
    for (int i = n; i >= pos; i--)
	{
        	arr[i] = arr[i - 1];
        	printf("Moved arr[%d] = %d\n", i, arr[i]);
    	}

    // Insert element
    arr[pos - 1] = x;
    printf("Inserted %d at position %d.\n", x, pos);

    printf("Updated array:\n");
    for (int i = 0; i <= n; i++)
	{
        	printf("%d ", arr[i]);
    	}

    // Free memory
    free(arr);
    printf("\nMemory freed successfully.\n");

    return 0;
}