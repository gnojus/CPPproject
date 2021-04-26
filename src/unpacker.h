#ifndef UNPACKER_H
#define UNPACKER_H

#include <iostream>
#include "header.h"

namespace Packer {
    using namespace std;

    class Unpacker {
       public:
        class file {
           public:
            const string &getFilename() const;
            size_t getFileSize() const;

           private:
            string fileName;
            size_t fileSize;
        };

        Unpacker(istream &i);
        vector<file> listFiles();
        void extractFile(string name, string dir);
        void extractFile(string name, ostream &o);
        void extractFiles(string dir);

       private:
        istream &in;
        Header header;
    };
}

#endif /* UNPACKER_H */
