#ifndef DAN_ENV_H
#define DAN_ENV_H

#include <string>

namespace dan {
  std::string getenv(const char* name, const bool required=true);
}

#endif // DAN_ENV_H
