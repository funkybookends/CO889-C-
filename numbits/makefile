#makefile

#objects variable
#list all the src file objects
OBJECTS = main.o numbits.o

#prefix flags
CXXFLAGS += -g -std=c++11 -Wall

##code to generate dependancies from .d files
#you can just copy this, it determines the dependancies for you
%.d : %.cpp
	set -e; $(CXX) -M $(CPPFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

####
#single test
###
#TheTestPassedFile : TheTestInput TheTestExpectedOutput
test1.ok : numbits test1.in test1.good
	./numbits < test1.in > test1.out
	diff test1.out test1.good
	rm test1.out
	touch test1.ok

#we can also define how a test should fail. see the slides

###makes all tests run
# include all the test passed files here
tests : test1.ok

numbits : $(OBJECTS)
	$(LINK.cpp) -o $@ $(OBJECTS)


