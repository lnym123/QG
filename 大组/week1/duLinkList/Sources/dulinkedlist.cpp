//
// Created by y on 2024/3/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "dulinkedlist.h"


char Menu1[10][40] = {

        "[1] 创建空链表",
        "[2] 销毁链表",
        "[3] 头插法插入数据",
        "[4] 尾插法插入数据",
        "[5] 遍历链表",
        "[6] 删除数据",
        "[7] 退出 "};
void displaymenu()
{
    int i;
    printf("双链表ADT\n\n");
    for (i = 0; i < 7; i++)
    {
        printf("%s\n", Menu1[i]);
    }
    printf("输入要选择的功能序号:");
}
int main() {
    int number = 0;
    int num = 0;
    DuLinkedList head=NULL;
    for (;;) {
        displaymenu();
        scanf("%d", &number);
        switch (number) {
            case 1://创建空链表
            {
            	system("cls");
                if (InitList_DuL(&head)) {
                    printf("空链表创建成功\n");
                } else {
                    printf("空链表创建失败\n");
                }
                break;
            }
            case 2://销毁链表
            {   system("cls");
                DestroyList_DuL(&head);
                printf("链表销毁成功\n");
                break;
            }
            case 3://头插法插入数据
            {
                system("cls");
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertBeforeList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }

                break;
            }
            case 4://尾插法插入数据
            {   system("cls");
                if (head == NULL) {
                    printf("链表未创建，请先创建链表\n");
                } else {
                    DuLinkedList newNode;
                    if (InitList_DuL(&newNode)) {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if (InsertAfterList_DuL(head, newNode)) {
                            printf("数据插入成功\n");
                        } else {
                            printf("数据插入失败\n");
                        }
                    } else {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 5://遍历链表
            {   system("cls");
                TraverseList_DuL(head);
                break;

                break;
            }
            case 6://删除数据
            {   system("cls");
                if (head == NULL) {
                    printf("链表未创建，请先创建链表\n");
                } else {
                    printf("你想删除哪个数据：");
                    scanf("%d", &num);
                    if (DeleteList_DuL(head, &num)) {
                        printf("数据删除成功\n");
                    } else {
                        printf("数据删除失败\n");
                    }
                }
                break;
            }
            case 7:
                return 0;


        }
    }
}

Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if(List == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(p->next == NULL)//当链表为空时，直接连接p、q
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return SUCCESS;
    }
}
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

void TraverseList_DuL(DuLinkedList L) {
    if(L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }
    else if(L->next == NULL)
    {
        printf("当前链表为空\n");
    }
    else
    {
        DuLinkedList temp = L->next;
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }

    }
}

Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p->next == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;
        //找到删除结点的位置
        while(posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("找不到该数据\n");
                return error;
            }
        }
        if(posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        free(posNode);
        return SUCCESS;
    }
}
