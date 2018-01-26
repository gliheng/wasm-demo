(module
    (import "js" "tbl" (table 2 anyfunc))

    (func $f52 (result i32) i32.const 52)
    (func $f63 (result i32) i32.const 63)
    (elem (i32.const 0) $f52 $f63)

    (type $T (func (result i32)))
    (func (export "dispatch") (param $0 i32) (result i32)
          (call_indirect $T (get_local $0))))