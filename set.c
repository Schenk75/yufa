/************  SET.c  *************/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "set.h"

//合并两个symset
symset uniteset(symset s1, symset s2)
{
	symset s;
	snode* p;
	
	s = p = (snode*) malloc(sizeof(snode));
	
	s1 = s1->next;           
	s2 = s2->next;			 				

	
	while (s1 && s2)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		if (s1->elem < s2->elem)
		{
			p->elem = s1->elem;
			s1 = s1->next;
		}
		else
		{
			p->elem = s2->elem;
			s2 = s2->next;
		}
	}

	while (s1)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		p->elem = s1->elem;
		s1 = s1->next;
		
	}

	while (s2)
	{
		p->next = (snode*) malloc(sizeof(snode));
		p = p->next;
		p->elem = s2->elem;
		s2 = s2->next;
	}

	p->next = NULL;

	return s;
} // uniteset

//将一个新元素按elem大小插入链表中的对应位置
void setinsert(symset s, int elem)
{
	/* TO BE MODIFIED */
	snode* p;
	snode* q;

	p = s;
	//根据elem的值和链中各个元素的elem属性比较大小，找到其在链中的位置
	while (p->next && p->next->elem < elem){
		p = p->next;
	}
	//将elem插入链中对应位置
	q = (snode*) malloc(sizeof(snode));
	q->elem = elem;
	q->next = p->next;
	p->next = q;
} // setinsert

//创建链表
symset createset(int elem, .../* SYM_NULL */)
{
	va_list list;
	symset s;

	s = (snode*) malloc(sizeof(snode));
	s->next = NULL;

	va_start(list, elem);
	while (elem)
	{
		setinsert(s, elem);
		elem = va_arg(list, int);
	}
	va_end(list);
	return s;
} // createset

//删除链表
void destroyset(symset s)
{
	snode* p;

	while (s)
	{
		p = s;
		s = s->next;
		free(p);
	}
} // destroyset

//查找一个元素是否在链表中，若在返回1，不在则返回0
int inset(int elem, symset s)
{
	/* TO BE MODIFIED */
	snode* p;
	p = s;
	while (p->next && p->next->elem < elem){
		p = p->next;
	}
	//p之前的元素的elem属性<elem，p->next->elem >= elem
	if (p->next && p->next->elem == elem){
		return 1;
	}
	else{
		return 0;
	}
} // inset

// EOF set.c
