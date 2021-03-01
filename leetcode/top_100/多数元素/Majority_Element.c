struct hash_entry {
    int id;            /* we'll use this field as the key */
    int count;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct hash_entry *hash_num = NULL;
int major_num = 0;

struct hash_entry *find(int num, int numsSize) {
    struct hash_entry *hash_num_entry = NULL;

    HASH_FIND_INT(hash_num, &num, hash_num_entry);
    if (hash_num_entry != NULL) {
        hash_num_entry->count++;
        if(hash_num_entry->count > numsSize/2) {
            major_num = num;
            printf("%d %d\n", num, hash_num_entry->count);
        }
    }
    return hash_num_entry;
}

void add_hash_entry(int num, int numsSize) {
    struct hash_entry *hash_num_entry = NULL;

    hash_num_entry = find(num, numsSize);
    if (hash_num_entry == NULL) {
        hash_num_entry = calloc(1, sizeof(struct hash_entry));

        hash_num_entry->id = num;
        hash_num_entry->count = 1;
        HASH_ADD_INT(hash_num, id, hash_num_entry);
    }
}

void del_hash_entry(int num) {
    struct hash_entry *hash_num_entry = NULL;
    HASH_FIND_INT(hash_num, &num, hash_num_entry);
    if (hash_num_entry != NULL) {
        HASH_DEL(hash_num, hash_num_entry);
    }
}

int majorityElement(int* nums, int numsSize){
    int i;

    if (numsSize == 1) {
        return nums[0];
    }
    for (i = 0; i < numsSize; i++) {
        add_hash_entry(nums[i], numsSize);
    }

    for (i = 0; i < numsSize; i++) {
        del_hash_entry(nums[i]);
    }

    return major_num;
}
