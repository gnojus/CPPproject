#include <iostream>
#include <vector>
#include <set>

#include "file_list.h"

using namespace std;

int main() {
    FileList list;
    for (auto s : {
        "README.md",
        "e.exe",
        "link.txt",
        "build.txt",
        "logs.txt",
        "src/main.cpp",
        "src/main.exe",
        "src/main.o",
    }) {
        list.add(File(s));
    }
    Filter filter("*.txt");
    for (auto it = list.begin(filter); it != list.end(); ++it) {
        cout << (*it).getName() << endl;
    } 

    auto it = list.begin();
    for (it.setFilter(Filter("src/*")); it != list.end(); ++it) {
        cout << (*it).getName() << endl;
    } 
}