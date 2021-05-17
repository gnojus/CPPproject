#ifndef UNPACKER_H
#define UNPACKER_H

#include <iostream>
#include "file.h"
#include "header.h"

namespace Packer {
    using namespace std;

    class Unpacker {
       public:
        Unpacker(istream &i);
        vector<File> listFiles();
        void extractFile(string name, string dir);
        void extractFile(string name, ostream &o);
        void extractFiles(string dir);

       private:
        istream &in;
        Header header;
    };
}

#endif /* UNPACKER_H */
