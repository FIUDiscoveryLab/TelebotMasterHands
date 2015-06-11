/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)disc_rtps_impl.h    generated by: makeheader    Sat Nov 23 02:39:02 2013
 *
 *		built from:	rtps_impl.ifc
 */

#ifndef disc_rtps_impl_h
#define disc_rtps_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



#include "pres/pres_common.h"

/* --------------------------------------------------------- */

/* RTPS spec - PB + DG*domainId + dX */ \
#define DISCRtps_getWellKnownMulticastPort(domain_id, port_base, domain_id_gain, port_offset) \
    PRESRtps_getWellKnownMulticastPort(domain_id,port_base,domain_id_gain,port_offset)

/* RTPS spec - PB + DG*domainId + PG*participantId + dX */ \
#define DISCRtps_getWellKnownUnicastPort(domain_id, participant_id, port_base, domain_id_gain, participant_id_gain, port_offset) \
    PRESRtps_getWellKnownUnicastPort(domain_id,participant_id,port_base,domain_id_gain,participant_id_gain,port_offset)

/* --------------------------------------------------------- */



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* disc_rtps_impl_h */