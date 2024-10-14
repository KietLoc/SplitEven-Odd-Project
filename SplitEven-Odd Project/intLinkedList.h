#ifndef H_intLinkedList
#define H_intLinkedList

#include "unorderedLinkedList.h"
using namespace std;

class intLinkedList : public unorderedLinkedList<int> {
public:
    // Default constructor
    intLinkedList() : unorderedLinkedList<int>() {}

    // Function to split the list into evens and odds
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) 
    {
        nodeType<int>* current = this->first; // Start from the first node in the original list
        nodeType<int>* nextNode;

        // Ensure the evensList is initially empty
        evensList.first = nullptr;
        evensList.last = nullptr;
        evensList.count = 0;

        // Ensure the oddsList is initially empty
        oddsList.first = nullptr;
        oddsList.last = nullptr;
        oddsList.count = 0;

        // Traverse and split the list into evens and odds
        while (current != nullptr) 
        {
            nextNode = current->link; // Store the next node

            if (current->info % 2 == 0) { // Even number
                if (evensList.first == nullptr) 
                {
                    evensList.first = current;
                    evensList.last = current;
                }
                else 
                {
                    evensList.last->link = current;
                    evensList.last = current;
                }
                evensList.count++;
            }
            else { // Odd number
                if (oddsList.first == nullptr) 
                {
                    oddsList.first = current;
                    oddsList.last = current;
                }
                else 
                {
                    oddsList.last->link = current;
                    oddsList.last = current;
                }
                oddsList.count++;
            }

            current->link = nullptr; // Detach the current node from the original list
            current = nextNode; // Move to the next node
        }

        // Make the original list empty
        this->first = nullptr;
        this->last = nullptr;
        this->count = 0;
    }
};

#endif