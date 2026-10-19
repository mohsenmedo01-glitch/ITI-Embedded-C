#include <stdio.h>

struct arr {
    int size;
    int capacity;
    int *ptr;
};

// 1. Display
void display(struct arr array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.ptr[i]);
    }
    printf("\n");
}

// 2. Append
void append(struct arr *array, int value) {
    if (array->capacity > array->size) {
        array->ptr[array->size] = value;
        array->size++;
    }
    else {
        printf("there is no place\n");
    }
}

// 3. Insert
void insert(struct arr *array, int element, int index) {
    if (array->capacity > array->size &&
        index >= 0 && index <= array->size) {

        for (int i = array->size; i > index; i--) {
            array->ptr[i] = array->ptr[i - 1];
        }

        array->ptr[index] = element;
        array->size++;
    }
    else {
        printf("invalid index or there is no place\n");
    }
}

// 4. Delete
void del(struct arr *array, int index) {
    if (index >= 0 && index < array->size) {
        for (int i = index; i < array->size - 1; i++) {
            array->ptr[i] = array->ptr[i + 1];
        }

        array->size--;
        array->ptr[array->size] = 0;
    }
    else {
        printf("invalid index\n");
    }
}

// 5. Search
int search(struct arr array, int number) {
    for (int i = 0; i < array.size; i++) {
        if (array.ptr[i] == number) {
            return i;
        }
    }

    return -1;
}

// 6. Get
int get(struct arr array, int index) {
    if (index >= 0 && index < array.size) {
        return array.ptr[index];
    }

    return -1;
}

// 7. Max
int max(struct arr array) {
    if (array.size == 0) {
        return -1;
    }

    int maximum = array.ptr[0];

    for (int i = 1; i < array.size; i++) {
        if (array.ptr[i] > maximum) {
            maximum = array.ptr[i];
        }
    }

    return maximum;
}

// 8. Reverse
void reverse(struct arr *array) {
    int temp;

    for (int i = 0; i < array->size / 2; i++) {
        temp = array->ptr[i];

        array->ptr[i] = array->ptr[array->size - 1 - i];

        array->ptr[array->size - 1 - i] = temp;
    }
}

// 9. Shift Right
void shift(struct arr *array) {
    if (array->size > 0) {
        for (int i = array->size - 1; i > 0; i--) {
            array->ptr[i] = array->ptr[i - 1];
        }

        array->ptr[0] = 0;
    }
}

// 10. Rotate Right
void rotate(struct arr *array) {
    if (array->size > 1) {
        int temp = array->ptr[array->size - 1];

        for (int i = array->size - 1; i > 0; i--) {
            array->ptr[i] = array->ptr[i - 1];
        }

        array->ptr[0] = temp;
    }
}

// 11. Merge
struct arr merge(struct arr array1, struct arr array2, int *result) {
    struct arr array3;

    array3.size = array1.size + array2.size;
    array3.capacity = array3.size;
    array3.ptr = result;

    for (int i = 0; i < array1.size; i++) {
        array3.ptr[i] = array1.ptr[i];
    }

    for (int i = 0; i < array2.size; i++) {
        array3.ptr[array1.size + i] = array2.ptr[i];
    }

    return array3;
}

// 12. Average
float average(struct arr array) {
    if (array.size == 0) {
        return 0;
    }

    int total = 0;

    for (int i = 0; i < array.size; i++) {
        total += array.ptr[i];
    }

    return (float)total / array.size;
}

// 13. Sum
int sum(struct arr array) {
    int total = 0;

    for (int i = 0; i < array.size; i++) {
        total += array.ptr[i];
    }

    return total;
}

// 14. Replace
void replace(struct arr *array, int oldValue, int newValue) {
    for (int i = 0; i < array->size; i++) {
        if (array->ptr[i] == oldValue) {
            array->ptr[i] = newValue;
        }
    }
}

int main() {
    int arr[7] = {10, 20, 30};

    struct arr array;

    array.size = 3;
    array.capacity = 7;
    array.ptr = arr;

    printf("Original array: ");
    display(array);

    // 2. Append
    append(&array, 40);
    printf("After append: ");
    display(array);

    // 3. Insert
    insert(&array, 15, 1);
    printf("After insert: ");
    display(array);

    // 4. Delete
    del(&array, 2);
    printf("After delete: ");
    display(array);

    // 5. Search
    int index = search(array, 30);
    printf("Search index: %d\n", index);

    // 6. Get
    printf("Element at index 1: %d\n", get(array, 1));

    // 7. Max
    printf("Maximum: %d\n", max(array));

    // 8. Reverse
    reverse(&array);
    printf("After reverse: ");
    display(array);

    // 9. Shift
    shift(&array);
    printf("After shift right: ");
    display(array);

    // 10. Rotate
    rotate(&array);
    printf("After rotate right: ");
    display(array);

    // 12. Average
    printf("Average: %.2f\n", average(array));

    // 13. Sum
    printf("Sum: %d\n", sum(array));

    // 14. Replace
    replace(&array, 40, 100);
    printf("After replace: ");
    display(array);

    // 11. Merge
    int arr2[3] = {50, 60, 70};

    struct arr array2;
    array2.size = 3;
    array2.capacity = 3;
    array2.ptr = arr2;

    int result[10];

    struct arr array3 = merge(array, array2, result);

    printf("After merge: ");
    display(array3);

    return 0;
}