#ifndef LIST_H
#define LIST_H

//я бы сюда конструкторов дописал - для инициализации значений, но в тз их нету
struct List {
    struct List* next{ nullptr };
    int payload;
};

#endif // LIST_H
