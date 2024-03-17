
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include <unistd.h>
#include <winuser.h>
#include "linkedlist.h"



char Menu1[11][40] = {

    "[1]创建链表",
    "[2] 销毁链表",
    "[3] 插入节点",
    "[4] 删除节点",
    "[5] 遍历链表",
    "[6] 查找数据",
    "[7] 翻转链表",
    "[8] 判断链表是否成环",
    "[9] 查找中间节点",
    "[10] 退出 "};
void displaymenu()
{
    int i;
    printf("单链表ADT\n\n");
    for (i = 0; i < 12; i++)
    {
        printf("%s\n", Menu1[i]);
    }
    printf("输入要选择的功能序号:");
}
int main()
{
    int number = 0;
    int num=0;
    LinkedList head=NULL;

    for (;;)
    {
        displaymenu();
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            system("cls");
                
            if (InitList(&head))
            {
                printf("空链表成功");
            }
            else
            {
                printf("空链表创建失败");
            }

            break;

        case 2:
        	  system("cls");
            DestroyList(&head);
                printf("链表销毁完成\n\n\n");
                break;

        case 3:
            system("cls");
            if(head== NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
                printf("请输入数据：");
                scanf("%d", &num);
                if(InsertList(head, num))
                {
                    printf("数据插入成功\n");
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;

        case 4:
            system("cls");
            printf("输入要删除的数据：");
                scanf("%d", &num);
                if(DeleteList(head, num))
                {
                    printf("数据删除成功\n");
                }
                else
                {
                    printf("数据删除失败\n");
                }
                break;


        case 5:
            system("cls");
            if(head== NULL)
            {
                printf("链表为空， 请先创建链表\n");
                break;
            }
            TraverseList(head);
            break;

        case 6:
            system("cls");
            printf("请输入要查找的数据：");
                scanf("%d", &num);
                if(SearchList(head, num))
                {
                    printf("该数存在\n");
                }
                else
                {
                    printf("该数不存在\n");
                }
                break;

        case 7:
            system("cls");
            if(head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if(ReverseList(&head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }

            }
                break;

        case 8:
            system("cls");
            if(head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                if(IsLoopList(head))
                {
                    printf("链表成环\n");
                }
                else
                {
                    printf("链表没有成环\n");
                }
            }
            break;
        case 9:
            system("cls");
            if(head == NULL || head->next == NULL)
            {
                printf("这是空链表, 先创建链表\n");
            }
            else
            {
                printf("链表中间值为%d\n", (FindMidNode(head))->data);
            }
                break;
            break;
        case 10:
            return 0;


        default:
            break;
        }
    }
}

Status InitList(LinkedList *L)
{
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if (list == NULL)
    {
        printf("内存分配失败\n");
        return ERROR;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList *L) {
    LinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
Status InsertList(LNode *p, ElemType Tdata)
{
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if(newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = Tdata;
    newNode->next = NULL;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}

Status DeleteList(LNode *p, ElemType e)
{
    LinkedList nextNode = p->next;
    LinkedList preNode = p;
    if (nextNode == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while (nextNode->data != e)
        {
            preNode = nextNode;
            nextNode = nextNode->next;
            if (nextNode == NULL)
            {
                printf("没有该数据\n");
                return ERROR;
            }
        }
        preNode->next = nextNode->next;
        free(nextNode);
        return success;
    }
}

void TraverseList(LinkedList L)
{
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e)
{
    while (L != NULL)
    {
        if (L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return ERROR;
}

Status ReverseList(LinkedList *L)
{

    if (L == NULL || *L == NULL || (*L)->next == NULL)
    {
        // 空链表或只有一个节点的链表不需要反转
        return success;
    }

    LNode *prev;
    LNode *temp1 ;
    LNode *temp2 ;
    temp1=(*L)->next;
    temp2=temp1->next;
    temp1->next=NULL;
    prev=temp1;
    while (temp2!= NULL) {
        temp1=temp2;
        temp2=temp1->next;
        temp1->next=prev;
        prev=temp1;
    }
    (*L)->next=prev;
    return success;
}
Status IsLoopList(LinkedList L)
{
    LinkedList slow = L, fast = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return success;
        }
    }
    return ERROR;
}
LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while(fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
