# compiler

assembly like language.

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
        data += add([data, i, value])
        print([data, '\n'])
    }
}
```
