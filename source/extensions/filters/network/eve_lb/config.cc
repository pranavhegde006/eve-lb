#include "source/extensions/filters/network/eve_lb/config.h"

#include "envoy/extensions/filters/network/eve_lb/v3/eve_lb.pb.h"
#include "envoy/extensions/filters/network/eve_lb/v3/eve_lb.pb.validate.h"
#include "envoy/registry/registry.h"
#include "envoy/server/filter_config.h"

#include "source/extensions/filters/network/eve_lb/eve_lb.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace EVE_LB {

Network::FilterFactoryCb EVE_LBNetworkFilterConfigFactory::createFilterFactoryFromProto(
    const Protobuf::Message&, Server::Configuration::FactoryContext&) {
  return [](Network::FilterManager& filter_manager) -> void {
    filter_manager.addReadFilter(std::make_shared<SniClusterFilter>());
  };
}

ProtobufTypes::MessagePtr EVE_LBNetworkFilterConfigFactory::createEmptyConfigProto() {
  return std::make_unique<envoy::extensions::filters::network::eve_lb::v3::eve_lb>();
}

/**
 * Static registration for the sni_cluster filter. @see RegisterFactory.
 */
REGISTER_FACTORY(EVE_LBNetworkFilterConfigFactory,
                 Server::Configuration::NamedNetworkFilterConfigFactory);

} // namespace EVE_LB
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
