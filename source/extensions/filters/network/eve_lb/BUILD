load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_extension",
    "envoy_cc_library",
    "envoy_extension_package",
)

licenses(["notice"])  # Apache 2

# EVE LoadBalancer filter

envoy_extension_package()

envoy_cc_library(
    name = "eve_lb",
    srcs = ["eve_lb.cc"],
    hdrs = ["eve_lb.h"],
    deps = [
        "//envoy/network:connection_interface",
        "//envoy/network:filter_interface",
        "//source/common/buffer:buffer_lib",
        "//source/common/common:assert_lib",
        "//source/common/common:minimal_logger_lib",
        "//source/common/tcp_proxy",
    ],
)

envoy_cc_extension(
    name = "config",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    deps = [
        ":eve_lb",
        "//envoy/registry",
        "//envoy/server:filter_config_interface",
        "//source/extensions/filters/network:well_known_names",
        "@envoy_api//envoy/extensions/filters/network/eve_lb/v3:pkg_cc_proto",
    ],
)
