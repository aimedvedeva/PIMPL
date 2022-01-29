#include <string>

namespace test{
  class interface_v1{
  public:
    virtual ~interface_v1(){}
    virtual size_t id() const = 0;
    virtual const std::string &name() const = 0;
  };

  class interface_v2 : public virtual interface_v1{  //(?) -> expand
  public:
    using interface_v1::id;
    using interface_v1::name;

    virtual void setId(size_t new_id) = 0;
    virtual void setName(const std::string &new_name) = 0;
  };

  typedef enum{
    impl1,
    impl2
  }interface_impl_type;   //(?) -> expand

  interface_v1 *create_interface(interface_impl_type type);
}