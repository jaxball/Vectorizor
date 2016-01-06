#include "singleton_factory.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <algorithm>

using namespace cv;

// authored by Jason Lin on Nov 22nd. Continuation of data visualization project from Make Hacks
class HoughLineProcessor : public Processor {
  public:
    Mat operator()(Mat);
  private:
    static void createOutput(Mat&, Mat&);
};

Mat HoughLineProcessor::operator()(Mat im) {
 
  Mat im_gray;
  // Remove noise by blurring with Gaussian
  cv::GaussianBlur(im, im, cv::Size(3,3), 0,0, BORDER_DEFAULT);

  cv::cvtColor( im, im_gray, CV_BGR2GRAY );
  
  // Canny edge detector
  int lowThreshold = 50;
  int ratio = 4;
  int kernel_size = 3;
  Mat detected_edges;
  cv::Canny( grey, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

  // Hough line transform
  std::vector<Vec2f> lines;
  int houghRho = 1; // pixel
  double houghTheta = CV_PI/180; //radians
  int houghThreshold = 100;
  int srn = 0;
  int stn = 0;
  HoughLines( detected_edges, lines, houghRho, houghTheta, houghThreshold, srn, stn);

  // Display intermediate images for debugging
  Mat dest;
  cvtColor( detected_edges, dest, CV_GRAY2BGR);

  // Draw detected lines
  for( auto line : lines ) {
    float rho = line[0], theta = line[1];
    Point pt1, pt2;
    double a = cos(theta), b = sin(theta);
    double x0 = a*rho, y0 = b*rho;
    pt1.x = cvRound(x0 + 1000*(-b));
    pt1.y = cvRound(y0 + 1000*(a));
    pt2.x = cvRound(x0 - 1000*(-b));
    pt2.y = cvRound(y0 - 1000*(a));
    line(dest, pt1, pt2, Scalar(0,255,0), 2, CV_AA);
  }

  cvtColor( dest, dest, CV_BGR2RGBA );
  return dest; 

}

void HoughLineProcessor::createOutput( Mat& src, Mat& dest )
{
  // Show intermediate images - need to expand CV_8UC1 to RGBA
  Mat fullAlpha = Mat( src.size(), CV_8UC1, Scalar(255));
  std::vector<Mat> rgba_out;
  rgba_out.push_back( src );
  rgba_out.push_back( src );
  rgba_out.push_back( src );
  rgba_out.push_back( fullAlpha );

  merge(rgba_out, dest);
}

namespace {
  auto scProcReg = ProcessorRegister<HoughLineProcessor>("Hough Line Transform");
}

