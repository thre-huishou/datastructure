#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
////1、给一个非递减的整数数组nums，返回每个数字的平方组成的新数组，要求也按非递减排序
//int * test1(int *nums, int numsSize, int* returnSize)
//{
//	int i = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		returnSize[i] = (nums[i]) * (nums[i]);
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		int j = 0;
//		for (j = 0; j < numsSize - i - 1; j++)
//		{
//			if (returnSize[j] > returnSize[j + 1])
//			{
//				int tmp = returnSize[j];
//				returnSize[j] = returnSize[j + 1];
//				returnSize[j + 1] = tmp;
//			}
//		}
//	}
//
//}

////旋转数组
//void rotate(int* nums, int numsSize, int k) {
//	k = k % numsSize;
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		int j = 0;
//		for (j = numsSize - 1; j > 0; j--)
//		{
//			int tmp = nums[j];
//			nums[j] = nums[j - 1];
//			nums[j - 1] = tmp;
//		}
//	}
//}
////三次旋转法
//void rotate(int* nums, int numsSize, int k) {
//	k = k % numsSize;
//	int left = 0; int right = numsSize - 1;
//	for (left = 0, right = numsSize - k - 1; left < right; left++, right--)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//	}
//	for (left = numsSize - k, right = numsSize - 1; left < right; left++, right--)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//	}
//	for (left = 0, right = numsSize - 1; left < right; left++, right--)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//	}
//}
//
////给定一个数组nums，编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序
//
////硬移方法
//void moveZeroes(int* nums, int numsSize) {
//	int i = 0;
//	int nn = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != 0)
//		{
//			nn++;
//		}
//	}
//	i = 0;
//	while (i != nn)
//	{
//		if (nums[i] == 0)
//		{
//			int j = 0;
//			for (j = i; j < numsSize - 1; j++)
//			{
//				int tmp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = tmp;
//			}
//		}
//		else
//		{
//			i++;
//		}
//	}
//}
//
////改进方法-双标签
//void moveZeroes(int* nums, int numsSize) {
//	int i = 0, j = 0;
//	while (i < numsSize)
//	{
//		if (nums[i] != 0)
//		{
//			int tmp = nums[i];
//			nums[i] = nums[j];
//			nums[j] = tmp;
//			j++;
//		}
//		i++;
//	}
//}


//给定一个已按照非递减顺序序列的整数数组numbers，请你从数组中找出两个数满足相加之和等于target。
//函数应该以长度为2的整数数组的形式返回这两个数的下标值。numbers的下标从1开始计数，所以答案数组应满足1《=answer[0]<answer[1]<=numbers.length
//硬算
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int * returnlist = (int *)malloc(sizeof(int) * 2);
	*returnSize = 2;
	int i = 0;
	for (i = 0; i < numbersSize; i++)
	{
		int j = 0;
		for (j = i + 1; j < numbersSize; j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				returnlist[0] = i + 1; returnlist[1] = j + 1;
				return returnlist;
			}
		}
	}
	returnlist[0] = -1; returnlist[1] = -1;
	return returnlist;
}

//双指针
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int * returnlist = (int *)malloc(sizeof(int) * 2);
	*returnSize = 2;
	int left = 0, right = numbersSize - 1;
	while (numbers[left] + numbers[right] != target)
	{
		numbers[left] + numbers[right] < target ? left++ : right--;
	}
	returnlist[0] = left + 1;
	returnlist[1] = right + 1;
	return returnlist;
}

int main()
{
	int nums[] = { -4,-1,0,3,10 };
	int len = sizeof(nums) / sizeof(nums[0]);
	/*int returnSize[6] = {0};*/
	int* aaa=twoSum(nums,len, 2,2);
	int i = 0;
	for (i = 0; i <2; i++)
	{
		printf("%d\n", aaa[i]);
	}
	return 0;
}