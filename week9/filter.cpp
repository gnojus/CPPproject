#include "filter.h"
#include <vector>

using namespace std;

Filter::Filter(string _filter) : invert(false) {
    string current;
    for (auto c : _filter) {
        if (c == '*') {
            filter.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }
    filter.push_back(current);
}

bool Filter::operator()(string s) const {
    bool ok = true;
    size_t pos = 0;
    for (int i = 0; ok && i < filter.size(); ++i) {
        if (i + 1 == filter.size()) {
            pos = s.rfind(filter[i]);
        } else {
            pos = s.find(filter[i], pos);
        }
        ok &= pos != string::npos && (i || !pos);
        pos += filter[i].length();
    }
    ok &= pos == s.length();
    return ok ^ invert;
}

Filter Filter::operator!() const {
    Filter tmp(*this);
    tmp.invert = !tmp.invert;
    return tmp;
}
