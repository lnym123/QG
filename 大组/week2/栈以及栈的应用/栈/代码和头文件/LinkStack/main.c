#include "LinkStack.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
char Menu1[11][40] = {

        "[1] ��ʼ��ջ",
        "[2] �õ�ջ��Ԫ��",
        "[3] ��ջ",
        "[4] ��ջ",
        "[5] ���ջ����",
        "[6] ����ջ",
        "[7] ���ջ",
        "[8] ����ջ",
        "[9] �˳� "};
void displaymenu()
{
    int i;
    printf("��ջ\n\n");
    for (i = 0; i < 9; i++)
    {
        printf("%s\n", Menu1[i]);
    }
    printf("����Ҫѡ��Ĺ������:");
}
int main() {
    ElemType innumber;
    int outnumber;
    int length=0;
    int number = 0;
    ElemType num = 0;
    LinkStack head;

    head.top=NULL;
    for (;;) {
        displaymenu();
        scanf("%d", &number);
        for(;;){
        if(number<0||number>9){
            printf("�����������������\n");
            scanf("%d", &number);
        }else{
            break;
        }}

        switch (number) {
            case 1:
                system("cls");
                if(initLStack(&head)){
                    printf("ջ��ʼ���ɹ�\n\n");
                }
                break;
            case 2:
                system("cls");
                if(getTopLStack(&head,&num)){
                printf("ջ��Ԫ��Ϊ%d\n",num);
            }else{
                printf("ջΪ�գ�������ջ\n");
            }
                break;
            case 3:
                system("cls");
                printf("����������\n");
                scanf("%d",&innumber);
                if(pushLStack(&head,innumber)){
                    printf("��ջ�ɹ�\n\n");
                }
                break;


            case 4:
                system("cls");
                if(popLStack(&head,&outnumber)){
                    printf("Ԫ��%d�ѳ�ջ\n",outnumber);
                }else{
                    printf("ջΪ�գ�������ջ\n");
                }
                break;
            
            case 5:
                system("cls");
                if(LStackLength(&head,&length)){
                    printf("��ջ����Ϊ��%d\n\n",length);
                }else{
                    printf("��ջ����Ϊ0\n\n");
                }

                    break;

            case 6:
                system("cls");
                if(destroyLStack(&head)) {
                    printf("ջ�������\n\n");
                }

                break;

            case 7:
                system("cls");
                if(clearLStack(&head)) {
                    printf("ջ������\n\n");
                }

                break;


            case 8:
                system("cls");
                if(traverse(&head)){
                    break;
                }else{
                    printf("��ջΪ��\n");
                }

                break;



            case 9:
                return 0;

        }
    }
}























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
