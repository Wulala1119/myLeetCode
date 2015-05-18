#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
using namespace std;

 
class Solution {
public:
    bool isValid(string s) 
    {
	   vector<char> bracketVec;
       for(int i = 0; i < s.size(); i ++) 
	   {
		   switch (s[i])
		   {
			case '(':
				bracketVec.push_back(s[i]);
				break;
			case '[':
				bracketVec.push_back(s[i]);
				break;
			case '{':
				bracketVec.push_back(s[i]);
				break;
			case ')':
				if(!bracketVec.empty() && bracketVec.back() == '(')
					bracketVec.pop_back();
				else
					return false;
				break;
			case ']':
				if(!bracketVec.empty() && bracketVec.back() == '[')
					bracketVec.pop_back();
				else
					return false;
				break;
			case '}':
				if(!bracketVec.empty() && bracketVec.back() == '{')
					bracketVec.pop_back();
				else
					return false;
				break;
			default:
				break;
		   }
	   }
	   if(bracketVec.empty())
		   return true;
	   else
		   return false;
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.isValid("([])") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}