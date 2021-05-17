#include "unpacker.h"

using namespace std;

namespace Packer {
    Unpacker::Unpacker(istream &i) : in(i) {
    }

    vector<File> Unpacker::listFiles() {
        return {};
    }

    void extractFile(string name, string dir) {
    }

    void extractFile(string name, ostream &o) {
    }

    void Unpacker::extractFiles(string dir) {
    }
}
