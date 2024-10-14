
#include <iostream>
#include "unorderedLinkedList.h"
#include "intLinkedList.h" // Your custom intLinkedList class

using namespace std;

int main() {
    intLinkedList originalList, evensList, oddsList;
    int num;

    // Input numbers into the original list
    cout << "Enter integers ending with -999" << endl;
    cin >> num;
    while (num != -999) {
        originalList.insertLast(num);
        cin >> num;
    }

    // Print the original list (which should now be empty)
    cout << "list: ";
    for (linkedListIterator<int> it = originalList.begin(); it != originalList.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Split the original list into evens and odds
    originalList.splitEvensOddsList(evensList, oddsList);

    // Print the even numbers list
    cout << "evensList: ";
    for (linkedListIterator<int> it = evensList.begin(); it != evensList.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Print the odd numbers list
    cout << "oddsList: ";
    for (linkedListIterator<int> it = oddsList.begin(); it != oddsList.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
