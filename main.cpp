#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > data;

void DFS(int a[], int n, int i, vector<int> &res)
{
    res.push_back(a[i]);
    if (i == n - 1)
    {
        data.push_back(res);
        return;
    }
    for (int j = 1; j <= a[i] && j + i < n; j++)
    {
        //继续递归
        DFS(a, n, i + j, res);
        res.pop_back();
    }
}

int main()
{
    int a[] = {3, 5, 2, 1, 3, 1};
    int n = 6;
    vector<int> res;
    DFS(a, n, 0, res);
    int num = 0;
    for (int i = 1; i < data.size(); i++)
    {
        if (data[num].size() > data[i].size())
            num = i;
    }

    for (int j = 0; j < data[num].size(); j++)
        cout << data[num][j] << " ";

    cout << endl;
    return 0;
}
