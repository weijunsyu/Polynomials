#DEBUG  = -g
CXX = g++
VERSION = -std=c++11
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG)
LFLAGS = -Wall $(VERSION) $(DEBUG)

INCS = Polys.h \ Term.h
SRCS = Poly.cpp \
	testPoly.cpp \
	Term.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = testPoly

all: $(SRCS) $(EXEC)

# To make an object from source
#.cpp.o:
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $@

# for Windows
clean:
	del *.o  $(EXEC).exe
	@echo clean done

# for UNIX / Linux
remove:
	\rm -f *.o  $(EXEC)
	@echo clean done
