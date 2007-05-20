/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiTextKeyExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTextKeyExtraData::TYPE("NiTextKeyExtraData", &NI_TEXT_KEY_EXTRA_DATA_PARENT::TYPE );

NiTextKeyExtraData::NiTextKeyExtraData() NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT {}

NiTextKeyExtraData::~NiTextKeyExtraData() {}

void NiTextKeyExtraData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTextKeyExtraData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTextKeyExtraData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTextKeyExtraData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTextKeyExtraData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTextKeyExtraData::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

vector< Key<string> > NiTextKeyExtraData::GetKeys() const {
	return textKeys;
}

void NiTextKeyExtraData::SetKeys( vector< Key<string> > const & keys ) {
	textKeys = keys;
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
		global_object_map["NiTextKeyExtraData"] = NiTextKeyExtraData::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiTextKeyExtraData::Create() {
	return new NiTextKeyExtraData;
}
