#include <algorithm>
#include <exception>
#include <iostream>

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

int main(int argc, char **argv) {
    try {
        return eval(argv + 1, argc - 1);
    } catch (std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred" << endl;
    }

    return 1;
}