The directory being used to test envoy custom filter:

`source/common/tcp_proxy`

BUILD command:

`bazel build //source/exe:envoy-static`

RUN locally built envoy:

`bazel-bin/source/exe/envoy-static -c envoy.yaml`

Envoy binary location:

`bazel-bin/source/exe/envoy-static`

Envoy YAML config file: 

`envoy.yaml`

Python flask servers: 

`source/extensions/filters/network/eve_lb` - Run s1, s2 and s3

