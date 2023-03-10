#include "response_headers.h"

namespace Envoy {
namespace Platform {

int ResponseHeaders::httpStatus() const {
  if (!contains(":status")) {
    throw std::logic_error("ResponseHeaders does not contain :status");
  }
  return stoi((*this)[":status"][0]);
}

ResponseHeadersBuilder ResponseHeaders::toResponseHeadersBuilder() {
  ResponseHeadersBuilder builder;
  if (contains(":status")) {
    builder.addHttpStatus(httpStatus());
  }
  for (const auto& pair : allHeaders()) {
    builder.set(pair.first, pair.second);
  }
  return builder;
}

} // namespace Platform
} // namespace Envoy
