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
	void getChild(BinaryTree C) {  //ȷ����������
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
		//cout << "���������ӵ�ֵ��" << endl;
		int v;
		cin >> v;
		Leftchild = new BinaryTree(v);
	}
	void GetRightChild(BinaryTree R) {
		//cout << "�������Һ��ӵ�ֵ��" << endl;
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
	cout << "������һ��������(��ǰ��˳��)(����-1��ʾת��)" << endl;
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
/*����������Ľṹ*/
typedef struct Node
{
    char data;                    /*������*/
    struct Node* lchild, * rchild; /*��������������*/
    bool Ischecked = 0;
} *BiTree, BiNode;
/*�������ͽ������*/

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

/*���贴��������*/
void CreateBiTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiNode; /*����һ���½ڵ�*/
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /*�ݹ鴴��*/
}
void InOrderTraverse(BiTree T)
{
    /*�������*/
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    /*�������*/
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    /*�������*/
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
/*ͳ�ƶ������н��ĸ���*/
int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
/*���������*/
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
/*���ƶ�����*/
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
/*ͳ�ƶ�������Ҷ�ӽ��ĸ���*/
int LeafCount(BiTree T)
{
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
        return 1;
    /*�������������������������Ϊ�գ�˵���ö��������ڵ�ΪҶ�ӽ�㣬���Ϊ1*/
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}
/*�������д�ÿ��Ҷ�ӽ�㵽������·��*/
void PrintAllPath(BiTree T, char path[], int pathlen)
{
    int i;
    if (T != NULL)
    {
        path[pathlen] = T->data; /*����ǰ������·����*/
        if (T->lchild == NULL && T->rchild == NULL)
        {
            /*������ڵ���Ҷ�ӽ��*/
            for (i = pathlen; i >= 0; i--)
                cout << path[i] << "��";
            cout << "\n";
        }
        else
        {
            PrintAllPath(T->lchild, path, pathlen + 1);
            PrintAllPath(T->rchild, path, pathlen + 1);
        }
    }
}
/*�ж϶������Ƿ�Ϊ��*/
int BiTree_empty(BiTree T)
{
    if (T)
        return 1;
    else
        return 0;
}
int main()
{
    char S[24] = { "ABDH###EI###CFJ###GK###" };//��������
    BiTree T;
    //��������AB#CD##E##F#GH###
    cout << "�����������(��#����)��";
    CreateBiTree(T);
    cout << "������������";
    InOrderTraverse(T);
    cout << endl
        << "����������:";
    PreOrderTraverse(T);
    cout << "\n"
        << "����������:";
    PostOrderTraverse(T);
    cout << endl
        << "�������:" << Depth(T);
    cout << endl
        << "���ĸ���:" << NodeCount(T);
    cout << endl
        << "�������д�ÿ��Ҷ�ӽ�㵽����������·����" << endl;
    char path[256];
    int pathlen = 0;
    PrintAllPath(T, path, pathlen);
    cout << "BFS" << endl;
    BFS(T);
    cout << "DFS" << endl;
    DFS(T);
    return 0;
}

