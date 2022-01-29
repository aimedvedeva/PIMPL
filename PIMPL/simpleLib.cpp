#include "lib.h"

namespace{
  class interface_impl1 : public virtual test::interface_v1{
  public:
    interface_impl1();
    ~interface_impl1();
    size_t id() const;
    const std::string &name() const;

  protected:
    size_t _id;
    std::string _name;
  };
}

size_t interface_impl1::id() const{
  return _id;
};

const std::string &interface_impl1::name() const{
  return _name;
}

namespace test{
 
  interface_v1 *create_interface(interface_impl_type type){
    switch (type){
    case impl1:
      return new interface_impl1;
      break;
    default:
      return NULL;
    }
  }

}