#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> res;
        int length = s.size();
        if(length < 4 || length > 12)
        {
            return res;
        }
        if(s[0] > '2')
        {
            return res;
        }
        for(int i = 1; i < 4; i ++)
        {
            string saddr1 = s.substr(0, i);
            if(saddr1[0] == '0' && saddr1.size() > 1)
                continue;
            int iaddr1 = atoi(saddr1.c_str());
            if(iaddr1 > 255)
                continue;
            for(int j = i + 1; j - i < 4; j ++)
            {
                string saddr2 = s.substr(i, j - i);
                if(saddr2[0] == '0' && saddr2.size() > 1)
                    continue;
                int iaddr2 = atoi(saddr2.c_str());
                if(iaddr2 > 255)
                    continue;
                for(int k = j + 1; k - j < 4 && k < length; k ++)
                {
                    string saddr3 = s.substr(j, k - j);
                    if(saddr3[0] == '0' && saddr3.size() > 1)
                        continue;
                    int iaddr3 = atoi(saddr3.c_str());
                    if(iaddr3 <= 255 && length - k < 4)
                    {
                        string saddr4 = s.substr(k, length - k);
                        int iaddr4 = atoi(saddr4.c_str());
                        if(iaddr4 <= 255)
                        {
                            string saddr =  saddr1 + "." + saddr2 + "." + saddr3 + "." + saddr4;
                            res.push_back(saddr);
                        }
                    } 
                }
            }
        }
        return res;
    }
};
void Test()
{
	Solution solution0;
	vector<string> res = solution0.restoreIpAddresses("25525511135");
	for(int i = 0; i < res.size(); i ++)
		cout << res[i] << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}