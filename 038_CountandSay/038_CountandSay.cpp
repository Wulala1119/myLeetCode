#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
#include <sstream>
using namespace std;
class Solution {
public:
    string countAndSay(int n)
    {
        string output = "1";
        for(int i = 1; i < n; i ++)
        {
            output = countAndSaySingle(output);
        }
        return output;
    }
    string countAndSaySingle(string n) 
    {
		if(n == "1")
			return "11";
        string res = "";
        int count = 1;
		char num = n[0];
        for(int i = 1; i < n.size(); i ++)
		{
			if(n[i] == num)
			{
				count ++;
				if(i == n.size() - 1)
				{
					ostringstream out;
                    out << count;
                    res += out.str() + num;
					break;
				}				
			}
			else
			{
				ostringstream out;
                out << count;
                res += out.str() + num;
				if(i == n.size() - 1)
				{
					ostringstream out;
					out << 1;
					res += out.str() + n[i];
					break;
				}
				num = n[i];
				count = 1;
			}
		}
        return res;
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.countAndSay(4) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}