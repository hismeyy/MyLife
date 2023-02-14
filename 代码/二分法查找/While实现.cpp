#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    //请实现查找算法
    int mid;
    int left = 0;
    int right = numsSize - 1;
    // 只有left小于right的时候才可以循环
    while (left <= right) {
        // 找中间的下标
        mid = (left + right) >> 1;
        // 如果中间下标的值等于找的值 返回
        if (nums[mid] == target) {
            return mid;s
        }
        // 如果中间下标的值大于找的值 去右边找，所以缩小右边的范围
        if (nums[mid] > target) {
            right = mid - 1;
        }
        // 如果中间下标的值小于找的值 去左边找，所以缩小左边的范围
        else {
            left = mid + 1;
        }
    }
    // 执行到这里说明没找到 返回-1
    return -1;
}

int main() {
    int arr[] = { 1, 3, 4, 6, 7,8, 10, 11, 13, 15 }, target = 13;
    printf("%d", search(arr, 10, target));
}