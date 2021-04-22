#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>


int main()
{
	std::cout<<"Program Begins ..."<<std::endl;
	cv::VideoCapture cap;
	
	const std::string savePath = "../video/"
	std::string file = "../video/1.mp4";
	
	cv::Mat frame;
	
	if( !cap.open( file ) ){
		std::cout<<"Open Video File Failed ..."<<std::endl;
		exit( -1 );
	}

	long totalFrameNums = cap.get( cv::CAP_PROP_FRAME_COUNT );
	std::cout<<"total Frame Number: "<<totalFrameNums<<std::endl;
	
	int step = 10;
	
	long j = 0;
	while(1){
		cap >> frame;
		if( frame.empty() ) break;
		if( ++j % step == 0 ){
			cv::imwrite( savePath + std::to_string( j / step ) + ".jpg", frame );
		}
	}

	cap.release();
	return 0;
}
