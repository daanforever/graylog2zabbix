#include "restinio/all.hpp"
#include "dan/env.hpp"
#include "dan/logger.hpp"

int main() {

  LOG_INFO << dan::env_required("SERVER") << std::endl;

  restinio::run(
      restinio::on_this_thread()
      .port(8080)
      .address("localhost")
      .request_handler([](auto req) {
          return req->create_response().set_body("Hello, World!").done();
      }));

  return 0;

}
