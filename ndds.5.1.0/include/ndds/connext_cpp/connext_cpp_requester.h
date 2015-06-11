/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)connext_cpp_requester.h    generated by: makeheader    Sat Nov 23 02:41:09 2013
 *
 *		built from:	requester.ifcxx
 */

#ifndef connext_cpp_requester_h
#define connext_cpp_requester_h



#include <string>

#include "ndds/ndds_namespace_cpp.h"

#include "connext_cpp/connext_cpp_dll.h"
#include "connext_cpp/connext_cpp_infrastructure.h"
#include "connext_cpp/connext_cpp_requester_params.h"



#include "connext_cpp/connext_cpp_requester_details.h"

namespace connext {

using namespace DDS;

// --- Requester: -------------------------------------------------------------

/*e \dref_Requester
 */
template <typename TReq, typename TRep>
class XMQCPPDllExport Requester {
public:

    // --- types: -------------------------------------------------------------

    /**
     * @brief The request type
     */
    typedef TReq Request;

    /**
     * @brief The reply type
     */
    typedef TRep Reply;

    /**
     * @brief The typed DataWriter for type \p TReq
     */
    typedef typename dds_type_traits<TReq>::DataWriter RequestDataWriter;

    /**
     * @brief The typed DataReader for type \p TRep
     */
    typedef typename dds_type_traits<TRep>::DataReader ReplyDataReader;

    /**
     * @brief The type support for type \p TReq
     */
    typedef typename dds_type_traits<TReq>::TypeSupport RequestTypeSupport;

    /**
     * @brief The type support for type \p TRep
     */
    typedef typename dds_type_traits<TRep>::TypeSupport ReplyTypeSupport;

    // --- constructor and destructor: ----------------------------------------

    /**
     * \dref_Requester_new
     */
    Requester(
        DDSDomainParticipant * participant,
        const std::string& service_name);

    /**
     * \dref_Requester_new_w_params
     */
    explicit Requester(const RequesterParams& params);

    /**
     * \dref_Requester_finalize
     */
    virtual ~Requester();


    // --- send_request methods: ----------------------------------------------

    /**
     * \dref_Requester_send_request
     */
    template <typename UReq>
    void send_request(const UReq & request);

    /**
     * \dref_Requester_send_request_w_writesample
     */
    template<typename UReq>
    void send_request(WriteSample<UReq> & request);

    /**
     * \dref_Requester_send_request_w_writesampleref
     */
    template<typename UReq>
    void send_request(WriteSampleRef<UReq> & request);

    // --- receive methods: ---------------------------------------------------

    /**
     * \dref_Requester_receive_reply
     */
    inline bool receive_reply(
        Sample<TRep>& reply, const DDS_Duration_t& timeout);

    /**
     * \dref_Requester_receive_reply_sampleref
     */
    inline bool receive_reply(
        SampleRef<TRep> reply, const DDS_Duration_t& timeout);

    /**
     * \dref_Requester_receive_replies_simple
     */
    LoanedSamples<TRep> receive_replies(const DDS_Duration_t& max_wait);

    /**
     * \dref_Requester_receive_replies
     */
    LoanedSamples<TRep> receive_replies(int min_count,
                                        int max_count,
                                        const DDS_Duration_t & max_wait);


    // --- wait methods: ------------------------------------------------------

    /**
     * \dref_Requester_wait_for_replies
     */
    bool wait_for_replies(
        int min_count,
        const DDS_Duration_t& max_wait);

    /**
     * \dref_Requester_wait_for_replies_simple
     */
    bool wait_for_replies(const DDS_Duration_t& max_wait);

    /**
     * \dref_Requester_wait_for_replies_w_related_request
     */
    bool wait_for_replies(
        int min_count,
        const DDS_Duration_t& max_wait,
        const SampleIdentity_t& related_request_id);

    // --- get methods: -------------------------------------------------------

    /**
     * \dref_Requester_take_reply
     */
    inline bool take_reply(Sample<TRep>& reply);

    /**
     * \dref_Requester_take_reply_sampleref
     */
    inline bool take_reply(SampleRef<TRep> reply);

    /**
     * \dref_Requester_take_replies
     */
    LoanedSamples<TRep> take_replies(int max_count = DDS_LENGTH_UNLIMITED);

    /**
     * \dref_Requester_take_reply_w_related_request
     */
    inline bool take_reply(
        Sample<TRep>& reply, const SampleIdentity_t& related_request_id);

    /**
     * \dref_Requester_take_reply_w_related_request_sampleref
     */
    inline bool take_reply(
        SampleRef<TRep> reply, const SampleIdentity_t& related_request_id);

    /**
     * \dref_Requester_take_replies_w_related_request
     */
    LoanedSamples<TRep> take_replies(
        int max_count, const SampleIdentity_t& related_request_id);

    /**
     * \dref_Requester_take_replies_w_related_request_simple
     */
    LoanedSamples<TRep> take_replies(const SampleIdentity_t& related_request_id);

    // --- read methods: ------------------------------------------------------

    /**
     * \dref_Requester_read_reply
     */
    inline bool read_reply(Sample<TRep>& reply);

    /**
     * \dref_Requester_read_reply_sampleref
     */
    inline bool read_reply(SampleRef<TRep> reply);

    /**
     * \dref_Requester_read_replies
     */
    LoanedSamples<TRep> read_replies(int max_count = DDS_LENGTH_UNLIMITED);

    /**
     * \dref_Requester_read_reply_w_related_request
     */
    inline bool read_reply(
        Sample<TRep>& reply, const SampleIdentity_t& related_request_id);

    /**
     * \dref_Requester_read_reply_w_related_request_sampleref
     */
    inline bool read_reply(
        SampleRef<TRep> reply, const SampleIdentity_t& related_request_id);

    /**
     * \dref_Requester_read_replies_w_related_request
     */
    LoanedSamples<TRep> read_replies(
        int max_count, const SampleIdentity_t& related_request_id);

    /**
     * \dref_Requester_read_replies_w_related_request_simple
     */
    LoanedSamples<TRep> read_replies(const SampleIdentity_t& related_request_id);


    // --- query: -------------------------------------------------------------

    /**
     * \dref_Requester_get_request_datawriter
     */
    inline RequestDataWriter * get_request_datawriter();

    /**
     * \dref_Requester_get_reply_datareader
     */
    inline ReplyDataReader * get_reply_datareader();

private:


    template<typename UReq>
    void send_request(const WriteSample<UReq> & request);

    template<typename UReq>
    void send_request(const WriteSampleRef<UReq> & request);

    // --- members: -----------------------------------------------------------
private:
    connext::details::RequesterImpl<TReq, TRep> * _pImpl;
};

} // namespace connext

#ifndef xmq_cpp_requester_template_h
  #include "connext_cpp/connext_cpp_requester_template.h"
#endif

/* ----------------------------------------------------------------- */
/* End of $Id: requester.ifcxx,v 1.34 2012/08/07 05:33:46 alejandro Exp $ */
#endif /* connext_cpp_requester_h */