#define HASH                       separate_chain_hash
#define TEST_HASH_sample           test_separate_chain_hash_sample

#define HASH_create                separate_chain_hash_create
#define HASH_destroy               separate_chain_hash_destroy
#define HASH_load_factor_calculate separate_chain_hash_load_factor_calculate
#define HASH_insert                separate_chain_hash_insert
#define HASH_remove                separate_chain_hash_remove
#define HASH_find                  separate_chain_hash_find
#define HASH_rehashing             separate_chain_hash_rehashing

#include "../performance_test_hash.h"

PT_HASH_create(separate_chain)
PT_HASH_destroy(separate_chain)
PT_HASH_load_factor_calculate(separate_chain)
PT_HASH_insert(separate_chain)
PT_HASH_remove(separate_chain)
PT_HASH_find(separate_chain)
PT_HASH_rehashing(separate_chain)

#undef HASH
#undef TEST_HASH_sample

#undef HASH_create
#undef HASH_destroy
#undef HASH_load_factor_calculate
#undef HASH_insert
#undef HASH_remove
#undef HASH_find
#undef HASH_rehashing

