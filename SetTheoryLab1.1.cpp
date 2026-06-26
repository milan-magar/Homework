#include <stdio.h>

int main() {
    int U[100], A[100], B[100];
    int nU, nA, nB;
    int i, j, found;

    // Universal Set
    printf("Enter number of elements in Universal Set U: ");
    scanf("%d", &nU);

    printf("Enter elements of U:\n");
    for(i = 0; i < nU; i++)
        scanf("%d", &U[i]);

    // Set A
    printf("Enter number of elements in Set A: ");
    scanf("%d", &nA);

    printf("Enter elements of A:\n");
    for(i = 0; i < nA; i++)
        scanf("%d", &A[i]);

    // Set B
    printf("Enter number of elements in Set B: ");
    scanf("%d", &nB);

    printf("Enter elements of B:\n");
    for(i = 0; i < nB; i++)
        scanf("%d", &B[i]);

    // Union
    printf("\nA U B = { ");
    for(i = 0; i < nA; i++)
        printf("%d ", A[i]);

    for(i = 0; i < nB; i++) {
        found = 0;
        for(j = 0; j < nA; j++) {
            if(B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if(!found)
            printf("%d ", B[i]);
    }
    printf("}\n");

    // Intersection
    printf("A n B = { ");
    for(i = 0; i < nA; i++) {
        for(j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                printf("%d ", A[i]);
                break;
            }
        }
    }
    printf("}\n");

    // A - B
    printf("A - B = { ");
    for(i = 0; i < nA; i++) {
        found = 0;
        for(j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if(!found)
            printf("%d ", A[i]);
    }
    printf("}\n");

    // A + B (Symmetric Difference)
    printf("A + B = { ");

    for(i = 0; i < nA; i++) {
        found = 0;
        for(j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if(!found)
            printf("%d ", A[i]);
    }

    for(i = 0; i < nB; i++) {
        found = 0;
        for(j = 0; j < nA; j++) {
            if(B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if(!found)
            printf("%d ", B[i]);
    }
    printf("}\n");

    // A'
    printf("A' = { ");
    for(i = 0; i < nU; i++) {
        found = 0;
        for(j = 0; j < nA; j++) {
            if(U[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if(!found)
            printf("%d ", U[i]);
    }
    printf("}\n");

    // B'
    printf("B' = { ");
    for(i = 0; i < nU; i++) {
        found = 0;
        for(j = 0; j < nB; j++) {
            if(U[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if(!found)
            printf("%d ", U[i]);
    }
    printf("}\n");

    return 0;
}
