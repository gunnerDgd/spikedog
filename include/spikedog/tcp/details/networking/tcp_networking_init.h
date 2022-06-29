#pragma once
#include <spikedog/tcp/details/networking/tcp_networking_type.h>
#include <networking/address/v4/address_v4.h>

void
__spikedog_tcp_initialize_system
	();

void
__spikedog_tcp_cleanup_system
	();

__spikedog_tcp*
__spikedog_tcp_initialize_v4
	(synapse_networking_address_v4, void*);

void
__spikedog_tcp_cleanup
	(__spikedog_tcp*);