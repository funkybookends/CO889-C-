#makefile

#objects variable
#list all the src file objects
# OBJECTS = lzcode.o lzphrases.o lzdecode.o escapechars.o

# #prefix flags
# CXXFLAGS += -g -std=c++11 -Wall

# Prefix a line with @ to stop it from being echo'd

# ##code to generate dependancies from .d files
# #you can just copy this, it determines the dependancies for you
# %.d : %.cpp
# 	set -e; $(CXX) -M $(CPPFLAGS) $< \
# 	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
# 		[ -s $@ ] || rm -f $@

tests : escapechars.ok lzphrases.ok lzdecode.ok lzcode.ok newstest.ok
####
#single test
###
#TheTestPassedFile : TheTestInput TheTestExpectedOutput
escapechars.ok : a.out escapechars_in.txt escapechars_out.txt
	@echo "testing escapechars"
	@./a.out < escapechars_in.txt > test1.out
	@diff escapechars_out.txt test1.out
	@rm test1.out
	@touch escapechars.ok
	@echo "escapechars passed"

#TheTestPassedFile : TheTestInput TheTestExpectedOutput
lzphrases.ok : lzphrases sonnet18.txt sonnet18_phrases.txt
	@echo "testing lzphrases"
	@./lzphrases < sonnet18.txt > my_phrases.out
	@diff sonnet18_phrases.txt my_phrases.out
#	rm my_phrases.out
	@touch lzphrases.ok
	@echo "lzphrases passed"

#TheTestPassedFile : TheTestInput TheTestExpectedOutput
lzcode.ok my_code.out : lzcode sonnet18.txt sonnet18_code.txt
	@echo "testing lzcode"
	@./lzcode < sonnet18.txt > my_code.out
	@diff sonnet18_code.txt my_code.out
#	rm my_phrases.out
	@touch lzcode.ok
	@echo "lzcode passed"

lzdecode.ok : lzdecode my_code.out sonnet18.txt sonnet18_code.txt
	@./lzcode < sonnet18.txt > my_code.out
	@echo "testing lzdecode"
	@./lzdecode < sonnet18_code.txt > his_decoded.txt
	@./lzdecode < my_code.out > my_decoded.txt
	@diff his_decoded.txt my_decoded.txt
	@touch lzdecode.ok
	@echo "lzdecode passed"

newstest.ok : newstest.txt lzcode lzdecode
	@echo "testing newstest"
	@./lzcode < newstest.txt > newstest_encoded.txt
	@./lzdecode < newstest_encoded.txt > newstest_decoded.txt
	@diff newstest.txt newstest_decoded.txt
	@touch newstest.ok
	@echo "newstest passed"

#we can also define how a test should fail. see the slides


# numbits : $(OBJECTS)
# 	$(LINK.cpp) -o $@ $(OBJECTS)

a.out : escapechars.cpp
	g++ -g -Wall escapechars.cpp

lzcode : lzcode.cpp
	g++ -g -Wall -o lzcode lzcode.cpp

lzphrases : lzphrases.cpp
	g++ -g -Wall -o lzphrases lzphrases.cpp

lzdecode : lzdecode.cpp
	g++ -g -Wall -o lzdecode lzdecode.cpp