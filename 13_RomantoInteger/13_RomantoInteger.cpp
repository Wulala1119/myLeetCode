#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int res = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == 'I')
            {
                if(i < s.size() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    res -= 1;
				continue;
            }
            if(s[i] == 'X')
            {
                if(i < s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    res -= 10;
				continue;
            }
            if(s[i] == 'C')
            {
                if(i < s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    res -= 100;
				continue;
            }
            res += table[s[i]];
        }
        return res;
    }
};
void Test()
{
	Solution solution0;
	int nRows = 2;
	cout << solution0.romanToInt("DCXXI") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}