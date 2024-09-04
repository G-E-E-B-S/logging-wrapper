Pod::Spec.new do |spec|
  spec.name         = "log_wrapper"
  spec.version      = "0.0.1"
  spec.summary      = "Logging utility for cross platform games."
  spec.description  = <<-DESC
  This module includes following logging facilities:
  * Crash logging
  * Generic logging
  * Analytics
                      DESC
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.ios.deployment_target = "12.0"
  spec.source       = { :git => "https://github.com/G-E-E-B-S/logging-wrapper", :tag => "#{spec.version}" }
  spec.source_files  = ["src/*.cpp"]
  spec.static_framework = true
  spec.pod_target_xcconfig = { 
    "USER_HEADER_SEARCH_PATHS" => "${PODS_TARGET_SRCROOT}/includes"
  }
end
