/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../../include/obj/NiLight.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLight::TYPE("NiLight", &NI_LIGHT_PARENT::TYPE );

NiLight::NiLight() NI_LIGHT_CONSTRUCT {}

NiLight::~NiLight() {}

void NiLight::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiLight::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiLight::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiLight::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiLight::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiLight::GetType() const {
	return TYPE;
};

//--END CUSTOM CODE--//

float NiLight::GetDimmer() const {
	return dimmer;
}

void NiLight::SetDimmer( float value ) {
	dimmer = value;
}

Color3 NiLight::GetAmbientColor() const {
	return ambientColor;
}

void NiLight::SetAmbientColor( Color3 value ) {
	ambientColor = value;
}

Color3 NiLight::GetDiffuseColor() const {
	return diffuseColor;
}

void NiLight::SetDiffuseColor( Color3 value ) {
	diffuseColor = value;
}

Color3 NiLight::GetSpecularColor() const {
	return specularColor;
}

void NiLight::SetSpecularColor( Color3 value ) {
	specularColor = value;
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
		global_object_map["NiLight"] = NiLight::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiLight::Create() {
	return new NiLight;
}
