#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
struct stepWord
{
	string word;
	int step;
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) 
    {
		if(wordDict.empty())
			return 0;
		stepWord *tempStep = new stepWord();
		tempStep->word = beginWord;
		tempStep->step = 1;
        queue<stepWord*> sBegin;		
		sBegin.push(tempStep);
		stepWord *tempStepend = new stepWord();
		tempStepend->word = endWord;
		tempStepend->step = 1;
		queue<stepWord*> sEnd;
		sEnd.push(tempStepend);
		stepWord *ptrBegin;
		stepWord *ptrEnd;
		while(!sBegin.empty() || !sEnd.empty())
		{
			if(!sBegin.empty())
			{
				ptrBegin = sBegin.front();
				sBegin.pop();
			}
			if(!sEnd.empty())
			{
				ptrEnd = sEnd.front();
				sEnd.pop();
			}
			cout << "Õ»¶¥µ¥´Ê£º" << ptrBegin->word << "\t" << ptrEnd->word <<endl;
			if(isSimilar(ptrBegin->word, ptrEnd->word))
				return ptrBegin->step + ptrEnd->step;						
			if(wordDict.empty())
				continue;
			for(unordered_set<string>::iterator p = wordDict.begin(); p != wordDict.end();)
			{
				if(isSimilar(*p, ptrBegin->word))
				{
					stepWord *tempStep = new stepWord();
					tempStep->word = *p;
					tempStep->step = ptrBegin->step + 1;
					sBegin.push(tempStep);
					p = wordDict.erase(p);
				}
				else if(isSimilar(*p, ptrEnd->word))
				{
					stepWord *tempStep = new stepWord();
					tempStep->word = *p;
					tempStep->step = ptrEnd->step + 1;
					sEnd.push(tempStep);
					p = wordDict.erase(p);
				}
				else
					++ p;
			}
		}
		return 0;
    }
	bool isSimilar(string begin, string end)
	{
		int count = 0;
		for(int i = 0; i < begin.size(); i ++)
		{
			if(begin[i] == end[i])
				count ++;
		}
		if(count == begin.size() - 1)
			return true;
		else 
			return false;
	}
};
void Test()
{
	Solution solution0;
	unordered_set<string> uset;
	uset.insert("hot");
	uset.insert("dot");
	uset.insert("dog");
	uset.insert("lot");
	uset.insert("log");
	cout << solution0.ladderLength("hit", "cog", uset) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}