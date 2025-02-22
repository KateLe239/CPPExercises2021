cmake_minimum_required(VERSION 3.1)

add_subdirectory(libs)

project(CPPExercises)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lesson01)
add_subdirectory(lesson02) # двумерный массив для набивания руки перед работой с картинками + привыкание к rassert
add_subdirectory(lesson03) # знакомимся с OpenCV, меняем картинки, подкладываем фон под объект, подключаем вебкамеру, по клику определяем цвет фона и сделав его прозрачным - добавляем произвольный фон
add_subdirectory(lesson04) # морфология + СНМ = пытаемся сделать хорошее удаление фона по первому кадру без объекта
add_subdirectory(lesson05) # преобразуем картинку в картинку границ (оператор Собеля)
add_subdirectory(lesson06) # сглаживание картинки, блюр (свертка ядром Гаусса)

add_subdirectory(lesson07) # обнаружение прямых: построение пространства Хафа
add_subdirectory(lesson08) # обнаружение прямых: интерполяция отрезков голосов в пространстве Хафа + извлечение локальных экстремумов
add_subdirectory(lesson09) # обнаружение прямых: отрисовка найденных прямых

add_subdirectory(lesson10) # распознавание цифр/букв: построение HoG (Histogram Of Gradients) для цифр/букв
add_subdirectory(lesson11) # распознавание цифр/букв: учимся разбивать картинку на цифры/буквы

add_subdirectory(lesson12) # поиск прямой на базе точек
add_subdirectory(lesson13) # сопоставление двух картинок для склейки "панорамы" (SIFT + K-ratio test + Left-Right check + RANSAC)
add_subdirectory(lesson14) # накладывание картинки на другую в видеопотоке с веб. камеры (простой вариант AR)

add_subdirectory(lesson15) # алгоритм поиска кратчайшего пути методом Дейкстры + поиск пути в лабиринте-картинке
add_subdirectory(lesson16) # панорама и визуализация качества наложения (где разница большая, а где - маленькая)
add_subdirectory(lesson17) # выбор линии разреза в панораме методом Дейкстры по метрике похожести

add_subdirectory(lesson18) # ретуширование фотографии, заполнение удаленной пустой зоны
