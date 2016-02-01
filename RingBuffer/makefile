#makefile

#objects variable
#list all the src file objects
# OBJECTS = simplecheck.o simplecheck.cpp RingBuffer.hpp

# # #prefix flags
# CXXFLAGS += -g -std=c++11 -Wall

# # Prefix a line with @ to stop it from being echo'd

# # ##code to generate dependancies from .d files
# # #you can just copy this, it determines the dependancies for you
# %.d : %.cpp
# 	set -e; $(CXX) -M $(CPPFLAGS) $< \
# 	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
# 		[ -s $@ ] || rm -f $@

test : simplecheck.ok mylescheck.ok
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
	./simplecheck
	@echo "passed"

#TheTest

mylescheck.ok : mylescheck mylesout.txt
	@echo "Myles Test"
	./mylescheck > out.txt
	diff mylesout.txt out.txt
	@rm test.out
	@touch mylescheck.ok
	@echo "myles test passed"

#we can also define how a test should fail. see the slides

simplecheck : simplecheck.cpp RingBuffer.hpp
	@echo "\n\n\t\tBUILDING!!!"
	g++ -g -std=c++11 -Wall -o simplecheck simplecheck.cpp
	@echo "\t\tBUILT!!!"
# simplecheck : $(OBJECTS)
# 	$(LINK.cpp) -o $@ $(OBJECTS)

mylescheck : mylescheck.cpp mylesout.txt RingBuffer.hpp
	@echo "\n\n\n\t\tBuilding Myles Version"
	g++ -g -std=c++11 -Wall -o mylescheck mylescheck.cpp
	@echo "\t\tBuilt"
# simplecheck : simplecheck.cpp
# 	g++ -g -Wall -o simplecheck simplecheck.cpp