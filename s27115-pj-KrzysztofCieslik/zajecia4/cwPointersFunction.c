#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int sum(int a, int b) {
    return a + b;
}

int forAll(int* array, int elementCount, int (*f)(int, int)) {
    int v = array[0];
    int i;
    for (i = 1; i < elementCount; i++) {
        v = f(v, array[i]);
    }
    return v;
}

int main() {
    int functionId;
    int elementCount;
    int result;
    int* array;
    int i;
    scanf("%d", &functionId);
    scanf("%d", &elementCount);

    array = malloc(elementCount * sizeof(int));
    if (array == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 1;
    }

    
    for (i = 0; i < elementCount; i++) {
        scanf("%d", &array[i]);
    }

    result = forAll(array, elementCount, (functionId == 0) ? maximum : (functionId == 1) ? minimum : sum);
    printf("Result: %d\n", result);

    free(array);
    return 0;
}