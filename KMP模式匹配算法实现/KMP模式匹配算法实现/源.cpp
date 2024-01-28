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
	next[1] = 0;//�涨����һ����0��Ȼ���ټӾͱ����1�ˣ�
	while (i < T.length())
	{
		if (j == 0 || T[i] == T[j])//��j�ǵ�һ����ʱ����ߣ�ǰ����ں����ʱ��
		{
			i++;
			j++;
			next[i] = j;//�ҵ���⣬��������ȵ�������ǰ�����Ҫ��ȣ�
			//Ȼ�����Ժ�����ǰ��ĵ�������ÿ�ζ�ֻ�ܼ�1
		}
		//���һ���Ǹ�ǰ���KMP�㷨�Ľ���
		// next[j]�ĺ�����j-1ǰ��ǰ׺�ͺ�׺�ж�������ȵ���+1
		//���Խ����ۼӣ�j��0��ʼ��û�е�ʱ�����1��
		//ǰj-1λ�ж�����ȣ�next[j]��k+1��
		else
			j = next[j];
		//next���������jӦ�õ���λ�ã�������j=4��Ȼ����һ���жϲ���Ⱥ�
		//j��Ӧ������next[j]����Ӧ��ֵ������������
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
				//��Ϊ����ԭ��j��Ҫ��ֵ��next�ģ�
				//�������j����������ΪT[j1]��s[i]�����
				//����j1����next�����Ӧ��ֵ����J2��ʱ��
				//��������ȣ���ô����Ȼ���ȣ��൱�ڶ��ж��ˣ�
				//Ϊ�˽�ʡ��������������һ��
				nextval[i] = j;
			else//�����Ȱ�jλ�õ�nextvalֵ��iλ�ã�
				nextval[i] = nextval[j];
			//�����j��Ȼ��Ӧ��������ֵ
			//ӦΪ��ȣ�����ֱ������nextval[i]�Ϳ����ˣ�ʡȥ��ʣ�µļ������衢
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