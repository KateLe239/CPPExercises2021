#pragma once

#include <opencv2/highgui.hpp> // подключили часть библиотеки OpenCV, теперь мы можем работать с картинками (знаем про тип cv::Mat)

cv::Mat makeAllBlackPixelsBlue(cv::Mat image);

cv::Mat invertImageColors(cv::Mat image);

cv::Mat addBackgroundInsteadOfBlackPixels(cv::Mat object, cv::Mat background);

cv::Mat addBackgroundInsteadOfBlackPixelsLargeBackground(cv::Mat object, cv::Mat largeBackground);

cv::Mat addManyObjectOnLargeBackground(cv::Mat object, cv::Mat largeBackground, int n);

cv::Mat addBigObjectOnLargeBackground(cv::Mat object, cv::Mat largeBackground);

cv::Mat makeAllBlackPixelsRandom(cv::Mat image);