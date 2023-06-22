#include <sstream>
#include <stdlib.h>
#include "restinio/all.hpp"
#include "dan/env.hpp"
#include "dan/logger.hpp"

using namespace std;

namespace dan {
};

int main() {
  
  string port           = dan::env_required("PORT");
  string zabbix_command = dan::env_required("ZABBIX_COMMAND");
  string zabbix_server  = dan::env_required("ZABBIX_SERVER");
  string zabbix_host    = dan::env_required("ZABBIX_HOST");
  string zabbix_key     = dan::env_required("ZABBIX_KEY");
  string zabbix_value   = dan::env_required("ZABBIX_VALUE");

  auto sender = [&]() {
    stringstream commandline = {};

    LOG_INFO << "zabbix_sender will be called";   
    // zabbix_sender -z 127.0.0.1 -s "Linux DB3" -k db.connections -o 43

    commandline << "  " << zabbix_command 
                << " -z " << zabbix_server
                << " -s \"" << zabbix_host << "\""
                << " -k " << zabbix_key
                << " -o " << zabbix_value;

    LOG_DEBUG << commandline.str();

    const char* cmd = commandline.str().c_str();

    int result = system(cmd);
    LOG_DEBUG << "Return code: " << result;
  };

  restinio::run(
      restinio::on_this_thread()
      .port(stoi(port))
      .address("0.0.0.0")
      .request_handler([&](auto req) {
          sender();
          return req->create_response().set_body("done\n").done();
      }));

  return 0;

}
