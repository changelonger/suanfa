#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string>
#include<vector>;
#include<iostream>
using namespace std;
void getnext(string T, int next[]);
int IndexKMP(string s, string t, int pos);
int main()
{
	string T;
	cin >> T;
	int next[10] = {0};
	getnext(T, next);
	printf("%d\n", T.length());
	for (int i = 1; i < T.length();i++)
	{
		printf("%d ", next[i]);
	}
	return 0;
}
void getnext(string T,int next[])
{
	int i = 1; int j = 0;
	next[1] = 0;//规定，第一个是0；然后再加就变成了1了；
	while (i < T.length())
	{
		if (j == 0 || T[i] == T[j])//当j是第一个的时候或者，前面等于后面的时候
		{
			i++;
			j++;
			next[i] = j;//我的理解，后面多对相等的条件是前面必须要相等，
			//然后所以后面是前面的递增，且每次都只能加1
		}
		//结合一下那个前面的KMP算法的解释
		// next[j]的含义是j-1前面前缀和后缀有多少是相等的再+1
		//所以进行累加，j从0开始，没有的时候就是1；
		//前j-1位有多少相等，next[j]有k+1；
		else
			j = next[j];
		//next的意义就是j应该到的位置，比如所j=4，然后这一步判断不相等后
		//j就应该跳到next[j]所对应的值！！！！！！
	}
}
void getnextval(string T, int nextval[])
{
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] != T[j])
				//因为这里原本j是要赋值给next的，
				//后面进行j的跳动是因为T[j1]和s[i]不相等
				//这里j1根据next数组对应的值调到J2的时候
				//若还是相等，那么就任然不等，相当于多判断了；
				//为了节省算力，进行了另一步
				nextval[i] = j;
			else//如果相等把j位置的nextval值给i位置；
				nextval[i] = nextval[j];
			//这里的j仍然是应该跳到的值
			//应为相等，所以直接跳到nextval[i]就可以了，省去了剩下的几个步骤、
		}
	}
}
int IndexKMP(string s, string t, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getnext(t, next);
	while (i <= s[0] && j <= t[0])
	{
		if (j == 0 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > t[0])
	{
		return i - t[0];
	}
	else
		return 0;
}
int Index(string s, string t, int pos)
{
	int i = pos;
	int j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (s[i] = t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t[0])
	{
		return i - t[0];
	}
	else
		return 0;
}