#include <fuerte/collection.h>

namespace arangocxx {

  using namespace arangocxx::detail;

  Collection::Collection(std::shared_ptr<Database> db, std::string name)
    : _db(db)
    , _name(name)
    {}

}

