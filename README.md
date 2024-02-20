# Linear Linked List Implementation

This will provides an elegant overview of a linked list implementation in C++, encapsulated within two classes: `Node` and `LinkedList`. These classes offer a comprehensive set of methods for efficient manipulation of linked list data structure.

## Classes Overview

### `Node` Class

- Represents a single node in the linked list.
- Stores data of generic type `T` and a pointer to the next node.
- Provides constructors for node initialization with or without data.
- Offers a method to retrieve the data stored in the node.

### `LinkedList` Class

- Represents a linked list and manages its operations.
- Includes a pointer to the head node and various methods for list manipulation, such as:
  - Insertion (`insertAtHead`, `insertAtTail`, `insertBefore`, `insertAfter`)
  - Deletion (`deleteAtHead`, `deleteAtTail`, `deleteAfter`, `deleteSecondLastNode`)
  - Searching (`search`)
  - Length calculation (`getLength`)
  - Reversal (`reverse`, `reverseLinkedListIteratively`)
  - Palindrome check (`isPalindrome`)
  - Loop detection (`isLoopExists`)
  - Sorted merge of two lists (`sortedMerge`)
  - Middle node retrieval (`middleNode`)
  - Cloning the list (`createClone`)
  - Compressing the list (`compressList`)
  - Removing nodes with values greater than on the right side (`removeAllNodesValueGreaterRightSide`)
  - Alternative node deletion (`delAlternative`)
  - Swapping nodes at given indices (`swap`)
  - Splitting the list into two (`splitList`)

## Example Usage

```cpp
int main() {
    // Create a linked list of characters
    LinkedList<char> x;
    x.insertNode('a');
    x.insertNode('b');
    x.insertNode('c');
    x.insertNode('d');
    x.insertNode('c');
    x.insertNode('b');
    x.insertNode('a');

    // Check if the list is a palindrome
    bool isPalindromic = x.isPalindrome();
    cout << "Is Palindrome: " << isPalindromic << endl;

    // Display the list
    x.display();

    // Create two sorted lists
    LinkedList<int> list1;
    // Insert elements into list1
    LinkedList<int> list2;
    // Insert elements into list2

    // Merge the two sorted lists
    LinkedList<int> mergedList;
    mergedList.sortedMerge(list1, list2);
    cout << "Merged Sorted List: ";
    mergedList.display();

    // Check if a loop exists in the list
    bool loopExists = list2.isLoopExists();
    cout << "Loop Exists: " << loopExists << endl;

    return 0;
}
