#include "file.h"

namespace Packer {
    const string &File::getFilename() const {
        return fileName;
    }

    size_t File::getFileSize() const {
        return 0;
    }
}
