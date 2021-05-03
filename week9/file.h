#ifndef FILE_H
#define FILE_H

#include <string>

class File {
   private:
    std::string name;

   public:
    File(std::string _name);
    void setName(std::string _name);
    std::string getName() const;
};

#endif /* FILE_H */
