# CPP coding practice

---

reference: https://tuannguyen68.gitbooks.io/learning-cmake-a-beginner-s-guide/content/chap1/chap1.html

commands:
1. open vscode:
go to workspace directory and open vscode 
```bash
code ./
```

2. create a file:
```bash
touch file_name.ext
```

3. build project 
```bash
cmake -H. -B <build folder path>                   # create configuartion files
cmake --build <build folder path> -- -j<number of threads>          # generate output program project_name.out in bin 
```

Alternatively
```bash
mkdir build
cd build
cmake ..
make -j $(nproc) # nproc command returns max numbers of processes supported by your cpu
```


4. execute a program
```bash
cd bin
./executable_name
```

