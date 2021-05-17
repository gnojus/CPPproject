#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include "file_source.h"
#include "stdin_source.h"

using namespace std;


void printUsage() {
}

void printHelp() {
}

bool hasFlag(char *flags[], int flagCount, const string &flag) {
    return true;
}

int eval(char *flags[], int flagCount) {
    if (hasFlag(flags, flagCount, "--help")) {
        printHelp();
        return 0;
    }
    printUsage();
    return 1;
}

using Packer::DataSource;
using Packer::FileSource;
using Packer::StdinSource;

void polymorphism() {
    vector<DataSource*> sources;    

    string filename;
    cout << "Enter real filename:" << endl;
    cin >> filename;
    sources.push_back(new FileSource(filename));

    cout << "Enter imaginary filename:" << endl;
    cin >> filename;

    cout << "Enter this file contents:" << endl;
    cin.ignore();
    sources.push_back(new StdinSource(filename));

    cout << "File sources:" << endl;
    for (DataSource* source : sources) {
        cout << "Name: " << source->name() << endl;
        cout << "Size: " << source->size() << endl;
        cout << "Contents:" << endl;
        cout << "===========================" << endl;
        source->write(cout);
        cout << "===========================" << endl;

        if (FileSource *file = dynamic_cast<FileSource*>(source)) {
            cout << "And it's a file" << endl;
            file->close();
        }

        cout << endl;

        delete source;
    }
}

int main(int argc, char **argv) {
    polymorphism();

    return 0;

    try {
        return eval(argv + 1, argc - 1);
    } catch (std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred" << endl;
    }

    return 1;
}