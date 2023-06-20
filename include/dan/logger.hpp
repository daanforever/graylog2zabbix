#ifndef DAN_LOG_H
#define DAN_LOG_H

/* Basic usage: 
  auto log = dan::logger(trivial::trace);
  LOG_INFO << 'Hello world';
*/

#include <boost/format.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <boost/log/support/date_time.hpp>

#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>

#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/severity_logger.hpp>

#include <boost/log/sources/global_logger_storage.hpp>

#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace trivial = boost::log::trivial;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(mylogger, src::severity_logger_mt< trivial::severity_level >)

#define LOG(severity) BOOST_LOG_SEV(mylogger::get(),severity)
#define LOG_TRACE     LOG(trivial::trace)
#define LOG_DEBUG     LOG(trivial::debug)
#define LOG_INFO      LOG(trivial::info)
#define LOG_WARNING   LOG(trivial::warning)
#define LOG_ERROR     LOG(trivial::error)
#define LOG_FATAL     LOG(trivial::fatal)

#ifndef LOG_LEVEL
#define LOG_LEVEL trivial::debug
#endif

namespace dan {
  src::severity_logger_mt< trivial::severity_level >& logger( trivial::severity_level = LOG_LEVEL );
}

#endif //DAN_LOG_H
