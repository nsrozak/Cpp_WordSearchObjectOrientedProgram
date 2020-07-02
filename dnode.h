#ifndef _DNODE_H
#define _DNODE_H

template <class T>
class dnode {
    public:
        // CONSTRUCTOR
        dnode(const T& data=0, dnode<T>* prev=0, dnode<T>* next=0) 
         {this->data=data; this->prev=prev; this->next=next;}
        // MODIFIERS
        void set_value(const T& data) {this->data=data;}
        void set_prev(dnode<T>* prev) {this->prev=prev;}
        void set_next(dnode<T>* next) {this->next=next;}
        // OBSERVERS
        T value() const {return data;}
        dnode<T>* prev_link() {return prev;}
        dnode<T>* next_link() {return next;}
    private:
        T data;
        dnode<T>* prev;
        dnode<T>* next;
};

// NONMEMBER FUNCTIONS

// USE: insert item into list
template <class T>
void list_insert(dnode<T>*& head, dnode<T>* prev, const T& entry){
    dnode<T>* new_element=new dnode<T>(entry);
    if(prev==0){  // case where new_element becomes head
        new_element->set_next(head);
        if(head!=0)  // set previous of current head to new_element
            head->set_prev(new_element);
        head = new_element;
    }
    else {  // case where new_element is not head
        dnode<T>* future=prev->next_link();
        new_element->set_prev(prev);
        new_element->set_next(future);
        prev->set_next(new_element);
        if(future!=0)  // case where new_element isn't the last node
            future->set_prev(new_element);
    }
}

// USE: find location of item in list
// PRECONDITION: list arranged in alphabetical order
template <class T>
dnode<T>* list_locate(dnode<T>* head, const T& target){
    dnode<T>* cursor = head;
    dnode<T>* previous=0;
    while(cursor!=0 && target>cursor->value()){
        previous=cursor;
        cursor=cursor->next_link();
    }
    return previous;
}


// USE: search list for item
// PRECONDITION: list arranged in alphabetical order
template <class T>
dnode<T>* list_search(dnode<T>* head, const T& target){
    dnode<T>* cursor;
    for(cursor=head; cursor!=0; cursor=cursor->next_link()){
        if(target==cursor->value())
            return cursor;
        else if (target<cursor->value())
            break;
    }
    return 0;
}

// USE: remove all items from list
template <class T>
void list_clear(dnode<T>*& head){
    while(head!=0){
        dnode<T>* remove=head;
        dnode<T>* future=head->next_link();
        head=future;
        delete remove;
    }
}

// USE: make a deep copy of a list
template <class T>
void list_copy(dnode<T>* source, dnode<T>*& head){
    head=0;
    dnode<T>* prev=0;
    dnode<T>* source_cursor=source;
    while(source_cursor!=0){
        list_insert(head,prev,source_cursor->value());
        if(prev==0)
            prev=head;
        else
            prev=prev->next_link();
        source_cursor=source_cursor->next_link();
    }
}

#endif