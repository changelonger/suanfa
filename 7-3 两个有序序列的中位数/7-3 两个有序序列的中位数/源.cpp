//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int n; scanf("%d", &n); int i = 0;
    vector<int>a1(n);
    vector<int>a2(n);
    set<int>a3;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a1[i]);
        a3.insert(a1[i]);
    }
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a2[i]);
        a3.insert(a2[i]);
    }
    vector<int>a(a3.size());
    i = 0;
    for (auto p = a3.begin(); p != a3.end(); p++)
    {
        a[i] = *p;
        i++;
    }
    printf("%d ", a[(a3.size() + 1) / 2 - 1]);
    return 0;
}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    vector<int> C;//两序列的并集
//    int n, data1, data2;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> data1;
//        C.push_back(data1);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> data2;
//        C.push_back(data2);
//    }
//    sort(C.begin(), C.end());  //升序排序 ，取消冒泡 
//    cout << C[n - 1];
//}
