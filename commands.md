
**docker build:**
```
docker build -t cpp_sandbox .
```
pulls ubuntu, installs compiler and libs, copy source, build it, tag final image as cpp_sandbox


**docker run:**
```
docker run --rm \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  cpp_sandbox
```


**docker shell:**
```
docker run --rm -it cpp_sandbox bash
```


**g++12 compile:**
open docker shell, then:
```
cd /app/build
cmake --build .
```


**execute program:**
```
./playground
```
