#include "algo_hmac.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        //参数指定hash算法,支持HmacEncode列举的那些
        cout << "Please specify a hash algorithm!" << endl;
        return -1;
    }

    //char key[] = "fasdkgjl;asdfjg;dsfjgasdsr";//secret key
    //string data = "/pic/small/3007024147/8ba5a744-f48d-4ba2-b93f-da17e7f52dff";//要加密传输的数据

    string key = "4567"; //secret key
    string data = "123"; //要加密传输的数据

    unsigned char* mac = nullptr;
    unsigned int mac_length = 0;

    int ret = HmacEncode(argv[1], key.c_str(), key.length(), data.c_str(), data.length(), mac, mac_length);
    if (0 == ret) {
        cout << "Algorithm HMAC encode succeeded!" << endl;
    }
    else {
        cout << "Algorithm HMAC encode failed!" << endl;
        return -1;
    }

    cout << "mac length: " << mac_length << endl;
    cout << "mac:";
    for (int i = 0; i < mac_length; i++) {
        printf("%-3x", (unsigned int)mac[i]);
    }
    cout << endl;

    if (mac) {
        free(mac);
        cout << "mac is freed!" << endl;
    }

    return 0;
}
