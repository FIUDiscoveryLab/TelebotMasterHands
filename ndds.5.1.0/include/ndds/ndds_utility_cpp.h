/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)ndds_utility_cpp.h    generated by: makeheader    Sat Nov 23 02:40:02 2013
 *
 *		built from:	ndds_utility_cpp.ifcxx
 */

#ifndef ndds_utility_cpp_h
#define ndds_utility_cpp_h


#ifndef dds_cpp_dll_h
  #include "dds_cpp/dds_cpp_dll.h"
#endif
#ifndef dds_c_infrastructure_h
  #include "dds_c/dds_c_infrastructure.h"
#endif
#ifndef ndds_utility_c_h
  #include "ndds/ndds_utility_c.h"
#endif

class DDSCPPDllExport NDDSUtility {
  public:
    /*e \dref_Utility_sleep */
    static void sleep(const struct DDS_Duration_t& durationIn);
};

#endif /* ndds_utility_cpp_h */
