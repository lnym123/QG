
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
typedef struct GroupOfNumbers
{
  int numbers[100];
} GroupOfNumbers;

void savdtofile2(GroupOfNumbers *p);


int model = 0;
int op = 0;
int op2 = 0;
long size;
const int NUM_GROUPS = 100000; // 十万组
GroupOfNumbers *groups = (GroupOfNumbers *)malloc(NUM_GROUPS * sizeof(GroupOfNumbers));
char Menu1[11][40] = {

    "[1] 生成测试数据",
    "[2] 读取测试数据",
    "[3] 清空测试数据",
    "[4] 插入排序",
    "[5] 归并排序",
    "[6] 快排(递归版)",
    "[7] 计数排序",
    "[8] 基数计数排序",
    "[9] 退出 "};
void displaymenu()
{
  int i;
  printf("排序\n\n");
  for (i = 0; i < 9; i++)
  {
    printf("%s\n", Menu1[i]);
  }
  printf("输入要选择的功能序号:");
}

int main()
{

  GroupOfNumbers *groupsmid = groups;
  int mid[200000];
  FILE *fp = fopen("data.txt", "r");

  int number = 0;
  int i;
  int choice;
  clean(mid);

  for (;;)
  {
    displaymenu();
    scanf("%d", &number);
    switch (number)
    {

    case 1:

      system("cls");
      printf("选择数据类型：\n1:大数据量\n2:大量小数据\n");
      for (;;)
      {
        scanf("%d", &choice);
        if (choice == 1)
        {
          model = 1;
          printf("选择数据量层次:1、10000 2、50000 3、200000\n");
          int choice1;
          for (;;)
          {
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
              Generate_td(10000);
              size = 10000;
              system("cls");
              printf("数据已经生成并保存至data文件,使用前请读取\n");

              break;
            }
            else if (choice1 == 2)
            {
              Generate_td(50000);
              size = 50000;
              system("cls");
              printf("数据已经生成并保存至data文件,使用前请读取\n");
              break;
            }
            else if (choice1 == 3)
            {
              Generate_td(200000);
              size = 200000;
              system("cls");
              printf("数据已经生成并保存至data文件,使用前请读取\n");
              break;
            }
            else
            {
              printf("输入错误，重新输入");
            }
          }

          break;
        }
        else if (choice == 2)
        {
          model = 2;

          Generate_td2();
          system("cls");
          printf("数据已经生成并保存至data1文件,使用前请读取\n");
          break;
        }
        else
        {
          printf("输入错误，重新输入\n");
        }
      }
      op = 1;

      break;
    case 2:
      system("cls");
      if (op == 0)
      {
        printf("数据未生成，请先生成随机数");
        break;
      }
      for (int i = 0; i < 200000; i++)
      {
        fscanf(fp, "%d", &mid[i]);
      }

      printf("数据读取完毕，可进行操作\n");
      op2 = 1;
      break;
    case 3:
      system("cls");
      clean(mid);
      printf("文件中生成的随机数已清除");
      break;

    case 4:
      system("cls");
      i = judge1();
      if (i == 1)
      {
        break;
      }
      if (model == 1)
      {
        {
          clock_t start = clock();
          InsertSort(mid, size);
          clock_t diff = clock() - start;
          printf("总用时%d ms\n", diff);
          savetofile(mid, size);
        }
      }
      else
      {
        clock_t start = clock();
        for (long g = 0; g < NUM_GROUPS; ++g)
        {

          InsertSort(groups[g].numbers, 100);
        }
        clock_t diff = clock() - start;
        printf("总用时%d ms\n", diff);
        savdtofile2(groups);
      }
      // printf("排序结果已经保存至changed_data");

      break;

    case 5:
      system("cls");
      i = judge1();
      if (i == 1)
      {
        break;
      }
      if (model == 1)
      {
        {
          clock_t start = clock();
          MergeSort(mid, 0, size);
          clock_t diff = clock() - start;
          printf("总用时%d ms\n", diff);
        }
      }
      else
      {
        clock_t start = clock();
        for (long g = 0; g < NUM_GROUPS; ++g)
        {
          for (int n = 0; n < 100; ++n)
          {
            MergeSort(groups[g].numbers, 0, 100);
          }
        }
        clock_t diff = clock() - start;
        printf("总用时%d ms\n", diff);
        savdtofile2(groups);
      }

      savetofile(mid, size);
      break;
    case 6:
      system("cls");
      i = judge1();
      if (i == 1)
      {
        break;
      }
      if (model == 1)
      {
        {
          clock_t start = clock();
          QuickSort(mid, 0, size);
          clock_t diff = clock() - start;
          printf("总用时%d ms\n", diff);

          savetofile(mid, size);
        }
      }
      else
      {
        clock_t start = clock();
        for (long g = 0; g < NUM_GROUPS; ++g)
        {
          for (int n = 0; n < 100; ++n)
          {
            QuickSort(groups[g].numbers, 0, 100);
          }
        }
        clock_t diff = clock() - start;
        printf("总用时%d ms\n", diff);
        savdtofile2(groups);
      }

      break;
    case 7:

      system("cls");
      i = judge1();
      if (i == 1)
      {
        break;
      }
      if (model == 1)
      {
        {
          clock_t start = clock();
          printf("开始时间：%ld\n", start);

          CountSort(mid, size, 100000);

          clock_t end = clock();
          printf("结束时间：%ld\n", end);

          double duration_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0; // 转换为毫秒
          printf("总用时%.3f ms\n", duration_ms);
          savetofile(mid, size);
        }
      }
      else
      {
        clock_t start = clock();
        for (long g = 0; g < NUM_GROUPS; ++g)
        {

          CountSort(groups[g].numbers, 100, 100000);
        }
        clock_t diff = clock() - start;
        printf("总用时%d ms\n", diff);
        savdtofile2(groups);
      }

      break;
    case 8:
      system("cls");
      i = judge1();
      if (i == 1)
      {
        break;
      }
      if (model == 1)
      {
        {
          clock_t start = clock();
          printf("开始时间：%ld\n", start);

          radixsort(mid, size);

          clock_t end = clock();
          printf("结束时间：%ld\n", end);

          double duration_ms = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0; // 转换为毫秒
          printf("总用时%.3f ms\n", duration_ms);

          savetofile(mid, size);
        }
      }
      else
      {
        clock_t start = clock();
        for (long g = 0; g < NUM_GROUPS; ++g)
        {

          radixsort(groups[g].numbers, 100);
        }
        clock_t diff = clock() - start;
        printf("总用时%d ms\n", diff);
        savdtofile2(groups);
      }
      break;
    case 9:
      return 0;
    }
  }
}
void savetofile(int arr[], long size)
{
  FILE *fp = fopen("changed_data.txt", "w");
  for (int i = 0; i < size; i++)
  {
    fprintf(fp, "%d ", arr[i]);
  }
  fclose(fp);
}
void savdtofile2(GroupOfNumbers *p)
{
  FILE *fp1 = fopen("changed_data.txt", "a+");
  for (int i = 0; i < NUM_GROUPS; i++)
  {
    for (int n = 0; n < 100; ++n)
    {
      fprintf(fp1, "%d ", groups[i].numbers[n]);
    }
    fprintf(fp1, "\n\n");
  }
  fclose(fp1);
}

int judge1()
{
  if (op == 0)
  {
    printf("数据未生成，请先生成随机数\n");
    return 1;
  }
  if (op2 == 0)
  {
    printf("数据未从文件中读取，请先读取\n");
    return 1;
  }
  return 0;
}
void clean(int arr[])
{
  for (int i = 0; i < sizeof(arr); i++)
  {
    arr[i] = 0;
  }
  op = 0;
  op2 = 0;
  FILE *fp = fopen("data.txt", "w");
  fclose(fp);
  FILE *fp1 = fopen("data1.txt", "w");
  fclose(fp1);
  FILE *fp2 = fopen("changed_data.txt", "w");
  fclose(fp2);
}

void Generate_td(long size)
{
  long arr[size];
  long i;
  // 使用当前时间作为随机数生成器的种子，以确保每次运行程序时生成的随机数序列都不同
  srand((unsigned int)time(NULL));
  // 生成随机数并存储在数组中
  for (i = 0; i < size; i++)
  {
    arr[i] = rand();
  }
  FILE *fp = fopen("data.txt", "a+");
  for (int i = 0; i < size; i++)
  {
    fprintf(fp, "%ld ", arr[i]);
  }
  fclose(fp);
}
void Generate_td2()
{
  srand((unsigned)time(NULL));

  // 遍历每组，生成100个随机数
  for (long g = 0; g < NUM_GROUPS; ++g)
  {
    for (int n = 0; n < 100; ++n)
    {
      groups[g].numbers[n] = rand();
    }
  }
  FILE *fp1 = fopen("data1.txt", "a+");
  for (int i = 0; i < NUM_GROUPS; i++)
  {
    for (int n = 0; n < 100; ++n)
    {
      fprintf(fp1, "%d ", groups[i].numbers[n]);
    }
    fprintf(fp1, "\n\n");
  }
  fclose(fp1);
}
