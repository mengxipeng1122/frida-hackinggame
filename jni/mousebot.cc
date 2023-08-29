

extern "C" {
    void _frida_log(const char* p);
    void _frida_hexdump(void* p, unsigned int i);
}



extern "C" int test(void* base){

    _frida_log("Hello from C++ !");
    _frida_hexdump(base, 0x20);

    return 0; 
}

