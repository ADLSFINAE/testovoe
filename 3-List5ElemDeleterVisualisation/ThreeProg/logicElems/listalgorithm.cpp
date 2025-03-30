#include "listalgorithm.h"

ListAlgorithm::ListAlgorithm()
{

}

void ListAlgorithm::initList(int N)
{
    List* root = new List;

    head = root;

    for (int i = 2; i <= N; i++) {
        List* node = new List;
        node->payload = i;
        root->next = node;
        root = node;
    }

    // Удаляем каждый пятый элемент
    //deleteEveryFifth(head);

    // Выводим список после удаления
    /*List* current = head;
    while (current != nullptr) {
        cout << current->payload.getNumber() << " ";
        current = current->next;
    }*/
}

void ListAlgorithm::deleteEveryFifth(List *head) {
    int count = 0;
    List* current = head;
    List* prev = nullptr;

    while (current != nullptr) {
        count++;
        if (count == 5) {
            // Удаляем текущий узел
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
    List* current = head;
    while (current != nullptr) {
        List* next = current->next;
        delete current;
        current = next;
    }
}
