#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
class worknode {
public:
	int s;
	int e;
	string c;
	worknode* next;
	worknode* previous;
	worknode(int ss, int ee,string cc) {
		s = ss;
		e = ee;
		c = cc;
		next = NULL;
		previous = NULL;
	}
};
class worklist {
public:
	worknode* head;
	worknode* tail;
	int count;
	worklist() {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void insertC() {
		int s, e;
		string c;
		cin >>c>> s >> e;
		worknode* tmp;
		tmp = new worknode(s,e,c);
		if (head == NULL) {
			head = tmp;
			tail = tmp;
			//tmp->previous = head;
			//tmp->next = tail;
		}
		else {
			worknode* curr;
			curr = head;
			while (curr != NULL && tmp->e > curr->e) {
				curr = curr->next;
			}
			if (curr != NULL) {
				if (curr == head) {
					tmp->next = curr;
					curr->previous = tmp;
					head = tmp;
				}
				else {
					tmp->previous = curr->previous;
					curr->previous->next = tmp;
					tmp->next = curr;
					curr->previous = tmp;
				}
			}
			else {
				tmp->previous = tail;
				tail->next = tmp;
				tail = tmp;
			}
			
		}
		count++;
	}
	void insertV(int s, int e,string c) {
		worknode* tmp;
		tmp = new worknode(s, e,c);
		if (head == NULL) {
			head = tmp;
			tail = tmp;
			tmp->previous = head;
			//tmp->next = tail;
		}
		else {
			worknode* curr;
			curr = head;
			while (curr != NULL &&tmp->e > curr->e) {
				curr = curr->next;
			}
			if (curr != NULL) {
				if (curr == head) {
					tmp->next = curr;
					curr->previous = tmp;
					head = tmp;
				}
				else {
					tmp->previous = curr->previous;
					curr->previous->next = tmp;
					tmp->next = curr;
					curr->previous = tmp;
				}
				
			}
			else {
				tmp->previous = tail;
				tail->next = tmp;
				tail = tmp;
			}

		}
		count++;
	}
};
int earlist(int e[]) {
	int et = 0;
	for (int i = 1; i < 50; i++) {
		if (e[et] > e[i]) {
			et = i;
		}
	}
	return et;
}
int main() {
	worklist WORK;
	worklist ATT;
	int n;
	cout << "请输入任务总数：";
	cin >> n;
	cout << endl<<"请分别输入任务名称，开始时间和结束时间"<<endl;
	for (int i = 0; i < n; i++) {
		WORK.insertC();
	}
	ATT.insertV(WORK.head->s, WORK.head->e,WORK.head->c);
	worknode* curr = WORK.head->next;
	while (curr != NULL) {
		if (curr->s >= ATT.tail->e) {
			ATT.insertV(curr->s, curr->e, curr->c);
		}
		curr = curr->next;
	}
	cout <<"最大任务数为：" << ATT.count<<endl;
	cout << "这些任务是：";
	curr = ATT.head;
	while (curr) {
		cout << curr->c << " ";
		curr = curr->next;
	}
}