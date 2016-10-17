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
#include <unistd.h>
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
    
}LNode;

// adding a struct to repack the LinkList
// because you could not let class LinkList disclosing in programme
typedef struct LinkList {
    LNode *head;
    LNode *tail; //more convenience for insert or delete on tail
    int count;
}LinkList;

//a list that has a head null node
LinkList * InitLinkList()
{
    LinkList *list = malloc(sizeof(LinkList));
    list->count=0;
    
    //construct head node
    LNode *L;
    L = malloc(sizeof(LNode));
    L->data = 0;
    L->next = NULL;
    
    //has a error about node&List allocate memory
    if(!(L&&list)) //if L==null than L==0x00
    {
        printf("Initialization Failed");
        return NULL;
    }
    
    list->head = L;
    list->tail = L;
    list->count=0;
    printf("Initialed Successfully!\n");
    
    return list;
}

Status ListInsertHead(LinkList* L)// change interface
{
    if (!L) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else{
        ELemType dataInput;
        unsigned int i, n;
        printf("How many elements you need to insert from head?\n");
        scanf("%d",&n);
        printf("Please input the elements:\n");
        for (i=1; i<=n; ++i)
        {
            scanf("%d",&dataInput);
            LNode *p;  // The pointer of the node ready to insert.
            p = (LNode *)malloc(sizeof(LNode));  // Apply the memory for the node.
            p->data = dataInput;
            //caution！ the list has null head node
            p->next = L->head->next;
            L->head->next = p;
            //if this node is the first, undate the tail
            if (L->count==0) L->tail = p;
            L->count++;
            printf("%d/%d elements have been inserted.\n",i,n);
        }
        printf("All elements have been inserted.\n");
        return OK;
    }
}

Status ListInsertTail(LinkList *list)
{
    if (!list) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else{
        ELemType dataInput;
        int i, n;
        LNode *q;  // The pointer represents the last node.
        q = list->tail;
        //this will optimist the find method at O(1)
        printf("How many elements you need to insert from tail?\n");
        scanf("%d",&n);
        printf("Please input the elements:\n");
        for (i=1; i<=n; ++i)
        {
            scanf("%d",&dataInput);
            LNode *p;
            p = (LNode *)malloc(sizeof(LNode));
            p->data = dataInput;
            //this pointer modify's method could aslo used in circle list
            p->next = q->next;
            q->next = p;
            q = p;  // The node inserted becomes the last node, pointed by *q.
            list->tail = p;   //also will be the tail node in "list"
            
            list->count++;
            printf("%d/%d elements have been inserted.\n",i,n);
        }
        printf("All elements have been inserted.\n");
        return OK;
    }
}

Status ListReverse(LinkList *list)
{
    if (!list) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    else if (list->count==0)
    {
        printf("UNABLE TO REVERSE, NO ELEMENTS!\n");
        return ERROR;
    }
    else
    {
        LNode *p, *q ,*m;  // m points the node ahead.
        p = list->head->next;
        q = p->next;    // p points the node reversed
        //m = q->next;
        //first free the head node (because this list node has a head null node,aslo after the reverse....)
        free(list->head);
        //update the tail infor
        list->tail = p;
        p->next = NULL;  // Break the link to the head of the list.
        while(q)  // Start reversing the nodes in the list.
        {
             m = q->next;
            q->next = p;
            
            p = q;
            q = m;
            //m = q->next;  // Tried 3 different positions of this line of code
            
        }
        
        //add a new head null node
        //because of the C's feature.. the code's repetition is a little bit high
        LNode *newHead = malloc(sizeof(LNode));
        newHead->data = 0;
        newHead->next = p; //now this p point the new real first node
        list->head = newHead;
        return OK;
    }
}
Status DestoryList(LinkList *list)
{
    LNode *L = list->head;
    if (L) {
        LNode *p, *q;
        p = L->next;
        while(p)
        {
            q = p->next;
            free(p);
            p = q;
            list->count--;
        }
        
        list->tail = list->head;
        printf("The List Destoryed!\n");
        return OK;
    }
    else
    {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
}

Status ListTraverse(LinkList *list)
{
    if (!list) {
        printf("ERROR: Please initialize the list first!\n");
        return ERROR;
    }
    
    LNode *p;
    p = list->head;
    printf("The List: ");
    while (p->next)
    {
        p = p->next;
        printf("%d ",p->data);
    }
    printf("\n");
    return OK;
}

void PrintMenu(){
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
    printf("| 【7】Quit    |\n");
    printf("---------------------------------\n");
}
int main()
{
    
    int cmd;
    LinkList *List = NULL;  // Attention: Remember to set initial status!
    // this is a menu,should has a recycle use;
    while (1){
        PrintMenu();
        scanf("%d",&cmd);
        // switch case is even more better
        switch (cmd) {
            case 1:List = InitLinkList();break;
            case 2:ListInsertHead(List);break;
            case 3:ListInsertTail(List);break;
            case 4:ListTraverse(List);sleep(2);break;
            // not to used "if (ListTraverse()!=Error) ListTraverse ",its may take nonsence time, if you want to get a error message,try a var to get it.
            case 5:ListReverse(List);break;
            case 6:DestoryList(List);break;
            case 7:printf("bye~~~~~~~\n");return 0;
            default:
                 printf("Excuse me? :(\n");
                break;
        }
    
        printf("\n");
        sleep(1);
        system("clear");// clear the screen,remember to config your environment TERM(Xcode is in Product->Scheme->edit Scheme)
        //you can see this effect on target programme
    }
}
