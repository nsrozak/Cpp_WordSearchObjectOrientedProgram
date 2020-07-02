#include <iostream>
#include <string>
#include "bag.h"
#include "dnode.h"
#include "word.h"
#include "file.h"
using namespace std;

// MEMBER FUNCTIONS

Word::Word(std::string word, bag<file> files){
    this->word=word;
    this->files=files;
}

// NONMEMBER FUNCTIONS
bool operator ==(const Word& w1, const Word& w2){
    if (w1.get_word()==w2.get_word())
        return true;
    else
        return false;  
}

bool operator <(const Word& w1, const Word& w2){
    if (w1.get_word()<w2.get_word())
        return true;
    else
        return false; 
}

bool operator >(const Word& w1, const Word& w2){
    if (w1.get_word()>w2.get_word())
        return true;
    else
        return false; 
}

std::ostream& operator <<(std::ostream &output, const Word& w){
    output << w.get_word();
    return output;
}

void update_object(Word& update, const Word& entry){
    bag<file> update_bag = update.get_files();
    bag<file> entry_bag = entry.get_files();
    dnode<file>* entry_head = entry_bag.get_head();
    if (entry_head==0)
        std::cout << 'a' << std::endl;  // DELETE
    file entry_file = entry_head->value();
    update_bag.insert(entry_file);
    update.set_files(update_bag);
}