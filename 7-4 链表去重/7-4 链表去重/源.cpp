#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<set>
using namespace std;
struct node
{
	int date;
	int cur;
};
int main()
{
	node l[100000];
	vector<int>a;
	vector<int>b;
	set<int>se;
	int s, n;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		int ad;
		cin >> ad;
		cin >> l[ad].date >> l[ad].cur;
	}
	for (int i = s; i != -1;)
	{
		a.push_back(i);
		i = l[i].cur;
	}
	if (n == 1)
		cout << a[0] << " " << l[a[0]].date << " " << "-1";
	printf("%05d %d ", a[0], l[a[0]].date);
	se.insert(abs(l[a[0]].date));

	for (int i = 1; i < a.size(); i++)
	{
		if (se.find(abs(l[a[i]].date)) != se.end())
		{
			b.push_back(a[i]);
		}
		else
		{
			se.insert(fabs(l[a[i]].date));
			printf("%05d\n%05d %d ", a[i], a[i], l[a[i]].date);
		}
	}
	cout << -1 << endl;
	printf("%05d %d ", b[0], l[b[0]].date);
	for (int i = 1; i < b.size(); i++)
	{
		printf("%05d\n%05d %d ", b[i], b[i], l[b[i]].date);
	}
	cout << -1 << endl;
	return 0;
}






