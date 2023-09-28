#include <stdio.h>
#include <stdint.h>

// A function that takes two pointers and returns their XOR
void* xor_pointers(void* p1, void* p2) {
    return (void*)((uintptr_t)p1 ^ (uintptr_t)p2);
}

int main() {
    // A secret message that we want to hide
    const char* secret = "secret string";

    // A random key that we use to encrypt the pointer
    const char* key = "key string";

    // Encrypt the pointer by XORing it with the key
    void* encrypted = xor_pointers((void*)secret, (void*)key);

    // Print the encrypted pointer
    printf("Encrypted pointer: %p\n", encrypted);

    // Decrypt the pointer by XORing it again with the same key
    void* decrypted = xor_pointers(encrypted, (void*)key);

    // Print the decrypted pointer and the message
    printf("Decrypted pointer: %p\n", decrypted);
    printf("Message: %s\n", (const char*)decrypted);

    return 0;
}
