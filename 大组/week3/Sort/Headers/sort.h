
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void InsertSort(int arr[], int n);
void Merge(int arr[], int l, int m, int r);
void MergeSort(int arr[], int l, int r);
void QuickSort(int arr[], int low, long high);
int QuickSort2(int arr[], int low, long high);
void Generate_td2();
void CountSort(int arr[], int n, int max_val);
void countingSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
void Generate_td(long size);
int judge1();
void savetofile(int arr[], long size);
void clean(int arr[]);

// ��������
void InsertSort(int arr[], int n)
{

    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// �鲢����
void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int t1[n1], t2[n2];

    for (int i = 0; i < n1; i++)
    {
        t1[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        t2[j] = arr[m + 1 + j];
    }
    // ��ԭ���� arr ��Ԫ�ظ��Ƶ�������ʱ����t1��t2
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (t1[i] <= t2[j])
        {
            arr[k] = t1[i];
            i++;
        }
        else
        {
            arr[k] = t2[j];
            j++;
        }
        k++;
    }
    // ��ʱ����ص�ԭ����
    while (i < n1)
    {
        arr[k] = t1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = t2[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int l, int r)
{

    if (l < r)
    {
        int m = l + (r - l) / 2; // �е�
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r); // �ݹ�ض���벿�ֺ��Ұ벿�ֽ�������
        Merge(arr, l, m, r);      // �ϲ����������벿�ֺ��Ұ벿�֡�
    }
}

// �������򣨵ݹ�棩
int QuickSort2(int arr[], int low, long high)
{
    int point = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= point)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high]; // ������λ����ȷλ�ã���߶�������С
    arr[high] = temp;

    return (i + 1);
}

void QuickSort(int arr[], int low, long high)
{

    if (low < high)
    {                                        // ����ǰ����Ϊ�ջ��߾�һ��������
        int pi = QuickSort2(arr, low, high); // �õ�����

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
// ��������
void CountSort(int arr[], int n, int max_val)
{

    int result[n];
    int count[max_val + 1] = {0};

    for (int i = 0; i < n; i++)
    { // ͳ��ÿ��Ԫ�س��ֵĴ���
        count[arr[i]]++;
    }

    for (int i = 1; i <= max_val; i++)
    {
        count[i] += count[i - 1]; // �����ۻ���
    }

    for (int i = n - 1; i >= 0; i--)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}

void countingSort(int arr[], int n, int exp)
{
    int result[n];
    int count[10] = {0};

    // ��������
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // ����������
    for (int i = n - 1; i >= 0; i--)
    {
        result[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // ��������鸴�ƻ�ԭ����
    for (int i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

void radixsort(int arr[], int n)
{

    // �ҳ������
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // �������Чλ��ʼ����
    for (int exp = 1; max_val / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}
