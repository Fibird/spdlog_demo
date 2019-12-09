#spdlog_demo: spdlog_demo.cpp
#g++ -o spdlog_demo spdlog_demo.cpp -I/root/ruc_test/spdlog/include

cc = g++
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o)
proms = $(src:%.cpp=%)
cflags = -I/root/ruc_test/spdlog/include

all: $(proms)
.phony: all

$(proms): %: %.o
	$(cc) $< -o $@ 

%.o: %.cpp $(deps)
	$(cc) -c $(cflags) $< -o $@ 

.pony: clean
clean:
	rm -rf $(obj) $(proms)
