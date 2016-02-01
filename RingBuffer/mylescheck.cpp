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
/*#include "ChattyInt11.hpp"
#include <string>
#include <vector>*/

using namespace std;

int main()
{
    RingBuffer<int> rb(6);
    
    cout << rb.capacity() << ", " << rb.size() << ", " << rb.empty() << endl;
	// expect 6, 0, 1
    
    rb.push_back(1);
    rb.push_back(2);
    rb.push_back(3);
    rb.push_back(4);
    rb.push_back(5);
    rb.push_back(6);
    
    cout << rb.capacity() << ", " << rb.size() << ", " << rb.empty() << endl;
	//expect 6, 6, 0
    
    for(auto it = rb.begin(); it != rb.end(); ++it)
    {
    	cout << *it << endl;	
    }
    
    rb.clear();
    
    cout << rb.capacity() << ", " << rb.size() << ", " << rb.empty() << endl;
	//expect 6, 0, 1
    
    rb.push_back(1);
    rb.push_back(2);
    rb.push_back(3);
    rb.push_back(4);
    
    cout << rb.capacity() << ", " << rb.size() << ", " << rb.empty() << endl;
	//expect 6, 4, 0
    
    rb.pop_front();
    rb.pop_front();
    
    cout << rb.capacity() << ", " << rb.size() << ", " << rb.empty() << endl;
	//expect 6, 2, 0
    
    RingBuffer<int> rbCopy(rb);
    
    cout << (rb == rbCopy) << endl;
	//expect 1
    
    rbCopy.push_back(5);
    rbCopy.push_back(6);
    
    cout << (rb == rbCopy) << endl;
	//expect 0
    
    rbCopy.clear();
    rb.clear();
    rb.push_back(1);
    rb.push_back(2);
    rb.push_back(3);
    rb.push_back(4);
    rbCopy.push_back(1);
    rbCopy.push_back(2);
    rbCopy.push_back(3);
    rbCopy.push_back(4);
    
    cout << (rb == rbCopy) << endl;
	//expect 1
    
/*    RingBuffer<std::string> rb2(8);
    
    rb2.push_back("1st");
    rb2.push_back("2nd");

	for(auto it = rb2.begin(); it != rb2.end(); ++it)
    {
    	cout << *it << endl;	
    }
    
    cout << rb2.capacity() << ", " << rb2.size() << ", " << rb2.empty() << endl;
    
    rb2.pop_front();
    rb2.push_back("3rd");
    rb2.push_back("4th");
    rb2.push_back("5th");
    rb2.push_back("6th");
    rb2.push_back("7th");
    rb2.push_back("8th");
    
    cout << rb2.capacity() << ", " << rb2.size() << ", " << rb2.empty() << endl;
    
    rb2.push_back("9th");
    
    for(auto it = rb2.begin(); it != rb2.end(); ++it)
    {
    	cout << *it << endl;	
    }
    
    cout << rb2.capacity() << ", " << rb2.size() << ", " << rb2.empty() << endl;
    
    std::vector<int> v1 { 1, 2, 3, 4 };
    std::vector<int> v2 { 5, 6 };
    std::vector<int> v3 { 7, 8, 9 };
    
    RingBuffer<std::vector<int> > rb3(4);
    
    cout << rb3.capacity() << ", " << rb3.size() << ", " << rb3.empty() << endl;
    
    rb3.push_back(v1);
    rb3.push_back(v2);
    rb3.push_back(v3);
    
    for(auto it = rb3.begin(); it != rb3.end(); ++it)
    {
    	cout << it->size() << endl;
    	for(int i : *it)
    	{
    		cout << i << ' ';
    	}
    	cout << endl;	
    }
    
    cout << rb3.capacity() << ", " << rb3.size() << ", " << rb3.empty() << endl;
    
    rb3.pop_front();
    rb3.push_back(v1);
    rb3.push_back(v2);
    
    for(auto it = rb3.begin(); it != rb3.end(); ++it)
    {
    	for(int i : *it)
    	{
    		cout << i << ' ';
    	}
    	cout << endl;	
    }
    
    cout << rb3.capacity() << ", " << rb3.size() << ", " << rb3.empty() << endl;
    
    RingBuffer<ChattyInt> rb4(5);
    
    cout << rb4.capacity() << ", " << rb4.size() << ", " << rb4.empty() << endl;
    
    rb4.push_back(ChattyInt(32) ); 
    rb4.push_back(ChattyInt(21) );
    rb4.pop_front();
    rb4.push_back(ChattyInt(52) ); 
    rb4.push_back(ChattyInt(66) );
    rb4.front() = 42;
    rb4.push_back(ChattyInt(0) );
    rb4.push_back(ChattyInt(482) );
    
    for(auto it = rb4.begin(); it != rb4.end(); ++it)
    {
    	cout << *it << endl;	
    }
    
    cout << rb4.capacity() << ", " << rb4.size() << ", " << rb4.empty() << endl;
    */
    return 0;
}
