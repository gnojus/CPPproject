#include "file.h"

using namespace std;

File::File(string _name) {
    setName(_name);
}

void File::setName(string _name) {
    name = _name;
}

string File::getName() const {
    return name;
}
