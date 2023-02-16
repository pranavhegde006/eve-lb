#pragma once

#include "envoy/network/filter.h"

#include "source/common/common/logger.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace EVE_LB {

/**
 * Implementation of the sni_cluster filter that sets the upstream cluster name from
 * the SNI field in the TLS connection.
 */
class EVE_LB_Filter : public Network::ReadFilter, Logger::Loggable<Logger::Id::filter> {
public:
  EVE_LB_Filter(const std::string& response) : response_(response) {}
  // Network::FilterStatus onData(Buffer::Instance& data, bool end_stream) override;
  Network::FilterStatus onRead(Buffer::Instance& data, bool end_stream) override;
  void initializeReadFilterCallbacks(Network::ReadFilterCallbacks& callbacks) override {
    read_callbacks_ = &callbacks;
  }

private:
  Network::ReadFilterCallbacks* read_callbacks_{};
};

} // namespace EVE_LB
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
