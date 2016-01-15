/*  $Id$
 *
 *  Copyright (C) 2015  Andrew R. Runnalls
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  http://www.r-project.org/Licenses/
 */

#include "RingBuffer.hpp"
#include <assert.h>

using namespace std;

//list of functions to test
// Iterator Functions

// copy constructor operator=
// operator*
// operator->
// operator==
// operator++
// operator++(int)
// operator--
// operator--(int)
// operator+=
// operator+(difference_type n)
// operator-(it)
// operator[](difference_type)
// operator<

// RB functions

// begin
// begin() const
// cbegin() const
// capacity()
// clear()
// empty()
// end
// end() const
// cend() const
// front
// const front() const
// pop_front()
// push_back
// size()
// operator==

int main()
{
	//simple tests
	{
		unsigned int test_capacity = 4;
	    RingBuffer<unsigned int> rb(test_capacity); 
	    assert(rb.empty());
	    { //Capacity tests, size test and push back tests
		    assert(rb.capacity()==test_capacity);
		    assert(rb.size()==0);
		    for (unsigned int i = 1; i<=test_capacity; i++){
		    	rb.push_back(i);
		    	assert(!rb.empty());
			    assert(rb.capacity()==4);
			    assert(rb.size()==i);	
		    }
		} //close scope
		{ //increment iterator tests and 
		    unsigned int i = 1;
		    auto iterator = rb.begin();
		    while (i != test_capacity){
		    	assert(*iterator==i);
		    	assert(i==(*iterator++));
		    	++i;
		    }
		} //close scope
	    { //test const iterator
	    	unsigned int i = 1;
		    auto c_iterator = rb.cbegin();
		    while (i != test_capacity){
		    	assert(*c_iterator==i);
		    	assert(i==(*c_iterator++));
		    	++i;
		    }
		}
		{
			for (unsigned int i = 0; i <test_capacity; ++i){
				auto it = rb.begin();
				assert(it[i]==(i+1));
			}
		}
		{
			auto start = rb.begin();
			signed int i = 0;
			for (auto it=rb.begin(); it!=rb.end(); ++it){
				assert(it-start == i);
				assert(start-it == -i);
				if (it!=start) {
					assert(start<it);
				}
				else {
					assert(!(start<it));
				}
				++i;
			}
		}
	}
	{//equality tests
		RingBuffer<int> rba(10);
		RingBuffer<int> rbb(20);
		assert(rba==rbb);
		for (int i = 0; i < 7; ++i){
			rba.push_back(i);
			assert(rba!=rbb);
			rbb.push_back(i);
			assert(rba==rbb);
		}
		{
			auto it = rba.begin();
			it+=6;
			assert(*it == 6);
		}
		assert(rba.begin()<rba.end());
		for (int i = 0; i < 5; ++i){
			assert(*(rba.begin())==i);
			assert(*(rba.cbegin())==i);
			rba.pop_front();
			assert(rba!=rbb);
			rbb.pop_front();
			assert(rba==rbb);

			auto mover = rba.begin();
			auto stayer = rba.begin();
			++mover;
			assert(mover!=stayer);
			assert(*mover != * stayer);
			mover = stayer;
			assert(stayer == mover);
			assert(*mover == *stayer);
		}
		assert(rba.begin()<rba.end());
		for (int i = 0; i < 8; ++i){
			rba.push_back(i);
			assert(rba!=rbb);
			rbb.push_back(i);
			assert(rba==rbb);
		}
		for (int i = 0; i < 5; ++i){
			rba.pop_front();
			assert(rba!=rbb);
			rbb.pop_front();
			assert(rba==rbb);

			auto it = rba.begin();
			auto ib = rbb.begin();
			assert(it!=ib);
			ib = it;
			assert(it==ib);
		}
		rba.clear();
		assert(rba.empty());
		assert(rba.begin() == rba.end());
		assert(rba.cbegin() == rba.cend());
		assert(rba!=rbb);
		rbb.clear();
		assert(rba==rbb);
	}
    return 0;
}
