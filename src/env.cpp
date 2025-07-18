#include <iostream>
#include "dan/env.hpp"
#include "dan/logger.hpp"

using namespace std;

namespace dan {
  string getenv(const char* name, const bool required) {

    const char* env = std::getenv(name);

    if (env) {
      LOG_INFO << name << "=" << env;
    } else {
      if (required == true) {
        cerr << "[ERROR] No such '" << name << "' environment variable found!" << endl;
        exit(EXIT_FAILURE);
      }

      env = "";
    }

    return env;
  }
}

