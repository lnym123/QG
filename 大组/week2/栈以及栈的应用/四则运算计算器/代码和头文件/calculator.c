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
        printf("��������ȷ���ʽ\n");
        gets(tobechanged);
        changeEquation(tobechanged,changedEquation);
        double result = cal(changedEquation);
        printf("%lf\n",result);
    }
    system("pause");
}


int cal(char *p1){

    LinkStack1 cal;   //����ջ
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
    //�������ʽ
    for(int i=0;i<strlen(store);i++){

        if(store[i] != '+' && store[i] != '-' && store[i] != '*' && store[i] != '/'&& store[i] != '('&& store[i] != ')'){
            ChEquation[chi]= Equation[i];
            chi++;//����ֱ�����
            continue;
        }
        //������ѹ��
        if(Equation[i]=='('){
            pushLStack(&mid,Equation[i]);
        }
        //�����
        if(Equation[i]=='+'||Equation[i]=='-'||Equation[i]=='*'||Equation[i]=='/'){
            if(isEmptyLStack((&mid))) {
                pushLStack(&mid,Equation[i]);
                continue;//��ֱ��ѹ
            }
            char isLB;
            getTopLStack(&mid,&isLB);
            if(isLB=='('){
                pushLStack(&mid,Equation[i]);   //ջ��Ϊ������
                continue;
            }
            if( compareoperator(Equation[i],&mid)==SUCCESS){
                pushLStack(&mid,Equation[i]);
                continue;//  �����ȼ�����ջ�������ʱ�������ѹջ
            }else {//�����ȼ�С�ڵ��ڶ������ʱ����ջ����������������;�ٱ�?���µ�ջ���������ֱ������������ڶ���������ȼ�Ϊֹ��Ȼ?�󽫸������ѹջ;
                for (; compareoperator(Equation[i], &mid) ==
                       ERROR||compareoperator(Equation[i], &mid) ==
                              MIDDLE;) {
                    char pop;
                    popLStack(&mid, &pop);
                    ChEquation[chi] = pop;
                    chi++;
                }
                pushLStack(&mid,Equation[i]);
                continue;//  �����ȼ�����ջ�������ʱ�������ѹջ
            }
        }

        //������
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


