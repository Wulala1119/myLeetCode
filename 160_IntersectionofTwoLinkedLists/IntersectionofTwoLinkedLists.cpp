#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pA = headA;
		ListNode *pB = headB;
		int lenA = 0;
		int lenB = 0;
		while(pA != NULL)
		{
			pA = pA->next;
			lenA ++;
		}
		while(pB != NULL)
		{
			pB = pB->next;
			lenB ++;
		}
		pA = headA;
		pB = headB;
		int minLen = min(lenA, lenB);
		if(lenA < lenB)
		{
			int dLen = lenB - lenA;
			while(dLen)
			{
				pB = pB->next;
				dLen --;
			}				
		}
		if(lenA > lenB)
		{
			int dLen = lenA - lenB;
			while(dLen)
			{
				pA = pA->next;
				dLen --;
			}
		}
		while(minLen)
		{
			if(pA == pB)
				return pA;
			minLen --;
		}
		return NULL;
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.compareVersion("1.3.2", "1.1") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}