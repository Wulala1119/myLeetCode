#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) 
    {
        /*int length = num.end() - num.begin();
		if(length == 0)
			return 0;
        int sum1 = 0;
        int sum2 = 0;
		if((length & 0x1) == 1)
		{
			for(vector<int>::iterator iter = num.begin(); iter != num.end() - 1;iter ++)
			{
				sum1 += *iter;
				iter ++;
				sum2 += *iter;
			}
			sum1 += num.back();
		}
		else
		{
			for(vector<int>::iterator iter = num.begin(); iter != num.end();iter ++)
			{
				sum1 += *iter;
				iter ++;
				sum2 += *iter;
			}
		}            
        return sum1 >= sum2 ? sum1 : sum2;*/
		//dp[i] = max(dp[i - 1], dp[i - 2] + num[i])
		int n = num.size();
        if (n==0) return 0;
        if (n==1) return num[0];
        if (n==2) return max(num[0],num[1]);
        int n1 = num[0];
        int n2 = num[1];
        int maxRob = INT_MIN;
        for (int i = 2; i < n; ++i) 
		{
            maxRob = max(n1 + num[i], n2);
            n1 = max(n1, n2);
            n2 = maxRob;
        }
        return maxRob;

    }
};



void Test()
{
	int test[12] = {1, 5, 7, 8, 9 , 3, 6, 2, 1, 7, 10, 4};
	vector<int> input(test, test + 11);
	Solution solution0;
	cout << solution0.rob(input)<<endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}