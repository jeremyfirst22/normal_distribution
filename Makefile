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
clobber: clean
	rm -f $(NAME)
clean:
	rm -f $(OBJS)
echo:
	@echo $(OBJS)
test: 
	cd test ; ../tiltAngle --file random_data.txt --out out.dat --gauss gauss.dat --poly-fit poly.dat -n 100 --overwrite ; python plot_file.py out.dat gauss.dat ; python plot_file.py out.dat poly.dat ; open *.pdf ; cd ../ 
