#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
////1����һ���ǵݼ�����������nums������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�����
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

////��ת����
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
////������ת��
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
////����һ������nums����дһ������������0�ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//
////Ӳ�Ʒ���
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
////�Ľ�����-˫��ǩ
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


//����һ���Ѱ��շǵݼ�˳�����е���������numbers��������������ҳ��������������֮�͵���target��
//����Ӧ���Գ���Ϊ2�������������ʽ���������������±�ֵ��numbers���±��1��ʼ���������Դ�����Ӧ����1��=answer[0]<answer[1]<=numbers.length
//Ӳ��
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

//˫ָ��
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