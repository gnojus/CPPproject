#ifndef DATA_SOURCE_H
#define DATA_SOURCE_H

#include <string>

namespace Packer {

    class DataSource {
       public:
        virtual ~DataSource();
        virtual std::string name() = 0;
        virtual std::size_t size() = 0;
        virtual void write(std::ostream &o) = 0;
    };

}

#endif /* DATA_SOURCE_H */
