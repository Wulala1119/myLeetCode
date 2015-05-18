#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size() <= 1)
            return s;
        string longestP = "";
        for(int i = 0; i < s.size() - 1; i ++)
        {
            if(s[i] == s[i + 1])
            {
                if((i == 0 || i + 1 == s.size() - 1) && longestP.size() < 2)
                {
                    longestP = s.substr(i, 2);
                }
				int j = 1;
                for(; i - j >= 0 && i + j + 1 < s.size(); j ++)
                {
                    if(s[i - j] != s[i + j + 1])
                    {
						break;                        
                    }
                }
				int length = longestP.size();
				if(longestP.size() < j * 2)
					longestP = s.substr(i - j + 1, j * 2);
            }
        }
        for(int i = 0; i < s.size() - 2; i ++)
        {
            if(s[i] == s[i + 2])
            {
                if((i == 0 || i + 2 == s.size() - 1) && longestP.size() < 3)
                {
                    longestP = s.substr(i, 3);
                }
				int j = 1;
                for(; i - j >= 0 && i + j + 2  < s.size(); j ++)
                {
                    if(s[i - j] != s[i + j + 2])
                    {
                        break;
                    }
                }
				if(longestP.size() < j * 2 + 1)
					longestP = s.substr(i - j + 1, j * 2 + 1);
            }
        }  
        return longestP;
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.longestPalindrome("abcba") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}