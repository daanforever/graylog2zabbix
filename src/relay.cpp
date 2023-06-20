#include "restinio/all.hpp"
#include "dan/env.hpp"
#include "dan/logger.hpp"

using namespace std;

int main() {
  
  string zabbix_command = dan::env_required("ZABBIX_COMMAND");
  string zabbix_server  = dan::env_required("ZABBIX_SERVER");
  string zabbix_host    = dan::env_required("ZABBIX_HOST");
  string zabbix_key     = dan::env_required("ZABBIX_KEY");
  string zabbix_value   = dan::env_required("ZABBIX_VALUE");


  restinio::run(
      restinio::on_this_thread()
      .port(8080)
      .address("localhost")
      .request_handler([](auto req) {
          return req->create_response().set_body("Hello, World!").done();
      }));

  return 0;

}
