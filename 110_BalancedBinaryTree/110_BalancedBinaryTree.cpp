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

int depthRightorLeft(TreeNode *root, int direction)
{
	if(root == NULL)
		return 0;
	int depth = 0;
	TreeNode* temp = root;
	if(direction == 0)
	{
		while(temp->left != NULL)
		{
			depth ++;
			temp = root->left;
		}			
	}
	else
	{
		while(temp->right != NULL)
		{
			depth ++;
			temp = root->right;
		}	
	}
	return depth;
}
//bool isBalanced(TreeNode *root) 
//{
//    if (root != NULL)
//	{
//		if((int)abs(depthRightorLeft(root->left, 1) - depthRightorLeft(root->right, 0)) > 1)
//			return true;
//		else
//			return false;
//		else
//		{
//			findMin(root->left, depth, minDep);
//			findMin(root->right, depth, minDep);
//		}
//	}    
//}
bool IsBalanced(TreeNode* pRoot, int* depth)
    {
    	if(pRoot== NULL)
    	{
    		*depth = 0;
    		return true;
    	}
    	int nLeftDepth,nRightDepth;
    	bool bLeft= IsBalanced(pRoot->left, &nLeftDepth);
    	bool bRight = IsBalanced(pRoot->right, &nRightDepth);
    	
    	if (bLeft && bRight)
    	{
    		int diff = nRightDepth - nLeftDepth;
    		if (diff <= 1 && diff >= -1)
    		{
    			*depth = 1 + (nLeftDepth > nRightDepth ? nLeftDepth : nRightDepth);
    			return true;
    		}
    	}
    	
    	return false;
    }
    bool isBalanced(TreeNode *root)
    {
    	int depth = 0;
    
    	return IsBalanced(root, &depth);
    }

void preOrder2(TreeNode *root)     //非递归前序遍历 
{
    stack<TreeNode*> s;
    TreeNode *p = root;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            cout << p->val << " ";
            s.push(p);
			p = p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            s.pop();
			p = p->right;
        }
    }
}
//unsigned int depthNoRecursive(TreeNode *root)     //非递归前序遍历 
//{
//	if(root == NULL)
//		return 0;
//	stack<DeNode*> s;
//    TreeNode *p = root;
//	unsigned int maxd = 0;
//	int depth = 0;
//    while(p != NULL || !s.empty())
//    {
//        while(p != NULL)
//        {
//            cout << p->val << " ";
//            s.push(p);
//			p = p->left;
//        }
//		maxd = max(maxd, s.size() - 0);
//        if(!s.empty())
//        {
//            p = s.top();
//            s.pop();
//			p = p->right;
//        }
//    }
//	return maxd;
//}


int depthNoRecursive(TreeNode *root) 
{
    if(root==NULL)return 0;  
    queue<DeNode> que;  
      
    DeNode dnode;  
	dnode.depth = 1;  
    dnode.node = root;  
  
    que.push(dnode);  
  
    int degree = 1;  
    while(!que.empty())  
    {		
        DeNode ptr = que.front();  
        que.pop();  
  
        degree = ptr.depth;  
  
        if(ptr.node->left != NULL)  
        {  
            DeNode p;  
            p.node = ptr.node->left;  
            p.depth = ptr.depth + 1;  
            que.push(p);  
        }    
        if(ptr.node->right != NULL)  
        {  
            DeNode p;  
            p.node = ptr.node->right;  
            p.depth = ptr.depth + 1;  
            que.push(p);  
        }  
    }  
    return degree;   
}
bool isBalancedNonRecursive(TreeNode *root) 
{
    if(root==NULL)return 0;  
    queue<DeNode> que;  
      
    DeNode dnode;  
	dnode.depth = 1;  
    dnode.node = root;  
  
    que.push(dnode);  
  
    int degree = 1;  
    while(!que.empty())  
    {	
		int leftLen = 0, rightLen = 0;
		TreeNode *maxNode;
        DeNode ptr = que.front();  
        que.pop();  
  
        degree = ptr.depth;  
  
        if(ptr.node->left != NULL)  
        {  
            DeNode p;  
            p.node = ptr.node->left;  
            p.depth = ptr.depth + 1;  
            que.push(p);
			leftLen ++;
			maxNode = ptr.node->left;
        }    
        if(ptr.node->right != NULL)  
        {  
            DeNode p;  
            p.node = ptr.node->right;  
            p.depth = ptr.depth + 1;  
            que.push(p); 
			rightLen ++;
			maxNode = ptr.node->right;
        }
		if(leftLen != rightLen && (maxNode->left != NULL || maxNode->right != NULL))
			return false;
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
	/*int sum = 22;
	if(hasPathSum(pRoot, sum))
		cout << "yes" << endl;
	else
		cout << "no" << endl;*/
	//cout << isBalanced(pRoot) << endl;
	cout << isBalancedNonRecursive(pRoot) << endl;
	system("pause");
	return 0;
}