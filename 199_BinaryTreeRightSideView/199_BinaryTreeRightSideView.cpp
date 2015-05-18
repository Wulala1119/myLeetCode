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
vector<int> rightSideView(TreeNode* root) 
{
	vector<int> res;
	if(root == NULL)
		return res;
	queue<DeNode*> s;
	int nowDepth = 0;
	DeNode *denode = new DeNode();
	denode->node = root;
	denode->depth = 1;
	s.push(denode);
	while(!s.empty())
	{
		DeNode *ptr = s.front();
		if(nowDepth != ptr->depth)
		{
			res.push_back(s.back()->node->val);
			nowDepth = ptr->depth;
		}
		s.pop();
		if(ptr->node->left != NULL)  
        {  
            DeNode *p = new DeNode();  
            p->node = ptr->node->left;  
            p->depth = ptr->depth + 1;  
            s.push(p);  
        }    
        if(ptr->node->right != NULL)  
        {  
            DeNode *p = new DeNode();  
            p->node = ptr->node->right;  
            p->depth = ptr->depth + 1;  
            s.push(p);  
        }  

	}
    return res;
}
int main()
{
	TreeNode *pRoot = NULL;
	vector<int> path;
	int input[19] = {5, 4, 11, 7 , 0, 0, 2, 0, 0, 0, 8, 13, 0, 0, 4, 0, 1, 0, 0};
	CreatBTree(pRoot);
	cout << "二叉树中从根到叶子结点的所有路径如下：" << endl;
    FindAllPath(pRoot, path);
	cout << endl;
	/*int sum = 22;
	if(hasPathSum(pRoot, sum))
		cout << "yes" << endl;
	else
		cout << "no" << endl;*/
	//cout << isBalanced(pRoot) << endl;
	vector<int> output = rightSideView(pRoot);
	for(int i = 0; i < output.size(); i ++)
		cout << output[i] << endl;
	system("pause");
	return 0;
}