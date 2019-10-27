#pragma once

#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream>
#include "node.hpp"

template<class T>
class PQ{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
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

template<class T>
PQ<T>::PQ()
{
	head = NULL;
    tail = NULL;
    count = 0;
}

template<class T>
void PQ<T>::enqueue(T &data, int priority)
{
    Node<T> *new_node = new Node<T>(data, priority);
    if (head == NULL){
        head = new_node;
        tail = new_node; 
    } else {
        new_node->set_next(head);
        head = new_node;
    }

}

template<class T>
void PQ<T>::dequeue(void)
{
    if (head == NULL){
        return 0;
    }
    Node<T> *tmp = head;
    Node<T> *target = NULL;
    tmp_prio = tmp->get_prio; 
    while (while tmp != NULL)
    {
        tmp = tmp->get_next;
            if (tmp->get_prio < tmp_prio){
                target = tmp;
            } else {
                target = head;
            }
    }
    if (target == head){
        tmp = head;
        head = head->get_next;
        delete(tmp);
        delete(target)
        return 0;
    } else if ( target == tail){
        tmp = head;
        while (tmp->get_next != tail){
            tmp = tmp->get_next;
        }
        tail = tmp;
        delete(tmp);
        delete(target);
        return 0;
    } else (
        tmp = head; 
        while (tmp->get_next != target){
            tmp = tmp->get_next;
        }
        tmp->set_next = target->get_next;
        
    )

}

template<class T>
T  PQ<T>::get_front()
{
}

template<class T>
bool PQ<T>::isEmpty()
{
}

template<class T>
void PQ<T>::clear(void)
{
}


template<class T>
int PQ<T>::get_count(void)
{
}

