//
//  linklist.c
//  linklist
//
//  Created by Alan Tanis on 15/10/2016.
//  Copyright © 2016 Alan. All rights reserved.
//
/*
    Experiment I: Reversion of Single Link List
    
    The complete program should include four functions decribed as following:
        1. Initialization of the single link list.  √
        2. Output the value of the nodes in order.  √
        3. Destory the link list.  √
        4. Reverse the list locally.  √
 
    TODO:
        1. The program is able to initialize the list again and again without destorying the list.
        2. The program can destroy the list repeatedly.
        3. I am confused with the concepts of destroying a list and initializing a list.
        4. In short, It doesn't work nice. :(
 */
#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define ELemType int // <- Change the type of data here, if in need.

typedef struct LNode
{
    ELemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList InitLinkList()
{
    LNode *L;
    L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL)
    {
        printf("Initialization Failed");
    }
    else
    {
        L->next = NULL;
        printf("Initialed Successfully!\n");
    }
    return L;
}

Status ListInsertHead(LinkList L)
{
    if (L == NULL) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else{
        ELemType dataInput;
        int i, n;
        printf("How many elements you need to insert from head?\n");
        scanf("%d",&n);
        printf("Please input the elements:\n");
        for (i=1; i<=n; ++i)
        {
            scanf("%d",&dataInput);
            LNode *p;  // The pointer of the node ready to insert.
            p = (LNode *)malloc(sizeof(LNode));  // Apply the memory for the node.
            p->data = dataInput;
            p->next = L->next;
            L->next = p;
            printf("%d/%d elements have been inserted.\n",i,n);
        }
        printf("All elements have been inserted.\n");
        return OK;
    }
}

Status ListInsertTail(LinkList L)
{
    if (L == NULL) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else{
        ELemType dataInput;
        int i, n;
        LNode *q;  // The pointer represents the last node.
        q = L;
        while (q->next!=NULL)  // To find the last node.
        {
            q = q->next;
        }
        printf("How many elements you need to insert from tail?\n");
        scanf("%d",&n);
        printf("Please input the elements:\n");
        for (i=1; i<=n; ++i)
        {
            scanf("%d",&dataInput);
            LNode *p;
            p = (LNode *)malloc(sizeof(LNode));
            p->data = dataInput;
            p->next = NULL;
            q->next = p;
            q = p;  // The node inserted becomes the last node, pointed by *q.
            printf("%d/%d elements have been inserted.\n",i,n);
        }
        printf("All elements have been inserted.\n");
        return OK;
    }
}

Status ListReverse(LinkList L)
{
    if (L == NULL) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else if (L->next == NULL)
    {
        printf("UNABLE TO REVERSE, NO ELEMENTS!\n");
        return ERROR;
    }
    else
    {
        LNode *p, *q, *m;  // m points the node ahead.
        p = L->next;
        q = p->next;    // p points the node reversed
        //m = q->next;
        p->next = NULL;  // Break the link to the head of the list.
        while(q != NULL)  // Start reversing the nodes in the list.
        {
            m = q->next;
            q->next = p;
            p = q;
            q = m;
            //m = q->next;  // Tried 3 different positions of this line of code
        }
        L->next = p;
        return OK;
    }
}
Status DestoryList(LinkList L)
{
    if (L != NULL) {
        LNode *p, *q;
        p = L->next;
        while(p)
        {
            q = p->next;
            free(p);
            p = q;
        }
        L->next = NULL;
        L = NULL;
        printf("The List Destoryed!\n");
        return OK;
    }
    else
    {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
}

Status ListTraverse(LinkList L)
{
    if (L == NULL) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else{
        LNode *p;
        p = L;
        printf("The List: ");
        while (p->next!=NULL)
        {
            p = p->next;
            printf("%d ",p->data);

        }
        printf("\n");
        return OK;
    }
}

int main()
{
    printf("---------------------------------\n");  // Title
    printf("|    Link   List   Reversion    |\n");
    printf("---------------------------------\n");
    printf("|Description:                   |\n");
    printf("|  Please select the operation  |\n");
    printf("| 【1】Initialization            |\n");
    printf("| 【2】Insert Elements From Head |\n");
    printf("| 【3】Insert Elements From Tail |\n");
    printf("| 【4】Traverse                  |\n");
    printf("| 【5】Reverse The Link List     |\n");
    printf("| 【6】BOOM! Destory The List    |\n");
    printf("---------------------------------\n");
    
    int cmd;
    LinkList List = NULL;  // Attention: Remember to set initial status!
    while(scanf("%d",&cmd))
    {
        if (cmd == 1)
            List = InitLinkList();
        else if (cmd == 2)
            ListInsertHead(List);
        else if (cmd == 3)
            ListInsertTail(List);
        else if (cmd == 4)
            ListTraverse(List);
        else if (cmd == 5)
        {
            if(ListReverse(List) != ERROR)
                ListTraverse(List);
        }
        else if (cmd == 6)
            DestoryList(List);
        else
        {
            printf("Excuse me? :(\n");
        }
    }
    printf("\n");
    
    
}
