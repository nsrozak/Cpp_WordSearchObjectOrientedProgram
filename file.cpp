#include "file.h"
#include <iostream>
#include <string>
using namespace std;


// MEMBER FUNCTIONS
file::file(std::string filename){
    this->filename=filename;
    count=1;
}

// NONMEMBER FUNCTIONS
bool operator ==(const file& f1, const file& f2){
    if (f1.get_file()==f2.get_file())
        return true;
    else
        return false;  
}

bool operator <(const file& f1, const file& f2){
    if (f1.get_file()<f2.get_file())
        return true;
    else
        return false; 
}

bool operator >(const file& f1, const file& f2){
    if (f1.get_file()>f2.get_file())
        return true;
    else
        return false; 
}

void update_object(file& update, const file& entry){
    update.increase_count();
}