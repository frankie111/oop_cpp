cmake_minimum_required(VERSION 3.25)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 FruitApp.cpp UI/FruitUI.cpp UI/FruitUI.h Controller/FruitController.cpp Controller/FruitController.h Domain/Fruit.cpp Domain/Fruit.h Repository/FruitRepo.cpp Repository/FruitRepo.h)
