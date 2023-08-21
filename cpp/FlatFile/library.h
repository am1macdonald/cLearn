#ifndef FLATFILE_LIBRARY_H
#define FLATFILE_LIBRARY_H

// class for a flat file database
namespace DatabaseLibrary
{
    class Database {
    public:
        static int add(std::string name, std::string value);

        static std::string getById(int name);

    };
}

#endif //FLATFILE_LIBRARY_H
