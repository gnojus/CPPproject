#include "unpacker.h"

using namespace std;

namespace Packer {
    Unpacker::Unpacker(istream &i) : in(i) {
    }

    vector<file> Unpacker::listFiles() {
    }

    void extractFile(string name, string dir) {
    }

    void extractFile(string name, ostream &o) {
    }

    void Unpacker::extractFiles(string dir) {
    }

    const string &Unpacker::file::getFilename() const {
        return fileName;
    }

    size_t Unpacker::file::getFileSize() const {
        return 0;
    }
}
