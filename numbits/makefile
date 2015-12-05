#makefile

#objects variable
OBJECTS = main.o numbits.o

#prefix flags
CXXFLAGS += -g -std=c++11 -Wall

##code to generate dependancies from .d files
%.d : %.cpp
	set -e; $(CXX) -M $(CPPFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

####
#single test
###
test1.ok : numbits test1.in test1.good
	./numbits < test1.in > test1.out
	diff test1.out test1.good
	rm test1.out
	touch test1.ok

###makes all tests run
tests : test1.ok

numbits : $(OBJECTS)
	$(LINK.cpp) -o $@ $(OBJECTS)


