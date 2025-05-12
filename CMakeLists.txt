cmake_minimum_required(VERSION 3.5) #Проверка версии CMake.

set(PROJECT_NAME BLAS) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта


set(application BLASAPP) #Переменная с именем приложения

set(errorlib TErrorLibrary)
set(umllib UMLLibrary)
set(stringlib TStringLibrary)   


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TError)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TMatrix)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TVector)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TString)


add_subdirectory(Main)
add_subdirectory(TError)
add_subdirectory(TVector)
add_subdirectory(TString)