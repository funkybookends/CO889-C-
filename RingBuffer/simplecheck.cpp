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

#include <iostream>  
#include <assert.h> 
#include "RingBuffer.hpp"

using namespace std; 

void my_dump(RingBuffer<int>& rb){ 

	if (rb.cbegin() == rb.cend()) {
		cout<<"empty\n";
	}
	for (auto it = rb.cbegin(); it != rb.cend(); ++it) {
		cout <<"dumping \n\n";
		cout << *it << "-- ";
	}
	cout << endl;
}

int main()
{
    RingBuffer<int> rb(7);
    //cout<<rb.capacity()<<" "<<rb.size()<<endl;
    assert(rb.begin() == rb.end());
    int in = 3;
    rb.push_back(in);
    cout<<"displaying end\n";
    rb.end();
    cout<<endl;
    //assert(rb.begin() != rb.end());
    cout<<"start dump1";
    for (auto it = rb.cbegin(); it != rb.cend(); ++it) {
		cout <<"dumping1 \n\n";
		cout << *it << ":\n";
	}
	cout<<"\nstart dump2\n";
	if (rb.cbegin() == rb.cend()) {
		cout<<"empty\n";
	}
	for (auto it = rb.cbegin(); it != rb.cend(); ++it) {
		cout <<"dumping \n\n";
		cout << *it << ": ";
	}
	cout << endl;
	cout<<"\nstart dump3\n";
	my_dump(rb);
    return 0;
}
