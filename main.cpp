#include "Registry.h"
#include <memory>

int main(int argc, char* argv[])
{  
   std::string handler{"Protocol"};
   auto& prot = Registry::instance().get(handler);
   prot->handle("test");

}