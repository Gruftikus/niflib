/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiTriBasedGeomData.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriBasedGeomData::TYPE("NiTriBasedGeomData", &NI_TRI_BASED_GEOM_DATA_PARENT::TYPE );

NiTriBasedGeomData::NiTriBasedGeomData() NI_TRI_BASED_GEOM_DATA_CONSTRUCT {}

NiTriBasedGeomData::~NiTriBasedGeomData() {}

void NiTriBasedGeomData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTriBasedGeomData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTriBasedGeomData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTriBasedGeomData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTriBasedGeomData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTriBasedGeomData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

void NiTriBasedGeomData::SetTriangles( const vector<Triangle> & in ) {
   throw runtime_error("SetTriangles is not implemented for this object.");
}

vector<Triangle> NiTriBasedGeomData::GetTriangles() const {
	return vector<Triangle>();
}

//--END CUSTOM CODE--//

namespace Niflib { 
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiTriBasedGeomData"] = NiTriBasedGeomData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiTriBasedGeomData::Create() {
	return new NiTriBasedGeomData;
}
