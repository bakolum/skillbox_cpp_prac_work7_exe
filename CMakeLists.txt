cmake_minimum_required(VERSION 3.18)        # требуемая версия cmake
project(    
    Matrix                                 # название проекта                        
    VERSION 0.0.1                           # номер версии проекта
    DESCRIPTION "matrixlib"                 # описание           
    LANGUAGES CXX                           # язык программирования
)   
set(CMAKE_CXX_STANDARD 17)                  # устанавливаем требуемый стандарт языка (это значит, что в проекте буду использоваться фичи этоо стандарта)
set(CMAKE_CXX_STANDARD_REQUIRED ON)         # при сборке платформа будет проверять поддержку стандарта C++17 компилятором


# Путь к директориям с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/src)

# Добавляем исполняемый файл
add_executable(
    test-shared-matrix
    src/test-shared-matrix.cpp
)

# Путь к библиотеке в папке EXE/libs/matrixlib
set(SHARED_MATRIXLIB_DIR "${CMAKE_SOURCE_DIR}/libs/matrixlib")

# Линкуем библиотеку
target_link_libraries(test-shared-matrix PRIVATE ${CMAKE_SOURCE_DIR}/libs/matrixlib/libshared-matrixlib.dll.a)

# Копируем DLL в папку с исполняемым файлом после сборки
add_custom_command(TARGET test-shared-matrix POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SHARED_MATRIXLIB_DIR}/shared-matrixlib.dll"
    $<TARGET_FILE_DIR:test-shared-matrix>
)

# Копируем DLL в папку с исполняемым файлом после сборки
add_custom_command(TARGET test-shared-matrix POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SHARED_MATRIXLIB_DIR}/shared-matrixlib.dll"
    $<TARGET_FILE_DIR:test-shared-matrix>
)

# Копируем файл импорта в папку build
add_custom_command(TARGET test-shared-matrix POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SHARED_MATRIXLIB_DIR}/libshared-matrixlib.dll.a"
    $<TARGET_FILE_DIR:test-shared-matrix>
)