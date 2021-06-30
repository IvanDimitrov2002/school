CC = g++

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: ${OBJS}
	${CC} -o shop ${OBJS}

%.o: %.cpp
	${CC} -c $<

clean:
	rm -rf *.o shop