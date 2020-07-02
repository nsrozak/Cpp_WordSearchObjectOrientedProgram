#ifndef _WORD_H
#define _WORD_H
#include "bag.h"
#include "file.h"
#include <string>

class Word {
    public:
        // CONSTRUCTOR
        Word() {word=""; bag<file> files; files=files;}
        Word(std::string word, bag<file> files);
        // MODIFIERS
        void set_files(bag<file> files) {this->files=files;}
        // OBSERVERS
        std::string get_word() const {return word;}
        bag<file> get_files() const {return files;}
    private:
        std::string word;
        bag<file> files;
};

// NONMEMBER FUNCTIONS
bool operator ==(const Word& w1, const Word& w2);
bool operator <(const Word& w1, const Word& w2);
bool operator >(const Word& w1, const Word& w2);
std::ostream& operator <<(std::ostream &output, const Word& w);
void update_object(Word& update, const Word& entry);

#endif