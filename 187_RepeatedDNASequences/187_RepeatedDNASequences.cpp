#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
//#include <multimap>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> res;
        if(s.size() < 11)
            return res;
        map<int, int> mapS;
        for(int i = 0; i < s.size() - 9; i ++)
        {
            string subS = s.substr(i, 10);
            int num = s2n(subS);
            if(mapS.count(num) == 0)
                mapS[num] = 1;
            else
            {
				cout << "ÊýÄ¿£º" << mapS.find(num)->second << endl;
				if(mapS.find(num)->second == 1)
                {
                    res.push_back(subS);
                    mapS[num] ++;
                    // mapS.erase(mapS.find(subS));
                }
            }
        }
        return res;
    }
    int s2n(string s)
    {
        int res = 0;
        for(int i = 0; i < 10; i ++)
        {
            switch(s[i])
            {
                case 'A':
                    res += 0;
                    break;
                case 'C':
                    res += 1;
                    break;
                case 'G':
                    res += 2;
                    break;
                case 'T':
                    res += 3;
                    break;
                
            }
            res = res << 2;
        }
        return res;
    }
};
void Test()
{
	Solution solution0;
	vector<string> res = solution0.findRepeatedDnaSequences("AAAAAAAAAAAA");
	for(int i = 0; i < res.size(); i ++)
		cout << res[i] << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}