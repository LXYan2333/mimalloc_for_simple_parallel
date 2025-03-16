#pragma once

#include <mimalloc.h>
#include <mimalloc/types.h>

namespace simple_parallel {
__attribute__((visibility("default"))) void register_heap(mi_heap_t *heap);
__attribute__((visibility("default"))) void unregister_heap(mi_heap_t *heap);

struct mpi_info {
  int world_size;
  int world_rank;
};

__attribute__((visibility("default"))) auto get_mpi_info_from_env() -> mpi_info;

__attribute__((visibility("default"))) auto proxy_mmap(void *addr, size_t len,
                                                       int prot, int flags,
                                                       int file_desc,
                                                       off_t offset) -> void *;

__attribute__((visibility("default"))) auto
proxy_madvise(void *addr, size_t size, int advice) -> int;

__attribute__((visibility("default"))) auto proxy_munmap(void *addr,
                                                         size_t size) -> int;

} // namespace simple_parallel

auto mi_should_proxy() -> bool;

auto _mi_os_alloc(size_t size, mi_memid_t *memid, mi_stats_t *tld_stats)
    -> void *;

void _mi_os_free(void *p, size_t size, mi_memid_t memid, mi_stats_t *tld_stats);