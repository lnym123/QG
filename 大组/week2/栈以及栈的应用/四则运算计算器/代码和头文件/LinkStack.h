#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define NULL ((void *)0)

#include <stdlib.h>
#include <stdio.h>

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1,
    MIDDLE =2
} Status;

typedef char ElemType;


//转换用栈
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef  struct  LinkStack  //结构堆栈
{
	LinkStackPtr top;//栈顶指针
	int	count;//计数器
}LinkStack;

//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s, ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s, int *length);//检测栈长度
Status pushLStack(LinkStack *s, ElemType data);//入栈
Status popLStack(LinkStack *s, ElemType *data);//出栈
Status traverse(LinkStack *s);//遍历栈

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
//入栈
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

Status compareoperator ( char c,LinkStack *s){  //success不执行
    if(isEmptyLStack(s)){
        return SUCCESS;
    }
    char compared;
    getTopLStack(s,&compared);
    if(c==compared){


            return MIDDLE;
        }


      //加减号遇到，或乘除号
    if(c== '+' || c== '-'){
        if(compared=='('){
            return SUCCESS;}else {
            return ERROR;
        }
        }
    else if(c== '*' || c== '/') {
        if (compared == '*' || compared == '/') {
            return ERROR;

        }

    }
    if(c== '*' || c== '/'){
        if (compared == '+' || compared == '-'||compared == '(') {
            return SUCCESS;
        }
    }



}



#endif 
