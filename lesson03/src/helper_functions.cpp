#include "helper_functions.h"

#include <libutils/rasserts.h>
#include <iostream>


cv::Mat makeAllBlackPixelsBlue(cv::Mat image) {


    int width = 0;
    int height = 0;
    width = image.cols;
    height = image.rows;
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    for (int i = 0; i < width; ++i) {
        for(int j = 0; j < height; j++){
            cv::Vec3b color = image.at<cv::Vec3b>(j, i);
            blue = color[0]; // если это число равно 255 - в пикселе много синего, если равно 0 - в пикселе нет синего
            green = color[1];
            red = color[2];
            if(blue < 5 && green < 5 && red < 5){
                image.at<cv::Vec3b>(j, i) = cv::Vec3b(255, 0, 0);
            }
        }
    }


    // как получить белый цвет? как получить черный цвет? как получить желтый цвет?
    // поэкспериментируйте! например можете всю картинку заполнить каким-то одним цветом

    // пример как заменить цвет по тем же координатам
    red = 255;
    // запустите эту версию функции и посмотрите на получившуюся картинку - lesson03/resultsData/01_blue_unicorn.jpg
    // какой пиксель изменился? почему он не чисто красный?
    image.at<cv::Vec3b>(13, 5) = cv::Vec3b(blue, green, red);

    return image;
}

cv::Mat invertImageColors(cv::Mat image) {
    // TODO реализуйте функцию которая каждый цвет картинки инвертирует:
    int width = 0;
    int height = 0;
    width = image.cols;
    height = image.rows;
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    for (int i = 0; i < width; ++i) {
        for(int j = 0; j < height; j++){
            cv::Vec3b color = image.at<cv::Vec3b>(j, i);
            blue = color[0]; // если это число равно 255 - в пикселе много синего, если равно 0 - в пикселе нет синего
            green = color[1];
            red = color[2];
            image.at<cv::Vec3b>(j, i) = cv::Vec3b(255 - blue, 255 - green, 255 - red);

        }
    }
    return image;
}

cv::Mat addBackgroundInsteadOfBlackPixels(cv::Mat object, cv::Mat background) {
    // TODO реализуйте функцию которая все черные пиксели картинки-объекта заменяет на пиксели с картинки-фона

    rassert(object.cols == background.cols, 341241251251351);
    rassert(object.rows == background.rows, 341241251251352);

    int width = 0;
    int height = 0;
    width = object.cols;
    height = object.rows;
    unsigned char blue1, blue2;
    unsigned char green1, green2;
    unsigned char red1, red2;

    for (int i = 0; i < width; ++i) {
        for(int j = 0; j < height; j++){
            cv::Vec3b color_obj = object.at<cv::Vec3b>(j, i);
            blue1 = color_obj[0];
            green1 = color_obj[1];
            red1 = color_obj[2];
            cv::Vec3b color_back = background.at<cv::Vec3b>(j, i);
            blue2 = color_back[0];
            green2 = color_back[1];
            red2 = color_back[2];
            if(blue1 < 5 && green1 < 5 && red1 < 5){
                object.at<cv::Vec3b>(j, i) = cv::Vec3b(blue2, green2, red2);
            }
        }
    }

    return object;
}

cv::Mat addBackgroundInsteadOfBlackPixelsLargeBackground(cv::Mat object, cv::Mat largeBackground) {
    std::cout << largeBackground.cols;
    rassert(object.cols < largeBackground.cols, 341241251251354);
    rassert(object.rows < largeBackground.rows, 341241251251353);

    int width = 0;
    int height = 0;
    width = object.cols;
    height = object.rows;
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    for (int i = 0; i < width; ++i) {
        for(int j = 0; j < height; j++){
            cv::Vec3b color_obj = object.at<cv::Vec3b>(j, i);
            blue = color_obj[0];
            green = color_obj[1];
            red = color_obj[2];
            if(blue > 10 || green > 10 || red > 10){
                largeBackground.at<cv::Vec3b>(j + largeBackground.rows / 2 - height / 2, i + largeBackground.cols / 2 - width / 2) = cv::Vec3b(blue, green, red);
            }
        }
    }
    return largeBackground;
}


cv::Mat addManyObjectOnLargeBackground(cv::Mat object, cv::Mat largeBackground, int n) {
    rassert(object.cols < largeBackground.cols, 341241251251354);
    rassert(object.rows < largeBackground.rows, 341241251251353);

    int width1 = 0;
    int height1 = 0;
    width1 = object.cols;
    height1 = object.rows;
    int width2 = 0;
    int height2 = 0;
    width2 = largeBackground.cols;
    height2 = largeBackground.rows;
    unsigned char blue;
    unsigned char green;
    unsigned char red;

    for(int o = 0; o < n; o++){
        int w = rand() % (width2 - width1);
        int h = rand() % (height2 - height1);
        for (int i = 0; i < width1; ++i) {
            for(int j = 0; j < height1; j++){
                cv::Vec3b color_obj = object.at<cv::Vec3b>(j, i);
                blue = color_obj[0];
                green = color_obj[1];
                red = color_obj[2];
                if(blue > 10 || green > 10 || red > 10){
                    largeBackground.at<cv::Vec3b>(j + h, i + w) = cv::Vec3b(blue, green, red);
                }
            }
        }
    }

    return largeBackground;
}

cv::Mat addBigObjectOnLargeBackground(cv::Mat object, cv::Mat largeBackground) {
    rassert(object.cols < largeBackground.cols, 341241251251354);
    rassert(object.rows < largeBackground.rows, 341241251251353);

    int width1 = 0;
    int height1 = 0;
    width1 = object.cols;
    height1 = object.rows;
    int width2 = 0;
    int height2 = 0;
    width2 = largeBackground.cols;
    height2 = largeBackground.rows;
    unsigned char blue;
    unsigned char green;
    unsigned char red;


        for (int i = 0; i < width1; ++i) {
            for(int j = 0; j < height1; j++){
                cv::Vec3b color_obj = object.at<cv::Vec3b>(j, i);
                blue = color_obj[0];
                green = color_obj[1];
                red = color_obj[2];
                if(blue > 10 || green > 10 || red > 10){
                    for(int k = 0; k < height2/height1 + 5; k++){
                        for(int l = 0; l < width2/width1 + 5; l++){
                            largeBackground.at<cv::Vec3b>(j*height2/height1 + k, i*width2/width1 + l) = cv::Vec3b(blue, green, red);
                        }
                    }


                }
            }
        }


    return largeBackground;
}


cv::Mat makeAllBlackPixelsRandom(cv::Mat image) {


    int width = 0;
    int height = 0;
    width = image.cols;
    height = image.rows;
    unsigned char blue;
    unsigned char green;
    unsigned char red;

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; j++) {
                cv::Vec3b color = image.at<cv::Vec3b>(j, i);
                blue = color[0];
                green = color[1];
                red = color[2];
                if (blue < 5 && green < 5 && red < 5) {
                    int b = rand() % 255;
                    int g = rand() % 255;
                    int r = rand() % 255;
                    image.at<cv::Vec3b>(j, i) = cv::Vec3b(b, g, r);
                }
            }
        }
        return image;
}