// https://leetcode.com/problems/contains-duplicate-ii/

#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct node_t
{
    int key;
    int value;
    struct node_t *next;
} node_t;

typedef struct ht_t
{
    node_t *buckets[SIZE];
} ht_t;

ht_t *ht_create()
{
    ht_t *hashMap = malloc(sizeof(ht_t));
    for (int i = 0; i < SIZE; i++)
        hashMap->buckets[i] = NULL;

    return hashMap;
}

node_t *createNode(int key, int value)
{
    node_t *node = malloc(sizeof(node));
    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

unsigned int hash(int key)
{
    return abs(key) % SIZE;
}

void insert(ht_t *hashMap, int key, int value)
{
    unsigned int index = hash(key);
    node_t *newNode = createNode(key, value);

    if (hashMap->buckets[index] == NULL)
    {
        hashMap->buckets[index] = newNode;
        return;
    }

    node_t *current = hashMap->buckets[index];
    while (current->next != NULL)
    {
        if (current->key == key)
        {
            current->value = value;
            return;
        }

        current = current->next;
    }

    current->next = newNode;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    ht_t *hashMap = ht_create();

    for (int i = 0; i < numsSize; i++)
    {
        int key = nums[i];
        int index = hash(key);

        node_t *current = hashMap->buckets[index];
        while (current != NULL)
        {
            if (current->key == key && abs(current->value - i) <= k)
                return true;
            current = current->next;
        }

        insert(hashMap, key, i);
    }

    return false;
}