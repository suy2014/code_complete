/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct hash_entry_s {
    int key;
    int value;
    UT_hash_handle hh;
} hash_entry_t;

hash_entry_t *hash_table = NULL;

hash_entry_t* hash_find(int key) {
    hash_entry_t *entry = NULL;
    HASH_FIND_INT(hash_table, &key, entry);
    return entry;
}

void hash_insert(int key, int value) {
    hash_entry_t *hash_entry;
    hash_entry_t *item_entry;

    item_entry = hash_find(key);
    if (item_entry == NULL) {
        hash_entry = calloc(1, sizeof(hash_entry_t));
        hash_entry->key = key;
        hash_entry->value = value;
        HASH_ADD_INT(hash_table, key, hash_entry);
    } else {
        item_entry->value = value;
    }

    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int j;
    int* ret;
    hash_table = NULL;
    hash_entry_t *entry = NULL;

    ret = NULL;
    for (j = 0; j < numsSize; j++) {
        entry = hash_find(target - nums[j]);
        if (entry != NULL) {
            ret = calloc(2, sizeof(int));
            *returnSize = 2;
            ret[0] = entry->value;
            ret[1] = j;
            return ret;
        }
        hash_insert(nums[j], j);
    }

    *returnSize = 0;
    return NULL;
}
