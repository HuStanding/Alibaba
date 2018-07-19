#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Find(int a[], int n, int min[], int max[])
{
    sort(a, a + n);
    if (a[0] > 2)
        return false;
    //获取最小时间
    min[0] = a[0];
    min[1] = a[1];
    min[2] = a[2];
    min[3] = a[3];
    min[4] = a[4];
    min[5] = a[5];
    if (min[1] > 3 || min[2] > 5 || min[4] > 5)
        return false;

    //获取最大时间
    int max_hour1 = -1, max_hour2 = -1, max_min1 = -1,
        max_min2 = -1, max_sec1 = -1, max_sec2 = -1;
    //获取数组中<=2的最大值下标
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 2)
            max_hour1 = i;
    }
    //获取数组中<=3的最大值下标
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 3 && i != max_hour1)
            max_hour2 = i;
    }
    //获取数组中<=5的最大值下标
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 5 && i != max_hour1 && i != max_hour2)
            max_min1 = i;
    }
    //获取数组中<=9的最大值下标
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 9 && i != max_hour1 && i != max_hour2 && i != max_min1)
            max_min2 = i;
    }
    //获取数组中<=5的最大值下标
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 5 && i != max_hour1 && i != max_hour2 && i != max_min1 && i != max_min2)
            max_sec1 = i;
    }
    //获取数组中<=9的最大值下标
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 9 && i != max_hour1 && i != max_hour2 && i != max_min1 && i != max_min2 && i != max_sec1)
            max_sec2 = i;
    }
    //获取最大时间
    if (max_hour1 != -1 && max_hour2 != -1 && max_min1 != -1 && max_min2 != -1 && max_sec1 != -1 && max_sec2 != -1)
    {
        max[0] = a[max_hour1];
        max[1] = a[max_hour2];
        max[2] = a[max_min1];
        max[3] = a[max_min2];
        max[4] = a[max_sec1];
        max[5] = a[max_sec2];
    }

    else
    {
        cout << "lallal" << endl;
        return false;
    }

    return true;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    int *min = new int[n];
    int *max = new int[n];
    if (Find(a, n, min, max))
    {
        for (int i = 0; i < n; i++)
            cout << min[i];
        cout << " ";
        for (int i = 0; i < n; i++)
            cout << max[i];
        cout << endl;
    }
    else
    {
        cout << "时间无效" << endl;
    }

    delete[] a;
    delete[] min;
    delete[] max;
    return 0;
}
