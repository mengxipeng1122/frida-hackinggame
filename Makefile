

all:./modinfos/libmousebot.ts
	./node_modules/frida-compile/bin/compile.js -o _agent.js index.ts

./modinfos/libmousebot.ts:
	make -C jni
	./utils/so2ts.py -b ./libs/arm64-v8a/libmousebot.so -o $@

clean:
	rm _agent.js ./modinfos/lib*.ts
