//
#include <stdio.h>

#include <string.h>
#include <windows.h>
#include "calculator.h"
#include "LinkStack.h"
int cal(char *p1);

void changeEquation(char *p,char*r);
int main(){
    for(;;) {
        char changedEquation[20];
        char tobechanged[20];
        printf("请输入正确表达式\n");
        gets(tobechanged);
        changeEquation(tobechanged,changedEquation);
        double result = cal(changedEquation);
        printf("%lf\n",result);
    }
    system("pause");
}


int cal(char *p1){

    LinkStack1 cal;   //计算栈
    cal.top=NULL;
    for(int i=0;i<strlen(p1);i++){
        if(p1[i] != '+' && p1[i] != '-' && p1[i] != '*' && p1[i] != '/'){
            dpushLStack(&cal, (double)(p1[i]));
        }

        if(p1[i]=='+'||p1[i]=='-'||p1[i]=='*'||p1[i]=='/') {
            double num1, num2;
            double result=1.0;
            dpopLStack(&cal, &num2);
            dpopLStack(&cal, &num1);
            num1*=1.0;
            num2*=1.0;
            if (p1[i] == '+') {
                result=num1+num2;
                dpushLStack( &cal,  result);
            }
            if (p1[i] == '-') {
                result=num1-num2;
                dpushLStack( &cal,  result);
            }
            if (p1[i] == '/') {
                result=num1/num2;
                dpushLStack( &cal,  result);
            }
            if (p1[i] == '*') {
                result=num1*num2;
                dpushLStack( &cal,  result);
            }

        }
    }
    double result;
    dpopLStack(&cal, &result);
    return result;
}













 void changeEquation(char *p,char*r){
     char Equation[30]="0";
     char ChEquation[30]="0";
     LinkStack mid;

     int chi=0;
     initLStack(&mid);
     strcpy(Equation,p);

     int mid222=0;
     char store[30]="0";

     int m=0;
     for (int i = 0; i < strlen(Equation); ) {
         if (Equation[i] == '+' || Equation[i] == '-' || Equation[i] == '*' || Equation[i] == '/'|| Equation[i] == '('|| Equation[i] == ')') {
             store[m] = Equation[i];
             m++;
             i++;
             continue;

         }
         while (Equation[i] > 47 && Equation[i] < 58) {
             mid222 = mid222*10 + (Equation[i] - 48);
             i++;
         }
         store[m] = mid222;
         m++;
         mid222 = 0;
     }
     strcpy(Equation,store);
    //读入计算式
    for(int i=0;i<strlen(store);i++){

        if(store[i] != '+' && store[i] != '-' && store[i] != '*' && store[i] != '/'&& store[i] != '('&& store[i] != ')'){
            ChEquation[chi]= Equation[i];
            chi++;//数字直接输出
            continue;
        }
        //左括号压进
        if(Equation[i]=='('){
            pushLStack(&mid,Equation[i]);
        }
        //运算符
        if(Equation[i]=='+'||Equation[i]=='-'||Equation[i]=='*'||Equation[i]=='/'){
            if(isEmptyLStack((&mid))) {
                pushLStack(&mid,Equation[i]);
                continue;//空直接压
            }
            char isLB;
            getTopLStack(&mid,&isLB);
            if(isLB=='('){
                pushLStack(&mid,Equation[i]);   //栈顶为左括号
                continue;
            }
            if( compareoperator(Equation[i],&mid)==SUCCESS){
                pushLStack(&mid,Equation[i]);
                continue;//  若优先级大于栈顶运算符时，则把它压栈
            }else {//若优先级小于等于顶运算符时，将栈顶运算符弹出并输出;再比?较新的栈顶运算符，直到该运算符大于顶运算符优先级为止，然?后将该运算符压栈;
                for (; compareoperator(Equation[i], &mid) ==
                       ERROR||compareoperator(Equation[i], &mid) ==
                              MIDDLE;) {
                    char pop;
                    popLStack(&mid, &pop);
                    ChEquation[chi] = pop;
                    chi++;
                }
                pushLStack(&mid,Equation[i]);
                continue;//  若优先级大于栈顶运算符时，则把它压栈
            }
        }

        //右括号
        if(Equation[i]==')'){
            char pop1;
            popLStack(&mid,&pop1);
            ChEquation[chi]=pop1;
            chi++;
            getTopLStack(&mid,&pop1);
            while(pop1!='('){
                popLStack(&mid,&pop1);
                ChEquation[chi]=pop1;
                chi++;
                getTopLStack(&mid,&pop1);
            }
            popLStack(&mid,&pop1);

        }
    }

    while(isEmptyLStack(&mid)==ERROR) {
        char last;
        popLStack(&mid, &last);
        ChEquation[chi] = last;
        chi++;
    }

    strcpy(r,ChEquation);

}


