/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysGravityModifier.h"

//Definition of TYPE constant
const Type NiPSysGravityModifier::TYPE("NiPSysGravityModifier", &NI_P_SYS_GRAVITY_MODIFIER_PARENT::TYPE );

NiPSysGravityModifier::NiPSysGravityModifier() NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT {}

NiPSysGravityModifier::~NiPSysGravityModifier() {}

void NiPSysGravityModifier::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_GRAVITY_MODIFIER_READ
}

void NiPSysGravityModifier::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_P_SYS_GRAVITY_MODIFIER_WRITE
}

string NiPSysGravityModifier::asString( bool verbose ) const {
	NI_P_SYS_GRAVITY_MODIFIER_STRING
}

void NiPSysGravityModifier::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_P_SYS_GRAVITY_MODIFIER_FIXLINKS
}
