/* -*- C++ -*- */

//=============================================================================
/**
 * @file   modTM_VC_Rcv_Access_Interface.cpp
 * @author Tad Kollar  
 *
 * $Id: modTM_VC_Rcv_Access_Interface.cpp 1670 2012-08-28 13:25:28Z tkollar $
 * Copyright (c) 2012.
 *      NASA Glenn Research Center.  All rights reserved.
 *      See COPYING file that comes with this distribution.
 */
//=============================================================================

#include "modTM_VC_Rcv_Access.hpp"
#include "TM_Interface_Macros.hpp"

namespace nTM_VC_Rcv_Access {

//=============================================================================
/**
 * @class modTM_VC_Rcv_Access_Interface
 * @author Tad Kollar  
 * @brief Provide an XML-RPC interface to the Virtual Channel Receive module.
 */
//=============================================================================
class modTM_VC_Rcv_Access_Interface: public nasaCE::TrafficHandler_Interface<modTM_VC_Rcv_Access> {
public:
	modTM_VC_Rcv_Access_Interface(xmlrpc_c::registryPtr& rpcRegistry):
		nasaCE::TrafficHandler_Interface<modTM_VC_Rcv_Access>(rpcRegistry, "modTM_VC_Rcv_Access") {
		ACE_TRACE("modTM_VC_Rcv_Access_Interface::modTM_VC_Rcv_Access_Interface");

		register_methods(rpcRegistry);
	}

	TM_PHYSICAL_CHANNEL_DEFINE_ACCESSORS();
	TM_MASTER_CHANNEL_DEFINE_ACCESSORS();
	TM_VIRTUAL_CHANNEL_DEFINE_ACCESSORS();

	// Export specified methods via XML-RPC.
	void register_methods(xmlrpc_c::registryPtr&);

protected:
	void get_counters_(xmlrpc_c::paramList const& paramList, modTM_VC_Rcv_Access* handler,
		xstruct& counters) {
		ACE_TRACE("modTM_VC_Rcv_Access_Interface::get_counters_");

		nasaCE::TrafficHandler_Interface<modTM_VC_Rcv_Access>::get_counters_(paramList, handler, counters);

		GET_TM_PHYSICAL_CHANNEL_COUNTERS();
		GET_TM_MASTER_CHANNEL_COUNTERS();
		GET_TM_VIRTUAL_CHANNEL_COUNTERS();
	}

	void get_settings_(xmlrpc_c::paramList const& paramList, modTM_VC_Rcv_Access* handler,
		xstruct& settings) {
		ACE_TRACE("modTM_VC_Rcv_Access_Interface::get_settings_");

		nasaCE::TrafficHandler_Interface<modTM_VC_Rcv_Access>::get_settings_(paramList, handler, settings);

		GET_TM_PHYSICAL_CHANNEL_SETTINGS();
		GET_TM_MASTER_CHANNEL_SETTINGS();
		GET_TM_VIRTUAL_CHANNEL_SETTINGS();
	}
};

modTM_VC_Rcv_Access_Interface* modTM_VC_Rcv_Access_InterfaceP;

TEMPLATE_METHOD_CLASSES(modTM_VC_Rcv_Access_Interface, modTM_VC_Rcv_Access_InterfaceP);

TM_PHYSICAL_CHANNEL_GENERATE_METHODS(modTM_VC_Rcv_Access_InterfaceP);
TM_MASTER_CHANNEL_GENERATE_METHODS(modTM_VC_Rcv_Access_InterfaceP);
TM_VIRTUAL_CHANNEL_GENERATE_METHODS(modTM_VC_Rcv_Access_InterfaceP);

void modTM_VC_Rcv_Access_Interface::register_methods(xmlrpc_c::registryPtr& rpcRegistry) {
	ACE_TRACE("modTM_VC_Rcv_Access_Interface::register_methods");

	TEMPLATE_REGISTER_METHODS(modTM_VC_Rcv_Access, modTM_VC_Rcv_Access_Interface);

	TM_PHYSICAL_CHANNEL_REGISTER_METHODS(modTM_VC_Rcv_Access);
	TM_MASTER_CHANNEL_REGISTER_METHODS(modTM_VC_Rcv_Access);
	TM_VIRTUAL_CHANNEL_REGISTER_METHODS(modTM_VC_Rcv_Access);

}

} // namespace nTM_VC_Rcv_Access
