#ifndef FILTER_H
#define FILTER_H

#include <string>
#include <vector>

class Filter {
   private:
    std::vector<std::string> filter;
    bool invert;

   public:
    Filter(std::string _filter);
    bool operator()(std::string s) const;
    Filter operator!() const;
};

#endif /* FILTER_H */
