#include <iostream>
#include "dan/env.hpp"
#include "dan/logger.hpp"

using namespace std;

namespace dan {
  string env_required(const char* name) {
    string sname(name);

    if (const char* env_p = std::getenv(name)) {
      LOG_INFO "" << sname << "=" << env_p << endl;     
      return std::string(env_p);
    } else {
      cerr << "[ERROR] No such '" << name << "' environment variable found!" << endl;
      exit(EXIT_FAILURE);
    }
    
  }
}

