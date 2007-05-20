/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiBlendBoolInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendBoolInterpolator::TYPE("NiBlendBoolInterpolator", &NI_BLEND_BOOL_INTERPOLATOR_PARENT::TYPE );

NiBlendBoolInterpolator::NiBlendBoolInterpolator() NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBlendBoolInterpolator::~NiBlendBoolInterpolator() {}

void NiBlendBoolInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBlendBoolInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBlendBoolInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendBoolInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBlendBoolInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendBoolInterpolator::GetType() const {
	return TYPE;
};

//--BEGIN MISC CUSTOM CODE--//

byte NiBlendBoolInterpolator::GetBoolValue() const {
	return boolValue;
}

void NiBlendBoolInterpolator::SetBoolValue( byte value ) {
	boolValue = value;
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
		global_object_map["NiBlendBoolInterpolator"] = NiBlendBoolInterpolator::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiBlendBoolInterpolator::Create() {
	return new NiBlendBoolInterpolator;
}
