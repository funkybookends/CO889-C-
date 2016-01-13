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
#include <iostream>
#include <assert.h>

using namespace std;

void my_dump_ref(RingBuffer<int>& rb){ 
	if (rb.cbegin() == rb.cend()) {
		cout<<"empty\n";
	}
	for (auto it = rb.cbegin(); it != rb.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void my_dump(RingBuffer<int> rb){ 
	if (rb.cbegin() == rb.cend()) {
		cout<<"empty\n";
	}
	for (auto it = rb.cbegin(); it != rb.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
    RingBuffer<int> rb(7);
    cout<<rb.capacity()<<" "<<rb.size()<<endl;
    assert(rb.begin() == rb.end());
    rb.push_back(3);
    assert(rb.begin() != rb.end());
	my_dump(rb);
	my_dump_ref(rb);
	rb.push_back(5);
	my_dump(rb);
	my_dump_ref(rb);
    return 0;
}
