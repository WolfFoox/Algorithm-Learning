/*
#include<iostream>
#include<queue>
using namespace std;

class BinaryTree {
private:
	int node_value;

public:
	BinaryTree* Leftchild;
	BinaryTree* Rightchild;
	BinaryTree* parent;
	BinaryTree(int V = 0) {
		node_value = V;
	}

	int getV(){
		return node_value;
	}

	void getParent(BinaryTree* P) {
		parent = P;
	}
	void getChild(BinaryTree C) {  //确认左右子树
		if (Leftchild == NULL) {
			Leftchild = &C;
			C.getParent(this);
		}
		else if(Rightchild==NULL)
		{
			Rightchild = &C;
			C.getParent(this);
		}
		else
		{
			parent->getChild(C);
		}
	}
	void GetLeftChild(BinaryTree L) {
		//cout << "请输入左孩子的值：" << endl;
		int v;
		cin >> v;
		Leftchild = new BinaryTree(v);
	}
	void GetRightChild(BinaryTree R) {
		//cout << "请输入右孩子的值：" << endl;
		int v;
		cin >> v;
		Rightchild = new BinaryTree(v);
	}
	friend void InitialTree(BinaryTree* T);
	void BFS(queue<BinaryTree> Q) {
		BinaryTree T = Q.front();
		Q.pop();
		cout << T.getV() << " ";
		if (T.Leftchild) {
			cout << T.Leftchild->getV() << " ";
			Q.push(*(T.Leftchild));
		}
		if (T.Rightchild) {
			cout << T.Rightchild->getV() << " ";
			Q.push(*(T.Rightchild));
		}
		if (Q.empty()) {
			return;
		}
		else
		{
			BFS(Q);
		}

	}
};
void InitialTree(BinaryTree* T) {
	int v;
	cin >> v;
	if (v == -1) {
		T = NULL;
	}
	else {
		T = new BinaryTree(v);
		InitialTree(T->Leftchild);
		InitialTree(T->Rightchild);
	}
}
int main() {
	BinaryTree *T;
	cout << "请输入一个二叉树(按前序顺序)(输入-1表示转换)" << endl;
	InitialTree(T);
	cout << T->getV() << endl;
	cout << T->Leftchild->getV() << endl;
	cout << T->Rightchild->getV() << endl;
	queue<BinaryTree> Q;
	Q.push(*T);
	T->BFS(Q);
}
*/

#include <iostream>
#include <string>
#include <algorithm>
#include<queue>
#include<stack>
using namespace std;
/*定义二叉树的结构*/
typedef struct Node
{
    char data;                    /*数据域*/
    struct Node* lchild, * rchild; /*左子树和右子树*/
    bool Ischecked = 0;
} *BiTree, BiNode;
/*整棵树和结点名称*/

void BFS(BiTree T) {
    queue<BiNode> Q;
    if (T) {
        Q.push(*T);
    }
    while (!Q.empty())
    {
        cout << Q.front().data << " ";
        if (Q.front().lchild) {
            Q.push(*(Q.front().lchild));
        }
        if (Q.front().rchild) {
            Q.push(*(Q.front().rchild));
        }
        Q.pop();
    }
    cout << endl;
}

void DFS(BiTree T) {
    stack<BiNode> Q;
    if (T) {
        Q.push(*T);
        cout << T->data<<" ";
        T->Ischecked = 1;
    }
    while (!Q.empty())
    {
        
        if ((Q.top().lchild)&&!(Q.top().lchild->Ischecked)) {
            cout << Q.top().lchild->data << " ";
            Q.top().lchild->Ischecked = 1;
            Q.push(*(Q.top().lchild));
           
        }
        else if ((Q.top().rchild)&&!(Q.top().rchild->Ischecked)) {
            cout << Q.top().rchild->data << " ";
            Q.top().rchild->Ischecked = 1;
            Q.push(*(Q.top().rchild));
            
        }
        else
        {
            Q.pop();
        }
    }
    cout << endl;
}

/*先需创建二叉树*/
void CreateBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiNode; /*创建一个新节点*/
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /*递归创建*/
}
void InOrderTraverse(BiTree T)
{
    /*中序遍历*/
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    /*先序遍历*/
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    /*后序遍历*/
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
/*统计二叉树中结点的个数*/
int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
/*求树的深度*/
int Depth(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int i = Depth(T->lchild);
        int j = Depth(T->rchild);
        return i > j ? i + 1 : j + 1;
    }
}
/*复制二叉树*/
void Copy(BiTree T, BiTree& NewT)
{
    if (T = NULL)
    {
        NewT = NULL;
        return;
    }
    else
    {
        NewT = new BiNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}
/*统计二叉树中叶子结点的个数*/
int LeafCount(BiTree T)
{
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
        return 1;
    /*如果二叉树左子树和右子树皆为空，说明该二叉树根节点为叶子结点，结果为1*/
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}
/*二叉树中从每个叶子结点到跟结点的路径*/
void PrintAllPath(BiTree T, char path[], int pathlen)
{
    int i;
    if (T != NULL)
    {
        path[pathlen] = T->data; /*将当前结点放入路径中*/
        if (T->lchild == NULL && T->rchild == NULL)
        {
            /*若这个节点是叶子结点*/
            for (i = pathlen; i >= 0; i--)
                cout << path[i] << "　";
            cout << "\n";
        }
        else
        {
            PrintAllPath(T->lchild, path, pathlen + 1);
            PrintAllPath(T->rchild, path, pathlen + 1);
        }
    }
}
/*判断二叉树是否为空*/
int BiTree_empty(BiTree T)
{
    if (T)
        return 1;
    else
        return 0;
}
int main()
{
    char S[24] = { "ABDH###EI###CFJ###GK###" };//测试数据
    BiTree T;
    //测试数据AB#CD##E##F#GH###
    cout << "先序遍历输入(以#结束)：";
    CreateBiTree(T);
    cout << "中序遍历输出：";
    InOrderTraverse(T);
    cout << endl
        << "先序遍历输出:";
    PreOrderTraverse(T);
    cout << "\n"
        << "后序遍历输出:";
    PostOrderTraverse(T);
    cout << endl
        << "树的深度:" << Depth(T);
    cout << endl
        << "结点的个数:" << NodeCount(T);
    cout << endl
        << "二叉树中从每个叶子结点到根结点的所有路径：" << endl;
    char path[256];
    int pathlen = 0;
    PrintAllPath(T, path, pathlen);
    cout << "BFS" << endl;
    BFS(T);
    cout << "DFS" << endl;
    DFS(T);
    return 0;
}

