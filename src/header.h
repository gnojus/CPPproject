#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

namespace Packer {
    using namespace std;

    class Header {
       public:
        class entry {
           public:
            const string &getFilename() const;
            size_t getFileSize() const;
            size_t getOffset() const;

           private:
            string fileName;
            size_t fileSize, offset;
        };
        void addEntry(string filename, size_t fileSize);
        void removeEntry(string filename);
        void write(ostream &o);
        void read(istream &i);
        vector<entry> getEntries() const;

       private:
        vector<entry> entries;
        void calculateOffsets();
    };
}

#endif /* HEADER_H */
