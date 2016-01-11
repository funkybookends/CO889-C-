#makefile

#objects variable
#list all the src file objects
OBJECTS = simplecheck.o

# #prefix flags
CXXFLAGS += -g -std=c++11 -Wall

# Prefix a line with @ to stop it from being echo'd

# ##code to generate dependancies from .d files
# #you can just copy this, it determines the dependancies for you
%.d : %.cpp
	set -e; $(CXX) -M $(CPPFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

test : simplecheck.ok
####
#single test
###
#TheTestPassedFile : TheTestInput TheTestExpectedOutput
# escapechars.ok : a.out escapechars_in.txt escapechars_out.txt
# 	@echo "testing escapechars"
# 	@./a.out < escapechars_in.txt > test1.out
# 	@diff escapechars_out.txt test1.out
# 	@rm test1.out
# 	@touch escapechars.ok
# 	@echo "escapechars passed"

simplecheck.ok : simplecheck
	@echo "testing"
	@./simplecheck > simplecheck.out
	@diff simplecheck.good simplecheck.out
	@rm simplecheck.out
	@touch simplecheck.ok
	@echo "passed"

#TheTest

#we can also define how a test should fail. see the slides

simplecheck : $(OBJECTS)
	$(LINK.cpp) -o $@ $(OBJECTS)


# simplecheck : simplecheck.cpp
# 	g++ -g -Wall -o simplecheck simplecheck.cpp