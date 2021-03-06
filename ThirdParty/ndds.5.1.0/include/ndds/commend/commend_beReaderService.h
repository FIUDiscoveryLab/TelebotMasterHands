/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_beReaderService.h    generated by: makeheader    Sat Nov 23 02:38:39 2013
 *
 *		built from:	beReaderService.ifc
 */

#ifndef commend_beReaderService_h
#define commend_beReaderService_h


  #ifndef reda_worker_h
    #include "reda/reda_worker.h"
  #endif
  #ifndef reda_weakReference_h
    #include "reda/reda_weakReference.h"
  #endif
  #ifndef reda_database_h
    #include "reda/reda_database.h"
  #endif
  #ifndef netio_common_h
    #include "netio/netio_common.h"
  #endif
  #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
  #endif
  #ifndef commend_dll_h
    #include "commend/commend_dll.h"
  #endif
  #ifndef commend_readerService_h
    #include "commend/commend_readerService.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDADatabase;

struct COMMENDFacade;

struct COMMENDBeReaderService;

extern COMMENDDllExport struct COMMENDBeReaderService *
COMMENDBeReaderService_new(
    struct REDADatabase *db, struct COMMENDFacade *facade,
    const struct COMMENDReaderServiceProperty *property,
    struct REDAExclusiveArea *ea, struct REDAWorker *worker);

struct COMMENDBeReaderServiceRemoteWriterProperty {

    struct RTINetioLocator sessionLocatorList[
        COMMEND_COMMON_APP_IPADDRESS_COUNT_MAX];

    RTI_INT32 sessionLocatorCount;
};


  #define COMMEND_BE_READER_SERVICE_REMOTE_WRITER_PROPERTY_DEFAULT { \
    { /* sessionLocatorsList */                                 \
     RTI_NETIO_LOCATOR_INVALID,                                 \
     RTI_NETIO_LOCATOR_INVALID,                                 \
     RTI_NETIO_LOCATOR_INVALID,                                 \
     RTI_NETIO_LOCATOR_INVALID                                  \
    },                                                          \
    0, /* sessionLocatorsList */                                \
}


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_beReaderService_h */
