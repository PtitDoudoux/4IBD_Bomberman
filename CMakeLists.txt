cmake_minimum_required(VERSION 3.10)
project(4IBD_Bomberman)

set(CMAKE_CXX_STANDARD 11)

add_executable(bomberman main.cpp ai/AI.h game_engine/GameEngine.h game_engine/GameEngine.cpp ai/AI.cpp)