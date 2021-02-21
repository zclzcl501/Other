#include "algo_hmac.h"
#include <openssl/hmac.h>
#include <string.h>
#include <iostream>
using namespace std;

int HmacEncode(const char* algo,
    const char* key, unsigned int key_length,
    const char* input, unsigned int input_length,
    unsigned char*& output, unsigned int& output_length)
{
    const EVP_MD* engine = nullptr;
    if (_stricmp("sha512", algo) == 0) {
        engine = EVP_sha512();
    }
    else if (_stricmp("sha256", algo) == 0) {
        engine = EVP_sha256();
    }
    else if (_stricmp("sha1", algo) == 0) {
        engine = EVP_sha1();
    }
    else if (_stricmp("md5", algo) == 0) {
        engine = EVP_md5();
    }
    else if (_stricmp("sha224", algo) == 0) {
        engine = EVP_sha224();
    }
    else if (_stricmp("sha384", algo) == 0) {
        engine = EVP_sha384();
    }
    else {
        cout << "Algorithm " << algo << " is not supported!" << endl;
        return -1;
    }

    HMAC_CTX* ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, key, strlen(key), engine, nullptr);
    HMAC_Update(ctx, (unsigned char*)input, strlen(input));

    output = (unsigned char*)malloc(EVP_MAX_MD_SIZE); 
    HMAC_Final(ctx, output, &output_length);
    HMAC_CTX_free(ctx);

    return 0;
}
