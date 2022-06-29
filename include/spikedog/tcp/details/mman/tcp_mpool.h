#pragma once
#include <spikedog/tcp/details/mman/tcp_mpool_type.h>

void
__spikedog_tcp_mpool_initialize
	();

void
__spikedog_tcp_mpool_cleanup
	();

__spikedog_tcp_mpool*
__spikedog_tcp_mpool_entity
	();

__spikedog_tcp_mpool_chunk
__spikedog_tcp_mpool_allocate
	(void*);

__spikedog_tcp_mpool_chunk
__spikedog_tcp_mpool_deallocate
	(void*);