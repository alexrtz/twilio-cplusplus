project(twilio-c++)
cmake_minimum_required(VERSION 2.8)

include_directories(.)
add_library(twilio-cplusplus STATIC Rest.cpp TwiML.cpp Utils.cpp)
