#include <stdio.h>

int binarySearch(int* nums, int target, int left, int right){
    // 如果右边的下标比左边的下标小，说明已经找完了
    if (right < left) {
        return -1;
    }
    // 找出中间的下标
    int maddle = (right + left) >> 1;
    // 判断中间下标和要找的值是否相同
    if (nums[maddle] == target) {
        return maddle;
    }
    // 如果要找的值比中间的大，需要去右边开始找
    if(nums[maddle] < target){
        return binarySearch(nums, target, maddle + 1, right);
    }
    // 如果要找的值比中间的小，需要去左边开始找
    else {
        return binarySearch(nums, target, left, maddle - 1);
    }

}

int search(int* nums, int numsSize, int target) {
    //请实现查找算法
    return binarySearch(nums, target, 0, numsSize - 1);
}

int main() {
    int arr[] = { 1, 3, 4, 6, 7,8, 10, 11, 13, 15 }, target = 13;
    printf("%d", search(arr, 10, target));
}