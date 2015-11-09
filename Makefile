NAME:=tiltAngle
SRC:=$(wildcard *.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(SRC))

BOOST_INC:=/usr/local/include/boost
BOOST_LIB:=/usr/local/lib

LDFLAGS:=-lboost_program_options
INCLUDE:=-I$(BOOST_INC)

CC:=g++

CPPFLAGS:=$(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $<

.PHONY: clean clobber echo
clobber: clean
	rm -f $(NAME)
clean:
	rm -f $(OBJS)
echo:
	@echo $(OBJS)

