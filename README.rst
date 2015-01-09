=====
About
=====

This is a header only tuple implementation for c++98 standard.


Samples
=======

.. highlight:: cpp

	tuple<int, char> t(0x31, '1');
	int ascii_code = t.get<0>();
	char symbol = t.get<1>();
