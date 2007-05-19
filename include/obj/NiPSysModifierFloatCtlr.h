/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIPSYSMODIFIERFLOATCTLR_H_
#define _NIPSYSMODIFIERFLOATCTLR_H_

#include "NiPSysModifierCtlr.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiFloatData;
class NiPSysModifierFloatCtlr;
typedef Ref<NiPSysModifierFloatCtlr> NiPSysModifierFloatCtlrRef;

/*!
 * NiPSysModifierFloatCtlr - A particle system modifier controller that
 * deals with floating point data?
 */

class NiPSysModifierFloatCtlr : public NI_P_SYS_MODIFIER_FLOAT_CTLR_PARENT {
public:
	NIFLIB_API NiPSysModifierFloatCtlr();
	NIFLIB_API ~NiPSysModifierFloatCtlr();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	NI_P_SYS_MODIFIER_FLOAT_CTLR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif