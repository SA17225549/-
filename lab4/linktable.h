#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#define SUCCESS 0
#define FAILURE (-1)
typedef struct LinkTableNode{
struct LinkTableNode *pNext;
}tLinkTableNode;//节点数据结构
typedef struct LinkTable{
tLinkTableNode *pHead;
tLinkTableNode *pTail;
int SumOfNode;
}tLinkTable;//链表数据结构
tLinkTable *CreateLinkTable();//创建链表
int DeleteLinkTable(tLinkTable *pLinkTable);//删除链表
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);//添加节点
int DeleteLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);//删除节点
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);//获取链表头节点
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);//获取下一节点
#endif
