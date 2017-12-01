(module
  (import "console" "log" (func $log (param i32)))
  (func (export "logIt")
    i32.const 12345
    call $log))