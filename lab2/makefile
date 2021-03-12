CROSS_COMPILE = aarch64-linux-gnu-
CXX=$(CROSS_COMPILE)g++
CXXFLAGS = -std=c++11
OBJ=main.o
SRC=main.cpp
EXE=main
LIBS= -lm

all:$(EXE)
$(EXE):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $? $(LIBS)

.PHONY:clean
clean:
	rm -rf $(OBJ) $(EXE)
