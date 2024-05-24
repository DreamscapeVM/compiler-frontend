# compiler

assembly like language.

## Code for Example
```sh
; data # Comments
let name: str = "hello world!\n"
let value: int64 = 1000;

; function add (x: [int32]) -> int64 {
    mut r: int64 = 0
    for mut i: int32 = 0; i < size(x); i += 1 {
        r += x[i]
    }
    return r
}

; main (argv: [str]) { 
    print(str)
    mut data: int64 = 0
    for mut i: int32 = 0; i < 10; i += 1 {
        data = add([data, i, value])
        print([data, '\n'])
    }
}
```

## Expected Result

```sh
hello world!
1000
2001
3003
4006
5010
6015
7021
8028
9036
10045
```

# How to 

```sh
$ vmc code.vmc -o code.vm
$ vm --max_memory_size 4096 \
     --max_register_size 8 \
     --insturction_per_seconds 1024 \
     --path_of_software code.vm
```
