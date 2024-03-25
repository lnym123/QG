
#define NULL ((void *)0)
#include <stdio.h>
#include "LinkStack.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>


typedef double ElemType1;

//计算用栈
typedef  struct StackNode1
{
    ElemType1 data;
    struct StackNode *next;
}StackNode1, *LinkStackPtr1;

typedef  struct  LinkStack1  //结构堆栈
{
    LinkStackPtr1 top;//栈顶指针
    int	count;//计数器
}LinkStack1;


//链栈
Status dinitLStack(LinkStack1 *s);//初始化栈
Status disEmptyLStack(LinkStack1 *s);//判断栈是否为空
Status dgetTopLStack(LinkStack1 *s, ElemType1 *e);//得到栈顶元素
Status dclearLStack(LinkStack1 *s);//清空栈
Status ddestroyLStack(LinkStack1 *s);//销毁栈
Status dLStackLength(LinkStack1 *s, int *length);//检测栈长度
Status dpushLStack(LinkStack1 *s, ElemType1 data);//入栈
Status dpopLStack(LinkStack1 *s, ElemType1 *data);//出栈
Status dtraverse(LinkStack1 *s);//遍历栈

Status dinitLStack(LinkStack1 *s){
    s->top=NULL;
    s->count=0;
    return  SUCCESS;
}

//判断栈是否为空
Status disEmptyLStack(LinkStack1 *s){
    if(s->top==NULL){
        return SUCCESS;
    } else{
        return ERROR;
    }
}

//得到栈顶元素
Status dgetTopLStack(LinkStack1 *s,ElemType1 *e){
    if(disEmptyLStack(s)){
        return ERROR;
    }else{
        *e=s->top->data;
        return SUCCESS;
    }

}
//入栈
Status dpushLStack(LinkStack1 *s,ElemType1 data) {

    LinkStackPtr1 p = (LinkStackPtr1) malloc(sizeof(StackNode1));
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;

}




Status dpopLStack(LinkStack1 *s,ElemType1 *data){
    if(disEmptyLStack(s)){
        return ERROR;
    }else{
        LinkStackPtr1 p=s->top;
        *data=s->top->data;
        s->top=s->top->next;
        free(p);
        return SUCCESS;
    }
}












