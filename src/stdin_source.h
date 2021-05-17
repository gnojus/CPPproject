#ifndef STDIN_SOURCE_H
#define STDIN_SOURCE_H

#include "data_source.h"

namespace Packer {

    class StdinSource : public DataSource {
       private:
        std::string filename, data;

       public:
        StdinSource(std::string _name);
        std::string name();
        std::size_t size();
        void write(std::ostream &o);
    };

}

#endif /* STDIN_SOURCE_H */
