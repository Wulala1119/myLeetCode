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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        ListNode* head = new ListNode(0);
        ListNode* pHead = head;
        ListNode* l1Head = l1;
        ListNode* l2Head = l2;
        int sum = l1Head->val + l2Head->val;
        head->val = sum % 10;
        int carry = sum / 10;
        while(l1Head->next && l2Head->next)
        {
            ListNode* node = new ListNode(0);
            sum = l1Head->next->val + l2Head->next->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            pHead->next = node;
            pHead = pHead->next;
            l1Head = l1Head->next;
            l2Head = l2Head->next;
        }
        while(l1Head->next)
        {
            ListNode* node = new ListNode(0);
            sum = l1Head->next->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            pHead->next = node;
            pHead = pHead->next;
            l1Head = l1Head->next;
        }
        while(l2Head->next)
        {
            ListNode* node = new ListNode(0);
            sum = l2Head->next->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            pHead->next = node;
            pHead = pHead->next;
            l2Head = l2Head->next;
        }
        if(carry != 0)
        {
            ListNode* node = new ListNode(carry);
            pHead->next = node;
        }    
        return head;
        
    }
};
void Test()
{
	Solution solution0;
	ListNode *l1 = new ListNode(9);
	ListNode *l2 = new ListNode(0);
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(6);
	l1->next = n1;
	n1->next = n2;
	/*l1->next = l2;
	ListNode * temp = l1;
	while(temp != NULL)
	{
		cout<< temp->val << '\t';
		temp = temp->next;
	}
	cout << endl;*/
	ListNode* res = solution0.addTwoNumbers(l1, l2);
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