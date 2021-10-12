#include <iostream>
#include <filesystem> // это нам понадобится чтобы создать папку для результатов
#include <libutils/rasserts.h>
#include <time.h>
#include <stdlib.h>

#include "helper_functions.h"

#include <opencv2/highgui.hpp> // подключили часть библиотеки OpenCV, теперь мы можем читать и сохранять картинки

void task1() {
    cv::Mat imgUnicorn = cv::imread("lesson03/data/unicorn.png");  // загружаем картинку с единорогом
    rassert(!imgUnicorn.empty(), 3428374817241); // проверяем что картинка загрузилась (что она не пустая)

    int width = 0;
    int height = 0;
    width = imgUnicorn.cols;
    height = imgUnicorn.rows;
    std::cout << "Unicorn image loaded: " << width << "x" << height << std::endl;

    // создаем папку в которую будем сохранять результаты - lesson03/resultsData/
    std::string resultsDir = "lesson03/resultsData/";
    if (!std::filesystem::exists(resultsDir)) { // если папка еще не создана
        std::filesystem::create_directory(resultsDir); // то создаем ее
    }

    cv::Mat blueUnicorn = makeAllBlackPixelsBlue(imgUnicorn.clone());
    std::string filename = resultsDir + "01_blue_unicorn.jpg";
    cv::imwrite(filename, blueUnicorn);

    cv::Mat invertedUnicorn = invertImageColors(imgUnicorn.clone());
    std::string filename2 = resultsDir + "02_inv_unicorn.jpg";
    cv::imwrite(filename2, invertedUnicorn);

    cv::Mat castle = cv::imread("lesson03/data/castle.png");

    cv::Mat unicornInCastle = addBackgroundInsteadOfBlackPixels(imgUnicorn.clone(), castle);
    std::string filename3 = resultsDir + "03_unicorn_castle.jpg";
    cv::imwrite(filename3, unicornInCastle);

    cv::Mat largeCastle = cv::imread("lesson03/data/lol.jpg");
    cv::Mat unicornInLargeCastle = addBackgroundInsteadOfBlackPixelsLargeBackground(imgUnicorn.clone(), largeCastle.clone());
    std::string filename4 = resultsDir + "04_unicorn_large_castle.jpg";
    cv::imwrite(filename4, unicornInLargeCastle);


    int n = rand() % 100;
    cv::Mat manyUnicornInLargeCastle = addManyObjectOnLargeBackground(imgUnicorn.clone(), largeCastle.clone(), n);
    std::string filename5 = resultsDir + "05_unicorns_otake.jpg";
    cv::imwrite(filename5, manyUnicornInLargeCastle);

    cv::Mat largeUnicornInLargeCastle = addBigObjectOnLargeBackground(imgUnicorn.clone(), largeCastle.clone());
    std::string filename6 = resultsDir + "06_unicorn_upscale.jpg";
    cv::imwrite(filename6, largeUnicornInLargeCastle);

}

[[noreturn]] void task2() {
    cv::Mat imgUnicorn = cv::imread("lesson03/data/unicorn.png");
    rassert(!imgUnicorn.empty(), 3428374817241);

    // cv::waitKey - функция некоторое время ждет не будет ли нажата кнопка клавиатуры, если да - то возвращает ее код
    int updateDelay = 10; // указываем сколько времени ждать нажатия кнопки клавиатуры - в миллисекундах
    while (cv::waitKey(updateDelay) != 32) {
        // поэтому если мы выполняемся до тех пор пока эта функция не вернет код 32 (а это код кнопки "пробел"), то достаточно будет нажать на пробел чтобы закончить работу программы

        // кроме сохранения картинок на диск (что часто гораздо удобнее конечно, т.к. между ними легко переключаться)
        // иногда удобно рисовать картинку в окне:;
        cv::imshow("lesson03 window", makeAllBlackPixelsRandom(imgUnicorn.clone()));

    }
}

struct MyVideoContent {
    cv::Mat frame;
    int lastClickX;
    int lastClickY;


};

void onMouseClick(int event, int x, int y, int flags, void *pointerToMyVideoContent) {
    MyVideoContent &content = *((MyVideoContent*) pointerToMyVideoContent);
    // не обращайте внимание на предыдущую строку, главное что важно заметить:
    // content.frame - доступ к тому кадру что был только что отображен на экране
    // content.lastClickX - переменная которая вам тоже наверняка пригодится
    // вы можете добавить своих переменных в структурку выше (считайте что это описание объекта из ООП, т.к. почти полноценный класс)

    if (event == cv::EVENT_LBUTTONDOWN) { // если нажата левая кнопка мыши
        std::cout << "Left click at x=" << x << ", y=" << y << std::endl;
    }
}

void task3() {
    // давайте теперь вместо картинок подключим видеопоток с веб камеры:
    cv::VideoCapture video(0);


    rassert(video.isOpened(), 3423948392481); // проверяем что видео получилось открыть

    MyVideoContent content; // здесь мы будем хранить всякие полезности - например последний видео кадр, координаты последнего клика и т.п.
    // content.frame - доступ к тому кадру что был только что отображен на экране
    // content.lastClickX - переменная которая вам тоже наверняка пригодится
    // вы можете добавить своих переменных в структурку выше (считайте что это описание объекта из ООП, т.к. почти полноценный класс)
    // просто перейдите к ее объявлению - удерживая Ctrl сделайте клик левой кнопкой мыши по MyVideoContent - и вас телепортирует к ее определению
    std::vector<int> clickX;
    clickX.clear();
    std::vector<int> clickY;
    clickY.clear();

    int j, k;
    while (video.isOpened()) { // пока видео не закрылось - бежим по нему
        bool isSuccess = video.read(content.frame); // считываем из видео очередной кадр
        rassert(isSuccess, 348792347819); // проверяем что считывание прошло успешно
        rassert(!content.frame.empty(), 3452314124643); // проверяем что кадр не пустой
        int n = clickX.size();

        rassert(!content.frame.empty(), 3333);
        if(!clickX.empty()){
            for(int i = 0; i < n; i++){
                j = clickX[i];
                k = clickY[i];
                content.frame.at<cv::Vec3b>(k, j) = cv::Vec3b(0, 0, 255);
            }
        }
        cv::imshow("video", content.frame); // покаызваем очередной кадр в окошке
        cv::setMouseCallback("video", onMouseClick, &content); // делаем так чтобы функция выше (onMouseClick) получала оповещение при каждом клике мышкой
        clickX.push_back(content.lastClickX);
        clickX.push_back(content.lastClickY);
        rassert(!clickX.empty(), 4444);
        for(int i = 0; i < n; i++){
            std::cout << clickX[i] << std::endl;
        }
        int key = cv::waitKey(10);
        if(cv::waitKey(key) == 32) return;
        if(cv::waitKey(key) == 27) return;


        clickX.push_back(content.lastClickX);
        clickX.push_back(content.lastClickY);

        // TODO и перед отрисовкой очередного кадра - заполняйте все уже прокликанные пиксели красным цветом

        // TODO сделайте по правому клику мышки переключение в режим "цвета каждого кадра инвертированы" (можете просто воспользоваться функцией invertImageColors)
    }
}

void task4() {
    // TODO на базе кода из task3 (скопируйте просто его сюда) сделайте следующее:
    // при клике мышки - определяется цвет пикселя в который пользователь кликнул, теперь этот цвет считается прозрачным (как было с черным цветом у единорога)
    // и теперь перед отрисовкой очередного кадра надо подложить вместо прозрачных пикселей - пиксель из отмасштабированной картинки замка (castle_large.jpg)

    // TODO попробуйте сделать так чтобы цвет не обязательно совпадал абсолютно для прозрачности (чтобы все пиксели похожие на тот что был кликнут - стали прозрачными, а не только идеально совпадающие)

    // TODO подумайте, а как бы отмаскировать фон целиком несмотря на то что он разноцветный?
    // а как бы вы справились с тем чтобы из фотографии с единорогом и фоном удалить фон зная как выглядит фон?
    // а может сделать тот же трюк с вебкой - выйти из вебки в момент запуска программы, и первый кадр использовать как кадр-эталон с фоном который надо удалять (делать прозрачным)
}

int main() {
    try {
//       task1();
//        task2();
        task3();
//        task4();
        return 0;
    } catch (const std::exception &e) {
        std::cout << "Exception! " << e.what() << std::endl;
        return 1;
    }
}
