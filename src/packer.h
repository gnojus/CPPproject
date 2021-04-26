#ifndef PACKER_H
#define PACKER_H

#include <ostream>
#include "header.h"

namespace Packer {
    using namespace std;

    class Packer {
       public:
        Packer(ostream &o);
        void addFile(string filename);
        void create();

       private:
        ostream &out;
        Header header;
    };

}

#endif /* PACKER_H */
