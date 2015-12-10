NAME:=tiltAngle
SRC:=$(wildcard *.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(SRC))

BOOST_INC:=/usr/local/include/boost
BOOST_LIB:=/usr/local/lib

GSL_INC:=/usr/local/include/gsl
GSL_LIB:=/usr/local/lib

LDLIBS:=-lboost_program_options -lgsl -lgslcblas
LDFLAGS:=-L$(BOOST_LIB) -L$(GSL_LIB)
INCLUDE:=-I$(BOOST_INC) -I$(GSL_INC)

CC:=g++

CPPFLAGS:=$(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $<

.PHONY: clean clobber echo test
test: 
	cd test && $(MAKE) test1
	./test
	cd ../
clobber: clean
	rm -f $(NAME)
	rm -f random_data.txt
clean:
	rm -f $(OBJS)
echo:
	@echo $(OBJS)

