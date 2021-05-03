#ifndef FILE_LIST_H
#define FILE_LIST_H

#include <map>
#include "file.h"
#include "filter.h"

class CopyNotAllowedException {};

class FileList {
   private:
    std::map<std::string, File> files;

   public:
    FileList();
    FileList(const FileList &f);
    FileList &operator=(const FileList &f);

    void add(const File &file);
    void remove(const File &file);
    File &operator[](std::string name);
    FileList &operator+=(const File &file);
    FileList &operator-=(const File &file);

    class Iterator {
       private:
        std::map<std::string, File>::iterator it, end;
        Filter *filter;
        void moveToMatch();

       public:
        Iterator(std::map<std::string, File>::iterator _it,
                 std::map<std::string, File>::iterator _end);
        Iterator(std::map<std::string, File>::iterator _it,
                 std::map<std::string, File>::iterator _end,
                 const Filter &_filter);
        Iterator(const Iterator &it);
        Iterator &operator=(const Iterator &it);
        ~Iterator();

        void setFilter(const Filter &_filter);
        const Filter *getFilter() const;
        File &operator*();
        Iterator &operator++();
        bool operator!=(const Iterator &_it) const;
    };

    Iterator begin();
    Iterator begin(const Filter &filter);
    Iterator begin(const Iterator &it);
    Iterator end();

    friend class Iterator;
};

#endif /* FILE_LIST_H */
