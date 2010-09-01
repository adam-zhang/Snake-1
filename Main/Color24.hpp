#ifndef __Color__
#define __Color__

struct Color24
{
	union
	{
		unsigned short r;
		unsigned short red;
	};
	union
	{
		unsigned short g;
		unsigned short green;
	};
	union
	{
		unsigned short b;
		unsigned short blue;
	};

	Color24();
	Color24(unsigned short red, unsigned short green, unsigned short blue);
};

#endif
