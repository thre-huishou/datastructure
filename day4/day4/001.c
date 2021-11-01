#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

//测试正确，提交显示超出时间限制，暴力求解
//int panduan(char* first, char* end)
//{
//	int len = end - first + 1;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		for (j = i + 1; j < len; j++)
//		{
//			if (first[i] == first[j])
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//int lengthOfLongestSubstring(char * s) {
//	int i = 0;
//	int k = 0;
//	int tmp = 0;
//	int len = strlen(s);
//	if (s == NULL)
//	{
//		return k;
//	}
//	for (k = 1; k <= len; k++)//遍历字符串子串长度
//	{
//		int j = 0;
//		for (j = 0; j < len - k + 1; j++)//遍历长度的子串
//		{
//			if (panduan(s + j, s + j + k - 1))
//			{
//				tmp = k;
//				break;
//			}
//		}
//	}
//	return tmp;
//}
//滑动窗口优化


//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
//换句话说，s1 的排列之一是 s2 的子串 。
int checkInclusion(char * s1, char * s2) {
	int n = strlen(s1), m = strlen(s2);
	if (n > m) {
		return 0;
	}
	int cnt1[26] = { 0 };
	for (int i = 0; i < n; ++i) {
		++cnt1[s1[i] - 'a'];
	}
	for (int i = 0; i <= m - n; ++i) {
		int j = 0;
		int cnt2[26] = { 0 };
		for (j = i; j < i + n; j++)
		{
			++cnt2[s2[j] - 'a'];
		}
		for (j = 0; j < 26; j++)
		{
			if (cnt1[j] == cnt2[j]&&j!=25)
			{
				continue;
			}
			else if (cnt1[j] != cnt2[j])
			{
				break;
			}
			else
			{
				return 1;
			}
		}
		
	}
	return 0;
}

int main()
{
	
	char s2[] = "eidhksk";
	char s1[] = "ie";
	int dd=checkInclusion(s1, s2);
	printf("%d\n", dd);
	return 0;
}