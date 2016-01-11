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
#include "RingBuffer.hpp"

using namespace std;

void dump(RingBuffer<int> rb){
	for (auto it = rb.begin(); it != rb.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
    RingBuffer<int> rb(7);
    rb.push_back(3);
    dump(rb);
    return 0;
}
