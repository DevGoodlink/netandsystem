/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calcul.h"

bool_t
xdr_operandes (XDR *xdrs, operandes *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->x))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->y))
		 return FALSE;
	return TRUE;
}
