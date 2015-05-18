#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
	static bool comp(const string &a, const string &b)
    {
        return a + b < b + a;
    }
    string largestNumber(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return "";
        if(nums.size() == 1)
            return m_toStr<int>(nums[0]);
        int length = nums.size();
        string *sNums = new string[length];
        for(int i = 0; i < length; i ++)
            sNums[i] = m_toStr<int>(nums[i]);
        sort(sNums, sNums + length, comp);
        string res = "";
        for(int i = 0; i < length; i ++)
            res = sNums[i] + res;
        return res;
    }
    
    /*
    convert other data to string
    usage :
        string str = m_toStr<int>(12345);
    */
    template <class T> string m_toStr(T tmp)
    {
        stringstream ss;
        ss << tmp;
        return ss.str();
    }
};
void Test()
{
	Solution solution0;
	vector<int> input;
	input.push_back(3);
	input.push_back(34);
	input.push_back(30);
	input.push_back(5);
	input.push_back(9);
	cout << solution0.largestNumber(input) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}