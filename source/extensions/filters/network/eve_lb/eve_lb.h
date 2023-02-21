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
class EVE_LBFilter : public Network::ReadFilter, Logger::Loggable<Logger::Id::filter> {
public:
  // Network::ReadFilter
  Network::FilterStatus onData(Buffer::Instance&, bool) override;

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
