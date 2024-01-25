#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin,s1);
	getline(cin, s2);
	int i, j,n=s1.length();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j])
			{
				if (s1[i] == '\n')
					continue;
				int k = i;
				while (k + 1 < s1.length())
				{

					s1[k] = s1[k + 1];
					k++;
				}
				s1[k] = '\n';
				n--;
			}
		}
	}
	cout << s1<<endl;
}
