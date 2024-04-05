
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

// 插入排序
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

// 归并排序
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
    // 将原数组 arr 的元素复制到两个临时数组t1，t2
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
    // 临时数组回到原数组
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
        int m = l + (r - l) / 2; // 中点
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r); // 递归地对左半部分和右半部分进行排序。
        Merge(arr, l, m, r);      // 合并已排序的左半部分和右半部分。
    }
}

// 快速排序（递归版）
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
    arr[i + 1] = arr[high]; // 让枢轴位于正确位置，左边都比枢轴小
    arr[high] = temp;

    return (i + 1);
}

void QuickSort(int arr[], int low, long high)
{

    if (low < high)
    {                                        // 若当前数组为空或者就一个，返回
        int pi = QuickSort2(arr, low, high); // 得到枢轴

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
// 计数排序
void CountSort(int arr[], int n, int max_val)
{

    int result[n];
    int count[max_val + 1] = {0};

    for (int i = 0; i < n; i++)
    { // 统计每个元素出现的次数
        count[arr[i]]++;
    }

    for (int i = 1; i <= max_val; i++)
    {
        count[i] += count[i - 1]; // 计算累积和
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

    // 计数排序
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // 填充输出数组
    for (int i = n - 1; i >= 0; i--)
    {
        result[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将输出数组复制回原数组
    for (int i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

void radixsort(int arr[], int n)
{

    // 找出最大数
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // 从最低有效位开始排序
    for (int exp = 1; max_val / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}
