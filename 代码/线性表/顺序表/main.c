#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct ArrayList* ArrayList;

// 定义一个数组
struct ArrayList {
	E* array; // 实现顺序表的底层数组
	int size; // 表示底层数组的容量
	int index; // 表示数组的下标
};


// 初始化数组
int initArrayList(ArrayList arrayList) {
	// 请求内存空间 请求失败返回0
	arrayList->array = malloc(sizeof(E) * 10);
	if (arrayList->array == NULL) return 0;
	arrayList->size = 10;
	arrayList->index = 0;
	return 1;
}

// 插入元素
void insert(ArrayList arrayList, E number, E index) {
	// index必须大于-1
	if (index < 0) {
		printf("插入下标不能小于0!\n");
		return;
	}
	// 有一种可能就是该数组满了， 当数组的下标与数组的大小-1相等时说明需要扩容
	if(arrayList->index == arrayList->size - 1){
		// 取1.5倍的长
		int newSize = arrayList->size + (arrayList->size >> 1);
		// 重写分配内存
		E* newArray = realloc(arrayList->array, sizeof(E) * newSize);
		// 把旧的数组指针指向新的数组
		arrayList->array = newArray;
		arrayList->size = newSize;
	}
	// 如果arrayList->index == 0 说明该数组中没有数，所以如果index比arrayList->index大则直接放到第一位
	if (arrayList->index == 0 || index > arrayList->index) {
		arrayList->array[arrayList->index] = number;
	}
	else {
		// 执行到这里说明arrayList->index > 0
		for (int i = arrayList->index; i > index; i--) {
			// 后移
			arrayList->array[i] = arrayList->array[i-1];
		}
		arrayList->array[index] = number;
		
	}
	arrayList->index++;
}

// 删除元素
void delete(ArrayList arrayList, E index) {
	// index必须大于-1
	if (index < 0) {
		printf("删除下标不能小于0!\n");
		return;
	}
	// 判断数组是否为空
	if (arrayList->index == 0) {
		// 说明数组已空
		printf("数组已空，无法删除!\n");
		return;
	}
	else if (index >= arrayList->index) {
		// 越界删除
		printf("删除数组越界!\n");
		return;
	}
	else {
		for (int i = index; i < arrayList->index; i++) {
			arrayList->array[i] = arrayList->array[i + 1];
		}		
	}
	arrayList->index--;
}

// 获取指定位置的元素
int findElementByIndex(ArrayList arrayList, E index) {
	// index必须大于-1
	if (index < 0 || index > arrayList->index - 1) {
		printf("下标越界!\n");
		return;
	}
	return arrayList->array[index];
}
// 获取元素的位置
int getElementIndex(ArrayList arrayList, E number) {
	// 先排序但是还没学排序算法先空着
	// 利用二分法进行查找
	int mid, arrayNumber;
	int left = 0;
	int right = arrayList->index - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		arrayNumber = arrayList->array[mid];
		if (arrayNumber == number) {
			return mid;
		}
		else if (arrayNumber > number) {
			right = mid - 1;
		}
		else if (arrayNumber < number) {
			left = mid + 1;
		}
	}
	return -1;
}
// 获取线性表的长度
int size(ArrayList arrayList) {
	return arrayList->index;   //直接返回size就完事
}

// 打印数组
void printList(ArrayList arrayList) {
	for (int i = 0; i < arrayList->index; ++i)
		printf("%d ", arrayList->array[i]);
	printf("\n");
}

int main() {
	struct ArrayList arrayList;
	initArrayList(&arrayList);
	insert(&arrayList, 1, 0);
	insert(&arrayList, 2, 1);
	insert(&arrayList, 3, 2);
	insert(&arrayList, 4, 3);
	insert(&arrayList, 5, 4);
	insert(&arrayList, 6, 5);

	int index = getElementIndex(&arrayList, 5);

	printf("%d\n", index);
	return 0;
}
