/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIFLOATINTERPOLATOR_H_
#define _NIFLOATINTERPOLATOR_H_

#include "NiKeyBasedInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiFloatData;

//#include "../gen/obj_defines.h"

class NiFloatInterpolator;
typedef Ref<NiFloatInterpolator> NiFloatInterpolatorRef;

/*!
 * NiFloatInterpolator - Unknown.
 */

class NiFloatInterpolator : public NI_FLOAT_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiFloatInterpolator();
	NIFLIB_API ~NiFloatInterpolator();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Gets the floating point value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \return The floating point value stored in this object.
	 */
	NIFLIB_API float GetFloatValue() const;

	/*!
	 * Sets the floating point value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \param[in] value The new floating point value to store in this object.
	 */
	NIFLIB_API void SetFloatValue( float value );

	/*!
	 * Gets the NiFloatData object that this interpolator links to, if any.
	 * \return The NiFloatData object that this interpolator links to, or NULL if one is not linked.
	 */
	NIFLIB_API Ref<NiFloatData > GetData() const;

	/*!
	 * Sets the NiFloatData object that this interpolator links to, if any.
	 * \return The NiFloatData object that this interpolator should now link to, or NULL to clear the current one.
	 */
	NIFLIB_API void SetData( NiFloatData * value );

	//--END CUSTOM CODE--//

protected:
	NI_FLOAT_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
