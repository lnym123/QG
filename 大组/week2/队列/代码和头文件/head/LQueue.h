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
//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
    p->next = NULL;  //尾节点next指针置空

    if (Q->front == NULL)  //队列为空
    {
        Q->front = p;
    } else  //队列不为空
    {
        Q->rear->next = p;
    }
    Q->rear = p;   //更新队尾指针
    return TRUE;
}


/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    Q->front = Q->rear;
};

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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


