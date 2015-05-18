#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
		ListNode* res = l1;
		ListNode* insertedNodehead = l2;
		ListNode* insertedNode = NULL;
		while(insertedNodehead != NULL)
		{
			insertedNode = insertedNodehead;
			insertedNodehead = insertedNodehead->next;
			res = insertNode(res, insertedNode);			
		}
		return res;        
    }
	ListNode* insertNode(ListNode* head, ListNode* node)
	{
		ListNode* pHead = head;
		if(node->val <= pHead->val  )
		{
			node->next = pHead;
			head = node;
		}
		else
		{
			while(pHead->next != NULL && node->val > pHead->next->val)
			{
				pHead = pHead->next;
			}
			if(pHead->next == NULL)
			{
				pHead->next = node;
				node->next = NULL;
			}
			else
			{
				node->next = pHead->next;
				pHead->next = node;
			}
		}
		return head;
	}
};
void Test()
{
	Solution solution0;
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(1);
	/*l1->next = l2;
	ListNode * temp = l1;
	while(temp != NULL)
	{
		cout<< temp->val << '\t';
		temp = temp->next;
	}
	cout << endl;*/
	ListNode* res = solution0.mergeTwoLists(l1, l2);
	while(res != NULL)
	{
		cout<< res->val << '\t';
		res = res->next;
	}
	cout << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}