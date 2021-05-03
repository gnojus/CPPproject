#include "file_list.h"

FileList::FileList() {
}

FileList::FileList(const FileList &f) {
    throw CopyNotAllowedException{};
}

FileList &FileList::operator=(const FileList &f) {
    throw CopyNotAllowedException{};
}

void FileList::add(const File &file) {
    files.insert({file.getName(), file});
}

void FileList::remove(const File &file) {
    files.erase(file.getName());
}

File &FileList::operator[](std::string name) {
    // return files[name];
    return files.find(name)->second;
}

FileList &FileList::operator+=(const File &file) {
    add(file);
    return *this;
}

FileList &FileList::operator-=(const File &file) {
    remove(file);
    return *this;
}

FileList::Iterator::Iterator(FileList::std::map<std::string, File>::iterator _it, std::map<std::string, File>::iterator _end)
    : it(_it), end(_end), filter(NULL) {
}

FileList::Iterator::Iterator(std::map<std::string, File>::iterator _it,
                             std::map<std::string, File>::iterator _end,
                             const Filter &_filter)
    : it(_it), end(_end) {
    setFilter(_filter);
    moveToMatch();
}

FileList::Iterator::Iterator(const Iterator &_it) {
    filter = NULL;
    *this = _it;
}

FileList::Iterator &FileList::Iterator::operator=(const Iterator &_it) {
    delete filter;
    it = _it.it;
    return *this;
}

FileList::Iterator::~Iterator() {
    delete filter;
}

void FileList::Iterator::setFilter(const Filter &_filter) {
    if (filter) {
        *filter = _filter;
    } else {
        filter = new Filter(_filter);
    }
    moveToMatch();
}

const Filter *FileList::Iterator::getFilter() const {
    return filter;
}

File &FileList::Iterator::operator*() {
    return it->second;
}

FileList::Iterator &FileList::Iterator::operator++() {
    ++it;
    moveToMatch();
    return *this;
}

bool FileList::Iterator::operator!=(const Iterator &_it) const {
    return it != _it.it;
}

void FileList::Iterator::moveToMatch() {
    while (filter && it != end && !(*filter)(it->first)) {
        ++it;
    }
}

FileList::Iterator FileList::begin() {
    return Iterator(files.begin(), files.end());
}

FileList::Iterator FileList::begin(const Filter &filter) {
    return Iterator(files.begin(), files.end(), filter);
}

FileList::Iterator FileList::begin(const Iterator &it) {
    if (it.getFilter()) {
        return begin(*it.getFilter());
    }
    return begin();
}

FileList::Iterator FileList::end() {
    return Iterator(files.end(), files.end());
}
