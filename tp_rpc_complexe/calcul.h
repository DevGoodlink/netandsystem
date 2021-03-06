/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALCUL_H_RPCGEN
#define _CALCUL_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct complex {
	float a;
	float b;
};
typedef struct complex complex;

struct operandes {
	complex x;
	complex y;
};
typedef struct operandes operandes;

#define MATH_CALCUL 0x20000002
#define MATH_VERSION_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADDITION 1
extern  complex * addition_1(operandes *, CLIENT *);
extern  complex * addition_1_svc(operandes *, struct svc_req *);
#define MULTI 2
extern  complex * multi_1(operandes *, CLIENT *);
extern  complex * multi_1_svc(operandes *, struct svc_req *);
extern int math_calcul_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADDITION 1
extern  complex * addition_1();
extern  complex * addition_1_svc();
#define MULTI 2
extern  complex * multi_1();
extern  complex * multi_1_svc();
extern int math_calcul_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_complex (XDR *, complex*);
extern  bool_t xdr_operandes (XDR *, operandes*);

#else /* K&R C */
extern bool_t xdr_complex ();
extern bool_t xdr_operandes ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALCUL_H_RPCGEN */
