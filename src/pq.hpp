#pragma once

#include <cstddef> // Include to use NULL, otherwise use nullptr
#include <iostream>
#include "node.hpp"

template <class T>
class PQ
{
private:
    Node<T> *head; // the pointer to the front of the list
    Node<T> *tail; // the pointer to the back of the list
    int count;

public:
    // desc: Inializes a new, empty queue
    PQ();

    // desc:    Adds new data to the queue
    // param:   data The data to add to the list
    // param:   priority The priority assigned to this node
    // returns: void
    void enqueue(T &data, int priority);

    // desc:    Removes the front element form the queue
    // returns: void
    void dequeue(void);

    // desc:    Removes the value found at the front of the queue
    // returns: The data found at the front of the queue
    T get_front(void);

    // desc:    Checks if the queue is empty or not
    // returns: true is the queue is empty, false if not
    bool isEmpty(void);

    // desc:    Clears the queue
    // returns: void
    void clear(void);

    // desc:    Returns the number of elements in the queue
    // returns: The number of elements in the queue
    int get_count(void);
};

template <class T>
PQ<T>::PQ()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <class T>
void PQ<T>::enqueue(T &data, int priority)
{
    Node<T> *new_node = new Node<T>(data, priority);
    Node<T> *placement = head;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->set_next(NULL);
    }
    else if (priority <= head->get_prio())
    {
        new_node->set_next(head);
        head = new_node;
    }
    else if (priority > head->get_prio())
    {
        while (placement->get_next() != NULL)
        {
            if (placement->get_next()->get_prio() > priority)
            {
                break;
            }
            placement = placement->get_next();
        }
        if (placement->get_next() == NULL)
        {
            new_node->set_next(NULL);
            placement->set_next(new_node);
            tail = new_node;
        }
        else
        {
            new_node->set_next(placement->get_next());
            placement->set_next(new_node);
        }
    }
}

template <class T>
void PQ<T>::dequeue(void)
{
    Node<T> *toDestroy = head;
    if (head == NULL)
    {
        return;
    } else if (head->get_next() == NULL){
        head = NULL;
        tail = NULL;
        delete(toDestroy);
    } else
    {
        head = head->get_next();
        delete(toDestroy);
    }
    
    
}

template <class T>
T PQ<T>::get_front()
{
    if (head == NULL)
    {
        return 1;
    }
    return head->get_data();
}

template <class T>
bool PQ<T>::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void PQ<T>::clear(void)
{
    Node<T> *tmp = head;
    Node<T> *tmp2 = head;
    while (tmp != NULL)
    {
        tmp2 = tmp->get_next();
        delete (tmp);
        tmp = tmp2;
    }
    delete (tmp2);
    delete (tmp);
    head = NULL;
    tail = NULL;
    return;
}

template <class T>
int PQ<T>::get_count(void)
{
    Node<T> *tmp = head;
    if (tmp == NULL)
    {
        count = 0;
    }
    else
    {
        while (tmp != NULL)
        {
            count += 1;
            tmp = tmp->get_next();
        }
    }
    return count;
}
