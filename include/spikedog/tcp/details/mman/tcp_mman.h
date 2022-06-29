#pragma once
#include <spikedog/tcp/details/mman/tcp_mman_type.h>

void
__spikedog_tcp_mman_initialize
	();

void
__spikedog_tcp_mman_cleanup
	();

__spikedog_tcp_mman*
__spikedog_tcp_mman_entity
	();

void*
__spikedog_tcp_mman_allocate
	(void*, size_t);

void*
__spikedog_tcp_mman_deallocate
	(void*, size_t);