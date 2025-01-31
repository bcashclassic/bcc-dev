/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __UTILS_CONTAINERS_HASH_HASHuint64_t_MAP_H__
#define __UTILS_CONTAINERS_HASH_HASHuint64_t_MAP_H__

#include "uthash.h"

#include "common/errors.h"
#include "common/trinary/flex_trit.h"
#include "utils/containers/hash/hash243_set.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hash_to_uint64_t_map_entry_s {
    flex_trit_t hash[FLEX_TRIT_SIZE_243];
    uint64_t value;
    UT_hash_handle hh;
} hash_to_uint64_t_map_entry_t;

typedef hash_to_uint64_t_map_entry_t *hash_to_uint64_t_map_t;

size_t hash_to_uint64_t_map_size(hash_to_uint64_t_map_t map);

retcode_t hash_to_uint64_t_map_add(hash_to_uint64_t_map_t *const map,
        flex_trit_t const *const hash,
uint64_t const value);
bool hash_to_uint64_t_map_contains(hash_to_uint64_t_map_t const *const map,
        flex_trit_t const *const hash);
bool hash_to_uint64_t_map_remove(hash_to_uint64_t_map_t *const map,
        flex_trit_t const *const hash);
bool hash_to_uint64_t_map_find(hash_to_uint64_t_map_t const *const map,
        flex_trit_t const *const hash,
hash_to_uint64_t_map_entry_t ** const res);
void hash_to_uint64_t_map_free(hash_to_uint64_t_map_t *const map);
void hash_to_uint64_t_map_keys(hash_to_uint64_t_map_t *const map,
                             hash243_set_t * const keys);

retcode_t hash_to_uint64_t_map_copy(hash_to_uint64_t_map_t const *const src,
        hash_to_uint64_t_map_t *const dst);

bool hash_to_uint64_t_map_equal(hash_to_uint64_t_map_t const lhs,
        hash_to_uint64_t_map_t const rhs);

#ifdef __cplusplus
}
#endif

#endif  // __UTILS_CONTAINERS_HASH_HASHuint64_t_MAP_H__
