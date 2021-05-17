#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

#include "file.h"

namespace Packer {
    using namespace std;

    class Header {
       public:
        class Entry : public File {
           public:
            size_t getOffset() const;

           private:
            size_t offset;
        };
        void addEntry(string filename, size_t fileSize);
        void removeEntry(string filename);
        void write(ostream &o);
        void read(istream &i);
        vector<Entry> getEntries() const;

       private:
        vector<Entry> entries;
        void calculateOffsets();
    };
}

#endif /* HEADER_H */
