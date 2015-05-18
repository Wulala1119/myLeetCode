#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s == "")
            return true;
        map<char, char> charMapS2T;
        map<char, char> charMapT2S;
        for(int i = 0; i < s.size(); i ++)
        {
            if(charMapS2T.find(s[i]) == charMapS2T.end() && charMapT2S.find(t[i]) == charMapT2S.end())
            {
				charMapS2T[s[i]] = t[i];
                charMapT2S[t[i]] = s[i];
                s[i] = t[i];               
            }
            else
            {
                if(charMapS2T.find(s[i]) != charMapS2T.end())
                    s[i] = charMapS2T[s[i]];
                else if(charMapT2S.find(t[i]) != charMapT2S.end() && s[i] != charMapT2S.find(t[i])->second)
                    return false;
                else
                    s[i] = charMapS2T[s[i]]; 
            }
        }
        return s == t;
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.isIsomorphic("aa","bb") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}