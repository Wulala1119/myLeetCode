#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    string *stringHead;
	Solution()
	{
		string temp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		stringHead = new string[10];
		for(int i = 0; i < 10; i ++)
		{
			stringHead[i] = temp[i];
		}
	}
    vector<string> letterCombinations(string digits) 
    {
		vector<string> res;
		string st = "";
		letterCombinations(digits, st, res, 0);
        return res;
    }
    void letterCombinations(string digits, string st, vector<string> & store, int index)
	{
		if(index < digits.size())
		{
			char c = digits[index];
			string s = stringHead[digits[index] - '0'];
			for(int i = 0; i < stringHead[digits[index] - '0'].size(); i ++)
			{
				string temp = st + stringHead[digits[index] - '0'][i];
				letterCombinations(digits, temp, store, index + 1);
			}
		}
		else
		{
			store.push_back(st);
			return;
		}
	}
};
void Test()
{
	Solution solution0;
	vector<string> res = solution0.letterCombinations("2345");
	for(int i = 0; i < res.size(); i ++)
		cout << res[i] << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}