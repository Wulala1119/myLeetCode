// 输出二叉树中所有从根结点到叶子结点的路径.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct DeNode
{
	TreeNode *node;
	int depth;
};

//先序创建二叉树
void CreatBTree(TreeNode *&root)
{	
	int nValue = 0;
	cin >> nValue;
	if (0 == nValue)
	{
		return;
	}
	else
	{
		root = new TreeNode(0);
		root->val = nValue;
		CreatBTree(root->left);
		CreatBTree(root->right);
	}	
}

//输出二叉树中所有从根结点到叶子结点的路径(递归)
void FindAllPath(TreeNode *pRoot, vector<int> path)
{
	if (pRoot != NULL)
	{
		path.push_back(pRoot->val);
		if (pRoot->left == NULL && pRoot->right == NULL)
		{
			for (vector<int>::iterator iter=path.begin(); iter!=path.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << endl;
			return;
		}
		else
		{
			FindAllPath(pRoot->left, path);
			FindAllPath(pRoot->right, path);
		}
	}
}

    void flatten(TreeNode* root) 
    {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        TreeNode* tempRoot = new TreeNode(root->val);
        TreeNode* pRoot = root;
        TreeNode* pTempRoot = tempRoot;
        stack<TreeNode*> s;
        s.push(pRoot);
        pRoot = pRoot->left;
        while(!s.empty() || pRoot != NULL)
        {
            while(pRoot != NULL)
            {
                TreeNode* temp = new TreeNode(pRoot->val);
                pTempRoot->right = temp;
                pTempRoot = temp;
                s.push(pRoot);
                pRoot = pRoot->left;
            }
            while(!s.empty())
            {
                TreeNode* topNode = s.top();
                s.pop();
                if(topNode->right != NULL)
                {
                    pRoot = topNode->right;
                    break;
                }
            }
        }
        root = tempRoot;
    }
	TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() >= 3)
            return sortedArrayToBST(nums, 0, nums.size() - 1);
        else
            return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) 
    {
        if(right - left == 2)
        {
            TreeNode* root = new TreeNode(nums[left + 1]);
            TreeNode* left = new TreeNode(nums[left]);
            TreeNode* right = new TreeNode(nums[right]);
            root->left = left;
            root->right = right;
            return root;
        }
        else
        {
            int middle = (left + right) / 2;
            TreeNode* root = new TreeNode(nums[middle]);
            root->left = sortedArrayToBST(nums, left, middle - 1);
            root->right = sortedArrayToBST(nums, middle + 1, right);
        }
    }
int main()
{
	TreeNode *pRoot = NULL;
	vector<int> path;
	int input[19] = {5, 4, 11, 7 , 0, 0, 2, 0, 0, 0, 8, 13, 0, 0, 4, 0, 1, 0, 0};
	CreatBTree(pRoot);
	cout << "二叉树中从根到叶子结点的所有路径如下：" << endl;
    FindAllPath(pRoot, path);
	flatten(pRoot);
	system("pause");
	return 0;
}