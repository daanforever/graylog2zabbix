#include <dan/logger.hpp>
#include <boost/log/core/core.hpp>
#include <boost/log/sinks/sink.hpp>

namespace dan {

  void coloring_formatter(logging::record_view const& rec, logging::formatting_ostream& strm) {
      auto severity = rec[logging::trivial::severity];

      auto date_time_formatter = expr::stream << 
          expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S.%f ");
          // std::setfill('0') << std::setw(3) << expr::format_date_time< boost::posix_time::ptime >("%f");
      date_time_formatter(rec, strm);

      static const std::string replace[] = {
        "T",
        "D",
        "I",
        "W",
        "E",
        "F"
      };

      if (severity)
      {
          // Set the color
          switch (severity.get())
          {
          // case trivial::severity_level::info:
              // strm << "\033[32m";
              // break;
          case trivial::severity_level::warning:
              strm << "\033[33m";
              break;
          case trivial::severity_level::error:
          case trivial::severity_level::fatal:
              strm << "\033[31m";
              break;
          default:
              break;
          }

          // strm << severity.extract<std::string>() << " ";
          // strm << replace[severity.get()] << " ";
          // char sym = trivial::to_string(severity.get())[0];
          strm << "[" << replace[severity.get()] << "] ";
      }


      // Format the message here...
      strm << rec[logging::expressions::smessage];
  
      if (severity)
      {
          // Restore the default color
          strm << "\033[0m";
      }
      
      strm << "\n";
  }


  src::severity_logger_mt< trivial::severity_level >& logger(trivial::severity_level level) {

    boost::log::core::get()->remove_all_sinks();

    logging::add_console_log(std::cout,
      keywords::filter = expr::attr< trivial::severity_level >("Severity") >= level
    )->set_formatter(&coloring_formatter);

    logging::add_common_attributes();
    src::severity_logger_mt< trivial::severity_level >& log = mylogger::get();
    return log;
  }
}
