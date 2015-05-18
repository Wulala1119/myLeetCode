#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
        if(s == "")
            return false;
        bool *isFind = new bool[s.size()];
        memset(isFind, false, sizeof(bool) * s.size());
        for(int i = 0; i < s.size(); i ++)
        {
            if(i == 0 || isFind[i - 1] == true)
            {
                int j = i;
                for(; j <= s.size(); j ++)
                {
                    if(wordDict.find(s.substr(i, j - i + 1)) != wordDict.end())
                    {
                        isFind[j] = true;
                    }
                }
            }
        }
        return isFind[s.size() - 1];
    }
};
void Test()
{
	Solution solution0;
	unordered_set<string> wordD;
	wordD.insert("a");
	wordD.insert("b");
	//wordD.insert("b");
	//wordD.insert("cd");
	cout << solution0.wordBreak("ab", wordD) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}