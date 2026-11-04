Code

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int **allocateMarks(int n, int m);
void readMarks(int **marks, int n, int m);
void printMarks(int **marks, int n, int m);
int sequentialSearch(int **marks, int n, int m, int target);
void freeMarks(int **marks, int n);

int main()
{
    int n, m, target;
    int **marks;

    printf("Enter number of students: \n");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter number of subjects per student: \n");
    if (scanf("%d", &m) != 1 || m <= 0)
    {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    /* ---------- 1. Allocate array of pointers ---------- */
    marks = allocateMarks(n, m);
    if (marks == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Memory allocated successfully.\n");

    /* ---------- 2. Read marks for each student ---------- */
    printf("\nEnter marks for %d students (%d values each):\n", n, m);
    readMarks(marks, n, m);

    printf("Marks after user input:\n");
    printMarks(marks, n, m);

    /* ---------- 3. Search for target mark ---------- */
    // \n is explicitly required here by the VPL test cases
    printf("\nEnter target mark to search for: \n");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid target value.\n");
        freeMarks(marks, n);
        return 1;
    }

    int index = sequentialSearch(marks, n, m, target);
    if (index != -1)
    {
        int studentIndex = index / m;
        int subjectIndex = index % m;
        printf("Target %d found at index %d (Student %d, Subject %d)\n",
               target, index, studentIndex + 1, subjectIndex + 1);
    }
    else
    {
        printf("Target %d not found.\n", target);
    }

    /* ---------- 4. free ---------- */
    freeMarks(marks, n);
    printf("\nMemory successfully released using free().\n");

    return 0;
}

/* Allocate an array of pointers, one dynamically allocated row per student */
int **allocateMarks(int n, int m)
{
    int **marks = (int **)malloc(n * sizeof(int *));
    if (marks == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        marks[i] = (int *)malloc(m * sizeof(int));
        if (marks[i] == NULL)
        {
            /* free previously allocated rows before failing */
            for (int k = 0; k < i; k++)
            {
                free(marks[k]);
            }
            free(marks);
            return NULL;
        }
    }
    return marks;
}

/* Read m marks for each of the n students */
void readMarks(int **marks, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &marks[i][j]);
        }
    }
}

/* Display marks for every student, one row per student */
void printMarks(int **marks, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", marks[i][j]);
            if (j < m - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Sequential search across the array of pointers.
 * Returns the flattened index (i * m + j) of the first occurrence
 * of target, or -1 if not found.
 * Student index = index / m, Subject index = index % m
 */
int sequentialSearch(int **marks, int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (marks[i][j] == target)
            {
                return i * m + j;
            }
        }
    }
    return -1; /* not found */
}

/* Release each student's row, then the array of pointers itself */
void freeMarks(int **marks, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(marks[i]);
    }
    free(marks);
}
