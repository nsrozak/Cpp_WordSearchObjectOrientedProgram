#ifndef _BAG_H
#define _BAG_H
#include "dnode.h"

template <class T>
class bag {
    public:
        // CONSTRUCTOR AND DESTRUCTOR
        bag();
        bag(const bag<T>& source);
        bag(const T& entry);
        ~bag();
        // MODIFIERS
        void insert(const T& entry);
        void operator =(const bag<T>& source);
        // OBSERVERS
        int size() const {return num_nodes;}
        dnode<T>* get_head() const {return head;}
    private:
        dnode<T>* head;
        int num_nodes;
};

template <class T>
inline bag<T>::bag(){
   head=0;
   num_nodes=0;
}

template <class T>
inline bag<T>::bag(const bag<T>& source){
   list_copy(source.head,head);
   num_nodes=source.num_nodes;
}

template <class T>
inline bag<T>::bag(const T& entry){
    dnode<T>* new_dnode = new dnode<T>(entry);
    head=new_dnode;
    num_nodes=1;
}

template <class T>
inline bag<T>::~bag(){
    list_clear(head);
    num_nodes=0;
}

template <class T>
inline void bag<T>::insert(const T& entry){
    dnode<T>* found = list_search(head,entry);
    if (found != 0){
        T update=found->value();
        update_object(update,entry);
        found->set_value(update);
    }
    else{
        dnode<T>* prev = list_locate(head,entry);
        list_insert(head,prev,entry);
        num_nodes++;
    } 
}

template <class T>
void bag<T>::operator =(const bag<T>& source){
    if(this==&source)
		return;
	list_clear(head);
	num_nodes=0;
	list_copy(source.head, head);
	num_nodes=source.num_nodes;
}

#endif