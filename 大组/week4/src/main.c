#include <stdio.h>
#include "binary_sort_tree.h"
#include <stdlib.h>

char Menu1[12][40] = {

    "[1] ��������",
    "[2] ��������",
    "[3] ɾ������",
    "[4] �������",
    "[5] ����������ݹ飩",
    "[6] �������",
    "[7] ����������ݹ飩",
    "[8] ��������",
    "[9] �������У��ݹ飩",
    "[10]�������� ",
    "[11] �˳� "};
void displaymenu()
{
    int i;
    printf("���������� ADT\n\n");
    for (i = 0; i < 12; i++)
    {
        printf("%s\n", Menu1[i]);
    }
    printf("����Ҫѡ��Ĺ������:");
}

int main()
{
    BinarySortTreePtr bst;
    bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    bst->root = NULL;

    int data;

    int i = 0;
    for (;;)
    {
        displaymenu();
        scanf("%d", &i);
        switch (i)
        {
           case 1:
            system("cls");
            printf("�����ѯ����\n");
            scanf("%d", &data);
           if( BST_search(bst, data)==1){
               printf("���ݴ���\n");
           }else{
               printf("���ݲ�����\n");
           }
            break;
            case 2:
            system("cls");
            scanf("%d", &data);
           if( BST_insert(bst, data)==1){
               printf("����ɹ�\n");
           }else{
               printf("�����Ѵ���\n");
           }
            break;
        case 3:
            system("cls");
            printf("����Ҫɾ��������\n");
            scanf("%d", &data);
           if( BST_delete(bst, data)==1){
               printf("ɾ�����\n");
           }
           else
           {
               printf("��ɾ�������ݲ�����������\n");
           }
        break;
        case 4:
            system("cls");
           if( BST_preorderI(bst, visit)==0){
               printf("��Ϊ�գ��������\n");
           }
            printf("\n");
            break;
        case 5:
            system("cls");

            if ((BST_preorderI(bst, visit)) == 0)
            {
                printf("��Ϊ�գ��������\n");
            }
            printf("\n");
            break;
        case 6:
            system("cls");

            if ((BST_inorderI(bst, visit)) == 0)
            {
                printf("��Ϊ�գ��������\n");
            }
            printf("\n");
            break;
        case 7:
            system("cls");

            if ((BST_inorderR(bst->root, visit)) == 0)
            {
                printf("��Ϊ�գ��������\n");
            }
            printf("\n");
            break;
        case 8:
            system("cls");

            if ((BST_postorderI(bst, visit)) == 0)
            {
                printf("��Ϊ�գ��������\n");
            }
            printf("\n");
            break;
        case 9:
            system("cls");

            if ((BST_postorderR(bst->root, visit)) == 0)
            {
                printf("��Ϊ�գ��������\n");
            }
            printf("\n");
            break;
        case 10:
            system("cls");

            if ((BST_levelOrder(bst, visit)) == 0)
            {
                printf("��Ϊ�գ��������\n");
            }
            printf("\n");
            break;
            case 11:
            return 0;
 default : break;
        }
    }
    return 0;
}

Status BST_init(BinarySortTreePtr BST)
{
    BST->root = NULL;
    return true;
}

Status BST_insert(BinarySortTreePtr BST, ElemType data)
{


    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (BST->root == NULL)
    {
        BST->root = newNode;
        return true;
    }

    Node *parent = NULL;//��¼��ǰ�ڵ�
    Node *current = BST->root;

    while (current != NULL)
    {
        parent = current;

        if (data < current->value)
        {
            current = current->left;
        }
        else if (data > current->value)
        {
            current = current->right;
        }
        else
        {
            free(newNode);
            return false; // �����Ѵ��ڣ�����ʧ��
        }
    }

    if (data < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    return true;
}
Status BST_search(BinarySortTreePtr BST, ElemType data)
{
    NodePtr current = BST->root;
    while (current != NULL)
    {
        if (current->value == data)
            return true;
        else if (current->value > data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

static Node *findMinInRightSubtree(Node *node, Node **parent)
{
    Node *current = node->right;
    *parent = node;

    while (current->left != NULL)
    {
        *parent = current;
        current = current->left;
    }
    return current;
}

Status BST_delete(BinarySortTreePtr BST, ElemType data)
{
    if (BST == NULL || BST->root == NULL)
    {
        return false; 
    }

    Node *parent = NULL;
    Node *current = BST->root;
    Node *toDelete = NULL;

    while (current != NULL)
    {
        if (data == current->value)
        {
            toDelete = current;
            break;
        }
        else if (data < current->value)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }

    if (toDelete == NULL)
    {
        return false; // ��ɾ�������ݲ�����������
    }

    // �������ֲ�ͬ�����ɾ������
    Node *replaceNode = NULL;
    if (toDelete->left == NULL && toDelete->right == NULL)
    { // Ҫɾ���Ľڵ���Ҷ�ӽڵ�
        if (parent == NULL)
        { // ɾ�����Ǹ��ڵ�
            BST->root = NULL;
        }
        else if (parent->left == toDelete)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(toDelete);
    }
    else if (toDelete->left != NULL && toDelete->right == NULL)
    { // Ҫɾ���Ľڵ�ֻ������
        if (parent == NULL)
        { // ɾ�����Ǹ��ڵ�
            BST->root = toDelete->left;
        }
        else if (parent->left == toDelete)
        {
            parent->left = toDelete->left;
        }
        else
        {
            parent->right = toDelete->left;
        }
        free(toDelete);
    }
    else if (toDelete->left == NULL && toDelete->right != NULL)
    { // Ҫɾ���Ľڵ�ֻ���Һ���
        if (parent == NULL)
        { // ɾ�����Ǹ��ڵ�
            BST->root = toDelete->right;
        }
        else if (parent->left == toDelete)
        {
            parent->left = toDelete->right;
        }
        else
        {
            parent->right = toDelete->right;
        }
        free(toDelete);
    }
    else
    { // Ҫɾ���Ľڵ�����������
        replaceNode = findMinInRightSubtree(toDelete, &parent);
        toDelete->value = replaceNode->value;

        if (parent != toDelete)
        { // replaceNode ���� toDelete ��ֱ������
            parent->left = replaceNode->right;
            replaceNode->right = toDelete->right;
        }
        else
        { // replaceNode �� toDelete ��ֱ������
            toDelete->right = replaceNode->right;
        }
        free(replaceNode);
    }

    return true;
}

Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))
    {
        if (BST == NULL || BST->root == NULL)
        {
            return false;
        }

        NodePtr stack[100];
        int top = -1; 

        // ���ڵ���ջ����ʼѭ��
        stack[++top] = BST->root;

        while (top != -1)
        {
            // ����ջ��Ԫ�ز�����
            NodePtr p = stack[top--];
            visit(p);
            if (p->right != NULL)
            {
                stack[++top] = p->right;
            }
            if (p->left != NULL)
            {
                stack[++top] = p->left;
            }
        }

        return true;
    }

Status BST_preorderR(NodePtr node, void (*visit)(NodePtr))
    {
        if (node == NULL)
            return true;

        visit(node);
        BST_preorderR(node->left, visit);
        BST_preorderR(node->right, visit);
    }

Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))
    {
        if (BST == NULL || BST->root == NULL)
        {
            return false;
        }
        NodePtr stack[100];
        int top = -1;
        NodePtr p = BST->root;

        while (p != NULL || top != -1)
        {
            // �����ǰ�ڵ㲻Ϊ�գ�������ջ�����ƶ���������
            while (p != NULL)
            {
                stack[++top] = p;
                p = p->left;
            }

            // ��ǰ�ڵ�Ϊ�գ����Ѿ�����������ߣ���ʱ����ջ��Ԫ�ز�����
            p = stack[top--];
            visit(p);
            p = p->right;
        }

        return true;
    }

Status BST_inorderR(NodePtr node, void (*visit)(NodePtr))
    {
        if (node == NULL)
            return true;
        BST_inorderR(node->left, visit);
        visit(node);
        BST_inorderR(node->right, visit);
    }

Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr))
    {
        if (BST == NULL || BST->root == NULL)
        {
            return false;
        }

        Node *stack1[100], *stack2[100];
        int top1 = -1, top2 = -1;
        stack1[++top1] = BST->root;

        while (top1 != -1)
        {
            Node *curr = stack1[top1--];
            stack2[++top2] = curr;

            if (curr->left != NULL)
            {
                stack1[++top1] = curr->left;
            }
            if (curr->right != NULL)
            {
                stack1[++top1] = curr->right;
            }
        }

        while (top2 != -1)
        {
            Node *curr = stack2[top2--];
            visit(curr);
        }
    }

Status BST_postorderR(NodePtr node, void (*visit)(NodePtr))
    {
        if(node==NULL){
            return true;
        }
        BST_postorderR(node->left, visit);
        BST_postorderR(node->right, visit);
        visit(node);
    }

Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)){

        if (BST == NULL || BST->root == NULL)
        {
            return false;
        }
        Queue Q;
        InitQueue(&Q);
        EnQueue(&Q, BST->root); // �����ڵ����

        while (!IsEmpty(&Q))
        {
            Node *node = DeQueue(&Q); // ����һ���ڵ�
            visit(node);         

            // ����ýڵ������ӣ����������
            if (node->left != NULL)
            {
                EnQueue(&Q, node->left);
            }
            // ����ýڵ����Һ��ӣ����Һ������
            if (node->right != NULL)
            {
                EnQueue(&Q, node->right);
            }
        }
        return true;
    }
   