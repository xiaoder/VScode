#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int random(int m, int n)
{
    return rand() % n + m;
}

int compareCount, swapCount;

void quickSort(int *arr, int left, int right)
{
    int i, j, t, temp;
    if (left > right)
    {
        return;
    }
    if (arr[(left + right) / 2] <= arr[left] && arr[left] <= arr[right] || arr[right] <= arr[left] && arr[left] <= arr[(left + right) / 2])
    {
        temp = arr[left];
    }
    else if (arr[left] <= arr[(left + right) / 2] && arr[(left + right) / 2] <= arr[right] || arr[right] <= arr[(left + right) / 2] && arr[(left + right) / 2] <= arr[left])
    {
        swapCount++;
        temp = arr[(left + right) / 2];
        arr[(left + right) / 2] = arr[left];
        arr[left] = temp;
    }
    else
    {
        swapCount++;
        temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
    }
    i = left;
    j = right;
    while (i != j)
    {
        while (arr[j] >= temp && i < j)
        {
            j--;
            compareCount++;
        }
        while (arr[i] <= temp && i < j)
        {
            i++;
            compareCount++;
        }
        if (i < j)
        {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            swapCount++;
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;
    swapCount++;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
    return;
}

int main()
{
    for (int t = 0; t < 3; t++)
    {
        cout << "��" << t + 1 << "������" << endl;
        compareCount = 0;
        swapCount = 0;
        srand(int(time(0)));
        cout << "���������ݸ���:";
        int n;
        cin >> n;
        int *arr = new int[n];
        cout << "���������ݷ�Χ:";
        int start, end;
        cin >> start >> end;
        cout << "������ɵ�����:";
        for (int i = 0; i < n; i++)
        {
            arr[i] = random(start, end);
            cout << arr[i] << " ";
        }
        cout << endl;
        quickSort(arr, 0, n - 1);
        cout << "�Ƚϴ���:" << compareCount << endl;
        cout << "��������:" << swapCount << endl;
        cout << "����������:";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}