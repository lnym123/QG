/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//��ʽ���нṹ
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
char datatype[30];			

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    Q->front=Q->rear=(Node*) malloc(sizeof (Node));
    Q->front->next=NULL;
    Q->rear->next=NULL;
    Q->rear->data=NULL;
    Q->front->data=NULL;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
    Node *p = Q->front;
    while (Q->front != Q->rear) {
        Q->front = Q->front->next;
        free(p);
        p = Q->front;
    }
    free(Q->rear);
    free(Q);

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){

    if(Q->front==Q->rear)
    {
        return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
     if(IsEmptyLQueue(Q)){
         return FALSE;
     }
     e=Q->front->data;
     return TRUE;


}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    Node *p;
    p=Q->front;

    int length=0;
    while(p->next)
    {
        length++;
        p=p->next;
    }
    return length;

};

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data) {
    Node *p = (Node *) malloc(sizeof(Node));

        if (type == 'i')
    {
        p->data = (int *)data;
    }
    else if (type == 'f')
    {
        p->data = (float *)data;
    }
    else if (type == 'c')
    {
        p->data = (char *)data;
    }
    p->next = NULL;  //β�ڵ�nextָ���ÿ�

    if (Q->front == NULL)  //����Ϊ��
    {
        Q->front = p;
    } else  //���в�Ϊ��
    {
        Q->rear->next = p;
    }
    Q->rear = p;   //���¶�βָ��
    return TRUE;
}


/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(Q->front==Q->rear)	
        return FALSE;
    Node *p=Q->front->next;

    Q->front->next=p->next;
    if(Q->rear==p)	
        Q->rear=Q->front;	
    free(p);	
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    Q->front = Q->rear;
};

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
    if (Q == NULL || foo == NULL) {
        return FALSE;
    }

    Node *cur = Q->front->next;
    while (cur != NULL)
    {
        foo(cur->data); 
        cur = cur->next;
    }

    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
    if(type=='i' ){
        printf("%d\t/",*(int*)q);
    }else if(type=='f' ){
        printf("%f\t", *(float*)q);
    }else if(type=='c'){
        printf("%c\t", *(char *)q);
    }
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


