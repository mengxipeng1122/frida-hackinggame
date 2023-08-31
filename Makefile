

all:./modinfos/libmousebot.ts
	./node_modules/frida-compile/bin/compile.js -o _agent.js index.ts

./modinfos/libmousebot.ts:./libs/arm64-v8a/libmousebot.so 
	./utils/so2ts.py -b $^ -o $@

./libs/arm64-v8a/libmousebot.so:./jni/mousebot.cc
	make -C jni

clean:
	rm -fr _agent.js ./modinfos/lib*.ts libs/ obj/
