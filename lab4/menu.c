#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10
int help();
int quit();
typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;//指令名
    char* desc;//指令描述
    int   (*handler)();//函数句柄
    struct DataNode *next;
}tDataNode;//定义命令结构体
tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode* pNode=(tDataNode*)GetLinkTableHead(head);
     while(pNode !=NULL)
    {
    if(!strcmp(pNode->cmd,cmd))
    {
        return pNode;
    }
    pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}   //从链表头寻找命令
int ShowAllCmd(tLinkTable* head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode !=NULL)
    {
    printf("%s - %s\n",pNode->cmd,pNode->desc);
    pNode =(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}  //显示所有命令
int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode* pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="menu command:";
    pNode->handler=help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="menu program v8.8.8";
    pNode->handler=NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="quit this software";
    pNode->handler=quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    return 0;
}//命令数据填充
tLinkTable* head=NULL;
int main()
{
    InitMenuData(&head);//取头节点指针，初始化链表
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please Input Command >");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if(p == NULL)
        {
             printf("wrong cmd!\n");
             continue;
         }
         printf("%s - %s\n",p->cmd,p->desc);
         if(p -> handler != NULL)
        {
            p -> handler();
        }
     }
}
int help()
{
    printf("Menu List:\n");
    ShowAllCmd(head);
    return 0;
}
int quit()
{
    exit(0);
    return 0;
}
