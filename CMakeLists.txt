cmake_minimum_required(VERSION 3.4)		# never set less 3.4 min version
project(SignalGenerator)

include_directories(include)


add_executable(Signal 
				src/signal_main_test.cpp 
				src/Signal.cpp 
				src/Sinus.cpp 
				src/Rectangle.cpp 
				src/Noise.cpp 
				src/Arbitrary.cpp
				src/Triangle.cpp)




