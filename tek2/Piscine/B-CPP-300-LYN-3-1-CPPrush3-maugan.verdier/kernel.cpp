#include <sys/utsname.h>
#include <iostream>
#include "MyGKrellM.hpp"

utsname getKernelInfo()
{
    struct utsname uts;
    uname(&uts);
    return uts;
}

void GKrellm::update_kernel()
{
    this->_osinfo = getKernelInfo();
}
