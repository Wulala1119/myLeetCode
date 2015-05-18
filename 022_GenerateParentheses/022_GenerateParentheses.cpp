#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string s = "";
        generateParenthesis(res, s, '(', n * 2, 0);
        return res;
    }
    void generateParenthesis(vector<string>& res, string s, char c, int length, int count)
    {
        if(s.size() == length - 1)
        {
			if(count == length / 2)
			{
				s += ')';
				res.push_back(s);
			}
        }
        else
        {
            s += c;
			if(c == '(')
				count ++;
			if(count == length / 2)
			{
				generateParenthesis(res, s, ')', length, count);
			}
			else
			{
				generateParenthesis(res, s, '(', length, count);
				generateParenthesis(res, s, ')', length, count);
			}            
        }
    }
};
void Test()
{
	Solution solution0;
	vector<string> res = solution0.generateParenthesis(3);
	for(int i = 0; i < res.size(); i ++)
		cout << res[i] << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}