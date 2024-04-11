//
// Created by eke_l on 2021/4/21.
//
#include <stdlib.h>
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node
{
    ElemType value;
    struct Node *left, *right;
} Node, *NodePtr;

typedef struct BinarySortTree
{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr BST);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr BST, ElemType data);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr BST, ElemType data);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr BST, ElemType data);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)); // 先序无递归

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr node, void (*visit)(NodePtr)); // 递归遍历

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)); // 中序遍历

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr node, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr node, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr));

void visit(NodePtr p)
{
    printf("%d ", p->value);
}
// 队列节点结构体
typedef struct QueueNode
{
    Node *bstNode;
    struct QueueNode *next;
} QueueNode, *QueuePtr;

// 队列结构体
typedef struct Queue
{
    QueuePtr front;
    QueuePtr rear;
} Queue;

// 初始化队列
void InitQueue(Queue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QueueNode));
    Q->front->next = NULL;
}

// 判断队列是否为空
int IsEmpty(Queue *Q)
{
    return Q->front == Q->rear;
}

// 入队
void EnQueue(Queue *Q, Node *node)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
    p->bstNode = node;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

// 出队操作
Node *DeQueue(Queue *Q)
{
    if (IsEmpty(Q))
    {
        return NULL;
    }
    QueuePtr p = Q->front->next;
    Node *node = p->bstNode;
    Q->front->next = p->next;
    if (Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return node;
}
#endif // BINARYSORTTREE_BINARY_SORT_TREE_H
