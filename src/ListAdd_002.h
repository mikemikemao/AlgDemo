/*
 * ListAdd_002.h
 *
 *  Created on: 2022年6月19日
 *      Author: pirate
 */

#ifndef LISTADD_002_H_
#define LISTADD_002_H_

#include "common.h"
/**
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

输入：l1 = [0], l2 = [0]
输出：[0]

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

提示：

	每个链表中的节点数在范围 [1, 100] 内
	0 <= Node.val <= 9
	题目数据保证列表表示的数字不含前导零
 *
 * **/

///Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() :
			val(0), next(nullptr) {
	}
	ListNode(int x) :
			val(x), next(nullptr) {
	}
	ListNode(int x, ListNode *next) :
			val(x), next(next) {
	}
};


class ListAdd002 {
public:
	static ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		int up = 0;
		int value = 0;
		ListNode *tmp = l1;
		ListNode *l1parent = NULL;
		while (l1 != NULL || l2 != NULL) {
			if (l1 != NULL && l2 != NULL) {
				value = l1->val + l2->val + up;
				l1->val = value % 10;
				up = (value >= 10) ? 1 : 0;
				l1parent = l1;
				l1 = l1->next;
				l2 = l2->next;
			} else if (l1 != NULL && l2 == NULL) {
				value = l1->val + up;
				l1->val = value % 10;
				up = (value >= 10) ? 1 : 0;
				l1parent = l1;
				l1 = l1->next;
			} else if (l1 == NULL && l2 != NULL) {
				value = l2->val + up;
				l2->val = value % 10;
				up = (value >= 10) ? 1 : 0;
				l1parent->next = new ListNode(l2->val);
				l1parent = l1parent-> next;
				l2 = l2->next;
			}
		}
		if(up == 1){
			cout << "up =" << up << endl;
			cout << "l1 =" << l1 << endl;
			l1parent->next = new ListNode(1);
		}
		return tmp;
	}

	static ListNode* constructList(ListNode *listNode, int *val,int len) {
		if (listNode != NULL && len > 0) {
			listNode->next = new ListNode(*val);
			return constructList(listNode->next, ++val,--len);
		}
	}

	static void showList(ListNode *listNode) {
		while(listNode!=NULL){
			cout << listNode->val << endl;
			listNode = listNode-> next ;
		}
	}

	static void main(){
		//建立一个链表
		int arry1[]={9,9,9,9,9,9,9};
		int arry2[]={9,9,9,9};
		//链表根节点
		ListNode* l1 = new ListNode();
		constructList(l1,arry1,ARR_SIZE(arry1));
		//showList(l1);
		ListNode* l2 = new ListNode();
		constructList(l2,arry2,ARR_SIZE(arry2));
		ListNode* tmp = addTwoNumbers(l2->next, l1->next);
		showList(tmp);

	}
};



#endif /* LISTADD_002_H_ */
