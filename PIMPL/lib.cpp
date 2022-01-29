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

  class interface_impl2 : public virtual interface_impl1, public virtual test::interface_v2{
  public:
    interface_impl2();
    ~interface_impl2();
    using test::interface_v1::id;
    using test::interface_v1::name;
    void setId(size_t new_id);
    void setName(const std::string &new_name);
  };
}

size_t interface_impl1::id() const{
  return _id;
};

const std::string &interface_impl1::name() const{
  return _name;
}

void interface_impl2::setId(size_t new_id){
  _id = new_id;
}

void interface_impl2::setName(const std::string &new_name){
  _name = new_name;
}

namespace test{
   interface_v1 *create_interface(interface_impl_type type){
    switch (type){
    case impl1:
      return new interface_impl1;
      break;
    case impl2:
      return new interface_impl2;   //(?) -> expand
      break; 
    default:
      return NULL;
    }
  }
}