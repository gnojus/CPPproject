#ifndef FILE_SOURCE_H
#define FILE_SOURCE_H

#include <fstream>
#include "data_source.h"

namespace Packer {

    class FileSource : public DataSource {
       private:
        std::string filename;
        std::ifstream file;

       public:
        FileSource(std::string _filename);
        void close();
        std::string name();
        std::size_t size();
        void write(std::ostream &o);
    };

}

#endif /* FILE_SOURCE_H */
