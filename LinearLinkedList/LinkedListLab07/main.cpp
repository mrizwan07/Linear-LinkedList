#include <iostream>
#include <string>
using namespace std;

//Forward Declaration.
template <typename T>
class LinkedList;

template <class T>
class Node
{
	friend LinkedList<T>;
	T info;
	Node<T>* next;

public:
	Node()
	{
		next = nullptr;
	}
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
	T getInfo()
	{
		return info;
	}
};

template <typename T>
class LinkedList
{
	Node<T>* head;
	void reversePrint(Node<T>* p)
	{
		if (p == nullptr)
		{
			return;
		}
		Node<T>* nodeptr = p;
		while (nodeptr != nullptr)
		{
			cout << nodeptr->info << "\n";
			nodeptr = nodeptr->next;
		}

	}
public:
	LinkedList()
	{
		head = nullptr;
	}
	bool sortedMerge(LinkedList<T>& list1, LinkedList<T>& list2)
	{
		if (list1.head == nullptr && list2.head == nullptr)
		{
			return true; // Both lists are empty, no merge needed
		}

		if (list1.head == nullptr)
		{
			head = list2.head; // If list1 is empty, result is list2
			list2.head = nullptr; // Reset list2
			return true;
		}

		if (list2.head == nullptr)
		{
			head = list1.head; // If list2 is empty, result is list1
			list1.head = nullptr; // Reset list1
			return true;
		}

		Node<T>* temp = nullptr;
		if (list1.head->info <= list2.head->info)
		{
			temp = list1.head;
			list1.head = list1.head->next;
		}
		else
		{
			temp = list2.head;
			list2.head = list2.head->next;
		}

		Node<T>* current = temp; // Pointer to the current node in the merged list

		// Merge the lists in sorted order
		while (list1.head != nullptr && list2.head != nullptr)
		{
			if (list1.head->info <= list2.head->info)
			{
				current->next = list1.head;
				list1.head = list1.head->next;
			}
			else
			{
				current->next = list2.head;
				list2.head = list2.head->next;
			}
			current = current->next;
		}

		// Append remaining nodes if any
		if (list1.head == nullptr)
		{
			current->next = list2.head;
		}
		else
		{
			current->next = list1.head;
		}

		// Update the head of the merged list
		head = temp;

		// Reset the heads of list1 and list2
		list1.head = nullptr;
		list2.head = nullptr;

		return true;
	}



	bool isLoopExists()
	{
		Node<T>* slow = head;
		Node<T>* fast = head;
		bool loop = false;

		if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
			return loop;

		slow = slow->next;
		fast = fast->next->next;
		while (true)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast->next == nullptr || fast == nullptr)
			{
				loop = false;
				break;
			}
			if (fast == slow)
			{
				loop = true;
				break;
			}
		}
		return loop;
	}

	void recursivePalindromeFunction(Node<T>* head, string& s1, string& s2) {
		if (head == nullptr) {
			return;
		}
		// Add the current node's data to both strings
		s1 += to_string(head->info);
		s2 = to_string(head->info) + s2; // Prepend to simulate reverse order

		// Call the function recursively for the next node
		recursivePalindromeFunction(head->next, s1, s2);
	}

	bool isPalindrome()
	{
		string str1 = "";
		string str2 = "";
		recursivePalindromeFunction(head, str1, str2);
		return str1 == str2;
	}


	



	void insertNodeAtTail(T val)
	{
		Node<T>* temp = new Node<T>(val);
		if (head == nullptr)
		{
			head = temp;
			return;
		}
		Node<T>* nodeptr = head;
		while (nodeptr->next != nullptr)
		{	
			nodeptr = nodeptr->next;
		}
		nodeptr->next = temp;
	}
	void display()
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>* nodeptr = head;
		while (nodeptr != nullptr)
		{
			cout<<nodeptr->info<<"\n";
			nodeptr = nodeptr->next;
		}
	}
	bool insertBefore(T val)
	{
		if (head == nullptr)
		{
			return false;
		}
		Node<T>* temp = new Node<T>(val);
		if (head->info == val)
		{
			temp->next = head;
			head = temp;
			return true;
		}
		Node<T>* previous = head;
		Node<T>* next = head->next;
		while (next != nullptr && next->info!=val)
		{
			previous = next;
			next = next->next;
		}
		temp->next = next;
		previous->next = temp;
		return true;
	}
	bool insertAfter(T val)
	{
		if (head == nullptr)
		{
			return false; // If the list is empty, cannot insert after any node
		}

		Node<T>* temp = new Node<T>(val);

		// Special case: inserting after the head
		if (head->info == val)
		{
			temp->next = head->next;
			head->next = temp;
			return true;
		}

		Node<T>* current = head;

		while (current != nullptr)
		{
			if (current->info == val)
			{
				// Insert after the current node
				temp->next = current->next;
				current->next = temp;
				return true;
			}
			current = current->next;
		}

		// If the value is not found in the list, return false
		return false;
	}

	void insertAtHead(T val)
	{
		Node<T>* temp = new Node<T>(val);
		if (head == nullptr)
		{
			head = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void insertAtHead(Node<T>* newNode)
	{
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}

	void insertAtTail(T val)
	{
		Node<T>* temp = new Node<T>(val);
		if (head == nullptr)
		{
			head = temp;
			return;
		}
		Node<T>* nodeptr = head;
		while (nodeptr->next != nullptr)
		{
			nodeptr = nodeptr->next;
		}
		nodeptr->next = temp;
	}
	bool deleteAtHead()
	{
		if (head == nullptr)
		{
			return false; // Empty list
		}

		Node<T>* temp = head->next;
		delete head;
		head = temp;
		return true;
	}

	bool deleteAtTail()
	{
		if (head == nullptr)
		{
			return false;
		}
		Node<T>* previous = nullptr;
		Node<T>* current=head;
		Node<T>* next = head->next;
		while (next != nullptr)
		{
			previous = current;
			current = next;
			next = next->next;
		}
		if (head->next == next)
		{
			delete head;
			head = nullptr;
			return true;
		}
		else
		{
			delete current;
			current = nullptr;
			previous->next = nullptr;
			return true;
		}
	}




	Node<T>* search(T val)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == val)
			{
				return temp;
			}
			temp = temp->next;
		}
		return nullptr; // Return nullptr if the value is not found
	}



	bool deleteAfter(T val)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return false; // Cannot delete if list has less than two nodes
		}

		Node<T>* temp = head;
		while (temp != nullptr && temp->info != val)
		{
			temp = temp->next;
		}

		if (temp == nullptr || temp->next == nullptr)
		{
			return false; // Value not found or it's the last node, cannot delete
		}

		Node<T>* toDelete = temp->next;
		temp->next = temp->next->next;
		delete toDelete;
		return true;
	}

	void compressList()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return; // Nothing to compress if list has less than two nodes
		}

		Node<T>* current = head;
		Node<T>* nextNode = head->next;

		while (nextNode != nullptr)
		{
			if (current->info == nextNode->info)
			{
				// Remove the next duplicate node
				Node<T>* temp = nextNode;
				current->next = nextNode->next;
				delete temp;
				nextNode = current->next;
			}
			else
			{
				// Move to the next pair of nodes
				current = nextNode;
				nextNode = nextNode->next;
			}
		}
	}

	int getLenght()
	{
		int count = 0;
		Node<T>* nodeptr = head;
		while (nodeptr != nullptr)
		{
			count++;
			nodeptr = nodeptr->next;
		}
		return count;
	}
	Node<T>* middleNode()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		int count = 0;
		Node<T>* slow = head;
		Node<T>* fast = head->next->next;
		while (fast != nullptr)
		{
			count = count + 2;
			slow = slow->next;
			if (fast->next == nullptr)
			{
				return slow;
			}
			fast = fast->next->next;
		}
		if (count % 2 == 0)
		{
			return slow;
		}
		else
		{
			return 
				slow->next;
		}
	}
	void reverse()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return; // Empty list or single node list
		}

		Node<T>* prev = nullptr;
		Node<T>* current = head;
		Node<T>* next = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}

	void reversePrintWrapper()
	{
		reversePrint(head);
	}
	bool deleteSecondLastNode()
	{
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		{
			return false; // Cannot delete if less than two nodes
		}

		Node<T>* previous = nullptr;
		Node<T>* current = head;
		Node<T>* next = head->next;

		while (next->next != nullptr)
		{
			previous = current;
			current = next;
			next = next->next;
		}

		if (previous == nullptr) // If the head is to be deleted
		{
			delete head;
			head = current;
			return true;
		}
		else
		{
			delete previous->next;
			previous->next = next;
			return true;
		}
	}


	bool isEqual(LinkedList<T>& list2)
	{
		Node<T>* temp1 = head;
		Node<T>* temp2 = list2.head;

		while (temp1 != nullptr && temp2 != nullptr)
		{
			if (temp1->info != temp2->info)
				return false;

			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		// If both lists have reached the end simultaneously, they are equal.
		return temp1 == nullptr && temp2 == nullptr;
	}


	//clone
	LinkedList<T> createClone()
	{
		LinkedList<T> list;

		Node<T>* temp = head;
		list.head = new Node<T>(temp->info);
		Node<T>* tempp = list.head;

		temp = temp->next;
		while (temp != nullptr)
		{
			Node<T>* newNode = new Node<T>(temp->info);
			tempp->next = newNode;
			tempp = tempp->next;
			temp = temp->next;
		}

		return list;
	}

	void delAlternative()
	{
		if (head == nullptr || head->next == nullptr)
			return; // No or single node, nothing to delete

		Node<T>* prev = head;
		Node<T>* current = head->next;
		Node<T>* next;

		while (current != nullptr && current->next != nullptr)
		{
			next = current->next;
			prev->next = next;
			delete current;
			prev = next;
			current = next->next;
		}

		// If current is not nullptr, we have one more node to delete
		if (current != nullptr)
		{
			prev->next = nullptr;
			delete current;
		}
	}


	void splitList(LinkedList<T>& list1, LinkedList<T>& list2)
	{
		if (head == nullptr)
			return; // Nothing to split if the original list is empty

		Node<T>* slow = head;
		Node<T>* fast = head->next;
		Node<T>* temp;

		// Initialize list1 with the first node
		list1.head = head;
		temp = list1.head;

		// Initialize list2 with the second node
		if (fast != nullptr)
		{
			list2.head = fast;
			fast = fast->next;
			temp = list2.head;
		}

		// Traverse the original list, alternating nodes between list1 and list2
		while (fast != nullptr && fast->next != nullptr)
		{
			temp->next = slow->next;
			temp = temp->next;

			slow = fast;
			fast = fast->next->next;
		}

		// If there's an odd number of nodes, add the last node to list1
		if (fast == nullptr && slow->next != nullptr)
		{
			temp->next = slow->next;
			temp = temp->next;
		}

		// Terminate both lists
		temp->next = nullptr;
		slow->next = nullptr;
	}




	void reverseLinkedListIteratively()
	{
		if (head == nullptr || head->next == nullptr)
			return; // Nothing to reverse if the list is empty or has only one node

		Node<T>* prev = nullptr;
		Node<T>* current = head;
		Node<T>* next = nullptr;

		while (current != nullptr)
		{
			next = current->next; // Store the next node
			current->next = prev; // Reverse the link

			// Move pointers one position ahead
			prev = current;
			current = next;
		}

		// Set the new head to the previous node (which is now the last node)
		head = prev;
	}


	void swap(int m, int n)
	{
		if (m == n) {
			// No need to swap if m and n are the same
			cout << "No need to swap as indices are the same." << endl;
			return;
		}

		if (m <= 0 || n <= 0) {
			// Invalid indices
			cout << "Invalid indices." << endl;
			return;
		}

		if (head == nullptr || head->next == nullptr) {
			// Nothing to swap if the list is empty or has only one node
			cout << "List is empty or has only one node." << endl;
			return;
		}

		Node<T>* prevM = nullptr;
		Node<T>* prevN = nullptr;
		Node<T>* nodeM = head;
		Node<T>* nodeN = head;
		int count = 1;

		// Find the nodes at positions m and n
		while (count < m && nodeM != nullptr) {
			prevM = nodeM;
			nodeM = nodeM->next;
			count++;
		}

		count = 1;

		while (count < n && nodeN != nullptr) {
			prevN = nodeN;
			nodeN = nodeN->next;
			count++;
		}

		if (nodeM == nullptr || nodeN == nullptr) {
			// At least one of the indices is out of bounds
			cout << "One or both indices are out of bounds." << endl;
			return;
		}

		if (prevM != nullptr) {
			prevM->next = nodeN;
		}
		else {
			head = nodeN;
		}

		if (prevN != nullptr) {
			prevN->next = nodeM;
		}
		else {
			head = nodeM;
		}

		// Swap the next pointers of the nodes
		Node<T>* temp = nodeM->next;
		nodeM->next = nodeN->next;
		nodeN->next = temp;
	}


	

	void removeAllNodesValueGreaterRightSide()
	{
		if (head == nullptr)
			return; // Empty list

		Node<T>* current = head;
		Node<T>* maxNode = head;
		Node<T>* temp;

		while (current != nullptr && current->next != nullptr)
		{
			temp = current->next;

			while (temp != nullptr && temp->info <= maxNode->info)
			{
				Node<T>* del = temp;
				temp = temp->next;
				delete del;
			}

			current->next = temp;

			if (temp != nullptr && temp->info > maxNode->info)
			{
				maxNode = temp;
				current = temp;
			}
			else
			{
				current = current->next;
			}
		}
	}

	void insertNode(T val)
	{
		insertAtTail(val);
	}
	

};


int main() {
	LinkedList<char> x;
	x.insertNode('a');
	x.insertNode('b');
	x.insertNode('c');
	x.insertNode('d');
	x.insertNode('c');
	x.insertNode('b');
	x.insertNode('a');
	x.display();
	cout << "PalinDrom\n";
	bool y = x.isPalindrome();
	cout << y << "\n";

	LinkedList<int> list1;
	list1.insertNode(4);
	list1.insertNode(7);
	list1.insertNode(10);
	list1.insertNode(12);
	list1.insertNode(20);
	list1.insertNode(23);
	list1.insertNode(19);
	list1.insertNode(35);
	list1.insertNode(40);
	list1.insertNode(20);
	list1.display();

	LinkedList<int> list2;
	list2.insertNode(1);
	list2.insertNode(3);
	list2.insertNode(6);
	list2.insertNode(8);
	list2.insertNode(9);
	list2.insertNode(15);
	list2.insertNode(19);
	list2.insertNode(21);
	list2.insertNode(24);
	list2.insertNode(27);
	list2.insertNode(32);
	list2.insertNode(38);
	list2.display();

	LinkedList<int> list3;
	cout << "After merging both sorted lists the final is :\n";
	list3.sortedMerge(list1, list2);
	list3.display();
	cout << "\n";
	cout << "Loop exists or not :\n";
	bool z = list2.isLoopExists();
	cout << z;
	int length;
	length = x.getLenght();
	cout << "Total number of nodes in the list are " << length << "\n";

	Node<char>* middle = x.middleNode();
	cout << "Info of node is " << middle->getInfo() << "\n";

	x.insertBefore(33);
	x.insertBefore(11);
	x.display();
	length = x.getLenght();
	cout << "Total number of nodes in the list are " << length << "\n";
	x.insertAfter(66);
	x.display();
	cout << "Insertion at head \n";
	x.insertAtHead(12);
	x.display();
	cout << "Insertion at tail \n";
	x.insertAtTail(109);
	x.display();
	cout << "Deletion at head \n";
	x.deleteAtHead();
	x.display();
	cout << "Deletion at tail \n";
	x.deleteAtTail();
	x.display();
	cout << "Insertion at Head by node passing \n";
	/*Node<char> y(2001);
	x.insertAtHead(y);
	*/x.display();
	cout << "Insertion at tail by node passing \n";
	/*Node<char> z(3001);
	x.insertAtTail(z);
	*/x.display();
	cout << "Deletion after specific value \n";
	x.deleteAfter(3001);
	x.display();
	x.reverse();
	x.reversePrintWrapper();

	return 0;
}
