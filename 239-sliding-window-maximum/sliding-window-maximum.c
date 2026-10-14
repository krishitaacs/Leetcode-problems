#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k <= 0 || k > numsSize) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;

    int* result = malloc(*returnSize * sizeof(int));
    int* deque = malloc(numsSize * sizeof(int));

    if (result == NULL || deque == NULL) {
        free(result);
        free(deque);
        *returnSize = 0;
        return NULL;
    }

    int front = 0, size = 0;

    for (int i = 0; i < numsSize; i++) {
        while (size > 0 && deque[front] <= i - k) {
            front = (front + 1) % numsSize;
            size--;
        }
        while (size > 0) {
            int back = (front + size - 1) % numsSize;

            if (nums[deque[back]] > nums[i])
                break;

            size--;
        }
        int back = (front + size) % numsSize;
        deque[back] = i;
        size++;
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    free(deque);
    return result;
}