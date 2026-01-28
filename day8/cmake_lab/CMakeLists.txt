# 1. Ã¼Ò¿䱸 ¹ö¹×Ç·Î§Ʈ À¸§
cmake_minimum_required(VERSION 3.10)
project(MyProject C)

# 2. µð×¸ð¿ɼÇ¼³d (±⺻°ª: ON)
option(DEBUG_MODE "Enable debug mode with -g and -DDEBUG_MODE" ON)

# 3. ÄÆÀ·¯ ¿ɼÇ¼³d
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

if(DEBUG_MODE)
    # µð×¸ðÏ¶§: -g Ã°¡ ¹×DEBUG_MODE ¸Å©·ÎdÀ
    set(CMAKE_BUILD_TYPE Debug)
    add_definitions(-DDEBUG_MODE)
    message(STATUS ">> Build Mode: Debug (DEBUG_MODE is defined)")
else()
    # ¸±¸®Á ¸ðÏ¶§: ÃÀȭ À¿ë   s
    set(CMAKE_BUILD_TYPE Release)
    message(STATUS ">> Build Mode: Release (Optimized)")
endif()

# 4. ¼ҽº ÆÀ Àµ¿ Ž»ö00°³°¡ µǾ OK!)
file(GLOB SOURCES "*.c")

# 5. ½ÇàÄÏ»ýd
add_executable(my_program ${SOURCES})

