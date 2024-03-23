#include "LinkStack.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define NULL ((void *)0)

Status initLStack(LinkStack *s){
    s->top=NULL;
    s->count=0;
    return  SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
    if(s->top==NULL){
        return SUCCESS;
    } else{
        return ERROR;
    }
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
    if(isEmptyLStack(s)){
        return ERROR;
    }else{
        *e=s->top->data;
        return SUCCESS;
    }

}
Status pushLStack(LinkStack *s,ElemType data) {

    LinkStackPtr p = (LinkStackPtr) malloc(sizeof(StackNode));
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;

}

Status traverse(LinkStack *s){
    if(isEmptyLStack(s)){
        return ERROR;
    }else {
        LinkStackPtr p = s->top;
        printf("链栈元素为:\n");
        while (p) {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
        return SUCCESS;
    }
}


Status popLStack(LinkStack *s,ElemType *data){
    if(isEmptyLStack(s)){
        return ERROR;
    }else{
        LinkStackPtr p=s->top;
        *data=s->top->data;
        s->top=s->top->next;
        free(p);
        return SUCCESS;
    }
}



Status LStackLength(LinkStack *s,int *length){
    if(isEmptyLStack(s)){
        return ERROR;
    }else{
        *length=s->count;
        return SUCCESS;
    }
}


Status clearLStack(LinkStack *s)
{
    StackNode *temp;
    while (s->top) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }

    s->count = 0;
    return SUCCESS;
}

/*销毁栈*/
Status destroyLStack(LinkStack *s)
{

    clearLStack(s);
    if (s) {
        s=NULL;
        return SUCCESS;
    }

}
