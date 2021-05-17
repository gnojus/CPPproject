#include "stdin_source.h"

#include <iostream>

using namespace std;

namespace Packer {

    StdinSource::StdinSource(string _name) : filename(_name) {
        char c;

        while (cin.get(c), !cin.eof()) {
            data.push_back(c);
        }
    }

    string StdinSource::name() {
        return filename;
    }

    size_t StdinSource::size() {
        return data.length();
    }

    void StdinSource::write(ostream &o) {
        o << data;
    }

}