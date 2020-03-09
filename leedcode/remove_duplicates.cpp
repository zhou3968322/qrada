#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicate(int *A, int N)
{
    if (N <= 1)
    {
        return N;
    }
    int index = 0;
    for (int i = 1; i != N; i++)
    {
        if (A[index] != A[i])
        {
            A[++index] = A[i];
        }
    }
    return index + 1;
}

int removeTwoDuplicate(int *A, int N)
{
    if (N <= 1)
    {
        return N;
    }
    int index1 = 0;
    int index2 = 1;
    for (int i = 2; i != N; i++)
    {
        if ((A[index1] != A[i]) || (A[index2] != A[i]))
        {
            A[++index1] = A[index2];
            A[++index2] = A[i];
        }
    }
    return index1 + 2;
}

int main()
{
    int A[7] = {1, 2, 2, 3, 3, 4, 4};
    int l = removeDuplicate(A, 7);
    cout << l << endl;
    for (int j = 0; j != l; j++)
    {
        cout << A[j] << endl;
    }
    int B[] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 7};
    int t = removeTwoDuplicate(B, 13);
    cout << t << endl;
    for (int j = 0; j != t; j++)
    {
        cout << B[j] << endl;
    }
    cout << "*************" << endl;
    vector<int> b = {2, 4, 7, 5};
    sort(b.rbegin(), b.rend());
    for (auto p = b.rbegin(); p != b.rend(); p++)
    {
        cout << *p << endl;
    }
    return 0;
}
