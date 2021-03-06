#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct _deque{
	_deque * p;
	_deque * next;
	int data;
}Node;

typedef struct {
	Node *head;
	Node *tail;
	int cnt;
}Deque;

char info[20];

void pushfront(Deque *plist, int n) {
	plist->cnt++;
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = n;
	newnode->p = NULL;
	if (plist->head == NULL) {
		newnode->next = NULL;
		plist->tail = newnode;
		plist->head = newnode;
	}
	else {
		newnode->next = plist->head;
		plist->head->p = newnode;
		plist->head = newnode;
	}
}

void pushback(Deque *plist, int n) {
	plist->cnt++;
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = n;
	newnode->next = NULL;
	if (plist->tail == NULL) {
		newnode->p = NULL;
		plist->tail = newnode;
		plist->head = newnode;
	}
	else {
		newnode->p = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
}

int popfront(Deque *plist) {
	if (plist->head == NULL && plist->tail == NULL) {
		return -1;
	}
	else {
		plist->cnt--;
		int ans = plist->head->data;
		Node *tmp = plist->head;
		if (plist->head == plist->tail) {
			free(tmp);
			plist->head = NULL;
			plist->tail = NULL;
			return ans;
		}
		else {
			plist->head = plist->head->next;
			plist->head->p = NULL;
			free(tmp);
			return ans;
		}
	}
}

int popback(Deque *plist) {
	if (plist->head == NULL && plist->tail == NULL) {
		return -1;
	}
	else {
		plist->cnt--;
		int ans = plist->tail->data;
		Node *tmp = plist->tail;
		if (plist->tail == plist->head) {
			free(tmp);
			plist->head = NULL;
			plist->tail = NULL;
			return ans;
		}
		else {
			plist->tail = plist->tail->p;
			plist->tail->next = NULL;
			free(tmp);
			return ans;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	Deque *newdeque = (Deque*)malloc(sizeof(Deque));
	newdeque->head = NULL; newdeque->tail = NULL;
	newdeque->cnt = 0;
	while (N--) {
		int num=0;
		cin >> info;
		if (strcmp("push_front", info) == 0) {
			cin >> num;
			pushfront(newdeque, num);
		}
		if (strcmp("push_back", info) == 0) {
			cin >> num;
			pushback(newdeque, num);
		}
		if (strcmp("pop_front", info) == 0) {
			int ans = popfront(newdeque);
			cout << ans << '\n';
		}
		if (strcmp("pop_back", info) == 0) {
			int ans = popback(newdeque);
			cout << ans << '\n';
		}
		if (strcmp("size", info) == 0) {
			cout << newdeque->cnt << '\n';
		}
		if (strcmp("empty", info) == 0) {
			if (newdeque->cnt == 0) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		if (strcmp("front", info) == 0) {
			if (newdeque->head == NULL) cout << "-1" << '\n';
			else cout << newdeque->head->data << '\n';
			
		}
		if (strcmp("back", info) == 0) {
			if (newdeque->tail == NULL) cout << "-1" << '\n';
			else cout << newdeque->tail->data << '\n';
		}
	}
	return 0;
}