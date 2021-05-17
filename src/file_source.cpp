#include "file_source.h"

namespace Packer {

    FileSource::FileSource(std::string _filename) : filename(_filename), file(_filename) {
    }

    void FileSource::close() {
        file.close();
    }

    std::string FileSource::name() {
        return filename;
    }

    std::size_t FileSource::size() {
        file.seekg(0, std::ios_base::end);
        std::size_t res = file.tellg();
        file.seekg(0);

        return res;
    }

    void FileSource::write(std::ostream &o) {
        char c;

        while (file.get(c)) {
            o << c;
        }

        file.seekg(0);
    }

}