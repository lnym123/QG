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


//ת����ջ
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef  struct  LinkStack  //�ṹ��ջ
{
	LinkStackPtr top;//ջ��ָ��
	int	count;//������
}LinkStack;

//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s, ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s, int *length);//���ջ����
Status pushLStack(LinkStack *s, ElemType data);//��ջ
Status popLStack(LinkStack *s, ElemType *data);//��ջ
Status traverse(LinkStack *s);//����ջ

#define NULL ((void *)0)

Status initLStack(LinkStack *s){
    s->top=NULL;
    s->count=0;
    return  SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
    if(s->top==NULL){
        return SUCCESS;
    } else{
        return ERROR;
    }
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
    if(isEmptyLStack(s)){
        return ERROR;
    }else{
        *e=s->top->data;
        return SUCCESS;
    }

}
//��ջ
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
        printf("��ջԪ��Ϊ:\n");
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

/*����ջ*/
Status destroyLStack(LinkStack *s)
{

    clearLStack(s);
    if (s) {
        s=NULL;
        return SUCCESS;
    }

}

Status compareoperator ( char c,LinkStack *s){  //success��ִ��
    if(isEmptyLStack(s)){
        return SUCCESS;
    }
    char compared;
    getTopLStack(s,&compared);
    if(c==compared){


            return MIDDLE;
        }


      //�Ӽ�����������˳���
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
