// 输出二叉树中所有从根结点到叶子结点的路径.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
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
		root = new TreeNode();
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

bool hasPathSum(TreeNode *root, int sum) 
{
	if (root != NULL)
	{
		sum -= root->val;

		if (root->left == NULL && root->right == NULL)
		{
			if(sum == 0)
				return true;
			else
				return false;
		}
		else
		{
			if(hasPathSum(root->left, sum))
				return true;
			if(hasPathSum(root->right, sum))
				return true;
		}
	}
	return false;
}
void findMin(TreeNode *root, int depth, int *minDep)
{
    if (root != NULL)
	{
		depth ++;
		if (root->left == NULL && root->right == NULL)
		{
			if(depth < *minDep || *minDep == 0)
				*minDep = depth;
            return;
		}
		else
		{
			findMin(root->left, depth, minDep);
			findMin(root->right, depth, minDep);
		}
	}
}
int minDepth(TreeNode *root) 
{
    if(root == NULL)
        return 0;
    int *min = new int(0);
    int depth = 0;
    findMin(root, depth, min);
    return *min;
}


int main()
{
	TreeNode *pRoot = NULL;
	vector<int> path;
	int input[19] = {5, 4, 11, 7 , 0, 0, 2, 0, 0, 0, 8, 13, 0, 0, 4, 0, 1, 0, 0};
	CreatBTree(pRoot);
	cout << "二叉树中从根到叶子结点的所有路径如下：" << endl;
    FindAllPath(pRoot, path);
	/*int sum = 22;
	if(hasPathSum(pRoot, sum))
		cout << "yes" << endl;
	else
		cout << "no" << endl;*/
	cout << minDepth(pRoot) << endl;
	system("pause");
	return 0;
}