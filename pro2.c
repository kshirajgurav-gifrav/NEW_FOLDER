C Code	#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int *allocateUsingMalloc(int n);
int *allocateUsingCalloc(int n);
int *resizeArray(int *arr, int newSize);
void readElements(int *arr, int start, int end);
void printArray(int *arr, int n);
void freeMemory(int *arr);

int main()
{
    int n, new_n;
    int *mallocArray;
    int *callocArray;
    int *resizedArray;

    printf("Enter array size: \n");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    /* ---------- 1. malloc: allocates uninitialized memory ---------- */
    mallocArray = allocateUsingMalloc(n);

    if (mallocArray == NULL)
    {
        printf("Memory allocation using malloc failed.\n");
        return 1;
    }

    printf("Memory allocated using malloc successfully.\n");

    printf("\nEnter %d elements for the malloc array:\n", n);
    readElements(mallocArray, 0, n);

    printf("Malloc array after user input:\n");
    printArray(mallocArray, n);

    /* ---------- 2. calloc: zero-initialized memory ---------- */
    callocArray = allocateUsingCalloc(n);

    if (callocArray == NULL)
    {
        printf("Memory allocation using calloc failed.\n");
        freeMemory(mallocArray);
        return 1;
    }

    printf("\nArray allocated using calloc (zero-initialized):\n");
    printArray(callocArray, n);

    printf("\nEnter %d elements for the calloc array:\n", n);
    readElements(callocArray, 0, n);

    printf("Calloc array after user input:\n");
    printArray(callocArray, n);

    /* ---------- 3. realloc: resize the malloc array ---------- */
    // \n is explicitly required here by the VPL test cases
    printf("\nEnter new size for realloc: \n");
    if (scanf("%d", &new_n) != 1 || new_n <= 0)
    {
        printf("Invalid new size.\n");
        freeMemory(mallocArray);
        freeMemory(callocArray);
        return 1;
    }

    resizedArray = resizeArray(mallocArray, new_n);

    if (resizedArray == NULL)
    {
        printf("Memory reallocation failed.\n");
        freeMemory(mallocArray);
        freeMemory(callocArray);
        return 1;
    }

    mallocArray = resizedArray;

    if (new_n > n)
    {
        printf("Enter %d additional elements:\n", new_n - n);
        readElements(mallocArray, n, new_n);
        printf("\n");
    }

    printf("Array after realloc:\n");
    printArray(mallocArray, new_n);

    /* ---------- 4. free ---------- */
    freeMemory(mallocArray);
    freeMemory(callocArray);

    printf("\nMemory successfully released using free().\n");

    return 0;
}

/* Allocate memory using malloc() */
int *allocateUsingMalloc(int n)
{
    return malloc(n * sizeof(int));
}

/* Allocate memory using calloc() */
int *allocateUsingCalloc(int n)
{
    return calloc(n, sizeof(int));
}

/* Resize memory using realloc() */
int *resizeArray(int *arr, int newSize)
{
    return realloc(arr, newSize * sizeof(int));
}

/* Read elements into arr[start] through arr[end - 1] */
void readElements(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        scanf("%d", &arr[i]);
    }
}

/* Display array elements */
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

/* Release dynamically allocated memory */
void freeMemory(int *arr)
{
    free(arr);
}
