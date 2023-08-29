

import {mod as libmosebotinfo} from './modinfos/libmousebot'

const _frida_log_callback =  new NativeCallback(function(sp:NativePointer){
    console.log(sp.readUtf8String());
}, 'void', ['pointer']);

const _frida_hexdump_callback =  new NativeCallback(function(sp:NativePointer, sz:number){
    console.log(
        hexdump(sp, {
            offset: 0,
            length: sz,
            header: true,
            ansi: false,
        })
    );
}, 'void', ['pointer','uint']);

const soname ='libmain.so'
const lib = libmosebotinfo.load([
    soname,
],{
    _frida_log      : _frida_log_callback,
    _frida_hexdump  : _frida_hexdump_callback,
    
})


const test = ()=>{
    const m = Process.getModuleByName(soname);
    new NativeFunction(lib.symbols.test, 'int', ['pointer'])(m.base);
}

console.log('##################################################')

test()
