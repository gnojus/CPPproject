#ifndef FILE_H
#define FILE_H

#include <string>

namespace Packer {
    using namespace std;

    class File {
       public:
        const string &getFilename() const;
        size_t getFileSize() const;

       private:
        string fileName;
        size_t fileSize;
    };
}

#endif /* FILE_H */
