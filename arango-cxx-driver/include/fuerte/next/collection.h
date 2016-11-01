#pragma once
#ifndef ARANGO_CXX_DRIVER_DATABASE
#define ARANGO_CXX_DRIVER_DATABASE

#include <memory>
#include <string>
#include "common_types.h"

namespace arangocxx {

class Database;

class Collection : public std::enable_shared_from_this<Collection> {
    friend class Database;
    typedef std::string Document; //FIXME

  public:
     // bool insert(Document){ return false; }
     // void drop(Document){}
     // void update(Document, Document){}
     // void replace(Document, Document){}
     // void dropAll(){}
     // void find(Document){}

  private:
    Collection(std::shared_ptr<Database>, std::string name);
    std::shared_ptr<Database> _db;
    std::string _name;

};


}
#endif

