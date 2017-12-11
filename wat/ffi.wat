(module
  (import "console" "log" (func $log (param i32)))
  (import "constants" "n" (global $n i32))
  (func (export "logIt")
    get_global $n
    get_global $n
    i32.mul
    call $log))