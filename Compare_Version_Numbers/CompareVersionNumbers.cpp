#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
		vector<int> version1Num,version2Num;
        this->S2N(version1, version1Num);
        this->S2N(version2, version2Num);
		int maxSize = max(version1Num.size() , version2Num.size());
		version1Num.resize(maxSize, 0);
		version2Num.resize(maxSize, 0);
        for(int i = 0; i < maxSize; i ++)
        {
            if(version1Num[i] == version2Num[i])
                continue;
            return version1Num[i] > version2Num[i] ? 1 : -1;
        }
        return 0;
    }
    void S2N(string s, vector<int> &num)
    {
		int forePosi = 0;
		int Posi = 0;
		int i = 0;  
		while((Posi = s.find_first_of('.',forePosi)) != string::npos)  
		{
			num.push_back(atoi(s.substr(forePosi, Posi - forePosi).c_str()));
			forePosi = Posi + 1;  
			i++;  
		} 
		if(i == 0)
		{
			num.push_back(atoi(s.c_str()));
		}
		else
		{
			num.push_back(atoi(s.substr(forePosi, s.size() - 1).c_str()));
		}
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.compareVersion("1.3.2", "1.1") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}