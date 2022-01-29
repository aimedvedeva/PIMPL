#include "lib.h"
#include <memory>

using namespace std;
using namespace test;

namespace test{
  typedef interface_v1* ptr;
  typedef std::unique_ptr<ptr> uptr;
}


int main(){
  interface_v1 *ptr1 = dynamic_cast<interface_v1*>(create_interface(impl1));
  interface_v2 *ptr2 = dynamic_cast<interface_v2*>(create_interface(impl2));

  if (ptr2 != NULL){
    ptr2->setId(1);
  }

  return 0;
}