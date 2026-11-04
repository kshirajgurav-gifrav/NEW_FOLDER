C Code	#include <stdio.h>

/* Generic print: reinterprets ptr based on type. Cannot judge bounds on its own. */
void safePrint(const void *ptr, int type)
{
    if (ptr == NULL)
    {
        printf("Null pointer, nothing to print\n");
        return;
    }
    if (type == 0)
        printf("Integer Value: %d\n", *(const int *)ptr);
    else if (type == 1)
        printf("Float Value: %.2f\n", *(const float *)ptr);
    else
        printf("Invalid type\n");
}

int main()
{
    int intArray[5];
    float floatArray[5];
    int *ip = intArray;
    float *fp = floatArray;
    int i, option, index;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", ip + i);

    printf("Enter 5 floats:\n");
    for (i = 0; i < 5; i++)
        scanf("%f", fp + i);

    printf("\nInteger Array:\n");
    for (i = 0; i < 5; i++)
        printf("Value: %d\n", *(ip + i));

    printf("\nFloat Array:\n");
    for (i = 0; i < 5; i++)
        printf("Value: %.2f\n", *(fp + i));

    printf("\n0-Integer 1-Float\nChoice: ");
    scanf("%d", &option);

    printf("Enter index to access: ");
    scanf("%d", &index);

    if (option == 0)
    {
        /* Validate BEFORE computing the address.
           If invalid, pass NULL — safePrint's guard handles it. */
        if (index >= 0 && index < 5)
            safePrint(ip + index, 0);   /* address via pointer arithmetic */
        else
            safePrint(NULL, 0);
    }
    else if (option == 1)
    {
        if (index >= 0 && index < 5)
            safePrint(fp + index, 1);
        else
            safePrint(NULL, 1);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}
