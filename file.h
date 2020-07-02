#ifndef _FILE_H
#define _FILE_H
#include <string>

class file {
    public:
        // CONSTRUCTOR
        file() {filename=""; count=-1;}
        file(std::string filename);
        // MODIFIERS
        void increase_count() {count++;}
        // OBSERVERS
        std::string get_file() const {return filename;}
        int get_count() const {return count;}
    private:
        std::string filename;
        int count;
};

// NONMEMBER FUNCTIONS
bool operator ==(const file& f1, const file& f2);
bool operator <(const file& f1, const file& f2);
bool operator >(const file& f1, const file& f2);
void update_object(file& update, const file& entry);

#endif