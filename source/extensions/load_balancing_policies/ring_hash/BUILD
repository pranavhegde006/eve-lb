load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_extension",
    "envoy_extension_package",
)

licenses(["notice"])  # Apache 2

envoy_extension_package()

envoy_cc_extension(
    name = "config",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    deps = [
        "//source/common/common:minimal_logger_lib",
        "//source/common/upstream:load_balancer_factory_base_lib",
        "//source/common/upstream:load_balancer_lib",
        "//source/common/upstream:ring_hash_lb_lib",
        "@envoy_api//envoy/extensions/load_balancing_policies/ring_hash/v3:pkg_cc_proto",
    ],
)
