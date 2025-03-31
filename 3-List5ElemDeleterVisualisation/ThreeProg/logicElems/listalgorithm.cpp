#include "listalgorithm.h"

ListAlgorithm::ListAlgorithm()
{

}

void ListAlgorithm::initList(int N)
{
    List* root = new List;

    _head = root;
    root->payload = 1;

    for (int i = 2; i <= N; i++) {
        List* node = new List;
        node->payload = i;
        root->next = node;
        root = node;
    }

}

void ListAlgorithm::deleteEveryFifth(List *head) {
    int count = 0;
    List* current = head;
    List* prev = nullptr;

    while (current != nullptr) {
        count++;
        if (count == 5) {
            prev->next = current->next;
            List* toDelete = current;
            current = current->next;
            delete toDelete;
            count = 0;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    emit signalToRedrawItems(head);
}

void ListAlgorithm::cleanList()
{
    List* current = _head;
    while (current != nullptr) {
        List* temp = current->next;
        delete current;
        current = temp;
    }
}

List *ListAlgorithm::getHead() const{
    return _head;
}
