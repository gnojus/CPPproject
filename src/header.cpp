#include "packer.h"

namespace Packer {
    using namespace std;

    size_t Header::Entry::getOffset() const {
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

    vector<Header::Entry> Header::getEntries() const {
        return {};
    }

    void Header::calculateOffsets() {
    }
}
