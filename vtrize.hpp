#ifndef VTRIZE_HPP
#define VTRIZE_HPP

#include <opencv2/core/core.hpp>

class Vtrize {
  public:
    explicit Vtrize() {
    };
    virtual ~Vtrize() {};
    cv::Mat process( std::function<cv::Mat(cv::Mat)> const& f, cv::Mat im ) {
      return f(im);
    };
    cv::Mat process(cv::Mat im) {
      auto f = [](cv::Mat x){ return x; };
      return process(f,im);
    }    
};

#endif
