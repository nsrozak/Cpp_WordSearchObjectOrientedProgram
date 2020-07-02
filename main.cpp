#include <iostream>
#include <vector>
#include <dirent.h>
#include <fstream>
#include "bag.h"
#include "word.h"
#include "dnode.h"
#include "file.h"
using namespace std;

void getfiles(std::string directory, vector<std::string>& files){
    DIR* dpath = opendir(directory.c_str());
    if (dpath==NULL){
        cout << "Error opening directory" << endl;
        exit(1);
    }
    else {
        struct dirent* next_file;
        while((next_file=readdir(dpath))!=NULL)
            files.push_back(std::string(next_file->d_name));
    }
    closedir(dpath);
}

std::string lower_case(std::string& word){
    std::string new_word;
    for (int i=0; i<word.length(); i++)
        new_word += std::tolower(word[i]);
    return new_word;
}

int main(int argc, char* argv[]) {

    std::string directory;
    directory = std::string(argv[1]);
    vector <std::string> files;

    getfiles(directory,files);

    bag<Word> words;

    for (int i=0; i<files.size();i++){
        if (files[i][0]=='.')
            continue;
        ifstream inStream;
        inStream.open((std::string(argv[1])+"/"+files[i]).c_str());
        if (inStream.fail()){
                cout << "Failed to open input file." << endl;
                exit(1);
        }
        std::string word;
        while(!inStream.eof()){
            inStream >> word;
            std::string new_word = lower_case(word);
            file new_file(files[i]);
            bag<file> new_bag(new_file);
            Word add(new_word,new_bag);
            words.insert(add);
        }
        inStream.close();
    }

    cout << "Total number of words: " << words.size() << endl;

    std::string word;
    cout << "Enter a word: ";
    getline(cin, word, '\n');

    file empty_file("Empty");
    bag<file> empty_bag(empty_file);
    Word user_word(word,empty_bag);
    dnode<Word>* found = list_search(words.get_head(),user_word);
    if (found == 0)
        cout << word << " is not in any of the files" << endl;
    else{
        Word found_word(found->value());
        bag<file> found_files = found_word.get_files();
        cout << found_word << " appears in " << found_files.size() << " files" << endl;
        dnode<file>* found_head = found_files.get_head();
        while (found_head!=0){
            file current = found_head->value();
            cout << current.get_file() << ": " << current.get_count() << " times" << endl;
            found_head=found_head->next_link();
        }
    }

    return 0;
}