#include "packer.h"

namespace Packer {
    using namespace std;

    const string &Header::entry::getFilename() const {
        return fileName;
    }

    size_t Header::entry::getFileSize() const {
        return 0;
    }

    size_t Header::entry::getOffset() const {
        return 0;
    }

    void Header::addEntry(string filename, size_t fileSize) {
    }

    void Header::removeEntry(string filename) {
    }

    void Header::write(ostream &o) {
    }

    void Header::read(istream &i) {
    }

    vector<Header::entry> Header::getEntries() const {
        return vector<entry>{};
    }

    void Header::calculateOffsets() {
    }
}
