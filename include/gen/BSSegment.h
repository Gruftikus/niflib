/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BSSEGMENT_H_
#define _BSSEGMENT_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Bethesda-specific node. */
struct BSSegment {
	/*! Default Constructor */
	NIFLIB_API BSSegment();
	/*! Default Destructor */
	NIFLIB_API ~BSSegment();
	/*! Copy Constructor */
	NIFLIB_API BSSegment( const BSSegment & src );
	/*! Copy Operator */
	NIFLIB_API BSSegment & operator=( const BSSegment & src );
		
	//--BEGIN MISC CUSTOM CODE--//

	//change, see: https://github.com/niftools/nifxml/pull/42/files
	/*! Unknown. */
	byte unknownByte1;
	/*! Offset of first triangle point of this Segment. Divide this value by 3 to get index of first Triangle in Triangles array of NiTriShapeData. */
	int offset;
	/*! The number of triangles in this Segment. Value 0 mean empty Segment. */
	int count;
	//--END CUSTOM CODE--//
};

}
#endif
