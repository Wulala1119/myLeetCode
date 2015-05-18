#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
		if(nums.size() < 3)
            return res;
        //sort(nums.begin(), nums.end());
		bubbleSort(nums);
        if(nums[0] > 0 || nums[nums.size() - 1] < 0)
            return res;
        if(nums[0] == 0 && nums[nums.size() - 1] == 0)
        {
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
			res.push_back(temp);
			return res;
        }
        int i = 0;
        while(i < nums.size() - 2)
        {
			if(i > 0 && nums[i] == nums[i - 1])
			{
			    i ++;
			    continue;
			}
			int start = i + 1;
			int end = nums.size() - 1;
			while(start < end)
			{
			    int sum = nums[i] + nums[start] + nums[end];
			    if(sum == 0)
			    {
					if(res.size() > 0 && res[res.size() - 1][0] == nums[i] && res[res.size() - 1][1] == nums[start])
					{
						start ++;
						end --;
						continue;
					}
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
					res.push_back(temp);
					start ++;
					end --;
			    }
			    if(sum < 0)
			        start ++;
			    if(sum > 0)
			        end --;
			}
			i ++;
        }
		return res;
    }

    void bubbleSort(vector<int>& nums)
    {
        for(int i = nums.size() - 1; i > 0; i --)
        {
            for(int j = 0; j < i; j ++)
            {
                if(nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};
void Test()
{

	Solution solution0;
	int a[15] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	int b[3] = {0, 0, 0};
	//vector<int> input(a, a + 5);
	vector<int> input(a, a + 15);
	vector<vector<int> > res =  solution0.threeSum(input);
	for(int i = 0; i < res.size(); i ++)
    {
		for(int j = 0; j < 3; j ++)
		{
			cout<< res[i][j] << "\t";
		}
		cout << endl;
	}

}
int main()
{
	Test();
	system("pause");
	return 0;
}