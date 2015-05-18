#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res;
		//res.resize(rowIndex + 1);
        if(rowIndex == 0)
            res.push_back(1);
        if(rowIndex == 1)
        {
            res.push_back(1);
            res.push_back(1);
        }
        if(rowIndex > 1)
        {
			res.push_back(1);
            for(int i = 1; i < rowIndex / 2 + 1; i ++)
            {
                res.push_back(res[i - 1] / i * (rowIndex - i + 1));
            }
            for(int i = (rowIndex - 1) / 2; i >= 0; i --)
            {
                res.push_back(res[i]);
            }
            
        }
        return res;
    }
    int permutation(int n, int m)
    {
        if(m == 0)
            return 1;
        if(m == 1)
            return n;
        int res = 1;
        int d = 1;
        for(int i = n - m + 1; i <= n; i ++)
        {
            res *= i;
        }
        for(int i = 2; i <= m; i ++)
        {
            d *= i;
        }
        return res / d;
    }
};
void Test()
{
	Solution solution0;
	int n;
	while(cin >> n)
	{
		vector<int> res = solution0.getRow(n);
		for(int i = 0; i < n + 1; i ++)
			cout << res[i] << "\t";
		cout << endl;
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}