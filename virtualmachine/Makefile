CXX=clang
RM=rm -f
CPPFLAGS=-I inc/ -std=c++14
LDFLAGS=-lc++
LDLIBS=

SRCS=main.cpp $(shell find src -name "*.cpp")

OBJS=$(subst .cpp,.o,$(SRCS))

all: armvm

armvm: $(OBJS)
	$(CXX) $(LDFLAGS) -o armvm $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) armvm

include .depend
