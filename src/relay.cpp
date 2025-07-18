#include <sstream>
#include <stdlib.h>
#include "restinio/all.hpp"
#include "dan/env.hpp"
#include "dan/logger.hpp"

using namespace std;

namespace dan {
};

int main() {
  
  string port           = dan::getenv("PORT");
  string zabbix_command = dan::getenv("ZABBIX_COMMAND");
  string zabbix_server  = dan::getenv("ZABBIX_SERVER");
  string zabbix_port    = dan::getenv("ZABBIX_PORT");
  string zabbix_host    = dan::getenv("ZABBIX_HOST");
  string zabbix_key     = dan::getenv("ZABBIX_KEY");
  string zabbix_value   = dan::getenv("ZABBIX_VALUE");
  string extra_args     = dan::getenv("EXTRA_ARGS", false);

  auto sender = [&]() {
    stringstream commandline = {};

    LOG_INFO << "zabbix_sender will be called";   
    // zabbix_sender -z 127.0.0.1 -s "Linux DB3" -k db.connections -o 43

    commandline << "  " << zabbix_command 
                << " -z " << zabbix_server
                << " -p " << zabbix_port
                << " -s \"" << zabbix_host << "\""
                << " -k " << zabbix_key
                << " -o " << zabbix_value
                << " " << extra_args;

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
