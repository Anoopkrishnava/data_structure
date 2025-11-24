#include<stdio.h>
#include<stdlib.h>

int max = 10;

// Check if element already exists in a set
int isDuplicate(int set[], int value, int count) {
    for (int i = 0; i < count; i++) {
        if (set[i] == value) {
            printf("Element already present in the set\n ");
            return 1;
        }
    }
    return 0;
}

// Check if element exists in Universal Set
int isUniversal(int universalSet[], int value, int size) {
    int found = 0;
    for (int i = 0; i < size; i++) {

        if (universalSet[i] == value) {
            found = 1;
            return 1;
        }
    }

    if (found == 0) {
        printf("Element not present in the universal set\n");
        return 0;
    }
}

// Create bitstring representation
void bitString(int universalSet[], int inputSet[], int bitArray[], int setSize) {

    int k = 0;

    while (k != max) {
        for (int i = 0; i < setSize; i++) {
            if (universalSet[k] == inputSet[i]) {
                bitArray[k] = 1;
                break;
            } else {
                bitArray[k] = 0;
            }
        }
        k++;
    }
}

// Union operation
void set_union(int bitA[], int bitB[], int result[]) {
    int k = 0;

    while (k != max) {
        if (bitA[k] == 1 || bitB[k] == 1) {
            result[k] = 1;
        }
        else {
            result[k] = 0;
        }
        k++;
    }
}

// Intersection operation
void set_intersection(int bitA[], int bitB[], int result[]) {
    int k = 0;

    while (k != max) {
        if (bitA[k] == 1 && bitB[k] == 1) {
            result[k] = 1;
        }
        else {
            result[k] = 0;
        }
        k++;
    }
}

// Difference operation
void set_difference(int bitA[], int bitB[]) {

    int diff[max];

    int k = 0;

    while (k != max) {
        if (bitA[k] == 1 && bitB[k] == 0) {
            diff[k] = 1;
        }
        else {
            diff[k] = 0;
        }
        k++;
    }

    for (int i = 0; i < max; i++) {
        printf("%d ", diff[i]);
    }
}

void main() {

    int checkDuplicate, checkUniversal;
    int sizeA, sizeB;
    int value;

    printf("Enter the size of the Universal Set: ");
    scanf("%d", &max);

    int universalSet[max], setA[max], setB[max];
    int bitA[max], bitB[max];
    int unionSet[max], intersectionSet[max];

    // Read Universal Set
    printf("Enter UNIVERSAL SET ELEMENTS:\n ");

    for (int i = 0; i < max; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &value);

        if (isDuplicate(universalSet, value, i) == 0) {
            universalSet[i] = value;
        }
        else {
            i--;
        }
    }

    printf("\nUniversal Set Elements:\n ");
    for (int i = 0; i < max; i++) {
        printf("%d ", universalSet[i]);
    }

    // Read Set A
    printf("\nEnter the size of set A: ");
    scanf("%d", &sizeA);

    if (sizeA > max) {
        printf("Size limit is %d, now size is set to %d", max, max);
        sizeA = max;
    }

    printf("\nEnter Set A Elements:\n");
    for (int i = 0; i < sizeA; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &value);

        checkDuplicate = isDuplicate(setA, value, i);
        checkUniversal = isUniversal(universalSet, value, max);

        if (checkDuplicate == 0 && checkUniversal == 1) {
            setA[i] = value;
        }
        else {
            i--;
        }
    }

    printf("\nSET A ELEMENTS: ");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", setA[i]);
    }

    // Read Set B
    printf("\nEnter the size of set B: ");
    scanf("%d", &sizeB);

    if (sizeB > max) {
        printf("Size limit is %d, now size is set to %d ", max, max);
        sizeB = max;
    }

    printf("\nEnter Set B Elements:\n");
    for (int i = 0; i < sizeB; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &value);

        checkDuplicate = isDuplicate(setB, value, i);
        checkUniversal = isUniversal(universalSet, value, max);

        if (checkDuplicate == 0 && checkUniversal == 1) {
            setB[i] = value;
        }
        else {
            i--;
        }
    }

    printf("\nSET B ELEMENTS: ");
    for (int i = 0; i < sizeB; i++) {
        printf("%d ", setB[i]);
    }

    // Bit Strings
    bitString(universalSet, setA, bitA, sizeA);
    printf("\n\nBit Representation of Set A: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", bitA[i]);
    }

    bitString(universalSet, setB, bitB, sizeB);
    printf("\n\nBit Representation of Set B: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", bitB[i]);
    }

    // Union
    printf("\n\nUnion of Set A and B: ");
    set_union(bitA, bitB, unionSet);
    for (int i = 0; i < max; i++) {
        printf("%d ", unionSet[i]);
    }

    // Intersection
    printf("\n\nIntersection of Set A and B: ");
    set_intersection(bitA, bitB, intersectionSet);
    for (int i = 0; i < max; i++) {
        printf("%d ", intersectionSet[i]);
    }

    // Difference A-B
    printf("\n\nSet Difference (A - B): ");
    set_difference(bitA, bitB);

    // Difference B-A
    printf("\n\nSet Difference (B - A): ");
    set_difference(bitB, bitA);
}
