#include "LinkStack.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
char Menu1[11][40] = {

        "[1] 初始化栈",
        "[2] 得到栈顶元素",
        "[3] 入栈",
        "[4] 出栈",
        "[5] 检测栈长度",
        "[6] 销毁栈",
        "[7] 清空栈",
        "[8] 遍历栈",
        "[9] 退出 "};
void displaymenu()
{
    int i;
    printf("链栈\n\n");
    for (i = 0; i < 9; i++)
    {
        printf("%s\n", Menu1[i]);
    }
    printf("输入要选择的功能序号:");
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
            printf("输入错误，请重新输入\n");
            scanf("%d", &number);
        }else{
            break;
        }}

        switch (number) {
            case 1:
                system("cls");
                if(initLStack(&head)){
                    printf("栈初始化成功\n\n");
                }
                break;
            case 2:
                system("cls");
                if(getTopLStack(&head,&num)){
                printf("栈顶元素为%d\n",num);
            }else{
                printf("栈为空，请先入栈\n");
            }
                break;
            case 3:
                system("cls");
                printf("请输入数据\n");
                scanf("%d",&innumber);
                if(pushLStack(&head,innumber)){
                    printf("入栈成功\n\n");
                }
                break;


            case 4:
                system("cls");
                if(popLStack(&head,&outnumber)){
                    printf("元素%d已出栈\n",outnumber);
                }else{
                    printf("栈为空，请先入栈\n");
                }
                break;
            
            case 5:
                system("cls");
                if(LStackLength(&head,&length)){
                    printf("链栈长度为：%d\n\n",length);
                }else{
                    printf("链栈长度为0\n\n");
                }

                    break;

            case 6:
                system("cls");
                if(destroyLStack(&head)) {
                    printf("栈销毁完成\n\n");
                }

                break;

            case 7:
                system("cls");
                if(clearLStack(&head)) {
                    printf("栈清除完成\n\n");
                }

                break;


            case 8:
                system("cls");
                if(traverse(&head)){
                    break;
                }else{
                    printf("链栈为空\n");
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
