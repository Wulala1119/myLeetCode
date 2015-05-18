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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            return NULL;
        }
        int k = n;
        ListNode* pFirst = head;
        ListNode* pSecond = head;
        ListNode* toBeDelete = NULL;
        while(n != 0)
        {
            pFirst = pFirst->next;
			n --;
        }
        if(pFirst == NULL)
        {
            toBeDelete = head;
            head = head->next;
        }
        else
        {
            while(pFirst->next != NULL)
            {
                pFirst = pFirst->next;
                pSecond = pSecond->next;
            }
            toBeDelete = pSecond->next;
            pSecond->next = pSecond->next->next;
        }
        delete toBeDelete;
        toBeDelete = NULL;
        return head;
    }
};
void Test()
{
	Solution solution0;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	l1->next = l2;
	ListNode * temp = l1;
	while(temp != NULL)
	{
		cout<< temp->val << '\t';
		temp = temp->next;
	}
	cout << endl;
	ListNode* res = solution0.removeNthFromEnd(l1, 2);
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