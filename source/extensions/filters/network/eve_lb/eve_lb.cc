#include "source/extensions/filters/network/eve_lb/eve_lb1.h"

#include "envoy/network/connection.h"
#include "source/common/buffer/buffer_impl.h"
#include "source/common/common/assert.h"
#include "source/common/tcp_proxy/tcp_proxy.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace EVE_LB {

class EVE_LB_Filter : public Network::ReadFilter, Logger::Loggable<Logger::Id::filter> {
public:
  EVE_LB_Filter(const std::string& response) : response_(response) {}
  // Network::FilterStatus onData(Buffer::Instance& data, bool end_stream) override;
  void onFilterStart(Upstream::FilterCallbacks& callbacks) override {
    // Save a reference to the filter's callbacks object for later use.
    ENVOY_LOG(info, "ITS reaching callback");
    callbacks_ = &callbacks;
  }
  Network::FilterStatus onRead(Buffer::Instance& data, bool end_stream) override {
    ENVOY_LOG(info, "its reaching eve_lb");
    StreamInfo::FilterState& filter_state = decoder_callbacks_->streamInfo().filterState();
    std::string new_cluster_name = "inspect";
    filter_state.setData("eve_lb.inspect", std::make_unique<Envoy::StreamInfo::StringAccessorImpl>(new_cluster_name), StreamInfo::FilterState::StateType::Mutable);

    // Route the request to the new cluster
    router::RouteConstSharedPtr new_route = decoder_callbacks_->route()->routeEntry()->cluster().clusterName(new_cluster_name);
    decoder_callbacks_->streamInfo().setRouteEntry(new_route);

    // Continue processing the request
    return Network::FilterStatus::Continue;
    }

    // Create a new destination address.
    // auto new_address = std::make_unique<Address::Ipv4Instance>("localhost", 9003);

    // // Update the destination address of the connection.
    // socket.setRemoteAddress(std::move(new_address));
    
    // // Continue the filter chain.
    // return Network::FilterStatus::StopIteration;
  }
  void initializeReadFilterCallbacks(Network::ReadFilterCallbacks& callbacks) override {
    read_callbacks_ = &callbacks;
  }

private:
  private:

  Upstream::FilterCallbacks* callbacks_{};
};


} // namespace eve_lb
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
