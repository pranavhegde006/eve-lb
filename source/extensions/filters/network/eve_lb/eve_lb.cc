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
  
    Network::FilterStatus onData(Buffer::Instance&, bool) override{
      ENVOY_LOG(info, "pranav connection established");
      return Network::FilterStatus::Continue;
    }
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
