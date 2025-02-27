#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode *prev;
	ListNode() : val(0), next(nullptr), prev(nullptr) {}
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
	ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class Solution {
private:
	ListNode* head;

public:
	Solution() {
		head = nullptr;
	}

	// Insert a ListNode at the end of the list
	void insert(int value) {
		ListNode* newNode = new ListNode(value);
		if (head == nullptr)
			head = newNode;
		else {
			ListNode* current = head;
			while (current->next != nullptr)
				current = current->next;

			current->next = newNode;
			newNode->prev = current;
		}
	}

	// delete the middle in the list
	void deleteMiddleelement() {
		if (head == nullptr) {
			cout << "List is empty " << endl;
			return;
		}

		ListNode* fast = head, * slow = head;
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}

		if (slow->prev != nullptr)
			slow->prev->next = slow->next;
		else
			head = slow->next;

		if (slow->next != nullptr)
			slow->next->prev = slow->prev;

		delete slow;
	}

	// print the list
	void printList() {
		ListNode* current = head;
		while (current != nullptr) {
			cout << current->val << " ";
			current = current->next;
		}
		cout << endl;
	}

};

void main() {
	Solution list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	cout << "Original list: ";
	list.printList();

	list.deleteMiddleelement();

	cout << "List after deleting middle element: ";
	list.printList();
}

/*
Output:
Original list: 1 2 3 4 5
List after deleting middle element: 1 2 4 5
*/
